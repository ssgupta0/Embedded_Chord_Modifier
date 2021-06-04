/*	Author: lab
 *  Partner(s) Name: Shashvat Gupta
 *	Lab Section: 025
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include "timer.h"
#include "pwm.h"
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif




/**/


int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;	
	DDRB = 0xFF; PORTB = 0x00; 
	DDRD = 0xFF; PORTD = 0x00; 
	
// 	TimerSet(100);
// 	TimerOn();
	
		
	PWM_on0();
	PWM_on1();
	PWM_on2();
	PWM_on3();
    /* Insert your solution below */
    
    	
	
		
    while (1) {
// 	while(!TimerFlag);
	    //note();
	    set_PWM0(440);
	    set_PWM1(554.37);
	    set_PWM2(659.25);
	    set_PWM3(880);
	    
// 	    TimerFlag = 0;
    }
  	PWM_off0();
   	PWM_off1();
    	PWM_off2();
   	PWM_off3();
    
	return 1;
}
