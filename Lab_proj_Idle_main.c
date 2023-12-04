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

#define RFFT_STAGES     8
#define RFFT_SIZE       (1 << RFFT_STAGES)
#define EPSILON         0.01
#define PI 3.14159265358979323

//includes:
#include <xdc/std.h>
#include <xdc/runtime/System.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Swi.h>


#include <Headers/F2837xD_device.h>

//Swi handle defined in .cfg file:
extern const Swi_Handle swi0;

//dsp includes:
#include "dsp/fpu_rfft.h"
#include "dsp/fpu_types.h"
#include <math.h>

//peripherals
#include "periph/F28379DZTQ/F28379D_i2c.h"
#include "periph/F28379DZTQ/F28379D_pwm.h"
#include "periph/F28379DZTQ/F28379D_adc.h"

//function prototypes:
extern void DeviceInit(void);

//declare global variables:
float RFFTin1Buff[RFFT_SIZE];
volatile Bool isrFlag = FALSE; //flag used by idle function
volatile Bool isrFlag2 = FALSE; //ES
volatile UInt tickCount = 0; //counter incremented by timer interrupt

//FFT Calculation Buffer:
//The input buffer needs to be aligned to a 4N word boundary
//If the number of FFT stages is odd, the result of the FFT will be writetn to this buffer
#pragma DATA_SECTION(RFFTin1Buff, "RFFTdata1")
float RFFTin1Buff[RFFT_SIZE];

//Magnitude Calculation Buffer:
#pragma DATA_SECTION(RFFTmagBuff,"RFFTdata2")
float RFFTmagBuff[RFFT_SIZE/2+1];

//FFT Calculation Buffer;
//If the number of FFT stages is even, the result of the FFT will be written to this buffer
#pragma DATA_SECTION(RFFToutBuff,"RFFTdata3")
float RFFToutBuff[RFFT_SIZE];

//Twiddle Factors:
#pragma DATA_SECTION(RFFTF32Coef,"RFFTdata4")
float RFFTF32Coef[RFFT_SIZE];

//Object of the structure RFFT_F32_STRUCT
RFFT_F32_STRUCT rfft;
//Declare and initialize FFT structure object:
RFFT_F32_STRUCT_Handle hnd_rfft = &rfft;

float RadStep = 0.1963495408494f; //step
float Rad = 0.0f;

Uint16 once = TRUE;
Uint16 bin = 0;
int32_t count = 1;

int sec = 0;                    //ES
int soc0_adc_voltage = 0;
int soc1_adc_voltage = 0;

/* ======== main ======== */
Int main()
{
    // Locals
    uint16_t i;

    System_printf("Enter main()\n"); //use ROV->SysMin to view the characters in the circular buffer

    //FFT init
    //Clear input buffer:
    for(i=0; i < RFFT_SIZE; i++){
        RFFTin1Buff[i] = 0.0f;
    }

    hnd_rfft->FFTSize   = RFFT_SIZE;
    hnd_rfft->FFTStages = RFFT_STAGES;
    hnd_rfft->InBuf     = &RFFTin1Buff[0];  //Input buffer
    hnd_rfft->OutBuf    = &RFFToutBuff[0];  //Output buffer
    hnd_rfft->MagBuf    = &RFFTmagBuff[0];  //Magnitude buffer
    //hnd_rfft->CosSinBuf = RFFT_f32_twiddleFactors; //Twiddle factor buffer
    hnd_rfft->CosSinBuf = &RFFTF32Coef[0];  //twiddle factor buffer

    for (i=0; i < RFFT_SIZE; i++){ //may not be necessary
        RFFToutBuff[i] = 0;     //clean up output buffer
    }

    for(i=0; i < RFFT_SIZE/2; i++) {//may not be necessary
        RFFTmagBuff[i] = 0;     //clean up magnitude buffer
    }

    //initialization:
    DeviceInit(); //initialize processor

    //jump to RTOS (does not return):
    BIOS_start();
    return(0);
}

/* ======== myTickFxn ======== */
//Timer tick function t hat increments a counter and sets the isrFlag
//Entered 100 times per second if PLL and Timer set up correctly
Void myTickFxn(UArg arg)
{
    tickCount++; //increment the tick counter
    //Swi_post(swi0);
    if(tickCount % 100 == 0) {
        isrFlag = TRUE; //tell idle thread to do something 2 times per second
    }
    if(tickCount % 500 == 0) {      //ES
        isrFlag2 = TRUE;
    }                               //ES

}

/* ======== myIdleFxn ======== */
//Idle function that is called repeatedly from RTOS
Void myIdleFxn(Void)
{
    // Locals
    uint16_t i;

    if(isrFlag == TRUE) {
        isrFlag = FALSE;
        //toggle blue LED:
        GpioDataRegs.GPATOGGLE.bit.GPIO31 = 1;
        //PWM_no_dutycycle();
        PWM_custom_dutycycle(0.7);
    }

    // Generate waveform:
    //Rad = 0.0f
    for(i=0; i < RFFT_SIZE; i++){
        RFFTin1Buff[i] = sin(Rad) + cos(Rad*2.3567); //Real input signal
        RFFTin1Buff[i] = sin(2 * PI * i * bin / RFFT_SIZE);
        Rad = Rad + RadStep;
    }

    RFFT_f32_sincostable(hnd_rfft);         //Calculate twiddle factor
    RFFT_f32(hnd_rfft);         //calculate real FFT
    RFFT_f32_mag(hnd_rfft);     //calculate magnitude
    RFFT_f32_phase(hnd_rfft);   //calculate phase

    if(bin == RFFT_SIZE/2 - 1)
        bin = 0;
    else
        bin++;
}

Void myIdleFxn2(Void)       //ES
{
    if(isrFlag2 == TRUE) {
        isrFlag2 = FALSE;
        sec++;
        //print time in seconds to SysMin
        //System_printf("Timer(sec) = %i \n",sec);
        PWM_custom_dutycycle(0.2);
    }

}                           //ES

Void adc_hwi(Void)
{
    soc0_adc_voltage = AdcaResultRegs.ADCRESULT0;   //result for ADCINA5
    soc1_adc_voltage = AdcaResultRegs.ADCRESULT1;   //result for ADCINA3
    AdcaRegs.ADCINTFLGCLR.bit.ADCINT1 = 1;          //clear interrupt flag
    System_printf("adca5 voltage: %i \n",soc0_adc_voltage);
    System_printf("adca3 voltage: %i \n",soc1_adc_voltage);
}

Void calc_FFT_swi4(Void)
{
 /*   //determine if tickCount is a prime:
    UInt counter, flag;

    counter = 2;
    flag = 1;
    while(counter < tickCount) {
        if(tickCount % counter == 0){
            flag = 0;
        }
        counter++;
    }
    if(flag == 1 && tickCount != 1){
        GpioDataRegs.GPBTOGGLE.bit.GPIO34 = 1; //toggle red LED
        //System_printf("tickCount: %u\n", tickCount);
    }*/
}

Void button_press(Void)
{

}
