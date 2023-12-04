// Filename:            F28379D_gpio.c
//
// Description:         gpio setup
//
// Version:             1.0
//
// Target:              TMS320F28379D
//
// Author:              Eddie Sherban
//
// Date:                Nov 25, 2023

#include "F28379D_gpio.h"
#include <xdc/std.h>
#include <xdc/runtime/System.h>

void GPIO_init()
{
    //configure D10 (blue LED)
    GpioCtrlRegs.GPAMUX2.bit.GPIO31 = 0;        //set pin as gpio
    GpioCtrlRegs.GPADIR.bit.GPIO31 = 1;         //set gpio as output
    GpioDataRegs.GPASET.bit.GPIO31 = 1;         //initialize output value to "1"

    //configure test GPIO for oscilloscope
    GpioCtrlRegs.GPAMUX2.bit.GPIO30 = 0;        //set pin as gpio
    GpioCtrlRegs.GPADIR.bit.GPIO30 = 1;         //set gpio as output
    GpioDataRegs.GPASET.bit.GPIO30 = 1;         //initialize output value to "1"

    //configure GPIOs as input for buttons
    GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 0;        //set pin as gpio
    GpioCtrlRegs.GPADIR.bit.GPIO29 = 0;         //set gpio as input
    GpioCtrlRegs.GPAPUD.bit.GPIO29 = 1;         //pull up resistor enabled DOUBLE CHECK***********

    //hwi interrupt number 35 --> XINT1 interrupt
    XintRegs.XINT1CR.bit.POLARITY = 1;          //positive edge triggered
    XintRegs.XINT1CR.bit.ENABLE = 1;            //enable interrupt
    InputXbarRegs.INPUT4SELECT = 29;            //connect input4 to GPIO29
    //XbarRegs.XBARFLG2.bit.INPUT4 = something <-- this reads the input flag to allow software knowledge of input sources which got triggered


}
