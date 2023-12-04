// Filename:            Lab_proj_Idle_DeviceInit.c
//
// Description:         Initialization code
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
#include "periph/F28379DZTQ/F28379D_gpio.h"

void DeviceInit(void)
{
EALLOW; //allow access to protected registers

    GPIO_init();
    ADC_init();
    PWM_init();
    //PWM_half_dutycycle();

EDIS; //disallow access to protected registers
}
