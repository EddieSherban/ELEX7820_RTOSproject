// Filename:            F28379D_i2c.h
//
// Description:         I2C setup with functions
//
// Version:             1.0
//
// Target:              TMS320F28379D
//
// Author:              Eddie Sherban
//
// Date:                Nov 25, 2023

#ifndef _28379D_I2C_H_
#define _28379D_I2C_H_

//C standard library includes
#include <ctype.h>

//TI includes
#include <Headers/F2837xD_device.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>

#define SYS_CLK_FREQ 200000000UL //system clock frequency
#define SCLK_FREQ 100000UL //desired i2c sclk frequency
#define D 5UL //Delay val d for divide-down (see Table 20-1, t.ref manual)
#define I2C_TIMEOUT_MS 5U //amount of time slave device has to ack a byte before transaction is considered failed in ms
/*
 * Function: i2c_init
 * -----------------------
 * Brief: initializes I2C module with SCLK of 400kHz
 *
 * Parameters:
 *   - param1: Description of the first parameter.
 *   - param2: Description of the second parameter.
 *
 * Returns:
 *   Description of the return value (if any).
 */
void i2c_init();

/*
 * Function: i2c_master_tx
 * -----------------------
 * Brief: send command buffer over I2C to slave device...
 * can input device address, data, data length in bytes
 *
 * Parameters:
 *   - param1: Description of the first parameter.
 *   - param2: Description of the second parameter.
 *
 * Returns:
 *   Description of the return value (if any).
 */
bool i2c_master_tx(char dev_addr, const char *data, uint16_t data_length);

/*
 * Function: i2c_master_rx
 * -----------------------
 * Brief: receive byutes from slave device by doing a read.
 *
 * Parameters:
 *   - param1: Description of the first parameter.
 *   - param2: Description of the second parameter.
 *
 * Returns:
 *   Description of the return value (if any).
 */
bool i2c_master_rx(char dev_addr, char *data, uint16_t data_length);


/*
 * Function: function_name
 * -----------------------
 * Brief: Brief description of the function.
 *
 * Parameters:
 *   - param1: Description of the first parameter.
 *   - param2: Description of the second parameter.
 *
 * Returns:
 *   Description of the return value (if any).
 */
static bool i2c_nack_check();


#endif /* _28379D_I2C_H_ */
