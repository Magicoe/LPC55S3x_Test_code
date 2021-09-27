/*
 * Copyright (c) 2017 - 2018 , NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "app_printf.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
 
/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
 
volatile uint8_t  g_DebugTxBuf[DEBUG_BUFFER_SIZE];
volatile uint16_t g_DebugTxIndex = 0;                   /* Index of the memory to save new arrived data. */

volatile uint8_t  g_DebugRxBuf[DEBUG_BUFFER_SIZE];
volatile uint16_t g_DebugRxIndex = 0;                   /* Index of the memory to save new arrived data. */

/*******************************************************************************
 * Code
 ******************************************************************************/

/**
 * @brief   Flexcomm Interrupt Handler
 * @param   NULL
 * @return  NULL
 */
void DEBUG_UART_IRQHANDLER(void)
{
    uint8_t data;
    /* If new data arrived. */
    if ((kUSART_RxFifoNotEmptyFlag | kUSART_RxError) & USART_GetStatusFlags(DEBUG_UART))
    {
        data = USART_ReadByte(DEBUG_UART);
        
        /* If ring buffer is not full, add data to ring buffer. */
    }
}



void debug_init(uint32_t baudrate)
{
    usart_config_t      config;
    
    /* 使能IO控制器的时钟 */
    CLOCK_EnableClock(kCLOCK_Iocon);
    // Debug Usart Pin Init
    IOCON->PIO[DEBUGTX_PORT][DEBUGTX_PIN] = (DEBUGTX_FUNC  | IOCON_MODE_INACT  | IOCON_DIGITAL_EN );  // Debug Usart TXD pin,            PIO0_2  - FC3_TXD_SCL_MISO_WS
    IOCON->PIO[DEBUGRX_PORT][DEBUGRX_PIN] = (DEBUGRX_FUNC  | IOCON_MODE_INACT  | IOCON_DIGITAL_EN );  // Debug Usart TXD pin,            PIO0_2  - FC3_TXD_SCL_MISO_WS
    /* 使能IO控制器的时钟 */
    CLOCK_DisableClock(kCLOCK_Iocon);
    /*
     * config.baudRate_Bps = 115200U;
     * config.parityMode = kUSART_ParityDisabled;
     * config.stopBitCount = kUSART_OneStopBit;
     * config.loopback = false;
     * config.enableTx = false;
     * config.enableRx = false;
     */
    CLOCK_AttachClk(DEBUG_UART_CLKATTACH);
    USART_GetDefaultConfig(&config);
    config.baudRate_Bps = baudrate;
    config.enableTx = true;
    config.enableRx = true;

    USART_Init(DEBUG_UART, &config, 12000000);
    /* Enable RX interrupt. */
    USART_EnableInterrupts(DEBUG_UART, kUSART_RxLevelInterruptEnable | kUSART_RxErrorInterruptEnable);
    NVIC_EnableIRQ(DEBUG_UART_IRQNUM);
}

/**
 * @brief   debug printf function
 * @param   string
 * @return  length
 */
/* See fsl_debug_console.h for documentation of this function. */
uint32_t debug_printf(const char *formatString, ...)
{
    va_list arg;
    uint32_t logLength = 0U, result = 0U;
    uint8_t *PrintBuf = NULL;
    PrintBuf = malloc(512);                                               /* malloc buffer */
    if(PrintBuf == NULL) {
//        PRINTF("Malloc BLE printf buffer failed\r\n");                    /*  */
        NVIC_SystemReset();                                               /* Can not malloc enough buffer, should be system issue, reset~ */
    }
    va_start(arg, formatString);
    logLength = vsprintf((char *)PrintBuf, formatString, arg);            /* format print log first */
    va_end(arg);
    USART_WriteBlocking(DEBUG_UART, PrintBuf, logLength);                /* Send Log data to BLE uart */
    free(PrintBuf);                                                       /* free buffer */
    return result;
}

/**
 * @brief   uart_getc
 * @param   NULL
 * @return  NULL
 */
uint8_t uart_getc(void)
{
    uint8_t c = 0;
    return c;
}

/**
 * @brief   uart_getc
 * @param   NULL
 * @return  NULL
 */
void uart_putc(uint8_t c)
{
    USART_WriteBlocking(DEBUG_UART, &c, 1);
}

/**
 * @brief   uart_getc
 * @param   NULL
 * @return  NULL
 */
void uart_puts(char *str)
{
    while (*str) {
        uart_putc(*str++);
    }
}


// end file
