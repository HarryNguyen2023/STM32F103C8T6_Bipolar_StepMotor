#ifndef STM32_UART_H
#define STM32_UART_H

#include "stm32f1xx_hal.h"
#include <string.h>

// Function prototypes
void STM32_UART_IDLE_Start(UART_HandleTypeDef* huart, DMA_HandleTypeDef* dma_huart, uint8_t* rcv_buffer, uint16_t size);
void STM32_UART_sendString(UART_HandleTypeDef* huart, uint8_t* tx_buffer);

#endif
