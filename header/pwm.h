//PB3
void set_PWM0(double frequency) {
    static double current_frequency0;

    if (frequency != current_frequency0) {
            TCCR0B |= 0x03;
	    
            OCR0A = (char) (8000000 / (2*128 * frequency)) - 1;
        
        TCNT0 = 0;
        current_frequency0 = frequency;
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
    static double current_frequency1;

    if (frequency != current_frequency1) {
            TCCR1B |= 0x03;
	    
            OCR1A = (short) (8000000 / (128 * frequency)) - 1;
        
        TCNT1 = 0;
        current_frequency1 = frequency;
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
    static double current_frequency2;

    if (frequency != current_frequency2) {
            TCCR2B |= 0x03;
	    
            OCR2A = (char) (8000000 / (128*2 * frequency)) - 1;
        
        TCNT2 = 0;
        current_frequency2 = frequency;
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
    static double current_frequency3;

    if (frequency != current_frequency3) {
            TCCR3B |= 0x03;
	    
            OCR3A = (short) (8000000 / (128 * frequency)) - 1;
        
        TCNT3 = 0;
        current_frequency3 = frequency;
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

//------------------------------------------------------------------------------------
//a2D

void A2D_init() {
      ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
    // ADEN: Enables analog-to-digital conversion
    // ADSC: Starts analog-to-digital conversion
    // ADATE: Enables auto-triggering, allowing for constant
    //        analog to digital conversions.
}

