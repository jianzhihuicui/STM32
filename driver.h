// #ifndef __drivver_h_
// #define __drivver_h_
// void CarGo(void);
// void CarStop(void);
// void CarBack(void);
// void CarLeft(void);
// void CarBigLeft(void);
// void CarRight(void);
// void CarBigRight(void);
// #endif
#ifndef __DRIVER_H
#define	__DRIVER_H
#include "stm32f10x.h"
#include "stm32f10x_tim.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

void TIM3_PWM_Init(void);
void CarGo(void);
void CarStop(void);
void CarBack(void);
void CarLeft(void);
void CarBigLeft(void);  //大右转
void CarRight(void);
void CarBigRight(void);   //大左转

#endif
