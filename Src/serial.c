#include "serial.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>


#define SERIAL_INFINITE_TIMEOUT HAL_MAX_DELAY

bool serial_sendData(UART_HandleTypeDef *handler, const char *msg, size_t size)
{
    int ret=HAL_UART_Transmit(handler,(uint8_t *) msg, strlen(msg), SERIAL_INFINITE_TIMEOUT);
    return (ret == HAL_OK);
}

bool serial_sendData_timeout(UART_HandleTypeDef *handler, const char *msg, size_t size, uint32_t timeout )
{
    int ret=HAL_UART_Transmit(handler,(uint8_t *) msg, strlen(msg), timeout);
    return (ret == HAL_OK);
}

bool serial_printf(UART_HandleTypeDef *handler, const char *format, ...)
{
    char buffer[512];
    va_list args;
    va_start (args, format);
    vsprintf (buffer,format, args);
    int ret=HAL_UART_Transmit(handler,(uint8_t *) buffer, strlen(buffer), SERIAL_INFINITE_TIMEOUT);
    va_end (args);
    return (ret == HAL_OK);
}

bool serial_printf_timeout(UART_HandleTypeDef *handler, uint32_t timeout ,const char *format , ...)
{
    char buffer[512];
    va_list args;
    va_start (args, format);
    vsprintf (buffer,format, args);
    int ret=HAL_UART_Transmit(handler,(uint8_t *) buffer, strlen(buffer), timeout);
    va_end (args);
    return (ret == HAL_OK);
}
