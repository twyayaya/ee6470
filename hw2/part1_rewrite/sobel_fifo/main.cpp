#include <iostream>
#include <string>
using namespace std;

// Wall Clock Time Measurement
#include <sys/time.h>

#include "SobelFilter.h"
#include "Testbench.h"
#include <systemc>

// TIMEVAL STRUCT IS Defined ctime
// use start_time and end_time variables to capture
// start of simulation and end of simulation
struct timeval start_time, end_time;

// int main(int argc, char *argv[])
int sc_main(int argc, char **argv) {
  //if ((argc < 3) || (argc > 4)) {
  //  cout << "No arguments for the executable : " << argv[0] << endl;
  //  cout << "Usage : >" << argv[0] << " in_image_file_name out_image_file_name"
  //       << endl;
  //  return 0;
  //}
  Testbench tb("tb");
  SobelFilter sobel_filter("sobel_filter");
  sc_clock clk("clk", CLOCK_PERIOD, SC_NS);
  sc_signal<bool> rst("rst");
  sc_fifo<int> r;
  sc_fifo<int> g;
  sc_fifo<int> b;
  sc_fifo<int> result;
  tb.i_clk(clk);
  tb.o_rst(rst);
  sobel_filter.i_clk(clk);
  sobel_filter.i_rst(rst);
  tb.o_r(r);  //source
  tb.o_g(g);
  tb.o_b(b);
  tb.i_result(result);
  sobel_filter.i_r(r);
  sobel_filter.i_g(g);
  sobel_filter.i_b(b);
  ///
  sc_fifo<int> rr;  //result
  sc_fifo<int> gg;
  sc_fifo<int> bb;
  tb.i_r(rr);
  tb.i_g(gg);
  tb.i_b(bb);
  sobel_filter.o_r(rr);
  sobel_filter.o_g(gg);
  sobel_filter.o_b(bb);

 



//
  std::cout << "read pic" << '\t' << sc_core::sc_time_stamp() << std::endl ;
  tb.read_bmp("lena.bmp");
  std::cout << "sc start"<< std::endl ;
  sc_start();
  
  std::cout << "Simulated time == " << sc_core::sc_time_stamp() << std::endl;
  tb.write_bmp("lena_hw2_part2_test.bmp");

  return 0;
}