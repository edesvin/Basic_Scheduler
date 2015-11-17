
#define Emain0 1
#if Emain0 == 1

/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: Kernel.c $
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
 * $Log: Kernel.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/

#include "kernel.h"

/* Constants and types  */
/*============================================================================*/
const S_STAT cas_STAT[E_TSK_N_OF] = {/*	Function Pointer	-	Period 	-	  Offset	*/
		
		{		Task_1,		101,		0		},
		{		Task_2,		211,		1		},
		{		Task_3,		409,		2		},
		{		Task_4,		797,		3		}
		
		/*	Add here your new task and a comma before the last one	*/			
		/*	{	Function Pointer	,	Period	,		Offset	}	*/	

};

/* Variables */
/*============================================================================*/
volatile T_UBYTE rub_Tick_Flag = 0;
volatile T_UWORD raub_DynConuter[E_TSK_N_OF];
/*============================================================================*/
void ISR_Tick(void){
	if( PIT.CH[0].TFLG.B.TIF ){
		
		PIT.CH[0].TFLG.B.TIF = 1;
		rub_Tick_Flag = 1;
		
	}
}
/*============================================================================*/
void main(void){

	T_UWORD luw_i;

	All_Init();
	Global_Init();

	while(1){

		if(rub_Tick_Flag){
			
			rub_Tick_Flag = 0;

			for(luw_i = 0; luw_i < E_TSK_N_OF; luw_i++){
				
				if(raub_DynConuter[luw_i] > 0){
					raub_DynConuter[luw_i]--;
					
				}
				else{
					
					raub_DynConuter[luw_i] = cas_STAT[luw_i].uw_T;
					(cas_STAT[luw_i].F_Pointer)();
					
				}
				
			}

		}
		
	}

}

#endif


