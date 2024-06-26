// Filename:            F28379D_adc.c
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

#include "F28379D_adc.h"

void ADC_init()
{
    //POWER UP SEQUENCE
    // turn on registers that enable ADC clock (ADC A)
    CpuSysRegs.PCLKCR13.bit.ADC_A = 1;

    //ADC Clock Divider
    AdcaRegs.ADCCTL2.bit.PRESCALE = 0xF;

    //Power up ADC
    AdcaRegs.ADCCTL1.bit.ADCPWDNZ = 1;

    AdcaRegs.ADCCTL1.bit.INTPULSEPOS = 1;
    //Delay before sampling

    //for(unsigned long del_ctr = 0; del_ctr < 1000; del_ctr++);  //wait ~1000ms

    //Basic Synchronous Operation
    AdcaRegs.ADCSOC0CTL.bit.CHSEL = 5;      //SOC0 will convert ADCINA5
    AdcaRegs.ADCSOC0CTL.bit.ACQPS = 139;    //set SOC0 window to 139 SYSCLK cycles
    AdcaRegs.ADCSOC0CTL.bit.TRIGSEL = 2;    //SOC0 will begin conversion on CPU Timer 1

    AdcaRegs.ADCSOC1CTL.bit.CHSEL = 3;      //SOC1 will convert ADCINA3
    AdcaRegs.ADCSOC1CTL.bit.ACQPS = 145;    //set SOC1 window to 301 SYSCLK cycles
    AdcaRegs.ADCSOC1CTL.bit.TRIGSEL = 2;    //SOC1 will begin conversion on CPU Timer 1

    AdcaRegs.ADCINTSEL1N2.bit.INT1SEL = 0;  //connect interrupt ADCINT1 to EOC0
    AdcaRegs.ADCINTSEL1N2.bit.INT1E = 1;    //enable interrupt ADCINT1
}
