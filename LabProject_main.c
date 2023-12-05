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
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Semaphore.h>

#include <Headers/F2837xD_device.h>

//Swi handle defined in .cfg file:
extern const Swi_Handle swi0;   //calc_FFT_swi4
extern const Swi_Handle swi1;   //Menu_swi5
extern const Swi_Handle swi2;   //Record_swi6
extern const Swi_Handle swi3;   //PvP_swi7

//Task handle defined in .cfg file:
extern const Task_Handle Tsk0;  //print_tsk8
extern const Task_Handle Tsk1;  //wait_tsk9
extern const Task_Handle Tsk2;  //start_sampling_tsk4
extern const Task_Handle Tsk3;  //pwm_tsk10
extern const Task_Handle Tsk5;  //print_message_tsk7
extern const Task_Handle Tsk999;//Testing task

//Semaphore handles defined in .cfg file:
extern const Semaphore_Handle testing_sem;
extern const Semaphore_Handle state_sem;
extern const Semaphore_Handle wait_sem;
extern const Semaphore_Handle pwm_sem;
extern const Semaphore_Handle sampling_sem;
extern const Semaphore_Handle print_sem;
//message semaphores
extern const Semaphore_Handle hello_msg_sem;
extern const Semaphore_Handle option_msg_sem;
extern const Semaphore_Handle start_recording_msg_sem;
extern const Semaphore_Handle countdown_msg_sem

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
float RFFTin2Buff[RFFT_SIZE];
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
//declare global variables:

/* ======== main ======== */
Int main()
{ 
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

/* ======== TIMER ISR ======== */

//Timer tick function that increments a counter and sets the isrFlag
//Entered 100 times per second if PLL and Timer set up correctly
Void myTickFxn(UArg arg)
{
    tickCount++; //increment the tick counter
    if(tickCount % 100 == 0) {
        isrFlag = TRUE; //tell idle thread to do something once per second
    }
    if(tickCount % 500 == 0) {      //ES
        isrFlag2 = TRUE;
        Semaphore_post(testing_sem);
    }                               //ES
}
/* ======== TIMER ISR ======== */


/* ======== IDLE FXNS ======== */
//Idle function that is called repeatedly from RTOS
Void myIdleFxn(Void)
{
   if(isrFlag == TRUE) {
       isrFlag = FALSE;
       GpioDataRegs.GPATOGGLE.bit.GPIO31 = 1; //toggle blue LED:
   }
}

Void myIdleFxn2(Void)       //ES
{
    if(isrFlag2 == TRUE) {
        isrFlag2 = FALSE;
        sec++;
        //print time in seconds to SysMin
        System_printf("Timer(sec) = %i \n",sec);
    }
}                           //ES
/* ======== IDLE FXNS ======== */


/* ======== HWIs ======== */
//adc HWI (1st Priority)
Void adc_hwi(Void)
{
    soc0_adc_voltage = AdcaResultRegs.ADCRESULT0;   //result for ADCINA5
    soc1_adc_voltage = AdcaResultRegs.ADCRESULT1;   //result for ADCINA3
    AdcaRegs.ADCINTFLGCLR.bit.ADCINT1 = 1;          //clear interrupt flag
    System_printf("adca3 voltage: %i \n",soc0_adc_voltage);
    System_printf("adca5 voltage: %i \n",soc1_adc_voltage);
}

//Reset HWI (2nd Priority)
Void button_press(Void)
{
    EALLOW;
    XintRegs.XINT1CR.bit.ENABLE = 0;    //disable xint1 interrupt
    EDIS;

    XbarRegs.XBARCLR2.bit.INPUT4 = 1;   //INPUT4 X-BAR Flag Clear
    EALLOW;
    XintRegs.XINT1CR.bit.ENABLE = 1;    //enable xint1 interrupt
    EDIS;
}
/* ======== HWIs ======== */


/* ======== SWIs ======== */
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

Void Menu_swi5(Void)
{
    //Semaphore_post(testing_sem);

}

Void Record_swi6(Void)
{

}

Void PvP_swi7(Void)
{

}

/* ======== SWIs ======== */

/* ======== TASKs ======== */
Void Testing(Void) //priority 1 (lowest task priority)
{
    while(TRUE){
        Semaphore_pend(testing_sem, BIOS_WAIT_FOREVER);   //wait for semaphore to be posted
        //GpioDataRegs.GPBTOGGLE.bit.GPIO34 = 1;    //toggle red LED
        GpioDataRegs.GPBTOGGLE.bit.GPIO34 = 1;
    }
}

Void Print_tsk8(Void){
    while(TRUE){
        Semaphore_pend(print_sem, BIOS_WAIT_FOREVER);
    }
}


Void print_message_tsk7(Void){
    while(TRUE){
        Semaphore_pend(hello_message_sem, BIOS_WAIT_FOREVER);
        //Semaphore_pend();
    }
}

Void wait_tsk9(Void){
    while(TRUE){
        Semaphore_pend(wait_sem, BIOS_WAIT_FOREVER);
    }
}

Void Start_sampling_tsk4(Void){
    while(TRUE){
        Semaphore_pend(print_sem, BIOS_WAIT_FOREVER);
    }
}

Void pwm_tsk10(Void){
    while(TRUE){
        Semaphore_pend(pwm_sem, BIOS_WAIT_FOREVER);
    }
}

/* ======== TASKs ======== */
