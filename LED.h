/*
 * LED.h
 *
 * Created: 10/21/2023 9:15:24 AM
 *  Author: Dell
 */ 


#ifndef LED_H_
#define LED_H_

void LED_VINIT(unsigned char portname, unsigned char pinnumber);
void LED_vTurnOn(unsigned char portname, unsigned char pinnumber);
void LED_vTurnOff(unsigned char portname, unsigned char pinnumber);
void LED_vToggle(unsigned char portname, unsigned char pinnumber);
void LED_SetBins(unsigned char portname, unsigned char direction);


#endif /* LED_H_ */