/*
 * _4seven_seg_bcd.h
 *
 * Created: 4/10/2021 4:12:58 PM
 *  Author: Alzahraa Eid
 */ 


#ifndef SEVEN_SEG4_BCD_H_
#define SEVEN_SEG4_BCD_H_

void seven_seg_bcd_4_set_dir(unsigned char portname ,unsigned char pins[4]);
void seven_seg_4pins_write(unsigned char portname,unsigned char pins[],unsigned char number);


#endif /* 4SEVEN_SEG_BCD_H_ */