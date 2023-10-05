
#include "hcsr04.h"
extern TIM_HandleTypeDef htim1;

uint32_t pMillis;
uint32_t Value1 = 0;
uint32_t Value2 = 0;
uint16_t Distance = 0; // cm

int DistanceMeasurement(void) {
  // Pull the TRIG pin HIGH
  HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_SET);

  // Wait for 10 us
  __HAL_TIM_SET_COUNTER(&htim1, 0);
  while (__HAL_TIM_GET_COUNTER(&htim1) < 10);

  // Pull the TRIG pin low
  HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_RESET);

  // Get the current time
  pMillis = HAL_GetTick();

  // Wait for the echo pin to go high
  while (!(HAL_GPIO_ReadPin(ECHO_PORT, ECHO_PIN)) && pMillis + 10 > HAL_GetTick());

  // Get the time at which the echo pin goes high
  Value1 = __HAL_TIM_GET_COUNTER(&htim1);

  // Get the current time
  pMillis = HAL_GetTick();

  // Wait for the echo pin to go low
  while ((HAL_GPIO_ReadPin(ECHO_PORT, ECHO_PIN)) && pMillis + 50 > HAL_GetTick());

  // Get the time at which the echo pin goes low
  Value2 = __HAL_TIM_GET_COUNTER(&htim1);

  // Calculate the distance
  Distance = (Value2 - Value1) * 0.034 / 2;

  // Add a delay to avoid reading the sensor too frequently
  HAL_Delay(50);

  return Distance;
}
