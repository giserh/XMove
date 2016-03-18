#include "config.h"


/***************************延时函数*******************************/
/*******************************************
函数名称：delay_Nus
功    能：延时N个us的时间
参    数：n--延时长度
返回值  ：无
********************************************/
void delay_us(unsigned int n)
{
  while(n>0)
  {
      n--;
  }  
} 
/*******************************************
函数名称：delay_1ms
功    能：延时约1ms的时间
参    数：无
返回值  ：无
********************************************/
void delay_1ms(void)
{
	unsigned int i;
	for(i = 1000;i > 0;i--)	; delay_us(1);
}  
/*******************************************
函数名称：delay_Nms
功    能：延时N个ms的时间
参    数：无
返回值  ：无
********************************************/  
void delay_ms(unsigned int n)
{
	unsigned int i = 0;

	for(i = n;i > 0;i--)
		delay_1ms();
}

void SetCPUSpeed(u8 value)
{
     DCOCTL = DCO0 + DCO1 + DCO2;              // Max DCO
	BCSCTL1 = RSEL0 + RSEL1 + RSEL2;          // XT2on, max RSEL
 

  BCSCTL2 |= SELM_2 + SELS;                 // MCLK= SMCLK= XT2 (safe)
}

void TimerInit()
{

  CCTL0 = CCIE;                             // CCR0 interrupt enabled
  CCR0 = 11200;
  TACTL = TASSEL_2 + MC_2;                  // SMCLK, contmode
}
	
//定时器计数器
u16 TimerCounter=0;

#pragma vector=TIMERA0_VECTOR
__interrupt void Timer_A0 (void)
{
     CCR0+= 11200;
    TimerCounter++;
}

