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

    //configure D9 (red LED)
    GpioCtrlRegs.GPBMUX1.bit.GPIO34 = 0;        //set pin as gpio
    GpioCtrlRegs.GPBDIR.bit.GPIO34 = 1;         //set gpio as output
    GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1;       //initialize output value to "0"

    //configure test GPIO for oscilloscope
    GpioCtrlRegs.GPAMUX2.bit.GPIO30 = 0;        //set pin as gpio
    GpioCtrlRegs.GPADIR.bit.GPIO30 = 1;         //set gpio as output
    GpioDataRegs.GPASET.bit.GPIO30 = 1;         //initialize output value to "1"

    //configure GPIOs as input for buttons (state switching button)
    GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 0;        //set pin as gpio
    GpioCtrlRegs.GPADIR.bit.GPIO29 = 0;         //set gpio as input
    GpioCtrlRegs.GPAPUD.bit.GPIO29 = 0;         //pull up resistor enabled; so we don't need to use pull down resistors on the breadboard

    //configure GPIOs as input for buttons (confriamtion button)
    GpioCtrlRegs.GPAMUX2.bit.GPIO24 = 0;        //set pin as gpio
    GpioCtrlRegs.GPADIR.bit.GPIO24 = 0;         //set gpio as input
    GpioCtrlRegs.GPAPUD.bit.GPIO24 = 0;         //pull up resistor enabled; so we don't need to use pull down resistors on the breadboard

    //hwi interrupt number 35 --> XINT1 interrupt
    XintRegs.XINT1CR.bit.POLARITY = 0;          //negative edge triggered; pressing button creates 0V, down from 3.3V from Pull-up res.
    XintRegs.XINT1CR.bit.ENABLE = 1;            //enable interrupt
    InputXbarRegs.INPUT4SELECT = 29;            //connect input4 to GPIO29
    //XbarRegs.XBARFLG2.bit.INPUT4 = something <-- this reads the input flag to allow software knowledge of input sources which got triggered


    //hwi interrupt number 36 --> XINT2 interrupt
    XintRegs.XINT2CR.bit.POLARITY = 0;          //negative edge triggered; pressing button creates 0V, down from 3.3V from Pull-up res.
    XintRegs.XINT2CR.bit.ENABLE = 0;            //disable interrupt initially, only enable when waiting for confirmation
    InputXbarRegs.INPUT5SELECT = 24;            //connect input5 to GPIO24

}
