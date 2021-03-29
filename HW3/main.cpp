#define SC_INCLUDE_FX
#include <iostream>
#include <string>
#include <systemc>
#include <sys/time.h>
#include "SobelFilter.h"
#include "Testbench.h"
using namespace sc_core;
using namespace sc_dt;


//struct timeval start_time, end_time;


int sc_main(int argc, char **argv) {

  Testbench tb("tb");
  SobelFilter sobel_filter("sobel_filter");
  tb.initiator.i_skt(sobel_filter.t_skt);
  std::cout << "initiator" << std::endl;

  tb.read_bmp("lena.bmp");  
  std::cout << "read" << std::endl;

  std::cout << "start" << std::endl;
  sc_start();

  std::cout << "Simulated time == " << sc_core::sc_time_stamp() << std::endl;
  tb.write_bmp("lena_hw3.bmp");
  std::cout << "write" << std::endl;


  return 0;
}
