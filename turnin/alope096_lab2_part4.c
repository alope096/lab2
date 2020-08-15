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
        DDRD = 0xFF; PORTD = 0x00; // output of carts
	
	unsigned char seatA = 0x00;
     	unsigned char seatB = 0x00;
    	unsigned char seatC = 0x00;
  	unsigned char weight = 0x00;
  	unsigned char finalWeight = 0x00;
        int totalWeight = 0;
        int average;
        
     
    /* Insert your solution below */
    while (1) {
       
        
        seatA = PINA;
        seatB = PINB;
        seatC = PINC;
	
        totalWeight = seatA + seatB + seatC;
        average= totalWeight;
        weight = average;
        finalWeight = weight << 2;

        if(totalWeight > 140){
           weight = weight + 0x01;
        }
      
        if(((seatA-seatC) > 80) || ((seatC - seatA) > 80)){
           weight = weight + 0x02;
        }
   
      
	PORTD = weight;
        finalWeight = 0x00;
    }
    return 1;
}
