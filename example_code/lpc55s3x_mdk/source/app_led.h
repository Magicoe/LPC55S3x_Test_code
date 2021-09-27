/*
 * Copyright (c) 2017 - 2021 , NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __APP_LED_H__
#define __APP_LED_H__

#include <stdint.h>

#include "fsl_common.h"
#include "fsl_iocon.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define LEDR_PORT                  1u
#define LEDR_PIN                   0u
#define LEDR_FUNC                  (IOCON_FUNC0 | IOCON_MODE_PULLUP | IOCON_DIGITAL_EN)

#define LEDR_NUM                   1u

extern void led_init(void);
extern void led_set(uint32_t num, uint8_t value);
extern void led_toggle(uint32_t num);

#endif
