/*
 * Gehad_Ahmed.c
 *
 * Created: 11/6/2023 12:52:11 PM
 *  Author: Dell
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include "keypad_driver.h"
#include "LCD.h"
#include "LED.h"
#include "Timer.h"
#include <math.h>
#include <stdio.h>
volatile short unsigned counter1 = 0, counter_green = 20, counter_yellow = 5, counter_red = 10;
int main(void)
{
   timer_CTC_init_interrupt();
   LCD_vInit();
   LED_VINIT('A', 0); // for green led
   LED_VINIT('A', 1); // for yellow led
   LED_VINIT('A', 2); // for red led
   
   while (1)
   {
	   counter_green = 30, counter_yellow = 10, counter_red = 15;
	   LCD_clearscreen();
	   LCD_vSend_string("Remaining ");
	   LED_vTurnOn('A', 0);
	   LCD_movecursor(1, 11);
	   char buf[3];
	   LCD_sendFloat(counter_green, buf, 0);
	   LCD_vSend_string(buf);
	   while(counter_green > 0){
		   if(counter1 >= 100){
			   counter_green--;
			   LCD_movecursor(1, 11);
			   LCD_sendFloat(counter_green, buf, 0);
			   LCD_vSend_string(buf);
			   LCD_vSend_string(" ");
			   counter1 = 0;
		   }			   
	   }
	   LED_vTurnOff('A', 0);
	   
	   LED_vTurnOn('A', 1);
	   LCD_movecursor(1, 11);
	   LCD_sendFloat(counter_yellow, buf, 0);
	   LCD_vSend_string(buf);
	   while(counter_yellow > 0){
		   if(counter1 >= 100){
			   counter_yellow--;
			   LCD_movecursor(1, 11);
			   LCD_sendFloat(counter_yellow, buf, 0);
			   LCD_vSend_string(buf);
			   LCD_vSend_string(" ");
			   counter1 = 0;
		   }
	   }
	   LED_vTurnOff('A', 1);
	   
	   LED_vTurnOn('A', 2);
	   LCD_movecursor(1, 11);
	   LCD_sendFloat(counter_red, buf, 0);
	   LCD_vSend_string(buf);
	   while(counter_red > 0){
		   if(counter1 >= 100){
			   counter_red--;
			   LCD_movecursor(1, 11);
			   LCD_sendFloat(counter_red, buf, 0);
			   LCD_vSend_string(buf);
			   LCD_vSend_string(" ");
			   counter1 = 0;
		   }
	   }
	   LED_vTurnOff('A', 2);
		   
     }
   }   

ISR(TIMER0_COMP_vect){
	counter1++;
}