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


enum States {start, noParking, oneSpot, twoSpot, threeSpot, fourSpot} state;

void tick(){

   unsigned char cntavail = 0;
   unsigned char sensorA = PINA & 0x01;
   unsigned char sensorB = PINA & 0x02;
   unsigned char sensorC = PINA & 0x04;
   unsigned char sensorD = PINA & 0x08;
   unsigned char parkingSensor = 0;
   
   parkingSensor = sensorA + sensorB + sensorC + sensorD;
   
  switch(state) {
      case start:
        if(parkingSensor == 0x0F){
	  state = noParking;
        }
        else if (parkingSensor == 0x00){
	   state = fourSpot;
        }
        else if(parkingSensor==0x07 || parkingSensor==0x0B || parkingSensor ==0x0D || parkingSensor==0x0E){
           state = oneSpot;
      }
        else  if(parkingSensor==0x03 || parkingSensor==0x05 || parkingSensor==0x06 || parkingSensor ==0x09 || parkingSensor==0x0A || parkingSensor==0x0C ){
           state = twoSpot;
       }
       else  if(parkingSensor==0x01 || parkingSensor==0x02 || parkingSensor ==0x04 || parkingSensor==0x08){
           state = threeSpot;
      }
        else{
	   state = start;
	}
      break;

      case noParking:
        if(parkingSensor == 0x0F){
           state = noParking;
        }
        else{
           state = start;
        }
      break;

    case oneSpot:
      if(parkingSensor==0x07 || parkingSensor==0x0B || parkingSensor ==0x0D || parkingSensor==0x0E){
           state = oneSpot;
      }
        else{
            state = start;
        }
      break;

      case twoSpot:
       if(parkingSensor==0x03 || parkingSensor==0x05 || parkingSensor==0x06 || parkingSensor ==0x09 || parkingSensor==0x0A || parkingSensor==0x0C ){
           state = twoSpot;
       }
        else{
           state = start;
        }
      break;

       case threeSpot:
      if(parkingSensor==0x01 || parkingSensor==0x02 || parkingSensor ==0x04 || parkingSensor==0x08){
           state = threeSpot;
      }
        else{
           state = start;
        }
      break;

      case fourSpot:
        if(parkingSensor == 0x00){
           state = fourSpot;
        }
        else{
         state = start;
        }
      break;

      default:
        state = start;
      break;
   }   
   switch(state) {
      case start:
      break;
      case noParking:
         cntavail = 0;
      break;
      case oneSpot:
         cntavail = 1;
      break;
      case twoSpot:
         cntavail = 2;
      break;
      case threeSpot:
         cntavail = 3;
      break;
      case fourSpot:
         cntavail = 4;
      break;
   }   
   PORTC = cntavail;
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0X00; PORTA = 0XFF;
	DDRB = 0XFF; PORTB = 0X00;
	DDRC = 0xFF; PORTC = 0x00;
	
	state = start;
     
    /* Insert your solution below */
    while (1) {
     tick();
    }
    return 1;
}
