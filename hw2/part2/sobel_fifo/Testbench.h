#ifndef TESTBENCH_H_
#define TESTBENCH_H_

#include <string>
using namespace std;

#include <systemc>
using namespace sc_core;

//#include "filter_def.h"

/*
const int WHITE = 255;
const int BLACK = 0;
const int THRESHOLD = 90;
*/

class Testbench : public sc_module {
public:
  sc_in_clk i_clk;
  sc_out<bool> o_rst;
  sc_fifo_out<int> o_r;
  sc_fifo_out<int> o_g;
  sc_fifo_out<int> o_b;
  sc_fifo_in<int> i_result;
  //
  sc_fifo_in<int> i_r;
  sc_fifo_in<int> i_g;
  sc_fifo_in<int> i_b;
  //
  sc_fifo_out<int> o_height;
  sc_fifo_out<int> o_width;

  SC_HAS_PROCESS(Testbench);

  Testbench(sc_module_name n);
  ~Testbench() = default;

  int read_bmp(const char *fname_s);
  int write_bmp(const char *fname_t);

  unsigned int get_width() { return width; }

  unsigned int get_height() { return height; }

  unsigned int get_width_bytes() { return width_bytes; }

  unsigned int get_bytes_per_pixel() { return bytes_per_pixel; }

  unsigned char *get_source_image() { return source_bitmap; }
  unsigned char *get_target_image() { return target_bitmap; }

private:
  unsigned int input_rgb_raw_data_offset;
  const unsigned int output_rgb_raw_data_offset;
  int width;
  int height;
  unsigned int width_bytes;
  unsigned char bits_per_pixel;
  unsigned short bytes_per_pixel;
  unsigned char *source_bitmap;
  unsigned char *target_bitmap;

  void do_sobel();
  void out();
};
#endif