// Filename:            F28379D_i2c.c
//
// Description:         I2C setup
//
// Version:             1.0
//
// Target:              TMS320F28379D
//
// Author:              Eddie Sherban
//
// Date:                Nov 25, 2023

//TI includes
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Clock.h>

//in-house includes
#include "F28379D_i2c.h"


void i2c_init()
{
    uint16_t divider = 0;

    EALLOW;

    CpuSysRegs.PCLKCR9.bit.I2C_A = 1; //enable I2CA peripheral

    //gpio initialization
    //SDA - GPIO104
    GpioCtrlRegs.GPDDIR.bit.GPIO104 = 0; //set as input
    GpioCtrlRegs.GPDPUD.bit.GPIO104 = 0; //enable pullup
    GpioCtrlRegs.GPDGMUX1.bit.GPIO104 = 0x00U;
    GpioCtrlRegs.GPDMUX1.bit.GPIO104 = 0x01U; //mux SDAT line of I2CA peripheral to GPIO104
    GpioCtrlRegs.GPDCSEL2.bit.GPIO104 = 0x00; //select CPU0 as master core
    GpioCtrlRegs.GPDQSEL1.bit.GPIO104 |= 0x3U; //set asychronous qualification mode (I2C module doesn't require clock sync)
    //SCLK - GPIO105
    GpioCtrlRegs.GPDDIR.bit.GPIO105 = 0;
    GpioCtrlRegs.GPDPUD.bit.GPIO105 = 0;
    GpioCtrlRegs.GPDGMUX1.bit.GPIO105 = 0x00U;
    GpioCtrlRegs.GPDMUX1.bit.GPIO105 = 0x01U;
    GpioCtrlRegs.GPDCSEL2.bit.GPIO105 = 0x00;
    GpioCtrlRegs.GPDQSEL1.bit.GPIO105 |= 0x3U;

    //I2CA module initialization
    I2caRegs.I2CMDR.bit.IRS = 0; //disable i2c module A for setup

    I2caRegs.I2CPSC.bit.IPSC = (Uint8)((SYS_CLK_FREQ / 10000000UL) - 1UL); //set prescaler to 20 (10MHz input clk)

    //set clock low and high periods for 50% duty cycle and specified frequency (see 20.1.5.1 of t.ref manual)
    divider = (uint16_t)(10000000UL / SCLK_FREQ) - (2UL * D);
    I2caRegs.I2CCLKH = divider/2; //high period
    I2caRegs.I2CCLKL = divider - I2caRegs.I2CCLKH; //low period

    I2caRegs.I2CMDR.bit.MST = 1; //enable master mode
    I2caRegs.I2CMDR.bit.TRX = 1; //enable transmitter mode
    I2caRegs.I2CMDR.bit.DLB = 0; //disable loopback
    I2caRegs.I2CMDR.bit.BC = 0; //8 bits per transmission
    I2caRegs.I2CMDR.bit.XA = 0; //7 bit addressing mode

    //disable fifo
    I2caRegs.I2CFFTX.bit.I2CFFEN = 0;
    I2caRegs.I2CFFTX.bit.TXFFRST = 0;
    I2caRegs.I2CFFRX.bit.RXFFRST = 0;

    //re-enable module
    I2caRegs.I2CMDR.bit.IRS = 1; //re-enable i2c module A

    EDIS;

}


bool i2c_master_tx(char dev_addr, const char *data, uint16_t data_length)
{

    uint16_t i = 0;
    uint32_t start_time = 0;


    I2caRegs.I2CMDR.bit.MST = 1; //enable master mode
    I2caRegs.I2CMDR.bit.TRX = 1; //enable transmitter mode

    I2caRegs.I2CCNT = data_length; //set amount of bytes to send
    I2caRegs.I2CSAR.bit.SAR = dev_addr; //set target slave address

    I2caRegs.I2CMDR.bit.STT = 1; //assert start condition




    for(i = 0; i < data_length; i++)
    {

        start_time = Clock_getTicks();

        // Wait for the transmit ready flag
        while (!I2caRegs.I2CSTR.bit.XRDY)
        {
            if(i2c_nack_check() || ((Clock_getTicks() - start_time) > I2C_TIMEOUT_MS))
                return false; //fail transaction if slave NACKs byte or does not ACK byte before I2C_TIMEOUT_MS
        }


        I2caRegs.I2CDXR.bit.DATA = data[i];

    }



    I2caRegs.I2CMDR.bit.STP = 1;//assert stop condition

    return true;


}

bool i2c_master_rx(char dev_addr, char *data, uint16_t data_length)
{
    uint16_t i = 0;
    uint32_t start_time = 0;

    i2c_init();

    I2caRegs.I2CMDR.bit.MST = 1; //enable master mode
    I2caRegs.I2CMDR.bit.TRX = 0; //enable receiver mode

    I2caRegs.I2CCNT = data_length; //set amount of bytes to send
    I2caRegs.I2CSAR.bit.SAR = dev_addr; //set target slave address

    I2caRegs.I2CMDR.bit.STT = 1; //assert start condition


    for (i = 0; i < data_length; i++)
    {

        start_time = Clock_getTicks();

        // Wait until data is received
        while (!I2caRegs.I2CSTR.bit.RRDY)
        {
            //check for NACK
            if (i2c_nack_check() || ((Clock_getTicks() - start_time) > I2C_TIMEOUT_MS))
                return false; //fail transaction if slave NACKs byte or does not ACK byte before I2C_TIMEOUT_MS

        }

        // If it's the last byte, send NACK before stopping
        if (i == (data_length - 2))
            I2caRegs.I2CMDR.bit.NACKMOD = 1;

        // Read the received data
        data[i] = (char)I2caRegs.I2CDRR.bit.DATA;

    }

    I2caRegs.I2CMDR.bit.STP = 1;//assert stop condition

    return true;
}

bool i2c_nack_check()
{
    if(I2caRegs.I2CSTR.bit.NACK) //check for NACK
    {

       //clear nack and data ready flags
       I2caRegs.I2CSTR.bit.NACK = 1;
       I2caRegs.I2CSTR.bit.XRDY = 1;
       I2caRegs.I2CMDR.bit.STP = 1;//assert stop condition

       return true;
    }

    return false;
}
