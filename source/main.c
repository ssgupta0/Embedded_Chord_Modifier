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
//         if(!frequency)
//             TCCR3B &= 0x08;
//         else
            TCCR3B |= 0x03;

//         if(frequency < 0.954)
//             OCR3B = 0xFFFF;
//         else if (frequency > 31250)
//             OCR3B = 0x0000;
//         else
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
//         if(!frequency)
//             TCCR3B &= 0x08;
//         else
            TCCR3B |= 0x03;

//         if(frequency < 0.954)
//             OCR3A = 0xFFFF;
//         else if (frequency > 31250)
//             OCR3A = 0x0000;
//         else
            OCR1A = (short) (8000000 / (128 * frequency)) - 1;
        
        TCNT1 = 0;
        current_frequency = frequency;
   }
}

void PWM_on2() {
    TCCR1A = (1 << COM1A0);
    TCCR1B = (1 << WGM12) | (1 << CS11) | (1 << CS10);
    set_PWM2(0);
}

void PWM_off2() {
    TCCR1A = 0x00;
    TCCR1B = 0x00;
}


//PD7
void set_PWM3(double frequency) {
    static double current_frequency;

    if (frequency != current_frequency) {
//         if(!frequency)
//             TCCR3B &= 0x08;
//         else
            TCCR3B |= 0x03;

//         if(frequency < 0.954)
//             OCR2A = 0xFFFF;
//         else if (frequency > 31250)
//             OCR2A = 0x0000;
//         else
            OCR2A = (short) (8000000 / (128 * frequency)) - 1;
        
        TCNT2 = 0;
        current_frequency = frequency;
   }
}

void PWM_on3() {
    TCCR2A = (1 << COM2B1);
    TCCR2B = (1 << WGM22) | (1 << CS21) | (1 << CS20);
    set_PWM3(0);
}

void PWM_off3() {
    TCCR3A = 0x00;
    TCCR3B = 0x00;
}

//PD6
void set_PWM4(double frequency) {
    static double current_frequency;

    if (frequency != current_frequency) {
//         if(!frequency)
//             TCCR2B &= 0x08;
//         else
            TCCR2B |= 0x03;

//         if(frequency < 0.954)
//             OCR2B = 0xFFFF;
//         else if (frequency > 31250)
//             OCR2B = 0x0000;
//         else
            OCR2B = (short) (8000000 / (128 * frequency)) - 1;
        
        TCNT2 = 0;
        current_frequency = frequency;
   }
}

void PWM_on4() {
    TCCR2A = (1 << COM2A0);
    TCCR2B = (1 << WGM21) | (1 << CS21) | (1 << CS20);
    set_PWM4(0);
}

void PWM_off4() {
    TCCR2A = 0x00;
    TCCR2B = 0x00;
}

/**/


int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;	
	DDRB = 0xFF; PORTB = 0x00; 
	DDRD = 0xFF; PORTD = 0x00; 
	
// 	TimerSet(100);
// 	TimerOn();
	
		
	PWM_on1();
	PWM_on2();
	PWM_on3();
	PWM_on4();
    /* Insert your solution below */
    
    	
	
		
    while (1) {
// 	while(!TimerFlag);
	    //note();
	    set_PWM1(440);
	    set_PWM2(554.37);
	    set_PWM3(659.25);
	    set_PWM4(880);
	    
// 	    TimerFlag = 0;
    }
  	PWM_off1();
   	PWM_off2();
    	PWM_off3();
   	PWM_off4();
    
	return 1;
}
