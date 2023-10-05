#ifndef STPRMOTOR_H_
#define STPRMOTOR_H_

#include "stm32f1xx_hal.h"

// Define the stepper motor pin numbers and ports
#define IN1_PIN GPIO_PIN_6
#define IN1_PORT GPIOA
#define IN2_PIN GPIO_PIN_5
#define IN2_PORT GPIOA
#define IN3_PIN GPIO_PIN_4
#define IN3_PORT GPIOA
#define IN4_PIN GPIO_PIN_3
#define IN4_PORT GPIOA

// Declare the stepper motor functions
void microDelay(uint16_t delay);
void stepCCV(int steps, uint16_t delay); // CCV - Counter Clockwise
void stepCV(int steps, uint16_t delay); // CV - Clockwise

#endif /* STPRMOTOR_H_ */
