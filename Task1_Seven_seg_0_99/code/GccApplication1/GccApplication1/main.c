/*
 * GccApplication1.c
 *
 * Created: 4/10/2021 1:03:49 PM
 *  Author: Alzahraa eid
 */ 


#include <avr/io.h>
#define  F_CPU  16000000UL
#include <util/delay.h>

#include "seven_seg4_bcd.h"
#include "push_but.h"
#include "macros.h"
int main(void)


{
	unsigned char bcd_pins[]={0,1,2,4};
	seven_seg_bcd_4_set_dir('B', bcd_pins);
	push_but_set_dir('C',0);
	
	SET_BIT(DDRB,6);    //pin direction for common anode for first Sev_seg
	SET_BIT(DDRB,5);    //pin direction for common anode for second Sev_seg
	
	unsigned char counter = 0; 
	unsigned char read_but;
	unsigned char pre_val=0;
	
    while(1)
    {
		read_but=but_read('C',0);
		if ((read_but==1)&&(pre_val==0))
		{
			counter++;
			pre_val=1;
		}
		else if (read_but==0)
		{
			pre_val=0;
		}
		if (counter==100)
		{
			counter=0;
		}
		for(unsigned char i=0;i<=10;i++)
		{
			seven_seg_4pins_write('B',bcd_pins,counter%10);
			SET_BIT(PORTB,5);
			_delay_ms(10);
			CLR_BIT(PORTB,5);
		
			seven_seg_4pins_write('B',bcd_pins,counter/10);
			SET_BIT(PORTB,6);
			_delay_ms(10);
			CLR_BIT(PORTB,6);
		}		
		
		
		
		
		 
		 
		 
		 
    }
}