/**
  ******************************************************************************
  * @file    stm8l15x_it.c
  * @author  Pichugin N.A
  * @version V1.0.0
  * @date    06-07-2021
  * @brief   ITR for timer 
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "defines.h"
#include "kernel.h"

/**
  * @brief TIM4 Update/Overflow/Trigger Interrupt routine.
  * @par Parameters:
  * None
  * @retval 
  * None
  */
/**/
INTERRUPT_HANDLER(TIM4_UPD_OVF_TRG_IRQHandler, 25)
{
  AddToQueue(); /* Timer routine */
  TIM4_ClearITPendingBit(TIM4_IT_Update);
}
