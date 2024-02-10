/*
 * LED.c
 *
 * Created: 10/21/2023 9:15:11 AM
 *  Author: Dell
 */ 
#include "DIO.h"

void LED_VINIT(unsigned char portname, unsigned char pinnumber)
{
	DIO_vsetPINDir(portname, pinnumber, 1);
}
void LED_vTurnOn(unsigned char portname, unsigned char pinnumber)
{
	DIO_write(portname, pinnumber, 1);
}
void LED_vTurnOff(unsigned char portname, unsigned char pinnumber)
{
	DIO_write(portname, pinnumber, 0);
}
void LED_vToggle(unsigned char portname, unsigned char pinnumber)
{
	DIO_toggle(portname, pinnumber);
}
void LED_SetBins(unsigned char portname, unsigned char direction)
{
	DIO_set_port_direction(portname, direction);
}
