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

//array of freq for C1
			//		C		C#	   D	  D#	 E	   F	  F#	 G	   G#	 A		A#	   B
double freq[12] = {32.7, 34.65, 36.71, 38.89, 41.2, 43.65, 46.25, 49.00, 51.91, 55.00, 58.27, 61.74};


struct notes {
	unsigned char pos;
	unsigned char octave;
} ;

struct chords {
	struct notes note0;
	struct notes note1;
	struct notes note2;
	struct notes note3;
	
	unsigned char maj;
// 	0, 1, 2, 3
// 	maj, min, aug, dim	
} ;

void noteInc(struct chords *chord, unsigned char inc) {
	(*chord).note0.pos+=inc;	
	(*chord).note1.pos+=inc;	
	(*chord).note2.pos+=inc;	
	(*chord).note3.pos+=inc;	
	return;
}

void noteDec(struct chords *chord, unsigned char dec) {
	(*chord).note0.pos-=dec;	
	(*chord).note1.pos-=dec;	
	(*chord).note2.pos-=dec;	
	(*chord).note3.pos-=dec;
}



double calcFreq(struct notes *note) {
	double f = freq[(*note).pos%12];
	unsigned char i;
	while((*note).pos>=12) {
		if((*note).octave<6) {
			(*note).octave++;
		}
		
		(*note).pos-=12;
	}
	while((*note).pos<0) {
		if((*note).octave>0) {
			(*note).octave--;
		}		
		
		(*note).pos+=12;
	}
	for(i=0;i<(*note).octave;i++) {
		f+=f;
	}
	return f;
}

void setNotes(struct chords chord) {
	set_PWM0(calcFreq(&(chord.note0)));
	set_PWM1(calcFreq(&(chord.note1)));
	set_PWM2(calcFreq(&(chord.note2)));
	set_PWM3(calcFreq(&(chord.note3)));
}

/**/


/**/

enum states {init, inc, dec, reset, wait} state;

void SM(struct chords *chord) {
	unsigned short joy = ADC;
	
	switch(state) {
	
		case init:
			state = wait;
			break;
			
		case wait:
			if(joy<300) {
				state = inc;	
			}
			else 
				state = wait;
			break;
			
		case inc:
			if(joy>500) {
				state = wait;	
			}
			else {
				state = inc;
			}
			break;
			
		default:
			state = init;
			break;
	}
	
	
	switch(state) {
	
		case init:
			(*chord).note0.pos=0;
			(*chord).note1.pos=0;
			(*chord).note2.pos=0;
			(*chord).note3.pos=0;
		break;
			
		case inc:
			noteInc(chord, 1);
			break;
			
		default:
			break;
			
	}
	
}

/**/


int main(void) {
    /* Insert DDR and PORT initializations */
	//DDRA = 0x00; PORTA = 0xFF;	
	DDRB = 0x48; PORTB = 0x00; 
	DDRD = 0xA0; PORTD = 0x00; 
	

	
	//while((~PINA&0x01)!=0x01);

		
	PWM_on0();
	PWM_on1();
	PWM_on2();
	PWM_on3();
//  ------------------------
// 	initialize C2maj Chord.
//  ------------------------

	struct notes n0;
		n0.pos = 0;
		n0.octave = 1;
	struct notes n1;
		n1.pos = 4;
		n1.octave = 1;
	struct notes n2;
		n2.pos = 7;
		n2.octave = 1;
	struct notes n3;
		n3.pos = 0;
		n3.octave=n0.octave+1;
	
	struct chords chord;
		chord.note0 = n0;
		chord.note1 = n1;
		chord.note2 = n2;
		chord.note3 = n3;
	
	setNotes(chord);
	
	TimerSet(500);
	TimerOn();
	
	A2D_init();
	
    while (1) {
		while(!TimerFlag);
		
// 	    	if(joy>800) {
// 			noteInc(&chord, 5);
// 			PORTB |= 0x01;
// 		}
// 	   	 else {
// 			noteDec(&chord, 5);
// 			PORTB &= 0xFE;
// 		 }
		
		SM(&chord);
	    
		setNotes(chord);
		
		TimerFlag = 0;
    }

  	PWM_off0();
   	PWM_off1();
  	PWM_off2();
   	PWM_off3();
    
	return 1;
}
