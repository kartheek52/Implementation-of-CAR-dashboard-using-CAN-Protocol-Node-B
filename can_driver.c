#include "header_nodeb.h"
#define RBR (C1GSR&1)
void CAN1_init(void){			//CAN1 initialization with 60MHZ
VPBDIV=1;
PINSEL1|=0X00040000;
C1MOD=1;
C1BTR=0X001C001D;
AFMR=2;
C1MOD=0;
}
 
 void CAN1_Rx(CAN1 *ptr){
	 while(RBR==0)
		 ptr->id=C1RID;
		 ptr->rtr=(C1RFS>>30)&1;
	   ptr->dlc=(C1RFS>>16)&0xF;
	 if(ptr->rtr==0){
		 ptr->byteA=C1RDA;
		 ptr->byteB=C1RDB;
	 }
	 C1CMR=(1<<2);
}

