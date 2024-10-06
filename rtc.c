#include "header_nodeb.h"


void RTC_Init(void) {
    // Enable RTC
    CCR |= (1 << 0);
    // Set prescaler values for 15MHz clock tick
    PREINT = 456;      
    PREFRAC = 25024; 
}

// Set RTC date & time
void RTC_set(){
	   HOUR=12;
	   MIN=0;
	   SEC=0;
	   DOM=5;
	   MONTH=7;
	   YEAR=2024;

}

// Get RTC date & time
void RTC_get(unsigned int *hour, unsigned int *min, unsigned int *sec,unsigned int *dayOfMonth, unsigned int *month, unsigned int *year){
    *hour = HOUR;
    *min = MIN;
    *sec = SEC;
	*dayOfMonth = DOM;
    *month = MONTH;
    *year = YEAR;
}


