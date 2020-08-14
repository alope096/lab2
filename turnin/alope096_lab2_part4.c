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
	DDRA = 0X00; PORTA = 0XFF; //input of cart A
	DDRB = 0X00; PORTB = 0XFF;// input for cart B
	DDRC = 0x00; PORTC = 0xFF; // input for cart C
        DDRD= 0xFF; PORTD = 0x00; // output of carts
	
       
        
     
    /* Insert your solution below */
    while (1) {
        unsigned char seatA = PINA & 0xFF;
     	unsigned char seatB = PINB & 0xFF;
    	unsigned char seatC = PINC & 0xFF;
  	unsigned char totalWeight = 0;
	unsigned char overWeight = 0;
        unsigned char differenceWeight = 0;
	unsigned char exceedsWeight = 0;
       
	totalWeight = seatA + seatB + seatC;

	differenceWeight = seatA - seatC;

        if (differenceWeight <0){
           differenceWeight = differenceWeight * (-1);
        }

	if (seatA > 0x8C || seatB > 0x8C || seatC > 0x8C || totalWeight > 0x8C){
         overWeight = 0x01;
     	}
	else{
	  overWeight = 0x00;
	}

	if(differenceWeight > 0x50){
	   exceedsWeight = 0x01;
	}
	else {
	   exceedsWeight = 0x00;
	}
	
	PORTD = (totalWeight << 5) || (overWeight || exceedsWeight);
	  

     
    }
    return 1;
}
