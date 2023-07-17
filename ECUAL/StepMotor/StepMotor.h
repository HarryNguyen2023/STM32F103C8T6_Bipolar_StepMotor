// Header file for application of step motor
// Author Harry Nguyen (07/16/2023)

#ifndef STEP_MOTOR
#define STEP_MOTOR

#include "stm32f1xx_hal.h"
#include "../util/DWT_Delay.h"

// Define the resolution of the step motor
#define RES 1.8

// Define the pins connect to the motor driver
#define PORT GPIOB
#define EN GPIO_PIN_3
#define DIR GPIO_PIN_5
#define STEP GPIO_PIN_4
#define STOP GPIO_PIN_6

// Define command to control the step motor
enum COMMAND
{
    direc = 48,
    speed1 = 49,
    speed2 = 50,
    speed3 = 51
};

// Define the mode for operation of the step motor
enum MODE
{
    speed = 1,
    pos = 2
};

void stepInit(void);
void brake(void);
void changeDir(uint8_t* cur_dir);
void speedCtrl(uint8_t com);
uint16_t angle2Step(uint16_t angle);
void positionCtrl(uint16_t step);

#endif