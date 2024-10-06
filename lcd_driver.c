#include "header_nodeb.h"
void lcd_data(u8 data){
			u32 temp;
			IOCLR1=0x00FE0000;
			temp=(data&0xF0)<<16;
			IOSET1=temp;
			IOSET1=1<<17;
			IOCLR1=1<<18;
			IOSET1=1<<19;
			delay_ms(2);
			IOCLR1=1<<19;
	
			//Lower nibble
			temp=(data&0x0F)<<20;
			IOSET1=temp;
			IOSET1=1<<17;
			IOCLR1=1<<18;
			IOSET1=1<<19;
			delay_ms(2);
			IOCLR1=1<<19;
}

void lcd_cmd(u8 cmd){
			u32 temp;
			IOCLR1=0x00FE0000;
			temp=(cmd&0xF0)<<16;
			IOSET1=temp;
			IOCLR1=1<<17;
			IOCLR1=1<<18;
			IOSET1=1<<19;
			delay_ms(2);
			IOCLR1=1<<19;
	
			//Lower nibble
			temp=(cmd&0x0F)<<20;
			IOSET1=temp;
			IOCLR1=1<<17;
			IOCLR1=1<<18;
			IOSET1=1<<19;
			delay_ms(2);
			IOCLR1=1<<19;
}

void lcd_init(){
	IODIR1=0x00FE0000;
	PINSEL2=0x0;
	lcd_cmd(0x02);
	lcd_cmd(0x28);
	lcd_cmd(0x02);
}

void lcd_string(u8 *p){
	while(*p!=0){
		lcd_data(*p);
		p++;
	}
}

void lcd_print(u32 s,float t){
	u8 c[15];
	sprintf((char*)c,"S=%d T:%f\n",s,t); 
	uart0_tx_string((s8 *)c);
	lcd_cmd(0xC0);
	lcd_string(c);
}
