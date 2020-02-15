#include "snake_output.h"

void snake_output(AXI_STREAM& m_axis_video,
                  cell field[GAME_HEIGHT][GAME_WIDTH])
{
	#pragma HLS INTERFACE axis register both port=m_axis_video
	#pragma HLS INTERFACE s_axilite port=return

	#pragma HLS INTERFACE s_axilite register port=field

	ap_axiu<24, 1, 1, 1> video;
	hls::rgb_8 pixel;

	for (ap_uint<12> frame = 0; frame < 36; frame++) {
		frame_line_loop: for (ap_uint<12> row = 0; row < HEIGHT; row++) {
			frame_pixel_loop: for (ap_uint<12> col = 0; col < WIDTH; col++) {
				#pragma HLS PIPELINE

				// user = SOF (start of frame)
				video.user = (row == 0 && col == 0) ? 1 : 0;

				// last = EOL (end of line)
				video.last = (col == WIDTH - 1) ? 1 : 0;

				int R, G, B;
				if (col < BORDER_LEFT || col >= BORDER_RIGHT) {

					double H = frame * 10;
					double S = 1;
					double V = 1;

					int hi = (int) (H / 60);
					double f = H / 60 - hi;

					double p = V * (1 - S);
					double q = V * (1 - S * f);
					double t = V * (1 - S * (1 - f));

					double r, g, b;
					switch (hi) {
						case 0: case 6: r = V; g = t; b = p; break;
						case 1: r = q; g = V; b = p; break;
						case 2: r = p; g = V; b = t; break;
						case 3: r = p; g = q; b = V; break;
						case 4: r = t; g = p; b = V; break;
						case 5: r = V; g = p; b = q; break;
					}

					R = (int) (r * 255);
					G = (int) (g * 255);
					B = (int) (b * 255);

				} else {

					int game_row = row * GAME_HEIGHT / HEIGHT;
					int game_col = (col - BORDER_LEFT) * GAME_WIDTH / HEIGHT;

					if (field[game_row][game_col] < 0) { // Essen
						R = 255;
						G = 0;
						B = 255;
					} else if (field[game_row][game_col] > 0) { // Schlange
						R = 0;
						G = 255;
						B = 255;
					} else { // Leer
						R = 0;
						G = 0;
						B = 0;
					}

				}

				pixel.R = R;
				pixel.G = G;
				pixel.B = B;

				video.data = set_rgb_8_pixel_value(pixel);

				m_axis_video << video;
			}
		}
	}
}

ap_uint<24> set_rgb_8_pixel_value(hls::rgb_8 pixel)
{
	#pragma HLS INLINE

	ap_uint<24> pixel_out;

	pixel_out = (pixel.R << 16) + (pixel.B << 8) + pixel.G;
	return pixel_out;
}
