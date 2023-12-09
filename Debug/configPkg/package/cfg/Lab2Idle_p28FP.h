/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-K04
 */

#include <xdc/std.h>

#include <ti/sysbios/family/c28/Timer.h>
extern const ti_sysbios_family_c28_Timer_Handle myTimer0;

#include <ti/sysbios/family/c28/Hwi.h>
extern const ti_sysbios_family_c28_Hwi_Handle hwi0;

#include <ti/sysbios/family/c28/Hwi.h>
extern const ti_sysbios_family_c28_Hwi_Handle hwi1;

#include <ti/sysbios/knl/Swi.h>
extern const ti_sysbios_knl_Swi_Handle mic1_FFT_swi;

#include <ti/sysbios/knl/Task.h>
extern const ti_sysbios_knl_Task_Handle state0;

#include <ti/sysbios/knl/Semaphore.h>
extern const ti_sysbios_knl_Semaphore_Handle testing_sem;

#include <ti/sysbios/knl/Swi.h>
extern const ti_sysbios_knl_Swi_Handle menu_swi;

#include <ti/sysbios/knl/Swi.h>
extern const ti_sysbios_knl_Swi_Handle rec_swi;

#include <ti/sysbios/knl/Swi.h>
extern const ti_sysbios_knl_Swi_Handle PvP_swi;

#include <ti/sysbios/knl/Task.h>
extern const ti_sysbios_knl_Task_Handle test;

#include <ti/sysbios/knl/Semaphore.h>
extern const ti_sysbios_knl_Semaphore_Handle print_sem;

#include <ti/sysbios/knl/Task.h>
extern const ti_sysbios_knl_Task_Handle msg;

#include <ti/sysbios/knl/Semaphore.h>
extern const ti_sysbios_knl_Semaphore_Handle state0_sem;

#include <ti/sysbios/knl/Semaphore.h>
extern const ti_sysbios_knl_Semaphore_Handle state1_sem;

#include <ti/sysbios/knl/Semaphore.h>
extern const ti_sysbios_knl_Semaphore_Handle state2_sem;

#include <ti/sysbios/knl/Task.h>
extern const ti_sysbios_knl_Task_Handle rec;

#include <ti/sysbios/family/c28/Timer.h>
extern const ti_sysbios_family_c28_Timer_Handle adctimer;

#include <ti/sysbios/knl/Swi.h>
extern const ti_sysbios_knl_Swi_Handle trans_swi;

#include <ti/sysbios/knl/Swi.h>
extern const ti_sysbios_knl_Swi_Handle find_fund;

#include <ti/sysbios/knl/Semaphore.h>
extern const ti_sysbios_knl_Semaphore_Handle confirmation;

#include <ti/sysbios/family/c28/Hwi.h>
extern const ti_sysbios_family_c28_Hwi_Handle hwi2;

#include <ti/sysbios/knl/Swi.h>
extern const ti_sysbios_knl_Swi_Handle mic2_FFT_swi;

#include <ti/sysbios/family/c28/Hwi.h>
extern const ti_sysbios_family_c28_Hwi_Handle hwi3;

#include <ti/sysbios/knl/Swi.h>
extern const ti_sysbios_knl_Swi_Handle spi_rx;

#include <ti/sysbios/knl/Task.h>
extern const ti_sysbios_knl_Task_Handle state1;

#include <ti/sysbios/knl/Task.h>
extern const ti_sysbios_knl_Task_Handle state2;

extern int xdc_runtime_Startup__EXECFXN__C;

extern int xdc_runtime_Startup__RESETFXN__C;

extern int xdc_rov_runtime_Mon__checksum;

extern int xdc_rov_runtime_Mon__write;

