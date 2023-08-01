# STM32F103C8T6_Bipolar_StepMotor
# Auhtor Harry Nguyen (Created 07/16/2023)

This is the project to control the bipolar step motor, using STM32 ARM from the computer. In this project, I have decided to use the A4988 step motor driver to facilitate the control algorithm, that I only need to use the GPIO pins to control the direction and speed of the motor

Besides, during this project, I have tried to use the STM32cubeMX + VSCode IDE + Makefile, for better programming experiment than the common KeilC or STM32CubeIDE, and I have suceesfully configure the environment set up for VSCode to programming and debugging the STMF103C8T6 using openOCD debug interface.

Moreover, I also succeedded using the IDLE line detection property of the STM32 chip to receive the data using UART whithout knowing the specific data length, which is a considerable advance of my study about ATM32 ARM.

### References
[1]. Khaleg Magdy, STM32 ARM tutorials, https://deepbluembedded.com/stm32-arm-programming-tutorials/.

[2]. UART DMA with IDLE Line Detection, https://controllerstech.com/uart-dma-with-idle-line-detection/.


