#ifndef __MYKEY_H__
#define __MYKEY_H__
#include "DHT11.H"
#include "OSAL.h"
////---------v1.0--------
//#define KEY1 P1_3
//#define KEY2 P0_6
//#define KEY3 P1_4
//#define KEY4 P0_4 //
//#define KEY5 P0_1 //
//#define KEY6 P0_2
//#define KEY7 P2_0  //
//#define KEY8 P1_1
////-----------------
////---------v2.0--------
//#define KEY1 P0_0  //s5
//#define KEY2 P0_6  //s7
//#define KEY3 P0_1  //s6
//#define KEY4 P0_7  //s8
//#define KEY5 P1_7  //s1
//#define KEY6 P1_5  //s3
//#define KEY7 P1_6  //s2
//#define KEY8 P1_4  //s4
////-----------------
//---------v3.0--------
#define KEY1 P0_6  //
#define KEY2 P0_0  //
#define KEY3 P0_1  //
#define KEY4 P0_7  //
#define KEY5 P1_5  //
#define KEY6 P1_7  //
#define KEY7 P1_4  //
#define KEY8 P1_6  //
//-----------------


#define KEY_DOWN 0
#define KEY_UP 1

#define TABLE_SIZE 4
#define DATA_SIZE 7
#define DEMO 1

typedef struct
{
    uint8 table[4];
    uint8 data[32][7];
}Stored_data;

extern uchar currentKeys[3]; 
extern uchar lastKeys[3];
extern Stored_data *stored_data;
extern bool android_ready;

void myKey_init();
uint keyStateChange();
void updateLastKeys();

void check_keys();

#endif