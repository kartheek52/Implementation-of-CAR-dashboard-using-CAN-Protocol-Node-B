#include <LPC21xx.h>
#include<stdio.h>
void timer_init(void);
typedef int s32;
typedef unsigned int u32;
typedef char s8;
typedef unsigned char u8;

void RTC_Init(void);
void RTC_set(void);
void RTC_get(unsigned int *hour, unsigned int *min, unsigned int *sec,unsigned int *dayOfMonth, unsigned int *month, unsigned int *year);

typedef struct CAN1_Frame{			//CAN structure
	u32 id;
	u32 dlc;
	u32 rtr;
	u32 byteA;
	u32 byteB;
}CAN1;

typedef struct data{
	u32 speed;
	u32 temp;
}D;

void CAN1_init(void);
void CAN1_Rx(CAN1 *ptr);
void Config_VIC_for_CAN1(void);
void CAN1_Rx_Handler(void) __irq ;
void display(void);

void delay_ms(unsigned int ms);
void lcd_data(u8 data);
void lcd_cmd(u8 cmd);
void lcd_init(void);
void lcd_print(u32 s,float t);
void lcd_string(u8 *p);

void uart0_init(u32 baud);
void uart0_tx(u8 data);
u8 uart0_rx(void);
void uart0_tx_string(s8 *ptr);
void uart0_rx_string(s8 *ptr,s32 len);
void uart0_tx_integer(int num);
void uart0_tx_float(float num);

