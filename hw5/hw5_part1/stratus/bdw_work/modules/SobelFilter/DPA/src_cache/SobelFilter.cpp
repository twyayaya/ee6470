#include <cmath>

#ifndef NATIVE_SYSTEMC
#include "stratus_hls.h"
#endif

#include "SobelFilter.h"

SobelFilter::SobelFilter(sc_module_name n) : sc_module(n)
{
	SC_THREAD(do_filter);
	sensitive << i_clk.pos();
	dont_initialize();
	reset_signal_is(i_rst, false);

#ifndef NATIVE_SYSTEMC
	i_rgb.clk_rst(i_clk, i_rst);
	o_result.clk_rst(i_clk, i_rst);
#endif
}

SobelFilter::~SobelFilter() {}

// sobel mask
//Gaussian Blur
#define filterWidth 3  //mask_X
#define filterHeight 3 //mask_Y

const int filter[filterHeight][filterWidth] =
	{
    {1,2,1},
    {2,4,2},
    {1,2,1}
};

const int f = 16;

void SobelFilter::do_filter()
{
	sc_uint<8> from_tb_r, from_tb_g, from_tb_b, v, u;
	sc_uint<24> rgb, result;
	sc_uint<32> R, G, B;
	{
#ifndef NATIVE_SYSTEMC
		HLS_DEFINE_PROTOCOL("main_reset");
		i_rgb.reset();
		o_result.reset();
#endif
		wait();
	}
	while (true)
	{
		R = G = B = 0;
		for (v = 0; v < filterHeight; ++v)
		{
			for (u = 0; u < filterWidth; ++u)
			{
#ifndef NATIVE_SYSTEMC
				{
					HLS_DEFINE_PROTOCOL("input");
					rgb = i_rgb.get();
					wait();
				}
#else
				rgb = i_rgb.read();
#endif
				from_tb_r = rgb.range(7 , 0);
				from_tb_g = rgb.range(15 , 8);
				from_tb_b = rgb.range(23 , 16);
				{
					HLS_CONSTRAIN_LATENCY(0, 1, "lat01");
					R += (sc_uint<32>)from_tb_r * filter[v][u];
					G += (sc_uint<32>)from_tb_g * filter[v][u];
					B += (sc_uint<32>)from_tb_b * filter[v][u];
				}
			}
		}
		result.range(7 , 0) = (sc_uint<8>)(R/f);
		result.range(15 , 8) = (sc_uint<8>)(G/f);
		result.range(23 , 16) = (sc_uint<8>)(B/f);
#ifndef NATIVE_SYSTEMC
		{
			HLS_DEFINE_PROTOCOL("output");
			o_result.put(result);
			wait();
		}
#else
		o_result.write(result);
#endif
	}
}
