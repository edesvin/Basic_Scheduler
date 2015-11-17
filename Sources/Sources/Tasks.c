/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: filename.c $
 * $Revision: version $
 * $Author: author $
 * $Date: date $
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
 * $Log: filename.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "Tasks.h"
/*============================================================================*/
void Task_1(void){

	SIU.GPDO[68].B.PDO = !SIU.GPDO[68].B.PDO;

}

void Task_2(void){

	SIU.GPDO[69].B.PDO = !SIU.GPDO[69].B.PDO;

}

void Task_3(void){

	SIU.GPDO[70].B.PDO = !SIU.GPDO[70].B.PDO;

}

void Task_4(void){

	SIU.GPDO[71].B.PDO = !SIU.GPDO[71].B.PDO;

}
