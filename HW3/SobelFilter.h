#define SC_INCLUDE_FX
#ifndef SOBEL_FILTER_H_
#define SOBEL_FILTER_H_
#include <systemc>
#include <sys/time.h> 
#include <cmath>
#include <iomanip>

#include "tlm"
#include "tlm_utils/simple_target_socket.h"
#include "filter_def.h"

using namespace sc_core;
using namespace sc_dt;

class SobelFilter : public sc_module {
public:
  tlm_utils::simple_target_socket<SobelFilter> t_skt;

  sc_fifo<int> i_r;
  sc_fifo<int> i_g;
  sc_fifo<int> i_b;
  //sc_fifo<int> o_result;
  //
  sc_fifo<int> o_r;
  sc_fifo<int> o_g;
  sc_fifo<int> o_b;


  SC_HAS_PROCESS(SobelFilter);
  SobelFilter(sc_module_name n);
  ~SobelFilter() = default;

private:
  //int val[MASK_N];

  unsigned int base_offset;
  void blocking_transport(tlm::tlm_generic_payload &payload,
                          sc_core::sc_time &delay);
  void do_filter();                        
};
#endif
