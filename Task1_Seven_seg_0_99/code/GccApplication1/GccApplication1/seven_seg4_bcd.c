/*
 * CFile1.c
 *
 * Created: 4/10/2021 4:11:40 PM
 *  Author: Alzahraa Eid
 */ 
#include "DIO.h"

void seven_seg_bcd_4_set_dir(unsigned char portname ,unsigned char pins[])
{    
	
	for(unsigned char i=0; i<=3; i++)
	{
		set_pin_dir(portname ,pins[i],1);
	}
	
	
}


//write from 0 to 99 using 2 seven segment
void seven_seg_4pins_write(unsigned char portname,unsigned char pins[],unsigned char number)
{
  unsigned char arr[10][4]={ {0,0,0,0},{1,0,0,0},{0,1,0,0},{1,1,0,0},{0,0,1,0},{1,0,1,0},{0,1,1,0},{1,1,1,0},{0,0,0,1},{1,0,0,1}};

  DIO_write_4_pin(portname, pins ,arr[number]);
}