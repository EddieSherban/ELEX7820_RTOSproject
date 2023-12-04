// Filename:            F28379D_pwm.h
//
// Description:         pwm setup
//
// Version:             1.0
//
// Target:              TMS320F28379D
//
// Author:              Eddie Sherban
//
// Date:                Nov 25, 2023

#ifndef _28379D_PWM_H_
#define _28379D_PWM_H_

#include <Headers/F2837xD_device.h>

#define EN                  1
#define INIT_DUTY_CYCLE     0.5
#define FREQ                1000                    //~750 is good
#define EPWM_DIV1           0                 //don't divide PLLSYSCLK
#define TB_DIV8             3
#define TB_HS_DIV1          0
#define TB_COUNT_UP         0
#define NO_SHADOW           1
#define SHADOW              0
#define TB_PRD              200000000/FREQ/8 //200000000/FREQ/8
#define AQ_SET              2
#define AQ_CLEAR            1

void PWM_init();
void PWM_custom_dutycycle(float duty_cycle);
void PWM_half_dutycycle();
void PWM_no_dutycycle();

#endif /* _28379D_PWM_H_ */
