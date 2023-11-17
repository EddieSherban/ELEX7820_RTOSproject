#include "timer.h"

void timer_init(UInt32 freq){
	PieVectTable.TIMER0_INT = timer_isr;
    CpuSysRegs.PCLKCR0.bit.CPUTIMER0 = 1;   //enable CPUTIMER0
    CpuTimer0Regs.TCR.bit.TSS = 1;          //set TSS to 1 to stop the CPU timer during init
    CpuTimer0Regs.PRD.all = SYSCLKFREQ/freq;//set PRD register to desired period of interrupt (fs)
    CpuTimer0Regs.TPR.bit.TDDR = 0;         //use SYSCLK frequency section 3.17.2.4
    CpuTimer0Regs.TPRH.bit.TDDRH = 0;       //high bits of TDDR, also set to 0
    CpuTimer0Regs.TCR.bit.TRB = 1;          //something interesting

    CpuTimer0Regs.TCR.bit.FREE = 0;
    CpuTimer0Regs.TCR.bit.SOFT = 1;
}

__interrupt void timer_isr(){

}
