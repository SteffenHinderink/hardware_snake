#include "xil_printf.h"
#include "xgpio.h"
#include "xsnake_output.h"
#include <unistd.h>
#include <stdbool.h>

#define TIME 1000
#define ITER 256
#define HEIGHT 16
#define WIDTH 16
#define PRIME 911;

XGpio gpio;
XSnake_output out;

int field[HEIGHT][WIDTH];
int spawn;
int curRow;
int curCol;
enum Dir {NORTH, EAST, SOUTH, WEST};
enum Dir curDir;
enum Dir nextDir;
bool released;

void spawnFood() {
    int row;
    int col;
    do {
        spawn += PRIME;
        spawn %= HEIGHT * WIDTH;
        row = spawn / WIDTH;
        col = spawn % WIDTH;
    } while (field[row][col] != 0);
    field[row][col] = -1;
}

void init() {
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            field[row][col] = 0;
        }
    }
    spawn = HEIGHT / 2 * WIDTH + WIDTH / 2;
    curRow = spawn / WIDTH;
    curCol = spawn % WIDTH;
    field[curRow][curCol] = 1;
    spawnFood();
    curDir = NORTH;
    nextDir = NORTH;
    released = true;
}

bool loop() {
    int nextRow = curRow;
    int nextCol = curCol;
    curDir = nextDir;
    switch (curDir) {
        case NORTH: nextRow--; break;
        case EAST: nextCol++; break;
        case SOUTH: nextRow++; break;
        case WEST: nextCol--; break;
    }
    if (nextRow < 0 || nextRow >= HEIGHT || nextCol < 0 || nextCol >= WIDTH || field[nextRow][nextCol] > 0) {
    	// VERLOREN
    	return false;
    } else {
        if (field[nextRow][nextCol] == -1) {
            field[nextRow][nextCol] = field[curRow][curCol] + 2;
            bool won = true;
            for (int row = 0; row < HEIGHT && won; row++) {
                for (int col = 0; col < WIDTH && won; col++) {
                    if (field[row][col] == 0) {
                        won = false;
                    }
                }
            }
            if (won) {
                // GEWONNEN
            	return false;
            }
            spawnFood();
        } else {
            field[nextRow][nextCol] = field[curRow][curCol] + 1;
        }
        curRow = nextRow;
        curCol = nextCol;
        for (int row = 0; row < HEIGHT; row++) {
            for (int col = 0; col < WIDTH; col++) {
                if (field[row][col] > 0) {
                    field[row][col]--;
                }
            }
        }
        return true;
    }
}

bool poll() {
	int btns = XGpio_DiscreteRead(&gpio, 1);
	if (released) {
		bool right = (btns & 0b0001) == 0b0001;
		bool left = (btns & 0b1000) == 0b1000;
		if (right ^ left) {
			if (right) {
				switch (curDir) {
					case NORTH: nextDir = EAST; break;
					case EAST: nextDir = SOUTH; break;
					case SOUTH: nextDir = WEST; break;
					case WEST: nextDir = NORTH; break;
				}
			} else {
				switch (curDir) {
					case NORTH: nextDir = WEST; break;
					case EAST: nextDir = NORTH; break;
					case SOUTH: nextDir = EAST; break;
					case WEST: nextDir = SOUTH; break;
				}
			}
			released = false;
			return true;
		}
	}
	if (btns == 0) {
		released = true;
		return false;
	}
	return true;
}

void draw() {
	for (int row = 0; row < HEIGHT; row++) {
		for (int col = 0; col < WIDTH; col++) {
			int cell = field[row][col];
			XSnake_output_Write_field_V_Words(&out, 16 * row + col, &cell, 1);
		}
	}
}

int main() {
	XGpio_Initialize(&gpio, XPAR_AXI_GPIO_0_DEVICE_ID);
	XGpio_SetDataDirection(&gpio, 1, 0b1111);

	XSnake_output_Initialize(&out, XPAR_SNAKE_OUTPUT_0_DEVICE_ID);
	XSnake_output_EnableAutoRestart(&out);
	XSnake_output_Start(&out);

	bool ingame = false;
	do {
		init();
		draw();
		while (!ingame) {
			ingame = poll();
			usleep(TIME);
		}
		for (int i = 0; ingame; i++) {
			poll();
			usleep(TIME);
			if (i == ITER) {
				ingame = loop();
				draw();
				i = 0;
			}
		}
	} while (true);

	return 0;
}