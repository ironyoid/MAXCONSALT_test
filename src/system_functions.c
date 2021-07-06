/**
  ******************************************************************************
  * @file    system_functions.c
  * @author  Pichugin N.A
  * @version V1.0.0
  * @date    06-07-2021
  * @brief   All HAL functions
  ******************************************************************************
  */ 
#include "system_functions.h"

/*Sys clk and GPIO initialisation */
void SysInit()
{
  CLK_SYSCLKSourceConfig(CLK_SYSCLKSource_HSI); // 8 Mhz
  CLK_SYSCLKDivConfig(CLK_SYSCLKDiv_1);
  CLK_HSICmd(ENABLE);
  GPIO_Init( GPIOB, GPIO_Pin_3, GPIO_Mode_Out_PP_Low_Fast); // LED 1 PIN
  GPIO_Init( GPIOB, GPIO_Pin_4, GPIO_Mode_Out_PP_Low_Fast); // LED 2 PIN
  GPIO_Init( GPIOB, GPIO_Pin_5, GPIO_Mode_Out_PP_Low_Fast); // LED 2 PIN
  enableInterrupts();
}

/* Main schedule timer initialisation */
void TimerInit()
{
  CLK_PeripheralClockConfig(CLK_Peripheral_TIM4, ENABLE);
  TIM4_TimeBaseInit(TIM4_Prescaler_128, 131);
  TIM4_ITConfig(TIM4_IT_Update, ENABLE);
  TIM4_Cmd(ENABLE);
}