// Generated by stratus_hls 19.12-s100  (91710.131054)
// Mon Apr 26 12:38:38 2021
// from ../SobelFilter.cpp
#include "SobelFilter_ROM_9X32_filter.h"

struct SobelFilter_ROM_9X32_filter;
SobelFilter_ROM_9X32_filter::SobelFilter_ROM_9X32_filter(sc_module_name name) : sc_module(name) 
    ,in1("in1")
    ,out1("out1")
    ,clk("clk")
    ,filter()
{
  CYN_ROM_INIT( sc_uint<32> , filter, ENUMS::CYN_HEX, "bdw_work/modules/SobelFilter/BASIC/SobelFilter_ROM_9X32_filter_0.memh", "initialize SobelFilter_ROM_9X32_filter" ); 
  SC_METHOD(SobelFilter_ROM_9X32_filter_filter_thread_1);
  sensitive << clk.pos();
  dont_initialize();

}
void SobelFilter_ROM_9X32_filter::SobelFilter_ROM_9X32_filter_filter_thread_1(){
  if ( (/*imp*/sc_uint<1>)(in1.read() < ((/*imp*/sc_uint<4> )(9ULL))) ) {
    out1 = (sc_uint<32> ) ((filter)[in1.read()]);
  } 
}
