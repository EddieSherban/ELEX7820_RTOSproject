// Filename:            Lab_proj_Idle_DeviceInit.c
//
// Description:	        Initialization code
//
// Version:             1.0
//
// Target:              TMS320F28379D
//
// Author:              Eddie Sherban
//
// Date:                Oct 29, 2021

#include <Headers/F2837xD_device.h>
#include "periph/F28379DZTQ/F28379D_i2c.h"
#include "periph/F28379DZTQ/F28379D_pwm.h"
#include "periph/F28379DZTQ/F28379D_adc.h"

void DeviceInit(void)
{
//initialize GPIO:
EALLOW; //allow access to protected registers

    //configure D10 (blue LED)
    GpioCtrlRegs.GPAMUX2.bit.GPIO31 = 0; //set pin as gpio
    GpioCtrlRegs.GPADIR.bit.GPIO31 = 1; //set gpio as output
    GpioDataRegs.GPASET.bit.GPIO31 = 1; //initialize output value to "1"

    ADC_init();
    PWM_init();
    //PWM_half_dutycycle();

EDIS; //disallow access to protected registers
}
