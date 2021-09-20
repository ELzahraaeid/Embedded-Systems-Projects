/*
 * push_but.c
 *
 * Created: 4/10/2021 4:13:29 PM
 *  Author: Alzahraa Eid
 */ 

//#include "DIO.h"

void push_but_set_dir(unsigned char portname, unsigned char pinnumber)
{
	set_pin_dir(portname,pinnumber,0);
}

unsigned char but_read(unsigned char portname, unsigned char pinnumber)
{
	unsigned char x;
	x=DIO_read_pin(portname,pinnumber);
	return x ;

}