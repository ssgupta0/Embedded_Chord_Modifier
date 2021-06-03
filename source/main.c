/*	Author: lab
 *  Partner(s) Name: Shashvat Gupta
 *	Lab Section:
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



//PB7
void set_PWM1(double frequency) {
    static double current_frequency;

    if (frequency != current_frequency) {
        if(!frequency)
            TCCR3B &= 0x08;
        else
            TCCR3B |= 0x03;

        if(frequency < 0.954)
            OCR3B = 0xFFFF;
        else if (frequency > 31250)
            OCR3B = 0x0000;
        else
            OCR3B = (short) (8000000 / (128 * frequency)) - 1;
        
        TCNT3 = 0;
        current_frequency = frequency;
   }
}

void PWM_on1() {
    TCCR3A = (1 << COM3A0);
    TCCR3B = (1 << WGM32) | (1 << CS31) | (1 << CS30);
    set_PWM1(0);
}

void PWM_off1() {
    TCCR3A = 0x00;
    TCCR3B = 0x00;
}


//PB6
void set_PWM2(double frequency) {
    static double current_frequency;

    if (frequency != current_frequency) {
        if(!frequency)
            TCCR3B &= 0x08;
        else
            TCCR3B |= 0x03;

        if(frequency < 0.954)
            OCR3A = 0xFFFF;
        else if (frequency > 31250)
            OCR3A = 0x0000;
        else
            OCR3A = (short) (8000000 / (128 * frequency)) - 1;
        
        TCNT3 = 0;
        current_frequency = frequency;
   }
}

void PWM_on2() {
    TCCR3A = (1 << COM3A0);
    TCCR3B = (1 << WGM32) | (1 << CS31) | (1 << CS30);
    set_PWM2(0);
}

void PWM_off2() {
    TCCR3A = 0x00;
    TCCR3B = 0x00;
}


//PD7
void set_PWM3(double frequency) {
    static double current_frequency;

    if (frequency != current_frequency) {
        if(!frequency)
            TCCR3B &= 0x08;
        else
            TCCR3B |= 0x03;

        if(frequency < 0.954)
            OCR2A = 0xFFFF;
        else if (frequency > 31250)
            OCR2A = 0x0000;
        else
            OCR2A = (short) (8000000 / (128 * frequency)) - 1;
        
        TCNT3 = 0;
        current_frequency = frequency;
   }
}

void PWM_on3() {
    TCCR0A = (1 << COM0B1);
    TCCR0B = (1 << WGM32) | (1 << CS31) | (1 << CS30);
    set_PWM3(0);
}

void PWM_off3() {
    TCCR3A = 0x00;
    TCCR3B = 0x00;
}

//PB3
void set_PWM4(double frequency) {
    static double current_frequency;

    if (frequency != current_frequency) {
        if(!frequency)
            TCCR3B &= 0x08;
        else
            TCCR3B |= 0x03;

        if(frequency < 0.954)
            OCR2B = 0xFFFF;
        else if (frequency > 31250)
            OCR2B = 0x0000;
        else
            OCR2B = (short) (8000000 / (128 * frequency)) - 1;
        
        TCNT3 = 0;
        current_frequency = frequency;
   }
}

void PWM_on4() {
    TCCR0A = (1 << COM0A0);
    TCCR0B = (1 << WGM02) | (1 << CS01) | (1 << CS00);
    set_PWM4(0);
}

void PWM_off4() {
    TCCR3A = 0x00;
    TCCR3B = 0x00;
}

/**/


int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;	
	DDRB = 0xFF; PORTB = 0x00; 
	
	TimerSet(100);
	TimerOn();
	
		
	PWM_on1();
	PWM_on2();
    /* Insert your solution below */
    
    	
	
		
    while (1) {
	while(!TimerFlag);
	    //note();
	    set_PWM1(440);
	    set_PWM2(554.37);
	    set_PWM3(659.25);
	    set_PWM4(880);
	    
	    TimerFlag = 0;
    }
    PWM_off1();
    PWM_off2();
    
	return 1;
}
