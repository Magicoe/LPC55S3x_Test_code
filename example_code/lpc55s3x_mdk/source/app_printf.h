/*
 * Copyright (c) 2017 - 2021 , NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef __APP_PRINTF_H__
#define __APP_PRINTF_H__

#include <stdint.h>
#include <math.h>
#include <stdarg.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

#include "fsl_usart.h"
#include "fsl_iocon.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define DEBUG_BUFFER_SIZE          1024   /* Debug Uart Buffer Length */

#define PRINTF                     debug_printf

#define DEBUGTX_PORT               0u
#define DEBUGTX_PIN                29u
#define DEBUGTX_FUNC               IOCON_FUNC1

#define DEBUGRX_PORT               0u
#define DEBUGRX_PIN                30u
#define DEBUGRX_FUNC               IOCON_FUNC1

#define DEBUG_UART                 USART0
#define DEBUG_UART_TYPE            kSerialPort_Uart

#define DEBUG_UART_CLKFREQ         12000000U
#define DEBUG_UART_CLKATTACH       kFRO12M_to_FLEXCOMM0
#define DEBUG_UART_RST             kFC0_RST_SHIFT_RSTn
#define DEBUG_UART_CLKSRC          kCLOCK_Flexcomm0
#define DEBUG_UART_IRQHANDLER      FLEXCOMM0_IRQHandler
#define DEBUG_UART_IRQNUM          FLEXCOMM0_IRQn
#define DEBUG_UART_BAUDRATE        115200U


extern void     debug_init(uint32_t baudrate);
extern uint32_t debug_printf(const char *formatString, ...);

extern uint8_t  uart_getc(void);
extern void     uart_putc(uint8_t c);
extern void     uart_puts(char *str);

#endif

