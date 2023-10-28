#include "stm32f10x.h"
#include "stm32f10x_tim.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "driver.h"
#include "xunji.h"
int delay_ms(unsigned int delay_ms)
{
	unsigned int i=delay_ms;
	while(i--);	
}
int main(void)
{
	//float  length_res[5];  //用来存放测距结果
	
	SystemInit();	// 配置系统时钟为72M 
  delay_init();    //延时初始化		
	xunji_config();   //循迹初始化
	TIM3_PWM_Init();	//电机pwm   TIM3
	//SG90_pwm_init();  //舵机pwm	    TIM2
	//CH_SR04_Init();  //超声波定时器    TIM4
	//OLED_Init();    //oled显示初始化
	
	 while(1)
  {	
     Read_xunji_Date(); //读循迹线值
	  
	  //车前4个循迹模块从左到右分别是xunji_1，xunji_2，xunji_3，xunji_4
   
	 if(xunji_1==0&&xunji_2==0&&xunji_3==0&&xunji_4==0)//0000
	  {
	  CarGo();		  //如果都没有读取到黑线，直走
	  delay_ms(10);
	  }
	 if(xunji_1==0&&xunji_2==1&&xunji_3==1&&xunji_4==0)//0110
	  {
	  CarGo();        //如果中间两个读取到黑线，直走
	  delay_ms(10);
	  }	  
	 if(xunji_1==0&&xunji_2==1&&xunji_3==0&&xunji_4==0)//0100
	  {
	  CarBigLeft();   //如果第二个读取到黑线，左转
	  delay_ms(10);
	  }
 	 if(xunji_1==0&&xunji_2==0&&xunji_3==1&&xunji_4==0)//0010
	  {
	  CarBigRight();   //如果第三个读取到黑线，右转
	  delay_ms(10); 
	  }
	  if(xunji_1==1&&xunji_2==0&&xunji_3==0&&xunji_4==0)//1000
	  {
	  CarBigLeft();   //如果第一个读取到黑线，左转
	  delay_ms(10);
	  }
	  if(xunji_1==0&&xunji_2==0&&xunji_3==0&&xunji_4==1)//0001
	  {
	  CarBigRight();   //如果第四个读取到黑线，左转
	  delay_ms(10); 
	  }
  
  }	
	
}










}