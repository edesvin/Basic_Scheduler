/*
 * HAL.h
 *
 *  Created on: Nov 17, 2015
 *      Author: Robo
 */

#ifndef HAL_H_
#define HAL_H_


#include "MPC5606B.h"
#include "stdtypedef.h"
#include "IntcInterrupts.h"

#define ValTMR_0 		0x0000F9FF

void initModesAndClock(void);
void Init_ISR(void);
void Init_PIT(void);
void Init_PIT_CH0(uint32_t LDVALOR_0);
void init_GPIO(void);
void All_Init(void);

extern void ISR_Tick(void);

#endif /* HAL_H_ */
