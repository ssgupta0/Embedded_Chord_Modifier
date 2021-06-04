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

#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif



//PB3
void set_PWM0(double frequency) {
    static double current_frequency;

    if (frequency != current_frequency) {
            TCCR0B |= 0x03;
	    
            OCR0A = (short) (8000000 / (128 * frequency)) - 1;
        
        TCNT0 = 0;
        current_frequency = frequency;
   }
}

void PWM_on0() {
    TCCR0A = (1 << COM0A0);
    TCCR0B = (1 << WGM02) | (1 << CS01) | (1 << CS00);
    set_PWM0(0);
}

void PWM_off0() {
    TCCR0A = 0x00;
    TCCR0B = 0x00;
}

//----------------------

//PD7
void set_PWM1(double frequency) {
    static double current_frequency;

    if (frequency != current_frequency) {
            TCCR1B |= 0x03;
	    
            OCR1A = (short) (8000000 / (128 * frequency)) - 1;
        
        TCNT1 = 0;
        current_frequency = frequency;
   }
}

void PWM_on1() {
    TCCR1A = (1 << COM1A0);
    TCCR1B = (1 << WGM12) | (1 << CS11) | (1 << CS10);
    set_PWM1(0);
}

void PWM_off1() {
    TCCR1A = 0x00;
    TCCR1B = 0x00;
}

//----------------------

//PD5
void set_PWM2(double frequency) {
    static double current_frequency;

    if (frequency != current_frequency) {
            TCCR2B |= 0x03;
	    
            OCR2A = (short) (8000000 / (128 * frequency)) - 1;
        
        TCNT2 = 0;
        current_frequency = frequency;
   }
}

void PWM_on2() {
    TCCR2A = (1 << COM2A0);
    TCCR2B = (1 << WGM22) | (1 << CS21) | (1 << CS20);
    set_PWM0(0);
}

void PWM_off2() {
    TCCR2A = 0x00;
    TCCR2B = 0x00;
}

//----------------------

//PB6
void set_PWM3(double frequency) {
    static double current_frequency;

    if (frequency != current_frequency) {
            TCCR3B |= 0x03;
	    
            OCR3A = (short) (8000000 / (128 * frequency)) - 1;
        
        TCNT3 = 0;
        current_frequency = frequency;
   }
}

void PWM_on3() {
    TCCR3A = (1 << COM3A0);
    TCCR3B = (1 << WGM32) | (1 << CS31) | (1 << CS30);
    set_PWM0(0);
}

void PWM_off3() {
    TCCR3A = 0x00;
    TCCR3B = 0x00;
}
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
