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

void set_PWM(double frequency) {
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

void PWM_on() {
    TCCR3A = (1 << COM3A0);
    TCCR3B = (1 << WGM32) | (1 << CS31) | (1 << CS30);
    set_PWM(0);
}

void PWM_off() {
    TCCR3A = 0x00;
    TCCR3B = 0x00;
}

#define MAX 64

enum states {mus, waitBut, wait} state;

	//A = 55

	double song[MAX] = {55, 55, 98, 55,  98, 110, 55, 98, 55, 82.41, 55, 87.31, 87.31, 82.41, 73.42, 82.4,                                                   41.2, 41.2, 73.42, 41.2, 73.42, 82.41, 41.2, 98, 41.2, 82.41, 41.2, 98, 98, 82.41, 98, 110,                                          73.42, 73.42, 130.81, 73.42, 130.81, 146.83, 73.42, 130.81, 73.41, 130.81, 123.47, 73.42, 123.47, 116.54, 73.42, 123.47,             110, 55, 98, 55, 98, 110, 55, 98, 55, 82.41, 55, 87.31, 87.31, 82.41, 73.42, 82.41,                                                  };
	unsigned char sound;
	unsigned char counter;

void note() {

	unsigned char tmpA = (~PINA) & 0x07;
	switch(state) {
		case mus:
			

			if(counter == MAX-1) {
				state = waitBut;
			}
			else {
				state = mus;
			}
			break;
		
		case wait:
			if(tmpA==0x01) {
				state = mus;
				counter = 0;
			}
			else {
				state = wait;
			}

			break;

		case waitBut:
			if(tmpA==0x01) {
				state = waitBut;
			}
			else {
				state = wait;
			}
			break;

		default:
			state = wait;
			break;
	}
	
	switch(state) {
		
		case mus:
			
			if(sound == 1) {
                                set_PWM(song[counter]);
                                sound = 0;
                        }
                        else {
                                set_PWM(0);
                                sound = 1;
                        }

			
			if(sound == 1) {
				if(counter+1 < MAX) {
					counter++;
				}
				else {
					counter = 0;
				}
			}
			
		default:
			break;
	}

}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;	
	DDRB = 0xFF; PORTB = 0x00; 
	
	TimerSet(82);
	TimerOn();
	
		state = wait;
		PWM_on();
    /* Insert your solution below */
    
		//set_PWM(261.63);
		
    while (1) {
	while(!TimerFlag);
	    note();
	    TimerFlag = 0;
    }
    PWM_off();
    return 1;
}
