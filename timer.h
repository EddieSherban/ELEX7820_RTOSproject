#ifndef TIMER_H_
#define TIMER_H_

#include <xdc/std.h>
#include <xdc/runtime/System.h>
#include <ti/sysbios/BIOS.h>

#include <Headers/F2837xD_device.h>

void timer_init(UInt32 freq);
void timer_isr();

UInt32 SYSCLKFREQ = 200000000;

#endif /* TIMER_H */
