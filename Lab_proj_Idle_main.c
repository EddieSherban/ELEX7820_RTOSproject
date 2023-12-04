// Filename:            Lab2Idle_main.c
//
// Description:         This file has a main, timer, and idle function for SYS/BIOS application.
//
// Target:              TMS320F28379D
//
// Author:              Eddie Sherban A01071318
//
// Date:                Oct. 13, 2023

//defines:
#define xdc__strict //suppress typedef warnings

//includes:
#include <xdc/std.h>
#include <xdc/runtime/System.h>
#include <ti/sysbios/BIOS.h>

#include <Headers/F2837xD_device.h>

//function prototypes:
extern void DeviceInit(void);

//declare global variables:
volatile Bool isrFlag = FALSE; //flag used by idle function
volatile Bool isrFlag2 = FALSE; //ES
volatile UInt tickCount = 0; //counter incremented by timer interrupt
int sec = 0;                    //ES
int soc0_adc_voltage = 0;
int soc1_adc_voltage = 0;

/* ======== main ======== */
int main()
{
    System_printf("Enter main()\n"); //use ROV->SysMin to view the characters in the circular buffer

    //initialization:
    DeviceInit(); //initialize processor

    //jump to RTOS (does not return):
    BIOS_start();
    return(0);
}

/* ======== myTickFxn ======== */
//Timer tick function that increments a counter and sets the isrFlag
//Entered 100 times per second if PLL and Timer set up correctly
void myTickFxn(UArg arg)
{
    tickCount++; //increment the tick counter
    if(tickCount % 50 == 0) {
        isrFlag = TRUE; //tell idle thread to do something 2 times per second
    }
    if(tickCount % 100 == 0) {      //ES
        isrFlag2 = TRUE;
    }                               //ES
}

/* ======== myIdleFxn ======== */
//Idle function that is called repeatedly from RTOS
void myIdleFxn(void)
{
   if(isrFlag == TRUE) {
       isrFlag = FALSE;
       //toggle blue LED:
       GpioDataRegs.GPATOGGLE.bit.GPIO31 = 1;
   }
}

void myIdleFxn2(void)       //ES
{
    if(isrFlag2 == TRUE) {
        isrFlag2 = FALSE;
        sec++;
        //print time in seconds to SysMin
        System_printf("Timer(sec) = %i \n",sec);
    }

}                           //ES

void adc_hwi(void)
{
    soc0_adc_voltage = AdcaResultRegs.ADCRESULT0;
    soc1_adc_voltage = AdcaResultRegs.ADCRESULT1;
    AdcaRegs.ADCINTFLGCLR.bit.ADCINT1 = 1;          //clear interrupt flag
    System_printf("ADCINA5(V) = %i \n",soc0_adc_voltage);
    System_printf("ADCINA3(V) = %i \n",soc1_adc_voltage);
}
