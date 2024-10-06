#include "header_nodeb.h"
//#include "data.h"
    unsigned int hour, min, sec,day, month, year;
		CAN1 i;
int main() {

	
    RTC_Init();
	  RTC_set();  // Set RTC initial time and date (e.g., 12:00:00 july 5, 2024)
		CAN1_init();
		Config_VIC_for_CAN1();
		lcd_init();
		uart0_init(9600);
	while (1) {
		u8 ch[15];
		RTC_get(&hour,&min, &sec,&day,&month, &year);         // Read RTC time
		display();																						// DD/MM/YY HH:MM:SS
		sprintf((char*)ch,"%d/%d/%d %d:%d:%d\n",day,month,year%100,hour,min,sec);
		uart0_tx_string((s8*)ch);
		lcd_cmd(0x80);
		lcd_string(ch);
    }
}
