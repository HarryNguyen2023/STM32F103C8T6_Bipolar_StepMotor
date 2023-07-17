#include "StepMotor.h"
#include "../util/DWT_Delay.h"

// Function to initiate the step motor module
void stepInit()
{
    // Enable the motor driver
    HAL_GPIO_WritePin(PORT, EN, 0);
    // Intiiate the direction of the motor
    HAL_GPIO_WritePin(PORT, DIR, 1);
    // Initiate the step pin
    HAL_GPIO_WritePin(PORT, STEP, 0);
}

// Function to stop the motor immediately
void brake()
{
    // Disable the motor driver
    HAL_GPIO_WritePin(PORT, EN, 1);
    // Initiate the step pin
    HAL_GPIO_WritePin(PORT, STEP, 0);
}

// Function to change the direction of the motor
void changeDir(uint8_t* cur_dir)
{
    *cur_dir =  1 - *cur_dir;
    // Change the state of the DIR pin
    HAL_GPIO_WritePin(PORT, DIR, *cur_dir);
}

// Function to change the speed of the motor
void speedCtrl(uint8_t com)
{
    switch (com)
    {
        case speed1:
            HAL_GPIO_WritePin(PORT, STEP, 0);
            DWT_Delay_us(1000);
            HAL_GPIO_WritePin(PORT, STEP, 1);
            DWT_Delay_us(1000);
            break;
        
        case speed2:
            HAL_GPIO_WritePin(PORT, STEP, 0);
            DWT_Delay_us(750);
            HAL_GPIO_WritePin(PORT, STEP, 1);
            DWT_Delay_us(750);
            break;
        
        case speed3:
            HAL_GPIO_WritePin(PORT, STEP, 0);
            DWT_Delay_us(500);
            HAL_GPIO_WritePin(PORT, STEP, 1);
            DWT_Delay_us(500);
            break;
    }
}

// Function to convert the input angle value into the number of the step required to move the motor
uint16_t angle2Step(uint16_t angle)
{
    if(angle > 65535)
        angle = 65535;
    return angle / RES;
}

// Function to control the position of the step motor 
void positionCtrl(uint16_t step)
{
    brake();
    stepInit();
    // Loop through the number of step
    for(uint16_t i = 0; i < step; ++i)
    {
        HAL_GPIO_WritePin(PORT, STEP, 0);
        DWT_Delay_us(500);
        HAL_GPIO_WritePin(PORT, STEP, 1);
        DWT_Delay_us(500);
    }
    return;
}