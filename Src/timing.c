#include "stm32f1xx_hal.h"

#include "timing.h"

void delay(uint32_t ms)
{
    uint32_t tickstart = HAL_GetTick();
    while((HAL_GetTick()-tickstart)<ms);
}
