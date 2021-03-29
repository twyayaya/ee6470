#include <cmath>
#include <iomanip>

#include "SobelFilter.h"

SobelFilter::SobelFilter(sc_module_name n)
    : sc_module(n), t_skt("t_skt"){
  SC_THREAD(do_filter);

  t_skt.register_b_transport(this, &SobelFilter::blocking_transport);
}



void SobelFilter::do_filter() {
    //Gaussian Blur
    #define filterWidth 3     //mask_X
    #define filterHeight 3    //mask_Y

    double filter[filterHeight][filterWidth] =
    {
      0.077847, 0.123317, 0.077847,
      0.123317, 0.195346, 0.123317,
      0.077847, 0.123317, 0.077847,
    };

    int v,u;        // for loop counter
    double R, G, B; // color of R, G, B
    while(1){
 
        R = G = B = 0;

        for (v = 0; v<filterHeight; ++v) {
          for (u = 0; u<filterWidth ; ++u) {

              R += i_r.read() * filter[v][u];
              G += i_g.read() * filter[v][u];
              B += i_b.read() * filter[v][u];

             }
          }   
        o_r.write(R);
        o_g.write(G);
        o_b.write(B);
    }
}

void SobelFilter::blocking_transport(tlm::tlm_generic_payload &payload,
                                     sc_core::sc_time &delay) {
  sc_dt::uint64 addr = payload.get_address();
  //addr = addr - base_offset;
  unsigned char *mask_ptr = payload.get_byte_enable_ptr();
  unsigned char *data_ptr = payload.get_data_ptr();
  //
  int r, g, b;

  //
  //word buffer;
  switch (payload.get_command()) {
  case tlm::TLM_READ_COMMAND:
    switch (addr) {
    case SOBEL_FILTER_RESULT_ADDR:
      r = o_r.read();
      g = o_g.read();
      b = o_b.read();
      break;
    default:
      std::cerr << "Error! SobelFilter::blocking_transport: address 0x"
                << std::setfill('0') << std::setw(8) << std::hex << addr
                << std::dec << " is not valid" << std::endl;
      std::cout<<"result!!"<<std::endl;
      break;
    }
    data_ptr[0] = r;
    data_ptr[1] = g;
    data_ptr[2] = b;
    data_ptr[3] = 0;
    break;

  case tlm::TLM_WRITE_COMMAND:
    switch (addr) {
    case SOBEL_FILTER_R_ADDR:
      if (mask_ptr[0] == 0xff) {
        i_r.write(data_ptr[0]);
      }
      if (mask_ptr[1] == 0xff) {
        i_g.write(data_ptr[1]);
      }
      if (mask_ptr[2] == 0xff) {
        i_b.write(data_ptr[2]);
      }
      break;
    default:
      std::cerr << "Error! SobelFilter::blocking_transport: address 0x"
                << std::setfill('0') << std::setw(8) << std::hex << addr
                << std::dec << " is not valid" << std::endl;
      std::cout<<"R!!"<<std::endl;
      break;
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
