/*	Author: lab
 *  Partner(s) Name: none
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0X00; PORTA = 0XFF;
	DDRB = 0XFF; PORTB = 0X00;
	unsigned char garageDoorSensor = 0;
	unsigned char lightSensor = 0;
	unsigned char led = 0;
    /* Insert your solution below */
    while (1) {
    garageDoorSensor = PINA & 0x01;
    lightSensor = PINA & 0x02;
       if(garageDoorSensor && !lightSensor){
          led = 0x01;
       }
       else{
          led=0x00;
       }
    
    PORTB = led;
    
    }
    return 1;
}
