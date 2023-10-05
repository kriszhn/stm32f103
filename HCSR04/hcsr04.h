#ifndef HCSR04_H_
#define HCSR04_H_

#include "stm32f1xx_hal.h"

// Define the TRIG and ECHO pin numbers and ports
#define TRIG_PIN GPIO_PIN_9
#define TRIG_PORT GPIOA
#define ECHO_PIN GPIO_PIN_8
#define ECHO_PORT GPIOA

// Declare the distance measurement function
int DistanceMeasurement(void);

#endif /* HCSR04_H_ */
