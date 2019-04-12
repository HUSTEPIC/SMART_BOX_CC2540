#include <ioCC2540.h>
#include "myKey.H"
//0 in 把按键所在位置为0
//1 out
/*
v1.0
#define KEY1 P1_3
#define KEY2 P0_6
#define KEY3 P1_4
#define KEY4 P0_4 //
#define KEY5 P0_1 //

#define KEY6 P0_2
#define KEY7 P2_0  //
#define KEY8 P1_1

0   1010 1001   a9
//串口的话
//0   1010 1101   ad
1   1110 0101   e5
2   1111 1110   fe

#define KEY_DOWN 0
#define KEY_UP 1
#define DEFULT_UP 1
*/

/*
//---------v2.0--------
#define KEY1 P0_0  //s5
#define KEY2 P0_6  //s7
#define KEY3 P0_1  //s6
#define KEY4 P0_7  //s8
#define KEY5 P1_7  //s1
#define KEY6 P1_5  //s3
#define KEY7 P1_6  //s2
#define KEY8 P1_4  //s4
//-----------------

0   0011 1100   3c
1   0000 1111   0f
*/
uchar currentKeys[3];  //电平
uchar lastKeys[3] ={0,0,0};
Stored_data *stored_data;
bool android_ready;
void myKey_init()
{
    //开机初始化stored_data;
    for(int i=0;i<TABLE_SIZE;i++)
    {
        stored_data->table[i] = 0x00;

    }
    for(int i=0;i<32;i++)
    {
      for(int j=0;j<7;j++)
        stored_data->data[i][j] = 0;
    }
    android_ready = false;

    //重新配置IO口方向
    //v1.0
//      P0DIR &= 0xa9; 
//    
////      P0DIR &= 0xad; 
//      P1DIR &= 0xe5; 
//      P2DIR &= 0xfe; 
      //v2.0
        P0DIR &= 0x3c;
        P1DIR &= 0x0f;
      if(DEMO)
      {
          /*默认松开*/
          //currentKeys 置1
          int i=0;
          for(i=0;i<3;i++)
          {
                currentKeys[i] = 0xff;
          }
      }
      else
      {
          /*默认按下*/
          //currentKeys 置0
          int i=0;
          for(i=0;i<3;i++)
          {
                currentKeys[i] = 0x00;
          }
      }
}

void check_keys()
{
  if(DEMO)
  {
     /*默认松开*/
          //currentKeys 置1
          int i=0;
          for(i=0;i<3;i++)
          {
                currentKeys[i] = 0xff;
          }
      
     
      if(KEY1== KEY_DOWN)
      {
            Delay_ms(10);
            if(KEY1==KEY_DOWN)
            currentKeys[0] &= ~(0x01<<7);
      }
     
      if(KEY2==KEY_DOWN)
      {
        Delay_ms(10);
              if(KEY2==KEY_DOWN)
              currentKeys[0] &= ~( 0x01<<6);
                
      }
      if(KEY3==KEY_DOWN)
      {
        Delay_ms(10);
            if(KEY3==KEY_DOWN)
              currentKeys[0] &= ~(0x01<<5);
      }
       if(KEY4==KEY_DOWN)
      {
        Delay_ms(10);
            if(KEY4==KEY_DOWN)
              currentKeys[0] &= ~(0x01<<4);
      }
             if(KEY5==KEY_DOWN)
      {
        Delay_ms(10);
            if(KEY5==KEY_DOWN)
              currentKeys[0] &= ~( 0x01<<3);
      }
       if(KEY6==KEY_DOWN)
      {
        Delay_ms(10);
            if(KEY6==KEY_DOWN)
              currentKeys[0] &= ~( 0x01<<2);
      }
       if(KEY7==KEY_DOWN)
      {
        Delay_ms(10);
            if(KEY7==KEY_DOWN)
              currentKeys[0] &= ~( 0x01<<1);
      }
       if(KEY8==KEY_DOWN)
      {
        Delay_ms(10);
            if(KEY8==KEY_DOWN)
              currentKeys[0] &= ~( 0x01<<0);
      }
  }
  else{
           /*默认按下*/
          //currentKeys 置0
          int i=0;
          for(i=0;i<3;i++)
          {
                currentKeys[i] = 0x00;
          }
      
     
      if(KEY1== KEY_UP)
      {
            Delay_ms(10);
            if(KEY1==KEY_UP)
            currentKeys[0] |= 0x01<<7;
      }
     
      if(KEY2==KEY_UP)
      {
        Delay_ms(10);
              if(KEY2==KEY_UP)
              currentKeys[0] |= 0x01<<6;
                
      }
      if(KEY3==KEY_UP)
      {
        Delay_ms(10);
            if(KEY3==KEY_UP)
              currentKeys[0] |= 0x01<<5;
      }
       if(KEY4==KEY_UP)
      {
        Delay_ms(10);
            if(KEY4==KEY_UP)
              currentKeys[0] |= 0x01<<4;
      }
             if(KEY5==KEY_UP)
      {
        Delay_ms(10);
            if(KEY5==KEY_UP)
              currentKeys[0] |= 0x01<<3;
      }
       if(KEY6==KEY_UP)
      {
        Delay_ms(10);
            if(KEY6==KEY_UP)
              currentKeys[0] |= 0x01<<2;
      }
       if(KEY7==KEY_UP)
      {
        Delay_ms(10);
            if(KEY7==KEY_UP)
              currentKeys[0] |= 0x01<<1;
      }
       if(KEY8==KEY_UP)
      {
        Delay_ms(10);
            if(KEY8==KEY_UP)
              currentKeys[0] |= 0x01<<0;
      }
  }

} 
uint keyStateChange()
{
  uint flag = 0;
  int i = 0;
  for(i=0;i<3;i++)
  {
    if(currentKeys[i] != lastKeys[i])
    {
      flag =1;
      break;
    }
  }
  return flag;
}
void updateLastKeys()
{
  int i = 0;
  for(i=0;i<3;i++)
  {
    lastKeys[i] = currentKeys[i];
    
  }
}
