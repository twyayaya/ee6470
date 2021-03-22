#ifndef SOBEL_FILTER_H_
#define SOBEL_FILTER_H_
#include <systemc>
using namespace sc_core;

//#include "filter_def.h"

class SobelFilter : public sc_module {
public:
  sc_in_clk i_clk;
  sc_in<bool> i_rst;
  sc_fifo_in<int> i_r;
  sc_fifo_in<int> i_g;
  sc_fifo_in<int> i_b;
  sc_fifo_out<int> o_r;
  sc_fifo_out<int> o_g;
  sc_fifo_out<int> o_b;
  //
  sc_fifo_in<int> i_height;
  sc_fifo_in<int> i_width;
  
  unsigned int get_width() { return width; }
  unsigned int get_height() { return height; }
  //sc_fifo_out<int> o_result;

  SC_HAS_PROCESS(SobelFilter);
  SobelFilter(sc_module_name n);
  ~SobelFilter() = default;

private:
  void do_filter();
  //int val[MASK_N];
  int width;
  int height;
};
#endif