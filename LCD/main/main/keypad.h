/*
 * keypad.h
 *
 * Created: 29/11/41 12:16:34 ص
 *  Author: ABDULLAH 01
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "keypad_Cfg.h"

void Keypad_Init(void);

uint8 Keypad_GetValue(void);

uint8 Keypad_GetPass(uint8 pass_Cha);



#endif /* KEYPAD_H_ */