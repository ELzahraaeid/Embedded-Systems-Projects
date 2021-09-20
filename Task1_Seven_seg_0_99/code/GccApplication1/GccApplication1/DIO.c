/*
 * CFile1.c
 *
 * Created: 4/10/2021 4:10:33 PM
 *  Author: Alzahraa Eid
 */ 
#include <avr/io.h>

#include "macros.h"

void set_pin_dir(unsigned char portname, unsigned char pinnumber,unsigned char direction)
{
	switch(portname)
	{
		case 'A':
		if(direction==1)
		{
			SET_BIT(DDRA,pinnumber);
		}
		else
		{
			CLR_BIT(DDRA,pinnumber);
		}
		break;
		
		case 'B':
		if(direction==1)
		{
			SET_BIT(DDRB,pinnumber);
		}
		else
		{
			CLR_BIT(DDRB,pinnumber);
		}
		break;
		
		case 'C':
		if(direction==1)
		{
			SET_BIT(DDRC,pinnumber);
		}
		else
		{
			CLR_BIT(DDRC,pinnumber);
		}
		break;
		
		case 'D':
		if(direction==1)
		{
			SET_BIT(DDRD,pinnumber);
		}
		else
		{
			CLR_BIT(DDRD,pinnumber);
		}
		break;
		default:
		break;
	}



}


void DIO_write_4_pin(unsigned char portname, unsigned char pins[], unsigned char num[])
{
	switch(portname)
	{
		case 'B':
		for(int i=0;i<=3;i++)
		{
			if (num[i]==0)
			{
				CLR_BIT(PORTB,pins[i]);
			}
			else
			{
				SET_BIT(PORTB,pins[i]);
			}
		}
		break;
		
		case 'A':
		for(int i=0;i<=3;i++)
		{
			if (num[i]==0)
			{
				CLR_BIT(PORTA,pins[i]);
			}
			else
			{
				SET_BIT(PORTA,pins[i]);
			}
		}
		break;
		
		case 'C':
		for(int i=0;i<=3;i++)
		{
			if (num[i]==0)
			{
				CLR_BIT(PORTC,pins[i]);
			}
			else
			{
				SET_BIT(PORTC,pins[i]);
			}
		}
		break;
		
		
		case 'D':
		for(int i=0;i<=3;i++)
		{
			if (num[i]==0)
			{
				CLR_BIT(PORTD,pins[i]);
			}
			else
			{
				SET_BIT(PORTD,pins[i]);
			}
		}
		break;
		
		default:
		break;
		
	}
}


unsigned char DIO_read_pin(unsigned char portname, unsigned char pinnumber)
{
	unsigned char read_pin=0;
	switch(portname)
	{
		case 'A' :
		read_pin=READ_BIT(PINA,pinnumber);
		break;

		case 'B' :
		read_pin=READ_BIT(PINB,pinnumber);
		break;
		
		case 'C' :
		read_pin=READ_BIT(PINC,pinnumber);
		break;
		
		case 'D' :
		read_pin=READ_BIT(PIND,pinnumber);
		break;
		
		default:
		break;
	}
	return read_pin;		

}