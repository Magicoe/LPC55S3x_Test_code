/*
 * Copyright (c) 2017 - 2021 , NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "clock_config.h"
#include "app_led.h"
#include "app_printf.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Main function
 */
int main(void)
{
    /* Init board hardware. */
    BOARD_BootClockFRO12M();
    led_init();
    debug_init(115200);
    PRINTF("Hello LPC55S3x\r\n");
    while (1)
    {
        led_toggle(LEDR_NUM);
        SDK_DelayAtLeastUs(50000U, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
    }
}

// end file
