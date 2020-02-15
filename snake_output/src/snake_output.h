#ifndef _VPG_H_
#define _VPG_H_
	
	#include <hls_video.h>

	#define HEIGHT 600
	#define WIDTH 800

	#define BORDER_LEFT 100
	#define BORDER_RIGHT 700

	#define GAME_HEIGHT 16
	#define GAME_WIDTH 16
	
	typedef hls::stream<ap_axiu<24,1,1,1> >	AXI_STREAM;

	typedef ap_int<32> cell;

	void snake_output(AXI_STREAM& m_axis_video,
			          cell field[GAME_HEIGHT][GAME_WIDTH]);
	ap_uint<24> set_rgb_8_pixel_value(hls::rgb_8 pixel);

#endif
