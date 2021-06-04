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

//array of freq for C0
			//		C		C#	   D	  D#	 E	   F	  F#	 G	   G#	 A		A#	   B
double freq[12] = {16.35, 17.32, 18.35, 19.45, 20.6, 21.83, 23.12, 24.5, 25.96, 27.5, 29.14, 30.87};


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

double calcFreq(struct notes note) {
	double f = freq[note.pos];
	unsigned char i;
	for(i=0;i<note.octave;i++) {
		f*=2;
	}
	return f;
}

void setNotes(struct chords chord) {
	set_PWM0(calcFreq(chords.note0));
	set_PWM1(calcFreq(chords.note1));
	set_PWM2(calcFreq(chords.note2));
	set_PWM3(calcFreq(chords.note3));
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
//  ------------------------
// 	initialize C0maj Chord.
//  ------------------------

	struct notes n0;
	struct notes n1;
		n1.pos = 4;
	struct notes n2;
		n2.pos = 7;
	struct notes n3;
		n3.octave=1;
	
	struct chords chord;
		chord.note0 = n0;
		chord.note1 = n1;
		chord.note2 = n2;
		chord.note3 = n3;
	
	setNotes(chord);
	
		
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
