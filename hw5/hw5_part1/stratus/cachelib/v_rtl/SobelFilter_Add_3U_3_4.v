`timescale 1ps / 1ps
/*****************************************************************************
    Verilog RTL Description
    
    Configured at: 01:55:07 CST (+0800), Monday 26 April 2021
    Configured on: ws32
    Configured by: m109061613 (m109061613)
    
    Created by: Stratus DpOpt 2019.1.01 
*******************************************************************************/

module SobelFilter_Add_3U_3_4 (
	in1,
	out1
	); /* architecture "behavioural" */ 
input [2:0] in1;
output [2:0] out1;
wire [2:0] asc001;

assign asc001 = 
	+(in1)
	+(3'B000);

assign out1 = asc001;
endmodule

/* CADENCE  urf5Qwk= : u9/ySgnWtBlWxVPRXgAZ4Og= ** DO NOT EDIT THIS LINE ******/


