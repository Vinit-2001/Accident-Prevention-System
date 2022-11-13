#include<xc.h>
#include<pic.h>

#define RS RB6
#define EN RB7
#define D0 RC0
#define D1 RC1
#define D2 RC2
#define D3 RC3
#define D4 RC4
#define D5 RC5
#define D6 RC6
#define D7 RC7
#define ALCOHOL RA0
#define EYE RA1
#define BUZ RD0
#define MINP1 RD1
#define MINP2 RD2
#define GREEN RD3
#define RED RD4

void motor(void);
void lcd_1(void);
void led(void);
void buz(void);
void lcd(void);
#define _XTAL_FREQ 20000000

#include "lcd.h"

void main()
{
  int i;
  ADCON1 = 0x06;
 
  TRISA0=1;
  TRISA1=1;
    TRISB = 0x00;
  
  TRISD = 0x00;
  TRISC = 0x00;
  Lcd8_Init();
    Lcd8_Set_Cursor(1,1);
    lcd();
    __delay_ms(100);
    Lcd8_Clear();
   
    motor();
    lcd_1();
    led();
    buz();
  
}
void lcd(void)
{int i;
   Lcd8_Write_String("WELCOME TO MINI PROJECT!!");
    for(i=0;i<100;i++)
    {
      __delay_ms(5);
      Lcd8_Shift_Left();
    }
    
}
void motor(void)
{
    if((ALCOHOL||EYE)==0)
    
    {
        MINP1=1;
        MINP2=0;
       __delay_ms(500);
    }
    else
    {
        MINP1=0;
        MINP2=0;
        __delay_ms(500);
    }
}
void lcd_1(void)
{
    if(ALCOHOL==0&&EYE==0)
    {
       Lcd8_Clear();
      Lcd8_Set_Cursor(1,1);
     Lcd8_Write_String("Hello USER!!");
     Lcd8_Set_Cursor(2,1);
     Lcd8_Write_String("YOU CAN DRIVE!");
      __delay_ms(1000);
    }
    else if(ALCOHOL==1&&EYE==0)
    {
       Lcd8_Clear();
      Lcd8_Set_Cursor(1,1);
     Lcd8_Write_String("YOU ARE DRUNKEN!!!");
     Lcd8_Set_Cursor(2,1);
     Lcd8_Write_String("YOU CAN'T DRIVE!");
     __delay_ms(1000);
    }
     else if(ALCOHOL==0&&EYE==1)
    {
       Lcd8_Clear();
      Lcd8_Set_Cursor(1,1);
     Lcd8_Write_String("YOU LOOK DROWSY!!!");
     Lcd8_Set_Cursor(2,1);
     Lcd8_Write_String("YOU CAN'T DRIVE!");
     __delay_ms(1000);
    } 
     else 
    {
       Lcd8_Clear();
      Lcd8_Set_Cursor(1,1);
     Lcd8_Write_String("WARNING!!!");
     Lcd8_Set_Cursor(2,1);
     Lcd8_Write_String("YOU CAN'T DRIVE!");
     __delay_ms(1000);
    }
}
void led(void)
{
    if((ALCOHOL||EYE)==0)
    
    {
        RED=0;
      GREEN=1;
       __delay_ms(500);
    }
    else
    {
        RED=1;
      GREEN=0;
       __delay_ms(500);
    }
}

    void buz(void)
{
    if((ALCOHOL||EYE)==0)
    
    {
        BUZ=0;
       __delay_ms(500);
    }
    else
    {
        BUZ=1;
       __delay_ms(500);
    }
}