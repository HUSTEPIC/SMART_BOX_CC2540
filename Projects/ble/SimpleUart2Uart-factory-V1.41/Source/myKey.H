#ifndef __MYKEY_H__
#define __MYKEY_H__
#include "DHT11.H"
//#define DATA_PIN P0_0
#define KEY1 P2_0
#define KEY2 P1_3
#define KEY3 P0_1
#define KEY4 P1_1 //
#define KEY5 P0_4 //
#define KEY6 P1_4
#define KEY7 P0_2  //
#define KEY8 P0_6


#define KEY_DOWN 0
#define KEY_UP 1

extern uchar currentKeys[3]; 
extern uchar lastKeys[3];
void myKey_init();
uint keyStateChange();
void updateLastKeys();

uchar* check_keys();

#endif