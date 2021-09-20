/*
 * macros.h
 *
 * Created: 4/10/2021 4:16:24 PM
 *  Author: Alzahraa Eid
 */ 


#ifndef MACROS_H_
#define MACROS_H_


#define SET_BIT(reg,bit) reg|=(1<<bit)
#define CLR_BIT(reg,bit) reg&=(~(1<<bit))
#define READ_BIT(reg,bit) ((reg&(1<<bit))>>bit)



#endif /* MACROS_H_ */