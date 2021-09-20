/*
 * IncFile1.h
 *
 * Created: 4/10/2021 4:11:09 PM
 *  Author: Alzahraa Eid
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_


void set_pin_dir(unsigned char portname, unsigned char pinnumber,unsigned char direction);

void DIO_write_4_pin(unsigned char portname, unsigned char pins[], unsigned char num[]);

unsigned char DIO_read_pin(unsigned char portname, unsigned char pinnumber);
#endif /* INCFILE1_H_ */