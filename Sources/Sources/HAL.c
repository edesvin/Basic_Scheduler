/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: HAL.c $
 * $Revision: 1.0 $
 * $Author: author $
 * $Date: 17-11-2015 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    short description in one sentence end with dot.
    detailed
    multiline
    description of the file
*/
/*============================================================================*/
/* COPYRIGHT (C) CONTINENTAL AUTOMOTIVE 2014                                  */
/* AUTOMOTIVE GROUP, Interior Division, Body and Security                     */
/* ALL RIGHTS RESERVED                                                        */
/*                                                                            */
/* The reproduction, transmission, or use of this document or its content is  */
/* not permitted without express written authority. Offenders will be liable  */
/* for damages.                                                               */
/* All rights, including rights created by patent grant or registration of a  */
/* utility model or design, are reserved.                                     */
/*                                                                            */
/*============================================================================*/
/*============================================================================*/
/*                    REUSE HISTORY - taken over from                         */
/*============================================================================*/
/*  DATABASE           |        PROJECT     | FILE VERSION (AND INSTANCE)     */
/*----------------------------------------------------------------------------*/
/*                     |                    |                                 */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: HAL.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "HAL.h"
/*============================================================================*/
void initModesAndClock(void){

	ME.RUN[0].R = 0x001F0074;
	ME.RUNPC[0].R = 0x000000FE;
	ME.MCTL.R = 0x40005AF0;
	ME.MCTL.R = 0x4000A50F; 

}
/*============================================================================*/
void Init_ISR(void){
	
	INTC_InstallINTCInterruptHandler(ISR_Tick,59,1);
	INTC.CPR.R = 0;

}
/*============================================================================*/
void Init_PIT(void){
	
	PIT.PITMCR.B.MDIS = 0;			//Enable Clock for PIT
	PIT.PITMCR.B.FRZ = 1;			
	
}
/*============================================================================*/
void Init_PIT_CH0(uint32_t LDVALOR_0){

	PIT.CH[0].LDVAL.R = LDVALOR_0;	
	PIT.CH[0].TCTRL.B.TEN = 1;		
	PIT.CH[0].TCTRL.B.TIE = 1;		
	PIT.CH[0].TFLG.B.TIF = 1;
	
}
/*============================================================================*/
void init_GPIO(void){
	
	T_UWORD luw_i;
	for(luw_i = 68; luw_i <=71; luw_i++) SIU.PCR[luw_i].R = 0x0200;
	for(luw_i = 68; luw_i <= 71; luw_i++) SIU.GPDO[luw_i].B.PDO = 1;

}
/*============================================================================*/
void All_Init(void){
	
	initModesAndClock();
	Init_PIT();
	Init_ISR();
	init_GPIO();
	Init_PIT_CH0(ValTMR_0);

}
