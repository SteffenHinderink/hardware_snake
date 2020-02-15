#include "snake_output.h"
#include <hls_opencv.h>

int main (int argc, char** argv) {

	CvSize pattern_size = {WIDTH,HEIGHT};
	IplImage* dst = cvCreateImage(pattern_size, IPL_DEPTH_8U, 3);
	AXI_STREAM dst_axi;

	cell field[GAME_HEIGHT][GAME_WIDTH];
	for (int row = 0; row < GAME_HEIGHT; row++) {
		for (int col = 0; col < GAME_WIDTH; col++) {
			field[row][col] = 0;
		}
	}
	field[0][0] = 1;
	field[1][1] = -1;

	// Call the function to be synthesized
	snake_output(dst_axi, field);

	// Convert the AXI4 Stream data to OpenCV format
	// This function is not following UG934 for AXI4S color mapping
	// Thus on the output image, the blue and green color will be switched
	int i = 0;
	while(dst_axi.size() >= (WIDTH*HEIGHT)){
		AXIvideo2IplImage(dst_axi, dst);
		cvSaveImage(cv::format("out_%0*i.png",3,i).c_str(), dst);
		i++;
	}
	std::cout << "Saved " << i << " images" << std::endl;
	cvReleaseImage(&dst);

	return 0;
}
