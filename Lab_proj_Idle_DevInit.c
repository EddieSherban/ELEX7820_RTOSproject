// Filename:            Lab2Idle_DeviceInit.c
//
// Description:	        Initialization code
//
// Version:             1.0
//
// Target:              TMS320F28379D
//
// Author:              David Romalo
//
// Date:                12Oct2021

#include <Headers/F2837xD_device.h>

void DeviceInit(void)
{
//initialize GPIO:
EALLOW; //allow access to protected registers

    //configure D10 (blue LED)
    GpioCtrlRegs.GPAMUX2.bit.GPIO31 = 0; //set pin as gpio
    GpioCtrlRegs.GPADIR.bit.GPIO31 = 1; //set gpio as output
    GpioDataRegs.GPASET.bit.GPIO31 = 1; //initialize output value to "1"

EDIS; //disallow access to protected registers
}
