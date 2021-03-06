// Generated by stratus_hls 19.12-s100  (91710.131054)
// Mon Apr 26 01:59:07 2021
// from ../SobelFilter.cpp

`timescale 1ps / 1ps

      
module SobelFilter(i_clk, i_rst, i_rgb_busy, i_rgb_vld, i_rgb_data, o_result_busy, o_result_vld, o_result_data);

      input i_clk;
      input i_rst;
      input i_rgb_vld;
      input [23:0] i_rgb_data;
      input o_result_busy;
      output i_rgb_busy;
      output o_result_vld;
      output [23:0] o_result_data;
      reg [23:0] o_result_data;
      reg o_result_m_req_m_prev_trig_req;
      reg o_result_m_unacked_req;
      wire SobelFilter_Xor_1Ux1U_1U_1_1_out1;
      wire SobelFilter_Or_1Ux1U_1U_4_2_out1;
      reg SobelFilter_N_Muxb_1_2_0_4_4_out1;
      reg i_rgb_m_unvalidated_req;
      wire SobelFilter_gen_busy_r_4_20_gnew_req;
      wire SobelFilter_gen_busy_r_4_20_gdiv;
      wire SobelFilter_gen_busy_r_4_20_gen_busy_i_rgb_m_data_is_invalid_next;
      reg[2:0] global_state_next;
      reg[11:0] SobelFilter_Add_12Ux12U_12U_4_12_in1;
      /*signed*/wire[11:0] SobelFilter_Mul_12Sx8U_12S_4_10_out1;
      reg[7:0] SobelFilter_Mul_12Sx8U_12S_4_10_in1;
      /*signed*/reg[11:0] SobelFilter_Mul_12Sx8U_12S_4_10_in2;
      wire[3:0] SobelFilter_Add_4Ux2U_4U_4_8_out1;
      reg[1:0] SobelFilter_Mul_2Ux2U_4U_4_7_in2;
      reg[1:0] SobelFilter_Add_2Ux1U_2U_4_6_in2;
      reg gs_ctrl0;
      /*signed*/wire[11:0] SobelFilter_Mul_12Sx8U_12S_4_11_out1;
      reg[11:0] s_reg_28;
      reg[11:0] s_reg_27;
      wire[3:0] SobelFilter_Mul_2Ux2U_4U_4_7_out1;
      reg[7:0] s_reg_26;
      wire[1:0] SobelFilter_Add_2Ux1U_2U_4_9_out1;
      reg[1:0] s_reg_25;
      reg[11:0] s_reg_23;
      reg[11:0] s_reg_22;
      wire[1:0] SobelFilter_Add_2Ux1U_2U_4_6_out1;
      reg[1:0] s_reg_21;
      reg[1:0] s_reg_20;
      wire SobelFilter_And_1Ux1U_1U_4_18_out1;
      wire[2:0] SobelFilter_gen_busy_r_4_20_out1;
      wire SobelFilter_Not_1U_1U_1_3_out1;
      reg o_result_m_req_m_trig_req;
      wire SobelFilter_LessThan_2Ux2U_1U_4_15_out1;
      wire SobelFilter_LessThan_2Ux2U_1U_4_17_out1;
      reg[2:0] global_state;
      reg i_rgb_m_busy_req_0;
      wire[11:0] SobelFilter_Add_12Ux12U_12U_4_12_out1;
      wire[11:0] SobelFilter_Add_12Ux12U_12U_4_16_out1;
      reg[11:0] s_reg_24;
      reg stall0;
      wire[3:0] filter_in1;
      wire[31:0] filter_out1;

         SobelFilter_ROM_9X32_filter filter(
                                       .in1( filter_in1 ),
                                       .out1( filter_out1 ),
                                       .clk( i_clk )
                                     );

         // resource: regr_en_24
         always @(posedge i_clk)
          begin :drive_o_result_data
            case (stall0) 

               1'b1:                begin
               end
               
               1'b0:                begin
                  o_result_data <= {SobelFilter_Add_12Ux12U_12U_4_12_out1[11:4], {SobelFilter_Add_12Ux12U_12U_4_16_out1[11:4], s_reg_24[11:4]}};
               end
               
            endcase

         end

         // resource: mux_1bx2i2c
         // resource: regr_en_ss_1
         always @(posedge i_clk)
          begin :drive_i_rgb_m_busy_req_0
            if (i_rst == 1'b0) begin
               i_rgb_m_busy_req_0 <= 1'd1;
            end
            else begin
               case (stall0) 

                  1'b1:                   begin
                  end
                  
                  1'b0:                   begin
                     case (global_state) 

                        3'd0, 3'd5:                         begin
                           i_rgb_m_busy_req_0 <= 1'd0;
                        end
                        
                        3'd1:                         begin
                           i_rgb_m_busy_req_0 <= 1'd1;
                        end
                        
                        3'd3:                         begin
                           if (SobelFilter_LessThan_2Ux2U_1U_4_17_out1) begin
                              i_rgb_m_busy_req_0 <= 1'd0;
                           end
                           else begin
                              if (SobelFilter_LessThan_2Ux2U_1U_4_15_out1) begin
                                 i_rgb_m_busy_req_0 <= 1'd0;
                              end
                           end
                        end
                        
                     endcase

                  end
                  
               endcase

            end
         end

         // resource: regr_en_sc_1
         always @(posedge i_clk)
          begin :drive_o_result_m_req_m_trig_req
            if (i_rst == 1'b0) begin
               o_result_m_req_m_trig_req <= 1'd0;
            end
            else begin
               case (stall0) 

                  1'b1:                   begin
                  end
                  
                  1'b0:                   begin
                     case (global_state) 

                        3'd3:                         begin
                           if (!SobelFilter_LessThan_2Ux2U_1U_4_17_out1 && !SobelFilter_LessThan_2Ux2U_1U_4_15_out1) begin
                              o_result_m_req_m_trig_req <= SobelFilter_Not_1U_1U_1_3_out1;
                           end
                        end
                        
                     endcase

                  end
                  
               endcase

            end
         end

         // resource: mux_1bx3i1c
         always @(SobelFilter_And_1Ux1U_1U_4_18_out1 or SobelFilter_gen_busy_r_4_20_out1[0] or global_state)
          begin :drive_stall0
            case (global_state) 

               3'd1:                begin
                  stall0 = SobelFilter_gen_busy_r_4_20_out1[0];
               end
               
               3'd4:                begin
                  stall0 = SobelFilter_And_1Ux1U_1U_4_18_out1;
               end
               
               default:                begin
                  stall0 = 1'b0;
               end
               
            endcase

         end

         // resource: mux_2bx2i1c
         // resource: regr_en_2
         always @(posedge i_clk)
          begin :drive_s_reg_20
            case (stall0) 

               1'b1:                begin
               end
               
               1'b0:                begin
                  case (global_state) 

                     3'd0, 3'd5:                      begin
                        s_reg_20 <= 2'd0;
                     end
                     
                     3'd3:                      begin
                        if (SobelFilter_LessThan_2Ux2U_1U_4_17_out1) begin
                        end
                        else begin
                           s_reg_20 <= s_reg_21;
                        end
                     end
                     
                  endcase

               end
               
            endcase

         end

         // resource: regr_en_2
         always @(posedge i_clk)
          begin :drive_s_reg_21
            case (stall0) 

               1'b1:                begin
               end
               
               1'b0:                begin
                  case (global_state) 

                     3'd0, 3'd5:                      begin
                        s_reg_21 <= SobelFilter_Add_2Ux1U_2U_4_6_out1;
                     end
                     
                     3'd3:                      begin
                        if (SobelFilter_LessThan_2Ux2U_1U_4_17_out1) begin
                        end
                        else begin
                           s_reg_21 <= SobelFilter_Add_2Ux1U_2U_4_6_out1;
                        end
                     end
                     
                  endcase

               end
               
            endcase

         end

         // resource: mux_12bx2i1c
         // resource: regr_en_12
         always @(posedge i_clk)
          begin :drive_s_reg_22
            case (stall0) 

               1'b1:                begin
               end
               
               1'b0:                begin
                  case (global_state) 

                     3'd0, 3'd5:                      begin
                        s_reg_22 <= 12'd0000;
                     end
                     
                     3'd3:                      begin
                        s_reg_22 <= SobelFilter_Add_12Ux12U_12U_4_12_out1;
                     end
                     
                  endcase

               end
               
            endcase

         end

         // resource: mux_12bx2i1c
         // resource: regr_en_12
         always @(posedge i_clk)
          begin :drive_s_reg_23
            case (stall0) 

               1'b1:                begin
               end
               
               1'b0:                begin
                  case (global_state) 

                     3'd0, 3'd5:                      begin
                        s_reg_23 <= 12'd0000;
                     end
                     
                     3'd3:                      begin
                        s_reg_23 <= SobelFilter_Add_12Ux12U_12U_4_16_out1;
                     end
                     
                  endcase

               end
               
            endcase

         end

         // resource: mux_12bx2i1c
         // resource: regr_en_12
         always @(posedge i_clk)
          begin :drive_s_reg_24
            case (stall0) 

               1'b1:                begin
               end
               
               1'b0:                begin
                  case (global_state) 

                     3'd0, 3'd5:                      begin
                        s_reg_24 <= 12'd0000;
                     end
                     
                     3'd2:                      begin
                        s_reg_24 <= SobelFilter_Add_12Ux12U_12U_4_12_out1;
                     end
                     
                  endcase

               end
               
            endcase

         end

         // resource: mux_2bx2i1c
         // resource: regr_en_2
         always @(posedge i_clk)
          begin :drive_s_reg_25
            case (stall0) 

               1'b1:                begin
               end
               
               1'b0:                begin
                  case (global_state) 

                     3'd0, 3'd5:                      begin
                        s_reg_25 <= 2'd0;
                     end
                     
                     3'd1:                      begin
                        s_reg_25 <= SobelFilter_Add_2Ux1U_2U_4_9_out1;
                     end
                     
                     3'd3:                      begin
                        if (SobelFilter_LessThan_2Ux2U_1U_4_17_out1) begin
                        end
                        else begin
                           s_reg_25 <= 2'd0;
                        end
                     end
                     
                  endcase

               end
               
            endcase

         end

         // resource: mux_8bx2i0c
         // resource: regr_en_8
         always @(posedge i_clk)
          begin :drive_s_reg_26
            case (stall0) 

               1'b1:                begin
               end
               
               1'b0:                begin
                  case (global_state) 

                     3'd0, 3'd3, 3'd5:                      begin
                        s_reg_26 <= {4'b0000, SobelFilter_Mul_2Ux2U_4U_4_7_out1};
                     end
                     
                     3'd1:                      begin
                        s_reg_26 <= i_rgb_data[23:16];
                     end
                     
                  endcase

               end
               
            endcase

         end

         // resource: mux_12bx2i0c
         // resource: regr_en_12
         always @(posedge i_clk)
          begin :drive_s_reg_27
            case (stall0) 

               1'b1:                begin
               end
               
               1'b0:                begin
                  case (global_state) 

                     3'd1:                      begin
                        s_reg_27 <= {4'b0000, i_rgb_data[7:0]};
                     end
                     
                     3'd2:                      begin
                        s_reg_27 <= filter_out1[11:0];
                     end
                     
                  endcase

               end
               
            endcase

         end

         // resource: mux_12bx2i0c
         // resource: regr_en_12
         always @(posedge i_clk)
          begin :drive_s_reg_28
            case (stall0) 

               1'b1:                begin
               end
               
               1'b0:                begin
                  case (global_state) 

                     3'd1:                      begin
                        s_reg_28 <= {4'b0000, i_rgb_data[15:8]};
                     end
                     
                     3'd2:                      begin
                        s_reg_28 <= SobelFilter_Mul_12Sx8U_12S_4_11_out1;
                     end
                     
                  endcase

               end
               
            endcase

         end

         // resource: mux_2bx2i1c
         always @(s_reg_21 or gs_ctrl0)
          begin :drive_SobelFilter_Add_2Ux1U_2U_4_6_in2
            if (gs_ctrl0) begin
               SobelFilter_Add_2Ux1U_2U_4_6_in2 = s_reg_21;
            end
            else begin
               SobelFilter_Add_2Ux1U_2U_4_6_in2 = 2'd0;
            end
         end

         // resource: SobelFilter_Add_2Ux1U_2U_4  instance: SobelFilter_Add_2Ux1U_2U_4_6
         assign SobelFilter_Add_2Ux1U_2U_4_6_out1 = SobelFilter_Add_2Ux1U_2U_4_6_in2 + 2'd1;

         // resource: mux_2bx3i1c
         always @(s_reg_20 or s_reg_21 or SobelFilter_LessThan_2Ux2U_1U_4_17_out1 or gs_ctrl0)
          begin :drive_SobelFilter_Mul_2Ux2U_4U_4_7_in2
            if (gs_ctrl0) begin
               if (SobelFilter_LessThan_2Ux2U_1U_4_17_out1) begin
                  SobelFilter_Mul_2Ux2U_4U_4_7_in2 = s_reg_20;
               end
               else begin
                  SobelFilter_Mul_2Ux2U_4U_4_7_in2 = s_reg_21;
               end
            end
            else begin
               SobelFilter_Mul_2Ux2U_4U_4_7_in2 = 2'd0;
            end
         end

         // resource: SobelFilter_Mul_2Ux2U_4U_4  instance: SobelFilter_Mul_2Ux2U_4U_4_7
         assign SobelFilter_Mul_2Ux2U_4U_4_7_out1 = {2'b00, SobelFilter_Mul_2Ux2U_4U_4_7_in2}*4'd03;

         // resource: SobelFilter_Add_4Ux2U_4U_4  instance: SobelFilter_Add_4Ux2U_4U_4_8
         assign SobelFilter_Add_4Ux2U_4U_4_8_out1 = s_reg_26[3:0] + {2'b00, s_reg_25};

         // resource: SobelFilter_Add_2Ux1U_2U_4  instance: SobelFilter_Add_2Ux1U_2U_4_9
         assign SobelFilter_Add_2Ux1U_2U_4_9_out1 = s_reg_25 + 2'd1;

         // instance: drive_filter_in1
         assign filter_in1 = SobelFilter_Add_4Ux2U_4U_4_8_out1;

         // resource: mux_12bx2i0c
         always @(s_reg_27 or filter_out1[11:0] or gs_ctrl0)
          begin :drive_SobelFilter_Mul_12Sx8U_12S_4_10_in2
            if (gs_ctrl0) begin
               SobelFilter_Mul_12Sx8U_12S_4_10_in2 = s_reg_27;
            end
            else begin
               SobelFilter_Mul_12Sx8U_12S_4_10_in2 = filter_out1[11:0];
            end
         end

         // resource: mux_8bx2i0c
         always @(s_reg_26 or s_reg_27[7:0] or gs_ctrl0)
          begin :drive_SobelFilter_Mul_12Sx8U_12S_4_10_in1
            if (gs_ctrl0) begin
               SobelFilter_Mul_12Sx8U_12S_4_10_in1 = s_reg_26;
            end
            else begin
               SobelFilter_Mul_12Sx8U_12S_4_10_in1 = s_reg_27[7:0];
            end
         end

         // resource: SobelFilter_Mul_12Sx8U_12S_4  instance: SobelFilter_Mul_12Sx8U_12S_4_10
         assign SobelFilter_Mul_12Sx8U_12S_4_10_out1 = SobelFilter_Mul_12Sx8U_12S_4_10_in2*{4'b0000, SobelFilter_Mul_12Sx8U_12S_4_10_in1};

         // resource: SobelFilter_Mul_12Sx8U_12S_4  instance: SobelFilter_Mul_12Sx8U_12S_4_11
         assign SobelFilter_Mul_12Sx8U_12S_4_11_out1 = filter_out1[11:0]*{4'b0000, s_reg_28[7:0]};

         // resource: mux_12bx2i0c
         always @(s_reg_22 or s_reg_24 or gs_ctrl0)
          begin :drive_SobelFilter_Add_12Ux12U_12U_4_12_in1
            if (gs_ctrl0) begin
               SobelFilter_Add_12Ux12U_12U_4_12_in1 = s_reg_22;
            end
            else begin
               SobelFilter_Add_12Ux12U_12U_4_12_in1 = s_reg_24;
            end
         end

         // resource: SobelFilter_Add_12Ux12U_12U_4  instance: SobelFilter_Add_12Ux12U_12U_4_12
         assign SobelFilter_Add_12Ux12U_12U_4_12_out1 = SobelFilter_Mul_12Sx8U_12S_4_10_out1 + SobelFilter_Add_12Ux12U_12U_4_12_in1;

         // resource: SobelFilter_LessThan_2Ux2U_1U_4  instance: SobelFilter_LessThan_2Ux2U_1U_4_15
         assign SobelFilter_LessThan_2Ux2U_1U_4_15_out1 = s_reg_21 < 2'd3;

         // resource: SobelFilter_Add_12Ux12U_12U_4  instance: SobelFilter_Add_12Ux12U_12U_4_16
         assign SobelFilter_Add_12Ux12U_12U_4_16_out1 = s_reg_28 + s_reg_23;

         // resource: SobelFilter_LessThan_2Ux2U_1U_4  instance: SobelFilter_LessThan_2Ux2U_1U_4_17
         assign SobelFilter_LessThan_2Ux2U_1U_4_17_out1 = s_reg_25 < 2'd3;

         // resource: regr_en_sc_3
         always @(posedge i_clk)
          begin :drive_global_state
            if (i_rst == 1'b0) begin
               global_state <= 3'd0;
            end
            else begin
               case (stall0) 

                  1'b1:                   begin
                  end
                  
                  1'b0:                   begin
                     global_state <= global_state_next;
                  end
                  
               endcase

            end
         end

         // resource: mux_3bx2i1c
         always @(SobelFilter_LessThan_2Ux2U_1U_4_15_out1 or SobelFilter_LessThan_2Ux2U_1U_4_17_out1 or global_state)
          begin :drive_global_state_next
            case (global_state) 

               3'd0, 3'd5:                begin
                  global_state_next = 3'd1;
               end
               
               3'd3:                begin
                  if (SobelFilter_LessThan_2Ux2U_1U_4_17_out1) begin
                     global_state_next = 3'd1;
                  end
                  else begin
                     if (SobelFilter_LessThan_2Ux2U_1U_4_15_out1) begin
                        global_state_next = 3'd1;
                     end
                     else begin
                        global_state_next = global_state + 3'd1;
                     end
                  end
               end
               
               default:                begin
                  global_state_next = global_state + 3'd1;
               end
               
            endcase

         end

         // resource: mux_1bx2i2c
         // resource: regr_en_sc_1
         always @(posedge i_clk)
          begin :drive_gs_ctrl0
            if (i_rst == 1'b0) begin
               gs_ctrl0 <= 1'b0;
            end
            else begin
               case (stall0) 

                  1'b1:                   begin
                  end
                  
                  1'b0:                   begin
                     case (global_state_next) 

                        3'd3:                         begin
                           gs_ctrl0 <= 1'b1;
                        end
                        
                        default:                         begin
                           gs_ctrl0 <= 1'b0;
                        end
                        
                     endcase

                  end
                  
               endcase

            end
         end

         // instance: drive_i_rgb_busy
         assign i_rgb_busy = SobelFilter_gen_busy_r_4_20_out1[2];

         // resource: SobelFilter_gen_busy_r_4  instance: SobelFilter_gen_busy_r_4_20
         assign SobelFilter_gen_busy_r_4_20_out1 = {SobelFilter_gen_busy_r_4_20_gnew_req, {SobelFilter_gen_busy_r_4_20_gdiv, SobelFilter_gen_busy_r_4_20_gen_busy_i_rgb_m_data_is_invalid_next}};

         // resource: SobelFilter_gen_busy_r_4  instance: SobelFilter_gen_busy_r_4_20
         assign SobelFilter_gen_busy_r_4_20_gen_busy_i_rgb_m_data_is_invalid_next = ~SobelFilter_gen_busy_r_4_20_gdiv;

         // resource: SobelFilter_gen_busy_r_4  instance: SobelFilter_gen_busy_r_4_20
         assign SobelFilter_gen_busy_r_4_20_gdiv = i_rgb_vld & !SobelFilter_gen_busy_r_4_20_gnew_req;

         // resource: SobelFilter_gen_busy_r_4  instance: SobelFilter_gen_busy_r_4_20
         assign SobelFilter_gen_busy_r_4_20_gnew_req = i_rgb_m_busy_req_0 & (i_rgb_m_unvalidated_req | i_rgb_vld);

         // resource: regr_ss_1
         always @(posedge i_clk)
          begin :drive_i_rgb_m_unvalidated_req
            if (i_rst == 1'b0) begin
               i_rgb_m_unvalidated_req <= 1'd1;
            end
            else begin
               i_rgb_m_unvalidated_req <= SobelFilter_N_Muxb_1_2_0_4_4_out1;
            end
         end

         // resource: SobelFilter_N_Muxb_1_2_0_4
         always @(i_rgb_vld or i_rgb_m_busy_req_0 or i_rgb_m_unvalidated_req)
          begin :SobelFilter_N_Muxb_1_2_0_4_4
            if (i_rgb_m_busy_req_0) begin
               SobelFilter_N_Muxb_1_2_0_4_4_out1 = i_rgb_m_unvalidated_req;
            end
            else begin
               SobelFilter_N_Muxb_1_2_0_4_4_out1 = i_rgb_vld;
            end
         end

         // instance: drive_o_result_vld
         assign o_result_vld = SobelFilter_Or_1Ux1U_1U_4_2_out1;

         // resource: SobelFilter_Or_1Ux1U_1U_4  instance: SobelFilter_Or_1Ux1U_1U_4_2
         assign SobelFilter_Or_1Ux1U_1U_4_2_out1 = o_result_m_unacked_req | SobelFilter_Xor_1Ux1U_1U_1_1_out1;

         // resource: regr_sc_1
         always @(posedge i_clk)
          begin :drive_o_result_m_unacked_req
            if (i_rst == 1'b0) begin
               o_result_m_unacked_req <= 1'd0;
            end
            else begin
               o_result_m_unacked_req <= SobelFilter_And_1Ux1U_1U_4_18_out1;
            end
         end

         // resource: SobelFilter_And_1Ux1U_1U_4  instance: SobelFilter_And_1Ux1U_1U_4_18
         assign SobelFilter_And_1Ux1U_1U_4_18_out1 = o_result_busy & o_result_vld;

         // resource: SobelFilter_Xor_1Ux1U_1U_1  instance: SobelFilter_Xor_1Ux1U_1U_1_1
         assign SobelFilter_Xor_1Ux1U_1U_1_1_out1 = o_result_m_req_m_trig_req ^ o_result_m_req_m_prev_trig_req;

         // resource: regr_sc_1
         always @(posedge i_clk)
          begin :drive_o_result_m_req_m_prev_trig_req
            if (i_rst == 1'b0) begin
               o_result_m_req_m_prev_trig_req <= 1'd0;
            end
            else begin
               o_result_m_req_m_prev_trig_req <= o_result_m_req_m_trig_req;
            end
         end

         // resource: SobelFilter_Not_1U_1U_1  instance: SobelFilter_Not_1U_1U_1_3
         assign SobelFilter_Not_1U_1U_1_3_out1 = !o_result_m_req_m_trig_req;


endmodule

