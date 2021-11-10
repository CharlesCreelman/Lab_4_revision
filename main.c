// CONFIG1L
#pragma config FEXTOSC = HS     // External Oscillator mode Selection bits (HS (crystal oscillator) above 8 MHz; PFM set to high power)
#pragma config RSTOSC = EXTOSC_4PLL// Power-up default value for COSC bits (EXTOSC with 4x PLL, with EXTOSC operating per FEXTOSC bits)

// CONFIG3L
#pragma config WDTE = OFF        // WDT operating mode (WDT enabled regardless of sleep)

#include <xc.h>
#include <stdio.h>
#include "LCD.h"
#include "ADC.h"

#define _XTAL_FREQ 64000000 //note intrinsic _delay function is 62.5ns at 64,000,000Hz  

void main(void) {
    LCD_Init();  
    ADC_init();
    char buf[10];
    int x=0;
    
	
	LCD_setline(1); //Set Line 1
    
    //LCD_sendstring("Hello world how are you today?");  //Send string Hello to line 1
    
    while (1) {
        
        x = ADC_getval();
        sprintf(buf,"x = %d",x);
        LCD_sendstring(buf);
        
        __delay_ms(100);
        
        LCD_sendbyte(0b00000001, 0);
        
        __delay_ms(100);
    }
}

