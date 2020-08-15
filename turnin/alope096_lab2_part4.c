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
	DDRA = 0X00; PORTA = 0X00; //input of cart A
	DDRB = 0X00; PORTB = 0X00;// input for cart B
	DDRC = 0x00; PORTC = 0x00; // input for cart C
        DDRD= 0xFF; PORTD = 0x00; // output of carts
	
       
        
     
    /* Insert your solution below */
    while (1) {
        unsigned char seatA = PINA;
     	unsigned char seatB = PINB;
    	unsigned char seatC = PINC;
  	unsigned char totalWeight;
	unsigned char overWeight;
        unsigned char differenceWeight1;
	unsigned char exceedsWeight;
        unsigned char differenceWeight2;
	
        totalWeight = seatA + seatB + seatC;

	differenceWeight1 = seatA - seatC;
	differenceWeight2 = seatC - seatA;
        if(totalWeight > 140){
           overWeight = 0x01;
        }
        else{
           overWeight = 0x00;
        }
        if( seatA == seatB){
           exceedsWeight = 0x00;
        }
        if(differenceWeight1 > 80 || differenceWeight2 > 80){
           exceedsWeight = 0x02;
        }
       else{
           exceedsWeight = 0x00;
        }
      
	PORTD = (totalWeight << 5) | overWeight | exceedsWeight;
     
    }
    return 1;
}
