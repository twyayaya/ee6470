/****************************************************************************
*
*  Copyright (c) 2015, Cadence Design Systems. All Rights Reserved.
*
*  This file contains confidential information that may not be
*  distributed under any circumstances without the written permision
*  of Cadence Design Systems.
*
****************************************************************************/
/****************************************************************************
*
* This file is used to wrap the three different versions of the DUT
* block called "SobelFilter". By default, it will include the behavioral
* model. Otherwise, it will include the RTL C++ or the RTL Verilog
* depending on the definition of either of "RTL" or "COSIM".
*
****************************************************************************/


#include	"SobelFilter_sc_wrap.h"
#include	"SobelFilter_sc_foreign.h"

// The following threads are used to connect structured ports to the actual
// RTL ports

void SobelFilter_wrapper::InitInstances(  )
{
	
            
    SobelFilter0 = new SobelFilter( "SobelFilter" );

    SobelFilter0->i_clk(i_clk);
    SobelFilter0->i_rst(i_rst);
    SobelFilter0->i_rgb_busy(i_rgb.busy);
    SobelFilter0->i_rgb_vld(i_rgb.vld);
    SobelFilter0->i_rgb_data(i_rgb.data);
    SobelFilter0->o_result_busy(o_result.busy);
    SobelFilter0->o_result_vld(o_result.vld);
    SobelFilter0->o_result_data(o_result.data);

}

void SobelFilter_wrapper::InitThreads()
{
    
}

void SobelFilter_wrapper::DeleteInstances()
{
    if (SobelFilter0)
    {
        delete SobelFilter0;
        SobelFilter0 = 0;
    }
}

