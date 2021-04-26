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
* This file contains the SobelFilter_type_wrapper module
* for use in the verilog verification wrapper SobelFilter_vlwrapper.v
* It creats an instance of the SobelFilter module and has threads
* for converting the BEH ports to RTL level ports on the wrapper.
*
****************************************************************************/

#include "SobelFilter_type_wrapper.h"


SC_MODULE_EXPORT(SobelFilter_type_wrapper)

// The following threads are used to connect RTL ports to the actual
// structured ports

void SobelFilter_type_wrapper::InitInstances()
{
    SobelFilter0 = new SobelFilter( "SobelFilter" );

    SobelFilter0->i_clk(i_clk);
    SobelFilter0->i_rst(i_rst);
    SobelFilter0->i_rgb.busy(i_rgb_busy);
    SobelFilter0->i_rgb.vld(i_rgb_vld);
    SobelFilter0->i_rgb.data(i_rgb_data);
    SobelFilter0->o_result.busy(o_result_busy);
    SobelFilter0->o_result.vld(o_result_vld);
    SobelFilter0->o_result.data(o_result_data);

}

void SobelFilter_type_wrapper::InitThreads()
{
    
}

void SobelFilter_type_wrapper::DeleteInstances()
{
        delete SobelFilter0;
        SobelFilter0 = 0;
}

