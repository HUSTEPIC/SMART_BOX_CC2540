#include <ioCC2540.h>
#include "myKey.H"
//0 in 
//1 out
/*
#define KEY1 P2_0
#define KEY2 P1_3
#define KEY3 P0_1
#define KEY4 P1_1
#define KEY5 P0_4
#define KEY6 P1_4
#define KEY7 P0_2
#define KEY8 P0_6

0   1010 1001   a9
1   1110 0101   e5
2   1111 1110   fe

#define KEY_DOWN 0
#define KEY_UP 1
#define DEFULT_UP 1
*/
uchar currentKeys[3];  //电平
uchar lastKeys[3] ={0,0,0};
void myKey_init()
{
  //重新配置IO口方向
      P0DIR &= 0xa9; 
      P1DIR &= 0xe5; 
      P2DIR &= 0xfe; 
      
      if(DEFAULT_UP)
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
  if(DEFAULT_UP)
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
            currentKeys[0] &= ~(0x01<<0);
      }
     
//      if(KEY2==KEY_DOWN)
//      {
//        Delay_ms(10);
//              if(KEY2==KEY_DOWN)
//              currentKeys[0] &= ~( 0x01<<1);
//                
//      }
      if(KEY3==KEY_DOWN)
      {
        Delay_ms(10);
            if(KEY3==KEY_DOWN)
              currentKeys[0] &= ~(0x01<<2);
      }
       if(KEY4==KEY_DOWN)
      {
        Delay_ms(10);
            if(KEY4==KEY_DOWN)
              currentKeys[0] &= ~(0x01<<3);
      }
             if(KEY5==KEY_DOWN)
      {
        Delay_ms(10);
            if(KEY5==KEY_DOWN)
              currentKeys[0] &= ~( 0x01<<4);
      }
       if(KEY6==KEY_DOWN)
      {
        Delay_ms(10);
            if(KEY6==KEY_DOWN)
              currentKeys[0] &= ~( 0x01<<5);
      }
       if(KEY7==KEY_DOWN)
      {
        Delay_ms(10);
            if(KEY7==KEY_DOWN)
              currentKeys[0] &= ~( 0x01<<6);
      }
       if(KEY8==KEY_DOWN)
      {
        Delay_ms(10);
            if(KEY8==KEY_DOWN)
              currentKeys[0] &= ~( 0x01<<7);
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
      
     
      if(KEY1== KEY_DOWN)
      {
            Delay_ms(10);
            if(KEY1==KEY_DOWN)
            currentKeys[0] |= 0x01<<0;
      }
     
      if(KEY2==KEY_DOWN)
      {
        Delay_ms(10);
              if(KEY2==KEY_DOWN)
              currentKeys[0] |= 0x01<<1;
                
      }
      if(KEY3==KEY_DOWN)
      {
        Delay_ms(10);
            if(KEY3==KEY_DOWN)
              currentKeys[0] |= 0x01<<2;
      }
       if(KEY4==KEY_DOWN)
      {
        Delay_ms(10);
            if(KEY4==KEY_DOWN)
              currentKeys[0] |= 0x01<<3;
      }
             if(KEY5==KEY_DOWN)
      {
        Delay_ms(10);
            if(KEY5==KEY_DOWN)
              currentKeys[0] |= 0x01<<4;
      }
       if(KEY6==KEY_DOWN)
      {
        Delay_ms(10);
            if(KEY6==KEY_DOWN)
              currentKeys[0] |= 0x01<<5;
      }
       if(KEY7==KEY_DOWN)
      {
        Delay_ms(10);
            if(KEY7==KEY_DOWN)
              currentKeys[0] |= 0x01<<6;
      }
       if(KEY8==KEY_DOWN)
      {
        Delay_ms(10);
            if(KEY8==KEY_DOWN)
              currentKeys[0] |= 0x01<<7;
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
