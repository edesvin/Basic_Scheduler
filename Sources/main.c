#include "MPC5606B.h"
#include "stdtypedef.h"
#include "IntcInterrupts.h"

#define PB_UP		SIU.GPDI[64].B.PDI
#define PB_DOWN 	SIU.GPDI[66].B.PDI
#define PB_AnPi 	SIU.GPDI[67].B.PDI

#define ValTMR_0 		0x0000F9FF

volatile T_UBYTE rub_TickFlag = 0;



typedef enum{
				E_TSK_TASK0,
				E_TSK_TASK1,
				E_TSK_TASK2,
				E_TSK_TASK3,
		
				/*Write here your new tasks*/
				
				E_TSK_N_OF
}E_TASKS;

typedef struct{
	void (*FuncPtr)(void);	/*	Function Pointer	*/	
	T_UWORD T;				/* 	Period				*/
	T_UWORD offset;			/*	Offset				*/
}S_STAT;

void task1(void);

void task2(void);

void task3(void);

void task4(void);

const S_STAT cas_stat[E_TSK_N_OF] = { /*	Function Pointer	-	Period 	-	  Offset	*/
										{	task1				,	5000		,		0		},
										{	task2				,	1000		,		1		},										
										{	task3				,	2000		,		2		},											
										{	task4				,	3000		,		3		}		

									/*	Add here your new task and a comma before the last one	*/			
									/*	{	Function Pointer	,	Period	,		Offset	}	*/										
				
};

volatile T_UWORD raub_dynCounter[E_TSK_N_OF];


void task1(void){
	
	SIU.GPDO[68].B.PDO = !SIU.GPDO[68].B.PDO;

}


void task2(void){

	SIU.GPDO[69].B.PDO = !SIU.GPDO[69].B.PDO;

}


void task3(void){

	SIU.GPDO[70].B.PDO = !SIU.GPDO[70].B.PDO;

}


void task4(void){

	SIU.GPDO[71].B.PDO = !SIU.GPDO[71].B.PDO;

}




void isr(void){
	if( PIT.CH[0].TFLG.B.TIF ){
		rub_TickFlag = 1;
		PIT.CH[0].TFLG.B.TIF = 1;
	}
}
void initModesAndClock(void) {
	ME.RUN[0].R = 0x001F0074;
	ME.RUNPC[0].R = 0x000000FE;
	ME.MCTL.R = 0x40005AF0;
	ME.MCTL.R = 0x4000A50F; 
}

/******************************************************************************/
void initPIT(uint32_t LDVALOR_0){

	PIT.PITMCR.B.MDIS = 0;			//Enable Clock for PIT
	PIT.PITMCR.B.FRZ = 1;			//Detiene el timer en modo debuger
	PIT.CH[0].LDVAL.R = LDVALOR_0;	//Carga el valor con el que se desbordara el timer
	PIT.CH[0].TCTRL.B.TEN = 1;		//Habilita el timer
	PIT.CH[0].TCTRL.B.TIE = 1;		//Habilita interrupcion del timer
	PIT.CH[0].TFLG.B.TIF = 1;
}
/******************************************************************************/

void initGPIO(void){
	T_UWORD luw_i;
	
	for(luw_i = 68; luw_i <=71; luw_i++) 
		SIU.PCR[luw_i].R = 0x0200;
	
	for(luw_i = 68; luw_i <= 71; luw_i++) 
		SIU.GPDO[luw_i].B.PDO = 1;

}

void global_init(void){
	T_UBYTE lub_i;

	initModesAndClock();
	
	INTC_InstallINTCInterruptHandler(isr,59,1);
	INTC.CPR.R = 0;
	
	initGPIO();

	initPIT(ValTMR_0);

	for(lub_i = 0; lub_i < E_TSK_N_OF; lub_i++){
		raub_dynCounter[lub_i] = cas_stat[lub_i].offset;
	}
	
}
void main (void) {
	T_UBYTE lub_i;

	global_init();
	
	while (1) {
			
		if(rub_TickFlag){
			rub_TickFlag = 0;		
			for(lub_i = 0; lub_i < E_TSK_N_OF; lub_i++){
				if( raub_dynCounter[lub_i] > 0){
					raub_dynCounter[lub_i]--;
				}else{
					(cas_stat[lub_i].FuncPtr)();
					raub_dynCounter[lub_i] = cas_stat[lub_i].T;
				}
			}
		}
			
	}/* End While(1) */
	
}

