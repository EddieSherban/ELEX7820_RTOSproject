// Filename:            F28379D_pwm.c
//
// Description:         useful pwm functions
//
// Version:             1.0
//
// Target:              TMS320F28379D
//
// Author:              Eddie Sherban
//
// Date:                Nov 25, 2023

#include "F28379D_pwm.h"
#include <xdc/std.h>
#include <xdc/runtime/System.h>

void PWM_init()
{
    // Configure EPWM4A (ENB)
    GpioCtrlRegs.GPAGMUX1.bit.GPIO6 = 0;
    GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 1;     // Sets pin as EPWM4A for GPIO6

    CpuSysRegs.PCLKCR2.bit.EPWM4 = EN;                       // Enable EPWM4A clock
    CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = EN;                   // Sync EPWM clocks

    ClkCfgRegs.PERCLKDIVSEL.bit.EPWMCLKDIV = EPWM_DIV1;    // EPWM clock divisor

    EPwm4Regs.TBCTL.bit.CLKDIV = TB_DIV8;                  // Time-base clock divisor
    EPwm4Regs.TBCTL.bit.HSPCLKDIV = TB_HS_DIV1;            // High speed time-base clock divisor
    EPwm4Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP;      // Count-up mode
    EPwm4Regs.TBCTL.bit.SYNCOSEL = 3;

    EPwm4Regs.TBPRD = TB_PRD_CLAMP;                       // Time-base period

    EPwm4Regs.CMPCTL.bit.SHDWAMODE = SHADOW;     //
    EPwm4Regs.CMPCTL.bit.LOADAMODE = 0;

    EPwm4Regs.CMPA.bit.CMPA = TB_PRD_CLAMP * INIT_DUTY_CYCLE;  // Default 50% duty cycle period

    EPwm4Regs.AQCTLA.bit.ZRO = AQ_SET;      // Set high when count at 0
    EPwm4Regs.AQCTLA.bit.CAU = AQ_CLEAR;    // Set low when count at CMPA
}

void PWM_custom_dutycycle(float duty_cycle)
{
    EPwm4Regs.CMPA.bit.CMPA = (Uint16)(TB_PRD_CLAMP * duty_cycle);
}

void PWM_half_dutycycle(){
    EPwm4Regs.CMPA.bit.CMPA = TB_PRD_CLAMP * 0.5;
}

void PWM_no_dutycycle(){
    EPwm4Regs.CMPA.bit.CMPA = 0;
}

void clamp_motor1_turn_left(float duty_cycle){
    EPwm4Regs.CMPA.bit.CMPA = (Uint16)(TB_PRD_CLAMP * duty_cycle);
}

void clamp_motor2_turn_left(){

}

void clamp_motor1_turn_right(){

}

void clamp_motor2_turn_right(){

}

void arena_motor(){

}
