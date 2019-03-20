#ifndef __MYKEY_H__
#define __MYKEY_H__
#include "DHT11.H"
#include "OSAL.h"

#define KEY1 P1_3
#define KEY2 P0_6
#define KEY3 P1_4
#define KEY4 P0_4 //
#define KEY5 P0_1 //
#define KEY6 P0_2
#define KEY7 P2_0  //
#define KEY8 P1_1


#define KEY_DOWN 0
#define KEY_UP 1
#define DEFAULT_UP 1

extern uchar currentKeys[3]; 
extern uchar lastKeys[3];

typedef struct
{
  osal_event_hdr_t hdr;
  uchar keys[3] ;
  unsigned long time;
} key_time_data;

void myKey_init();
uint keyStateChange();
void updateLastKeys();

void check_keys();

#endif