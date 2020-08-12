/*
 * UART.h
 *
 * Created: 04/12/41 12:51:37 م
 *  Author: ABDULLAH 01
 */ 


#ifndef UART_H_
#define UART_H_


#include "DIO.h"

void UART_INIT(void);

void UART_SenfByte(uint8 data);

void UART_SendString(uint8 *str);

char UART_RecieveByte(void);

void UART_RecieveString(void);

#endif /* UART_H_ */