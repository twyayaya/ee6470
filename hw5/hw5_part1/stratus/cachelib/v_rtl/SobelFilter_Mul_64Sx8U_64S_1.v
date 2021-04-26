`timescale 1ps / 1ps
/*****************************************************************************
    Verilog RTL Description
    
    Configured at: 01:55:04 CST (+0800), Monday 26 April 2021
    Configured on: ws32
    Configured by: m109061613 (m109061613)
    
    Created by: Stratus DpOpt 2019.1.01 
*******************************************************************************/

module SobelFilter_Mul_64Sx8U_64S_1 (
	in2,
	in1,
	out1
	); /* architecture "behavioural" */ 
input [63:0] in2;
input [7:0] in1;
output [63:0] out1;
wire  asc001;

assign asc001 = 
	+(in1[0] * in2[0]);

assign out1 = {{63{1'B0}}, asc001};
endmodule

/* CADENCE  ubPyTAk= : u9/ySgnWtBlWxVPRXgAZ4Og= ** DO NOT EDIT THIS LINE ******/


