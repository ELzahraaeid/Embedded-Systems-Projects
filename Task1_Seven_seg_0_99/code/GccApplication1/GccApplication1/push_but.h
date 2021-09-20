/*
 * push_but.h
 *
 * Created: 4/10/2021 4:13:51 PM
 *  Author: Alzahraa Eid
 */ 


#ifndef PUSH_BUT_H_
#define PUSH_BUT_H_

void push_but_set_dir(unsigned char portname, unsigned char pinnumber);

unsigned char but_read(unsigned char portname, unsigned char pinnumber);

#endif /* PUSH_BUT_H_ */