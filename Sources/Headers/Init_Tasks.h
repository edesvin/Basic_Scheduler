/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: Init_Tasks.h $
 * $Revision: 1.0 $
 * $Author: Edgar Escayola Vinagre $
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
 * $Log: Init_Tasks.h  $
  ============================================================================*/
#ifndef INIT_TASK_H_
#define INIT_TASK_H_
/* Includes */
/*============================================================================*/
#include "stdtypedef.h"
#include "Tasks.h"
/* Constants and types */
/*============================================================================*/
typedef enum{
	E_TSK_TASK0,
	E_TSK_TASK1,
	E_TSK_TASK2,
	E_TSK_TASK3,
	
	/*Write here your new tasks*/
	
	E_TSK_N_OF
	
}E_TASKS;
/*============================================================================*/
typedef struct{
	void(*F_Pointer)(void);		/*	Function Pointer	*/	
	T_UWORD uw_T;				/* 	Period				*/
	T_UWORD uw_Offset;			/*	Offset				*/
	
}S_STAT;
/*============================================================================*/
extern const S_STAT cas_STAT[E_TSK_N_OF];
extern volatile T_UWORD raub_DynConuter[E_TSK_N_OF];
/*============================================================================*/
void Global_Init(void);

#endif /* INIT_TASK_H_ */
