#include "header_nodeb.h"
u32 s;
float t,j;
CAN1 v1;

void CAN1_Rx_Handler(void) __irq {
    v1.id = C1RID;
    v1.rtr = (C1RFS >> 30) & 1;
    v1.dlc = (C1RFS >> 16) & 0xF;
    if (v1.rtr == 0) {
        v1.byteA = C1RDA;
        v1.byteB = C1RDB;
    }
    C1CMR = (1 << 2);
    
    if (v1.id == 0x19) {
        s = v1.byteA | (v1.byteB << 16);
    }else if (v1.id == 0x64) {
				j=v1.byteB;
 				t	=	v1.byteA+(j/100);
    }
		VICVectAddr = 0;
}

void Config_VIC_for_CAN1(void) {
    VICIntSelect = 0;
    VICVectAddr3 = (u32)CAN1_Rx_Handler;
    VICVectCntl3 = 26 | (1 << 5);
    VICIntEnable |= (1 << 26);
    C1IER = 1;
}

void display() {
    lcd_print(s, t);
}
