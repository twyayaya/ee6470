#define SC_INCLUDE_FX
#include <iostream>
#include <string>
#include <systemc>
#include <sys/time.h>
#include "SobelFilter.h"
#include "Testbench.h"
//
#include "SimpleBus.h"
//
using namespace sc_core;
using namespace sc_dt;

//struct timeval start_time, end_time;

int sc_main(int argc, char **argv)
{

  Testbench tb("tb");
  SobelFilter sobel_filter0("sobel_filter0", 0);
  SobelFilter sobel_filter1("sobel_filter1", 1);
  SimpleBus<1, 2> bus("bus");
  tb.initiator.i_skt(bus.t_skt[0]);
  bus.set_clock_period(sc_time(CLOCK_PERIOD, SC_NS));
  bus.setDecode(1, SOBEL_MM_BASE, SOBEL_MM_BASE + SOBEL_MM_SIZE - 1);
  bus.i_skt[0](sobel_filter0.t_skt);
  bus.i_skt[1](sobel_filter1.t_skt);

  //std::cout << "initiator" << std::endl;

  tb.read_bmp("lena.bmp");
  std::cout << "read" << std::endl;

  std::cout << "start" << std::endl;
  sc_start();

  std::cout << "Simulated time == " << sc_core::sc_time_stamp() << std::endl;
  tb.write_bmp("lena_hw4.bmp");
  //std::cout << "write" << std::endl;

  return 0;
}
