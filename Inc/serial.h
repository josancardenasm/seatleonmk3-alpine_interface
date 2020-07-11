

#include <stdbool.h>
#include "stm32f1xx_hal.h"

bool serial_sendData(UART_HandleTypeDef *handler, const char *msg, size_t size);
bool serial_sendData_timeout(UART_HandleTypeDef *handler, const char *msg, size_t size, uint32_t timeout );
bool serial_printf(UART_HandleTypeDef *handler, const char *msg, ...);
bool serial_printf_timeout(UART_HandleTypeDef *handler, uint32_t timeout , const char *format , ...);