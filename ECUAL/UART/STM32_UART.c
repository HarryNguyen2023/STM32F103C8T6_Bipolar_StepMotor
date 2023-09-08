#include "STM32_UART.h"

// Function to start idle line detection for receiving message via UART
void STM32_UART_IDLE_Start(UART_HandleTypeDef* huart, DMA_HandleTypeDef* dma_huart, uint8_t* rcv_buffer, uint16_t size)
{
    // Configure the USART DMA module
    HAL_UARTEx_ReceiveToIdle_DMA(huart, rcv_buffer, size);
    // Disable the half transfer interrupt
    __HAL_DMA_DISABLE_IT(dma_huart, DMA_IT_HT);
}

// Function to transmit message via UART
void STM32_UART_sendString(UART_HandleTypeDef* huart, uint8_t* tx_buffer)
{
    HAL_UART_Transmit(huart, tx_buffer, strlen((char*)tx_buffer), 100);
}
