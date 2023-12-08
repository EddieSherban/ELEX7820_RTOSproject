// Filename: F28379D_spi.c
// Description: SPI-A initialization
// Version: 1.0
// Target: TMS320F28379D
// Author: Felix Serban
// Date: 03 Dec 2023
// Modified:

#include "F28379D_spi.h"

void SPIa_init(void)
{
    EALLOW;

    // Enable SPIa clocks
    CpuSysRegs.PCLKCR8.bit.SPI_A = 1;
    ClkCfgRegs.LOSPCP.bit.LSPCLKDIV = 0; // Set LSPCLK equal to SYSCLK

    // Enable pull-up resistors for SPI pins
    GpioCtrlRegs.GPBPUD.bit.GPIO58 = 0;
    GpioCtrlRegs.GPBPUD.bit.GPIO59 = 0;
    GpioCtrlRegs.GPBPUD.bit.GPIO60 = 0;
    GpioCtrlRegs.GPBPUD.bit.GPIO61 = 0;

    // Set SPI pins to asynchronous input qualification
    GpioCtrlRegs.GPBQSEL2.bit.GPIO58 = 0b11;
    GpioCtrlRegs.GPBQSEL2.bit.GPIO59 = 0b11;
    GpioCtrlRegs.GPBQSEL2.bit.GPIO60 = 0b11;
    GpioCtrlRegs.GPBQSEL2.bit.GPIO61 = 0b11;

    // Configure SPI pins
    // ... Peripheral group mux 2
    GpioCtrlRegs.GPBGMUX2.bit.GPIO58 = 0b11;
    GpioCtrlRegs.GPBGMUX2.bit.GPIO59 = 0b11;
    GpioCtrlRegs.GPBGMUX2.bit.GPIO60 = 0b11;
    GpioCtrlRegs.GPBGMUX2.bit.GPIO61 = 0b11;

    // ... Mux 2
    GpioCtrlRegs.GPBMUX2.bit.GPIO58 = 0b11;
    GpioCtrlRegs.GPBMUX2.bit.GPIO59 = 0b11;
    GpioCtrlRegs.GPBMUX2.bit.GPIO60 = 0b11;
    GpioCtrlRegs.GPBMUX2.bit.GPIO61 = 0b11;

    EDIS;

    // Step 1. Clear the SPI Software Reset bit (SPISWRESET) to 0 to force the SPI to the reset state.
    SpiaRegs.SPICCR.bit.SPISWRESET = 0x0;

    // Step 2. Configure the SPI as desired:
    // � Select either master or slave mode (MASTER_SLAVE).
    SpiaRegs.SPICTL.bit.MASTER_SLAVE = 0; // SLAVE

    // � Choose SPICLK polarity and phase (CLKPOLARITY and CLK_PHASE).
    SpiaRegs.SPICCR.bit.CLKPOLARITY = 0;
    SpiaRegs.SPICTL.bit.CLK_PHASE = 0;

    // � Set the desired baud rate (SPIBRR).
    // No effect if in SLAVE mode. Keep in case MASTER is needed.
    SpiaRegs.SPIBRR.bit.SPI_BIT_RATE = 0x3;

    // � Enable high speed mode if desired (HS_MODE).
    SpiaRegs.SPICCR.bit.HS_MODE = 0x1;

    // � Set the SPI character length (SPICHAR).
    SpiaRegs.SPICCR.bit.SPICHAR = 0x7; // 8-bit mode

    // Set TALK mode

    SpiaRegs.SPICTL.bit.TALK = 0x1;
    // � Clear the SPI Flags (OVERRUN_FLAG, INT_FLAG).
    // Both cleared with SPISWRESET = 0

    // � Enable SPISTE inversion (STEINV) if needed.
    // Not needed.

    // � Enable 3-wire mode (TRIWIRE) if needed.
    // Not needed.

    // � If using FIFO enhancements:
    // � Enable the FIFO enhancements (SPIFFENA).
    // � Clear the FIFO Flags (TXFFINTCLR, RXFFOVFCLR, and RXFFINTCLR).
    // � Release transmit and receive FIFO resets (TXFIFO and RXFIFORESET).
    // � Release SPI FIFO channels from reset (SPIRST).
    // Not needed.

    // Step 3. If interrupts are used:
    // � In non-FIFO mode, enable the receiver overrun and/or SPI interrupts (OVERRUNINTENA
    // and SPIINTENA).
    SpiaRegs.SPICTL.bit.OVERRUNINTENA = 0x1;
    SpiaRegs.SPICTL.bit.SPIINTENA = 0x1;

    // � In FIFO mode, set the transmit and receive interrupt levels (TXFFIL and RXFFIL) then
    // enable the interrupts (TXFFIENA and RXFFIENA).
    // Not needed.

    // Step 4. Set SPISWRESET to 1 to release the SPI from the reset state.
    SpiaRegs.SPICCR.bit.SPISWRESET = 0x1;
}
