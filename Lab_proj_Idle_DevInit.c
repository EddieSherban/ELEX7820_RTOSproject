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
//
// Modified by:         Felix Serban
//
// Modified date:       03 Dec 2023
//
// Modifications:       Split up sections for different modules into separate functions

#include <Headers/DeviceInit.h>

void DeviceInit(void)
{
    Init_ADCa();
    Init_SPIa();
}
