/*uart0_driver.c*/
#include <LPC21xx.H>
#include "header_nodeb.h"

void uart0_init(u32 baud){
	int a[]={15,60,30,15,15};
	u32 result=0;
	u32 pclk=a[VPBDIV]*1000000;
	result=pclk/(16*baud);
	
	PINSEL0|=0x5;//P0.0->TXD0,P0.1->RXD0
	U0LCR=0x83;//8N1,DLAB=1
	U0DLL=result&0xFF;
	U0DLM=(result>>8)&0xFF;
	U0LCR=0x03;//8N1,DLAB=0	
}

#define THRE ((U0LSR>>5)&1)
void uart0_tx(u8 data){
	U0THR=data;
	while(THRE==0);
}


#define RDR (U0LSR&1)
u8 uart0_rx(void){
	while(RDR==0);//waiting for data-receive
	return U0RBR;
}

void uart0_tx_string(s8 *ptr){
	while(*ptr!=0){
		U0THR=*ptr;
		while(THRE==0);
		//delay_ms(10);
		ptr++;
	}
}



#include <stdio.h>
void uart0_tx_integer(int num){
	char a[10];
	sprintf(a,"%d",num);
	uart0_tx_string(a);
}

void uart0_tx_float(float num){
	char a[10];
	sprintf(a,"%.1f",num);
	uart0_tx_string(a);
}
