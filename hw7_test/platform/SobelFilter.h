#ifndef SOBEL_FILTER_H_
#define SOBEL_FILTER_H_
#include <systemc>
#include <cmath>
#include <iomanip>
using namespace sc_core;

#include <tlm>
#include <tlm_utils/simple_target_socket.h>

#include "filter_def.h"

struct SobelFilter : public sc_module
{
  tlm_utils::simple_target_socket<SobelFilter> tsock;

  sc_fifo<unsigned char> i_r;
  sc_fifo<unsigned char> i_g;
  sc_fifo<unsigned char> i_b;
  //sc_fifo<int> o_result;
  sc_fifo<unsigned char> o_r;
  sc_fifo<unsigned char> o_g;
  sc_fifo<unsigned char> o_b;
  //
  SC_HAS_PROCESS(SobelFilter);

  SobelFilter(sc_module_name n) : sc_module(n),
                                  tsock("t_skt"),
                                  base_offset(0)
  {
    tsock.register_b_transport(this, &SobelFilter::blocking_transport);
    SC_THREAD(do_filter);
  }

  ~SobelFilter()
  {
  }

  //int val[MASK_N];
  unsigned int base_offset;

  void do_filter()
  {
    {
      wait(CLOCK_PERIOD, SC_NS);
    }
    while (true)
    {
      int R = 0;
      int G = 0;
      int B = 0;
      unsigned char r = 0;
      unsigned char g = 0;
      unsigned char b = 0;
      for (unsigned int v = 0; v < filterHeight; ++v)
      {
        for (unsigned int u = 0; u < filterWidth; ++u)
        {
          r = i_r.read();
          g = i_g.read();
          b = i_b.read();

          wait(CLOCK_PERIOD, SC_NS);

          R += r * filter[v][u];
          G += g * filter[v][u];
          B += b * filter[v][u];
        }
      }
      o_r.write((unsigned char)(R * factor));
      o_g.write((unsigned char)(G * factor));
      o_b.write((unsigned char)(B * factor));
    }
  }

  void blocking_transport(tlm::tlm_generic_payload &payload, sc_core::sc_time &delay)
  {
    wait(delay);
    // unsigned char *mask_ptr = payload.get_byte_enable_ptr();
    // auto len = payload.get_data_length();
    tlm::tlm_command cmd = payload.get_command();
    sc_dt::uint64 addr = payload.get_address();
    unsigned char *data_ptr = payload.get_data_ptr();

    addr -= base_offset;

    // cout << (int)data_ptr[0] << endl;
    // cout << (int)data_ptr[1] << endl;
    // cout << (int)data_ptr[2] << endl;
    word buffer;

    switch (cmd)
    {
    case tlm::TLM_READ_COMMAND:
      // cout << "READ" << endl;
      switch (addr)
      {
      case SOBEL_FILTER_RESULT_ADDR:
        buffer.uc[0] = o_r.read();
        buffer.uc[1] = o_g.read();
        buffer.uc[2] = o_b.read();
        buffer.uc[3] = 0;
        break;
      default:
        std::cerr << "READ Error! SobelFilter::blocking_transport: address 0x"
                  << std::setfill('0') << std::setw(8) << std::hex << addr
                  << std::dec << " is not valid" << std::endl;
      }
      data_ptr[0] = buffer.uc[0];
      data_ptr[1] = buffer.uc[1];
      data_ptr[2] = buffer.uc[2];
      data_ptr[3] = buffer.uc[3];
      break;
    case tlm::TLM_WRITE_COMMAND:
      // cout << "WRITE" << endl;
      switch (addr)
      {
      case SOBEL_FILTER_R_ADDR:
        i_r.write(data_ptr[0]);
        i_g.write(data_ptr[1]);
        i_b.write(data_ptr[2]);
        break;
      default:
        std::cerr << "WRITE Error! SobelFilter::blocking_transport: address 0x"
                  << std::setfill('0') << std::setw(8) << std::hex << addr
                  << std::dec << " is not valid" << std::endl;
      }
      break;
    case tlm::TLM_IGNORE_COMMAND:
      payload.set_response_status(tlm::TLM_GENERIC_ERROR_RESPONSE);
      return;
    default:
      payload.set_response_status(tlm::TLM_GENERIC_ERROR_RESPONSE);
      return;
    }
    payload.set_response_status(tlm::TLM_OK_RESPONSE); // Always OK
  }
};
#endif
