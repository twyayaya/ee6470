// Generated by stratus_hls 19.12-s100  (91710.131054)
// Mon Apr 26 01:59:07 2021
// from ../SobelFilter.cpp
#include "SobelFilter_rtl.h"

struct SobelFilter;
SobelFilter::SobelFilter(sc_module_name name) : sc_module(name) 
    ,i_clk("i_clk")
    ,i_rst("i_rst")
    ,i_rgb_busy("i_rgb_busy")
    ,i_rgb_vld("i_rgb_vld")
    ,i_rgb_data("i_rgb_data")
    ,o_result_busy("o_result_busy")
    ,o_result_vld("o_result_vld")
    ,o_result_data("o_result_data")
    ,o_result_m_req_m_prev_trig_req("o_result_m_req_m_prev_trig_req")
    ,SobelFilter_Xor_1Ux1U_1U_1_1_out1("SobelFilter_Xor_1Ux1U_1U_1_1_out1")
    ,o_result_m_unacked_req("o_result_m_unacked_req")
    ,SobelFilter_Or_1Ux1U_1U_4_2_out1("SobelFilter_Or_1Ux1U_1U_4_2_out1")
    ,SobelFilter_N_Muxb_1_2_0_4_4_out1("SobelFilter_N_Muxb_1_2_0_4_4_out1")
    ,i_rgb_m_unvalidated_req("i_rgb_m_unvalidated_req")
    ,SobelFilter_gen_busy_r_4_20_gen_busy_i_rgb_m_data_is_invalid_next("SobelFilter_gen_busy_r_4_20_gen_busy_i_rgb_m_data_is_invalid_next")
    ,SobelFilter_gen_busy_r_4_20_gdiv("SobelFilter_gen_busy_r_4_20_gdiv")
    ,SobelFilter_gen_busy_r_4_20_gnew_req("SobelFilter_gen_busy_r_4_20_gnew_req")
    ,global_state_next("global_state_next")
    ,SobelFilter_Add_12Ux12U_12U_4_12_in1("SobelFilter_Add_12Ux12U_12U_4_12_in1")
    ,SobelFilter_Mul_12Sx8U_12S_4_10_out1("SobelFilter_Mul_12Sx8U_12S_4_10_out1")
    ,SobelFilter_Mul_12Sx8U_12S_4_10_in1("SobelFilter_Mul_12Sx8U_12S_4_10_in1")
    ,SobelFilter_Mul_12Sx8U_12S_4_10_in2("SobelFilter_Mul_12Sx8U_12S_4_10_in2")
    ,SobelFilter_Add_4Ux2U_4U_4_8_out1("SobelFilter_Add_4Ux2U_4U_4_8_out1")
    ,SobelFilter_Mul_2Ux2U_4U_4_7_in2("SobelFilter_Mul_2Ux2U_4U_4_7_in2")
    ,SobelFilter_Add_2Ux1U_2U_4_6_in2("SobelFilter_Add_2Ux1U_2U_4_6_in2")
    ,gs_ctrl0("gs_ctrl0")
    ,SobelFilter_Mul_12Sx8U_12S_4_11_out1("SobelFilter_Mul_12Sx8U_12S_4_11_out1")
    ,s_reg_28("s_reg_28")
    ,s_reg_27("s_reg_27")
    ,SobelFilter_Mul_2Ux2U_4U_4_7_out1("SobelFilter_Mul_2Ux2U_4U_4_7_out1")
    ,s_reg_26("s_reg_26")
    ,SobelFilter_Add_2Ux1U_2U_4_9_out1("SobelFilter_Add_2Ux1U_2U_4_9_out1")
    ,s_reg_25("s_reg_25")
    ,s_reg_23("s_reg_23")
    ,s_reg_22("s_reg_22")
    ,SobelFilter_Add_2Ux1U_2U_4_6_out1("SobelFilter_Add_2Ux1U_2U_4_6_out1")
    ,s_reg_21("s_reg_21")
    ,s_reg_20("s_reg_20")
    ,SobelFilter_gen_busy_r_4_20_out1("SobelFilter_gen_busy_r_4_20_out1")
    ,SobelFilter_And_1Ux1U_1U_4_18_out1("SobelFilter_And_1Ux1U_1U_4_18_out1")
    ,SobelFilter_Not_1U_1U_1_3_out1("SobelFilter_Not_1U_1U_1_3_out1")
    ,o_result_m_req_m_trig_req("o_result_m_req_m_trig_req")
    ,SobelFilter_LessThan_2Ux2U_1U_4_15_out1("SobelFilter_LessThan_2Ux2U_1U_4_15_out1")
    ,SobelFilter_LessThan_2Ux2U_1U_4_17_out1("SobelFilter_LessThan_2Ux2U_1U_4_17_out1")
    ,global_state("global_state")
    ,i_rgb_m_busy_req_0("i_rgb_m_busy_req_0")
    ,SobelFilter_Add_12Ux12U_12U_4_12_out1("SobelFilter_Add_12Ux12U_12U_4_12_out1")
    ,SobelFilter_Add_12Ux12U_12U_4_16_out1("SobelFilter_Add_12Ux12U_12U_4_16_out1")
    ,s_reg_24("s_reg_24")
    ,stall0("stall0")
    ,filter_in1("filter_in1")
    ,filter_out1("filter_out1")
{
  filter = new SobelFilter_ROM_9X32_filter("filter");
  filter->in1(filter_in1);
  filter->out1(filter_out1);
  filter->clk(i_clk);

  SC_METHOD(drive_o_result_data);
  sensitive << i_clk.pos();
  dont_initialize();

  SC_METHOD(drive_i_rgb_m_busy_req_0);
  sensitive << i_clk.pos();
  dont_initialize();

  SC_METHOD(drive_o_result_m_req_m_trig_req);
  sensitive << i_clk.pos();
  dont_initialize();

  SC_METHOD(drive_stall0);
  sensitive << ( global_state );
  sensitive << ( SobelFilter_gen_busy_r_4_20_out1 );
  sensitive << ( SobelFilter_And_1Ux1U_1U_4_18_out1 );

  SC_METHOD(drive_s_reg_20);
  sensitive << i_clk.pos();
  dont_initialize();

  SC_METHOD(drive_s_reg_21);
  sensitive << i_clk.pos();
  dont_initialize();

  SC_METHOD(drive_s_reg_22);
  sensitive << i_clk.pos();
  dont_initialize();

  SC_METHOD(drive_s_reg_23);
  sensitive << i_clk.pos();
  dont_initialize();

  SC_METHOD(drive_s_reg_24);
  sensitive << i_clk.pos();
  dont_initialize();

  SC_METHOD(drive_s_reg_25);
  sensitive << i_clk.pos();
  dont_initialize();

  SC_METHOD(drive_s_reg_26);
  sensitive << i_clk.pos();
  dont_initialize();

  SC_METHOD(drive_s_reg_27);
  sensitive << i_clk.pos();
  dont_initialize();

  SC_METHOD(drive_s_reg_28);
  sensitive << i_clk.pos();
  dont_initialize();

  SC_METHOD(drive_SobelFilter_Add_2Ux1U_2U_4_6_in2);
  sensitive << ( gs_ctrl0 );
  sensitive << ( s_reg_21 );

  SC_METHOD(SobelFilter_Add_2Ux1U_2U_4_6);
  sensitive << ( SobelFilter_Add_2Ux1U_2U_4_6_in2 );

  SC_METHOD(drive_SobelFilter_Mul_2Ux2U_4U_4_7_in2);
  sensitive << ( gs_ctrl0 );
  sensitive << ( SobelFilter_LessThan_2Ux2U_1U_4_17_out1 );
  sensitive << ( s_reg_20 );
  sensitive << ( s_reg_21 );

  SC_METHOD(SobelFilter_Mul_2Ux2U_4U_4_7);
  sensitive << ( SobelFilter_Mul_2Ux2U_4U_4_7_in2 );

  SC_METHOD(SobelFilter_Add_4Ux2U_4U_4_8);
  sensitive << ( s_reg_25 );
  sensitive << ( s_reg_26 );

  SC_METHOD(SobelFilter_Add_2Ux1U_2U_4_9);
  sensitive << ( s_reg_25 );

  SC_METHOD(drive_filter_in1);
  sensitive << ( SobelFilter_Add_4Ux2U_4U_4_8_out1 );

  SC_METHOD(drive_SobelFilter_Mul_12Sx8U_12S_4_10_in2);
  sensitive << ( gs_ctrl0 );
  sensitive << ( s_reg_27 );
  sensitive << ( filter_out1 );

  SC_METHOD(drive_SobelFilter_Mul_12Sx8U_12S_4_10_in1);
  sensitive << ( gs_ctrl0 );
  sensitive << ( s_reg_26 );
  sensitive << ( s_reg_27 );

  SC_METHOD(SobelFilter_Mul_12Sx8U_12S_4_10);
  sensitive << ( SobelFilter_Mul_12Sx8U_12S_4_10_in1 );
  sensitive << ( SobelFilter_Mul_12Sx8U_12S_4_10_in2 );

  SC_METHOD(SobelFilter_Mul_12Sx8U_12S_4_11);
  sensitive << ( s_reg_28 );
  sensitive << ( filter_out1 );

  SC_METHOD(drive_SobelFilter_Add_12Ux12U_12U_4_12_in1);
  sensitive << ( gs_ctrl0 );
  sensitive << ( s_reg_22 );
  sensitive << ( s_reg_24 );

  SC_METHOD(SobelFilter_Add_12Ux12U_12U_4_12);
  sensitive << ( SobelFilter_Add_12Ux12U_12U_4_12_in1 );
  sensitive << ( SobelFilter_Mul_12Sx8U_12S_4_10_out1 );

  SC_METHOD(SobelFilter_LessThan_2Ux2U_1U_4_15);
  sensitive << ( s_reg_21 );

  SC_METHOD(SobelFilter_Add_12Ux12U_12U_4_16);
  sensitive << ( s_reg_23 );
  sensitive << ( s_reg_28 );

  SC_METHOD(SobelFilter_LessThan_2Ux2U_1U_4_17);
  sensitive << ( s_reg_25 );

  SC_METHOD(drive_global_state);
  sensitive << i_clk.pos();
  dont_initialize();

  SC_METHOD(drive_global_state_next);
  sensitive << ( global_state );
  sensitive << ( SobelFilter_LessThan_2Ux2U_1U_4_17_out1 );
  sensitive << ( SobelFilter_LessThan_2Ux2U_1U_4_15_out1 );

  SC_METHOD(drive_gs_ctrl0);
  sensitive << i_clk.pos();
  dont_initialize();

  SC_METHOD(drive_i_rgb_busy);
  sensitive << ( SobelFilter_gen_busy_r_4_20_out1 );

  SC_METHOD(SobelFilter_gen_busy_r_4_20_p8);
  sensitive << ( 
  SobelFilter_gen_busy_r_4_20_gen_busy_i_rgb_m_data_is_invalid_next );
  sensitive << ( SobelFilter_gen_busy_r_4_20_gdiv );
  sensitive << ( SobelFilter_gen_busy_r_4_20_gnew_req );

  SC_METHOD(SobelFilter_gen_busy_r_4_20_p7);
  sensitive << ( SobelFilter_gen_busy_r_4_20_gdiv );

  SC_METHOD(SobelFilter_gen_busy_r_4_20_p6);
  sensitive << ( SobelFilter_gen_busy_r_4_20_gnew_req );
  sensitive << ( i_rgb_vld );

  SC_METHOD(SobelFilter_gen_busy_r_4_20_p5);
  sensitive << ( i_rgb_vld );
  sensitive << ( i_rgb_m_unvalidated_req );
  sensitive << ( i_rgb_m_busy_req_0 );

  SC_METHOD(drive_i_rgb_m_unvalidated_req);
  sensitive << i_clk.pos();
  dont_initialize();

  SC_METHOD(SobelFilter_N_Muxb_1_2_0_4_4);
  sensitive << ( i_rgb_m_busy_req_0 );
  sensitive << ( i_rgb_m_unvalidated_req );
  sensitive << ( i_rgb_vld );

  SC_METHOD(drive_o_result_vld);
  sensitive << ( SobelFilter_Or_1Ux1U_1U_4_2_out1 );

  SC_METHOD(SobelFilter_Or_1Ux1U_1U_4_2);
  sensitive << ( SobelFilter_Xor_1Ux1U_1U_1_1_out1 );
  sensitive << ( o_result_m_unacked_req );

  SC_METHOD(drive_o_result_m_unacked_req);
  sensitive << i_clk.pos();
  dont_initialize();

  SC_METHOD(SobelFilter_And_1Ux1U_1U_4_18);
  sensitive << ( o_result_vld );
  sensitive << ( o_result_busy );

  SC_METHOD(SobelFilter_Xor_1Ux1U_1U_1_1);
  sensitive << ( o_result_m_req_m_prev_trig_req );
  sensitive << ( o_result_m_req_m_trig_req );

  SC_METHOD(drive_o_result_m_req_m_prev_trig_req);
  sensitive << i_clk.pos();
  dont_initialize();

  SC_METHOD(SobelFilter_Not_1U_1U_1_3);
  sensitive << ( o_result_m_req_m_trig_req );

}
// resource: regr_en_24
void SobelFilter::drive_o_result_data(){
  switch( (sc_uint<1>)(stall0.read()) ) {
  case 1ULL: 
    break;
  case 0ULL: 
    o_result_data = ( (sc_uint<24> )(sc_bv<24>)((sc_bv<8>)(
                    SobelFilter_Add_12Ux12U_12U_4_12_out1.read().range(11,4)), 
                    (sc_bv<16>)((sc_bv<8>)(SobelFilter_Add_12Ux12U_12U_4_16_out1
                    .read().range(11,4)), 
                    (sc_bv<8>)(s_reg_24.read().range(11,4)))) );
    break;
  }
}
// resource: mux_1bx2i2c
// resource: regr_en_ss_1
void SobelFilter::drive_i_rgb_m_busy_req_0(){
  if ( (i_rst.read() == 0ULL) ) {
    i_rgb_m_busy_req_0 = 1ULL;
  } else {
    switch( (sc_uint<1>)(stall0.read()) ) {
    case 1ULL: 
      break;
    case 0ULL: 
      switch( (sc_uint<3>)(global_state.read()) ) {
      case 0ULL: case 5ULL: 
        i_rgb_m_busy_req_0 = 0ULL;
        break;
      case 1ULL: 
        i_rgb_m_busy_req_0 = 1ULL;
        break;
      case 3ULL: 
        if ( SobelFilter_LessThan_2Ux2U_1U_4_17_out1.read() ) {
          i_rgb_m_busy_req_0 = 0ULL;
        } else {
          if ( SobelFilter_LessThan_2Ux2U_1U_4_15_out1.read() ) {
            i_rgb_m_busy_req_0 = 0ULL;
          } 
        }
        break;
      }
      break;
    }
  }
}
// resource: regr_en_sc_1
void SobelFilter::drive_o_result_m_req_m_trig_req(){
  if ( (i_rst.read() == 0ULL) ) {
    o_result_m_req_m_trig_req = 0ULL;
  } else {
    switch( (sc_uint<1>)(stall0.read()) ) {
    case 1ULL: 
      break;
    case 0ULL: 
      switch( (sc_uint<3>)(global_state.read()) ) {
      case 3ULL: 
        if ( (!SobelFilter_LessThan_2Ux2U_1U_4_17_out1.read() && !
             SobelFilter_LessThan_2Ux2U_1U_4_15_out1.read()) ) {
          o_result_m_req_m_trig_req = (sc_uint<1> ) (
                                      SobelFilter_Not_1U_1U_1_3_out1.read());
        } 
        break;
      }
      break;
    }
  }
}
// resource: mux_1bx3i1c
void SobelFilter::drive_stall0(){
  switch( (sc_uint<3>)(global_state.read()) ) {
  default:
    stall0 = 0ULL;
    break;
  case 1ULL: 
    stall0 = (sc_uint<1> )SobelFilter_gen_busy_r_4_20_out1.read();
    break;
  case 4ULL: 
    stall0 = SobelFilter_And_1Ux1U_1U_4_18_out1.read();
    break;
  }
}
// resource: mux_2bx2i1c
// resource: regr_en_2
void SobelFilter::drive_s_reg_20(){
  switch( (sc_uint<1>)(stall0.read()) ) {
  case 1ULL: 
    break;
  case 0ULL: 
    switch( (sc_uint<3>)(global_state.read()) ) {
    case 0ULL: case 5ULL: 
      s_reg_20 = 0ULL;
      break;
    case 3ULL: 
      if ( SobelFilter_LessThan_2Ux2U_1U_4_17_out1.read() );
      else {
        s_reg_20 = s_reg_21.read();
      }
      break;
    }
    break;
  }
}
// resource: regr_en_2
void SobelFilter::drive_s_reg_21(){
  switch( (sc_uint<1>)(stall0.read()) ) {
  case 1ULL: 
    break;
  case 0ULL: 
    switch( (sc_uint<3>)(global_state.read()) ) {
    case 0ULL: case 5ULL: 
      s_reg_21 = SobelFilter_Add_2Ux1U_2U_4_6_out1.read();
      break;
    case 3ULL: 
      if ( SobelFilter_LessThan_2Ux2U_1U_4_17_out1.read() );
      else {
        s_reg_21 = SobelFilter_Add_2Ux1U_2U_4_6_out1.read();
      }
      break;
    }
    break;
  }
}
// resource: mux_12bx2i1c
// resource: regr_en_12
void SobelFilter::drive_s_reg_22(){
  switch( (sc_uint<1>)(stall0.read()) ) {
  case 1ULL: 
    break;
  case 0ULL: 
    switch( (sc_uint<3>)(global_state.read()) ) {
    case 0ULL: case 5ULL: 
      s_reg_22 = 0ULL;
      break;
    case 3ULL: 
      s_reg_22 = SobelFilter_Add_12Ux12U_12U_4_12_out1.read();
      break;
    }
    break;
  }
}
// resource: mux_12bx2i1c
// resource: regr_en_12
void SobelFilter::drive_s_reg_23(){
  switch( (sc_uint<1>)(stall0.read()) ) {
  case 1ULL: 
    break;
  case 0ULL: 
    switch( (sc_uint<3>)(global_state.read()) ) {
    case 0ULL: case 5ULL: 
      s_reg_23 = 0ULL;
      break;
    case 3ULL: 
      s_reg_23 = SobelFilter_Add_12Ux12U_12U_4_16_out1.read();
      break;
    }
    break;
  }
}
// resource: mux_12bx2i1c
// resource: regr_en_12
void SobelFilter::drive_s_reg_24(){
  switch( (sc_uint<1>)(stall0.read()) ) {
  case 1ULL: 
    break;
  case 0ULL: 
    switch( (sc_uint<3>)(global_state.read()) ) {
    case 0ULL: case 5ULL: 
      s_reg_24 = 0ULL;
      break;
    case 2ULL: 
      s_reg_24 = SobelFilter_Add_12Ux12U_12U_4_12_out1.read();
      break;
    }
    break;
  }
}
// resource: mux_2bx2i1c
// resource: regr_en_2
void SobelFilter::drive_s_reg_25(){
  switch( (sc_uint<1>)(stall0.read()) ) {
  case 1ULL: 
    break;
  case 0ULL: 
    switch( (sc_uint<3>)(global_state.read()) ) {
    case 0ULL: case 5ULL: 
      s_reg_25 = 0ULL;
      break;
    case 1ULL: 
      s_reg_25 = SobelFilter_Add_2Ux1U_2U_4_9_out1.read();
      break;
    case 3ULL: 
      if ( SobelFilter_LessThan_2Ux2U_1U_4_17_out1.read() );
      else {
        s_reg_25 = 0ULL;
      }
      break;
    }
    break;
  }
}
// resource: mux_8bx2i0c
// resource: regr_en_8
void SobelFilter::drive_s_reg_26(){
  switch( (sc_uint<1>)(stall0.read()) ) {
  case 1ULL: 
    break;
  case 0ULL: 
    switch( (sc_uint<3>)(global_state.read()) ) {
    case 0ULL: case 3ULL: case 5ULL: 
      s_reg_26 = (sc_uint<8> ) (SobelFilter_Mul_2Ux2U_4U_4_7_out1.read());
      break;
    case 1ULL: 
      s_reg_26 = (sc_uint<8> ) (i_rgb_data.read().range(23,16));
      break;
    }
    break;
  }
}
// resource: mux_12bx2i0c
// resource: regr_en_12
void SobelFilter::drive_s_reg_27(){
  switch( (sc_uint<1>)(stall0.read()) ) {
  case 1ULL: 
    break;
  case 0ULL: 
    switch( (sc_uint<3>)(global_state.read()) ) {
    case 1ULL: 
      s_reg_27 = (sc_uint<12> ) ((sc_uint<8> )i_rgb_data.read());
      break;
    case 2ULL: 
      s_reg_27 = (sc_uint<12> )filter_out1.read();
      break;
    }
    break;
  }
}
// resource: mux_12bx2i0c
// resource: regr_en_12
void SobelFilter::drive_s_reg_28(){
  switch( (sc_uint<1>)(stall0.read()) ) {
  case 1ULL: 
    break;
  case 0ULL: 
    switch( (sc_uint<3>)(global_state.read()) ) {
    case 1ULL: 
      s_reg_28 = (sc_uint<12> ) (i_rgb_data.read().range(15,8));
      break;
    case 2ULL: 
      s_reg_28 = (sc_uint<12> ) (SobelFilter_Mul_12Sx8U_12S_4_11_out1.read());
      break;
    }
    break;
  }
}
// resource: mux_2bx2i1c
void SobelFilter::drive_SobelFilter_Add_2Ux1U_2U_4_6_in2(){
  if ( gs_ctrl0.read() ) {
    SobelFilter_Add_2Ux1U_2U_4_6_in2 = s_reg_21.read();
  } else {
    SobelFilter_Add_2Ux1U_2U_4_6_in2 = 0ULL;
  }
}
// resource: SobelFilter_Add_2Ux1U_2U_4  instance: SobelFilter_Add_2Ux1U_2U_4_6
void SobelFilter::SobelFilter_Add_2Ux1U_2U_4_6(){
  SobelFilter_Add_2Ux1U_2U_4_6_out1 = (SobelFilter_Add_2Ux1U_2U_4_6_in2.read()
                                       + 1ULL);
}
// resource: mux_2bx3i1c
void SobelFilter::drive_SobelFilter_Mul_2Ux2U_4U_4_7_in2(){
  if ( gs_ctrl0.read() ) {
    if ( SobelFilter_LessThan_2Ux2U_1U_4_17_out1.read() ) {
      SobelFilter_Mul_2Ux2U_4U_4_7_in2 = s_reg_20.read();
    } else {
      SobelFilter_Mul_2Ux2U_4U_4_7_in2 = s_reg_21.read();
    }
  } else {
    SobelFilter_Mul_2Ux2U_4U_4_7_in2 = 0ULL;
  }
}
// resource: SobelFilter_Mul_2Ux2U_4U_4  instance: SobelFilter_Mul_2Ux2U_4U_4_7
void SobelFilter::SobelFilter_Mul_2Ux2U_4U_4_7(){
  SobelFilter_Mul_2Ux2U_4U_4_7_out1 = SobelFilter_Mul_2Ux2U_4U_4_7_in2.read() * 
                                      3ULL;
}
// resource: SobelFilter_Add_4Ux2U_4U_4  instance: SobelFilter_Add_4Ux2U_4U_4_8
void SobelFilter::SobelFilter_Add_4Ux2U_4U_4_8(){
  SobelFilter_Add_4Ux2U_4U_4_8_out1 = ((sc_uint<4> )s_reg_26.read() + s_reg_25
                                      .read());
}
// resource: SobelFilter_Add_2Ux1U_2U_4  instance: SobelFilter_Add_2Ux1U_2U_4_9
void SobelFilter::SobelFilter_Add_2Ux1U_2U_4_9(){
  SobelFilter_Add_2Ux1U_2U_4_9_out1 = (s_reg_25.read() + 1ULL);
}
void SobelFilter::drive_filter_in1(){
  filter_in1 = SobelFilter_Add_4Ux2U_4U_4_8_out1.read();
}
// resource: mux_12bx2i0c
void SobelFilter::drive_SobelFilter_Mul_12Sx8U_12S_4_10_in2(){
  if ( gs_ctrl0.read() ) {
    SobelFilter_Mul_12Sx8U_12S_4_10_in2 = (sc_int<12> ) (s_reg_27.read());
  } else {
    SobelFilter_Mul_12Sx8U_12S_4_10_in2 = (sc_int<12> )filter_out1.read();
  }
}
// resource: mux_8bx2i0c
void SobelFilter::drive_SobelFilter_Mul_12Sx8U_12S_4_10_in1(){
  if ( gs_ctrl0.read() ) {
    SobelFilter_Mul_12Sx8U_12S_4_10_in1 = s_reg_26.read();
  } else {
    SobelFilter_Mul_12Sx8U_12S_4_10_in1 = (sc_uint<8> )s_reg_27.read();
  }
}
// resource: SobelFilter_Mul_12Sx8U_12S_4  instance: SobelFilter_Mul_12Sx8U_12S_4_10
void SobelFilter::SobelFilter_Mul_12Sx8U_12S_4_10(){
  SobelFilter_Mul_12Sx8U_12S_4_10_out1 = SobelFilter_Mul_12Sx8U_12S_4_10_in2
                                         .read() * 
                                         SobelFilter_Mul_12Sx8U_12S_4_10_in1
                                         .read();
}
// resource: SobelFilter_Mul_12Sx8U_12S_4  instance: SobelFilter_Mul_12Sx8U_12S_4_11
void SobelFilter::SobelFilter_Mul_12Sx8U_12S_4_11(){
  SobelFilter_Mul_12Sx8U_12S_4_11_out1 = (sc_int<12> )filter_out1.read() * (
                                         sc_uint<8> )s_reg_28.read();
}
// resource: mux_12bx2i0c
void SobelFilter::drive_SobelFilter_Add_12Ux12U_12U_4_12_in1(){
  if ( gs_ctrl0.read() ) {
    SobelFilter_Add_12Ux12U_12U_4_12_in1 = s_reg_22.read();
  } else {
    SobelFilter_Add_12Ux12U_12U_4_12_in1 = s_reg_24.read();
  }
}
// resource: SobelFilter_Add_12Ux12U_12U_4  instance: SobelFilter_Add_12Ux12U_12U_4_12
void SobelFilter::SobelFilter_Add_12Ux12U_12U_4_12(){
  SobelFilter_Add_12Ux12U_12U_4_12_out1 = ((sc_uint<12> )
                                          SobelFilter_Mul_12Sx8U_12S_4_10_out1
                                          .read() + 
                                          SobelFilter_Add_12Ux12U_12U_4_12_in1
                                          .read());
}
// resource: SobelFilter_LessThan_2Ux2U_1U_4  instance: SobelFilter_LessThan_2Ux2U_1U_4_15
void SobelFilter::SobelFilter_LessThan_2Ux2U_1U_4_15(){
  SobelFilter_LessThan_2Ux2U_1U_4_15_out1 = (/*imp*/sc_uint<1>)(s_reg_21.read()
                                             < (sc_uint<2> )3ULL);
}
// resource: SobelFilter_Add_12Ux12U_12U_4  instance: SobelFilter_Add_12Ux12U_12U_4_16
void SobelFilter::SobelFilter_Add_12Ux12U_12U_4_16(){
  SobelFilter_Add_12Ux12U_12U_4_16_out1 = (s_reg_28.read() + s_reg_23.read());
}
// resource: SobelFilter_LessThan_2Ux2U_1U_4  instance: SobelFilter_LessThan_2Ux2U_1U_4_17
void SobelFilter::SobelFilter_LessThan_2Ux2U_1U_4_17(){
  SobelFilter_LessThan_2Ux2U_1U_4_17_out1 = (/*imp*/sc_uint<1>)(s_reg_25.read()
                                             < (sc_uint<2> )3ULL);
}
// resource: regr_en_sc_3
void SobelFilter::drive_global_state(){
  if ( (i_rst.read() == 0ULL) ) {
    global_state = 0ULL;
  } else {
    switch( (sc_uint<1>)(stall0.read()) ) {
    case 1ULL: 
      break;
    case 0ULL: 
      global_state = global_state_next.read();
      break;
    }
  }
}
// resource: mux_3bx2i1c
void SobelFilter::drive_global_state_next(){
  switch( (sc_uint<3>)(global_state.read()) ) {
  default:
    global_state_next = (global_state.read() + 1ULL);
    break;
  case 0ULL: case 5ULL: 
    global_state_next = 1ULL;
    break;
  case 3ULL: 
    if ( SobelFilter_LessThan_2Ux2U_1U_4_17_out1.read() ) {
      global_state_next = 1ULL;
    } else {
      if ( SobelFilter_LessThan_2Ux2U_1U_4_15_out1.read() ) {
        global_state_next = 1ULL;
      } else {
        global_state_next = (global_state.read() + 1ULL);
      }
    }
    break;
  }
}
// resource: mux_1bx2i2c
// resource: regr_en_sc_1
void SobelFilter::drive_gs_ctrl0(){
  if ( (i_rst.read() == 0ULL) ) {
    gs_ctrl0 = 0ULL;
  } else {
    switch( (sc_uint<1>)(stall0.read()) ) {
    case 1ULL: 
      break;
    case 0ULL: 
      switch( (sc_uint<3>)(global_state_next.read()) ) {
      default:
        gs_ctrl0 = 0ULL;
        break;
      case 3ULL: 
        gs_ctrl0 = 1ULL;
        break;
      }
      break;
    }
  }
}
void SobelFilter::drive_i_rgb_busy(){
  i_rgb_busy = (sc_uint<1> ) (((/*imp*/sc_uint<1> ) 
               SobelFilter_gen_busy_r_4_20_out1.read().range(2,2)));
}
// resource: SobelFilter_gen_busy_r_4  instance: SobelFilter_gen_busy_r_4_20
void SobelFilter::SobelFilter_gen_busy_r_4_20_p8(){
  SobelFilter_gen_busy_r_4_20_out1 = (sc_uint<3> ) (( (sc_biguint<3> )(sc_bv<3>)
                                     ((sc_bv<1>)(
                                     SobelFilter_gen_busy_r_4_20_gnew_req.read()
                                     ), 
                                     (sc_bv<2>)(( (sc_biguint<2> )(sc_bv<2>)(
                                     (sc_bv<1>)(SobelFilter_gen_busy_r_4_20_gdiv
                                     .read()), 
                                     (sc_bv<1>)(SobelFilter_gen_busy_r_4_20_gen_busy_i_rgb_m_data_is_invalid_next
                                     .read())) ))) ));
}
// resource: SobelFilter_gen_busy_r_4  instance: SobelFilter_gen_busy_r_4_20
void SobelFilter::SobelFilter_gen_busy_r_4_20_p7(){
  SobelFilter_gen_busy_r_4_20_gen_busy_i_rgb_m_data_is_invalid_next = ~(sc_uint<1>)SobelFilter_gen_busy_r_4_20_gdiv
                                                                      .read();
}
// resource: SobelFilter_gen_busy_r_4  instance: SobelFilter_gen_busy_r_4_20
void SobelFilter::SobelFilter_gen_busy_r_4_20_p6(){
  SobelFilter_gen_busy_r_4_20_gdiv = (sc_uint<1> ) (i_rgb_vld.read() & !
                                     SobelFilter_gen_busy_r_4_20_gnew_req.read()
                                     );
}
// resource: SobelFilter_gen_busy_r_4  instance: SobelFilter_gen_busy_r_4_20
void SobelFilter::SobelFilter_gen_busy_r_4_20_p5(){
  SobelFilter_gen_busy_r_4_20_gnew_req = (sc_uint<1> ) (i_rgb_m_busy_req_0
                                         .read() & ( i_rgb_m_unvalidated_req
                                         .read() | (sc_uint<1> )i_rgb_vld.read()
                                          ));
}
// resource: regr_ss_1
void SobelFilter::drive_i_rgb_m_unvalidated_req(){
  if ( (i_rst.read() == 0ULL) ) {
    i_rgb_m_unvalidated_req = 1ULL;
  } else {
    i_rgb_m_unvalidated_req = (sc_uint<1> ) (SobelFilter_N_Muxb_1_2_0_4_4_out1
                              .read());
  }
}
// resource: SobelFilter_N_Muxb_1_2_0_4
void SobelFilter::SobelFilter_N_Muxb_1_2_0_4_4(){
  if ( i_rgb_m_busy_req_0.read() ) {
    SobelFilter_N_Muxb_1_2_0_4_4_out1 = (sc_uint<1> ) (i_rgb_m_unvalidated_req
                                        .read());
  } else {
    SobelFilter_N_Muxb_1_2_0_4_4_out1 = (sc_uint<1> ) (i_rgb_vld.read());
  }
}
void SobelFilter::drive_o_result_vld(){
  o_result_vld = (sc_uint<1> ) (SobelFilter_Or_1Ux1U_1U_4_2_out1.read());
}
// resource: SobelFilter_Or_1Ux1U_1U_4  instance: SobelFilter_Or_1Ux1U_1U_4_2
void SobelFilter::SobelFilter_Or_1Ux1U_1U_4_2(){
  SobelFilter_Or_1Ux1U_1U_4_2_out1 = (sc_uint<1> ) (o_result_m_unacked_req
                                     .read() | (sc_uint<1>)
                                     SobelFilter_Xor_1Ux1U_1U_1_1_out1.read());
}
// resource: regr_sc_1
void SobelFilter::drive_o_result_m_unacked_req(){
  if ( (i_rst.read() == 0ULL) ) {
    o_result_m_unacked_req = 0ULL;
  } else {
    o_result_m_unacked_req = (sc_uint<1> ) (SobelFilter_And_1Ux1U_1U_4_18_out1
                             .read());
  }
}
// resource: SobelFilter_And_1Ux1U_1U_4  instance: SobelFilter_And_1Ux1U_1U_4_18
void SobelFilter::SobelFilter_And_1Ux1U_1U_4_18(){
  SobelFilter_And_1Ux1U_1U_4_18_out1 = (sc_uint<1> ) (o_result_busy.read() & 
                                       o_result_vld.read());
}
// resource: SobelFilter_Xor_1Ux1U_1U_1  instance: SobelFilter_Xor_1Ux1U_1U_1_1
void SobelFilter::SobelFilter_Xor_1Ux1U_1U_1_1(){
  SobelFilter_Xor_1Ux1U_1U_1_1_out1 = (sc_uint<1> ) (o_result_m_req_m_trig_req
                                      .read() ^ o_result_m_req_m_prev_trig_req
                                      .read());
}
// resource: regr_sc_1
void SobelFilter::drive_o_result_m_req_m_prev_trig_req(){
  if ( (i_rst.read() == 0ULL) ) {
    o_result_m_req_m_prev_trig_req = 0ULL;
  } else {
    o_result_m_req_m_prev_trig_req = o_result_m_req_m_trig_req.read();
  }
}
// resource: SobelFilter_Not_1U_1U_1  instance: SobelFilter_Not_1U_1U_1_3
void SobelFilter::SobelFilter_Not_1U_1U_1_3(){
  SobelFilter_Not_1U_1U_1_3_out1 = !o_result_m_req_m_trig_req.read();
}
