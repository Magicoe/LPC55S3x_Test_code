/*
 * Copyright (c) 2017 - 2021 , NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "app_led.h"
#include "fsl_gpio.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
/**
 * @brief   Initialize GPIO
 * @param   NULL
 * @return  NULL
 */
void led_init(void)
{
    gpio_pin_config_t   gpioPinConfig;
    gpioPinConfig.pinDirection = kGPIO_DigitalOutput;
    gpioPinConfig.outputLogic  = 1u; /* output high as default. */
    
    GPIO_PinInit (GPIO, LEDR_PORT, LEDR_PIN, &gpioPinConfig);
}

/**
 * @brief   设置LED对应IO状态
 * @param   num   - LED号
 * @param   value - 设置0、1
 * @return  NULL
 */
void led_set(uint32_t num, uint8_t value)
{
    if(num == LEDR_NUM)
    {
        GPIO_PinWrite(GPIO, LEDR_PORT, LEDR_PIN, value);
    }
}

/**
 * @brief   翻转LED IO的状态
 * @param   num - LED号
 * @return  NULL
 */
void led_toggle(uint32_t num)
{
    if(num == LEDR_NUM)
    {
        GPIO_PortToggle(GPIO, LEDR_PORT, 1 << LEDR_PIN);
    }
}

// end file - 文件结束
