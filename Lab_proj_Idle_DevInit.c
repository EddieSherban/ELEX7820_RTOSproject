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

void DeviceInit(void)
{
//initialize GPIO:
EALLOW; //allow access to protected registers

    //configure D10 (blue LED)
    GpioCtrlRegs.GPAMUX2.bit.GPIO31 = 0; //set pin as gpio
    GpioCtrlRegs.GPADIR.bit.GPIO31 = 1; //set gpio as output
    GpioDataRegs.GPASET.bit.GPIO31 = 1; //initialize output value to "1"

    //POWER UP SEQUENCE
    // turn on registers that enable ADC clock (ADC A)
    CpuSysRegs.PCLKCR13.bit.ADC_A = 1;

    //ADC Clock Divider
    AdcaRegs.ADCCTL2.bit.PRESCALE = 0xF;

    //Power up ADC
    AdcaRegs.ADCCTL1.bit.ADCPWDNZ = 1;

    AdcaRegs.ADCCTL1.bit.INTPULSEPOS = 1;
    //Delay before sampling
    //...?


    //Basic Synchronous Operation
    AdcaRegs.ADCSOC0CTL.bit.CHSEL = 5; //SOC0 will convert ADCINA5
    AdcaRegs.ADCSOC0CTL.bit.ACQPS = 139; //SOC0 will use sample duration of 20 SYSCLK cycles
    AdcaRegs.ADCSOC0CTL.bit.TRIGSEL = 1; //SOC0 will begin conversion on CPU Timer 0

    AdcaRegs.ADCSOC1CTL.bit.CHSEL = 3; //SOC1 will convert ADCINA3
    AdcaRegs.ADCSOC1CTL.bit.ACQPS = 145; //SOC1 will use sample duration of 31 SYSCLK cycles
    AdcaRegs.ADCSOC1CTL.bit.TRIGSEL = 1; //SOC1 will begin conversion on CPU Timer 0

    AdcaRegs.ADCINTSEL1N2.bit.INT1SEL = 0; //connect interrupt ADCINT1 to EOC0
    AdcaRegs.ADCINTSEL1N2.bit.INT1E = 1;    //enable interrupt ADCINT1


EDIS; //disallow access to protected registers
}
