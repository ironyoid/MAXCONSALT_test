/**
  ******************************************************************************
  * @file    defines.h
  * @author  Pichugin N.A
  * @version V1.0.0
  * @date    06-07-2021
  * @brief   All user defines here
  ******************************************************************************
  */  
#ifndef __DEFINES_H
#define __DEFINES_H
#include "stm8l15x.h"
#include <stdio.h>
//#include <stdlib.h>
#include "stm8l15x_conf.h"
/* Insert here your own tougle functions */
#define TOUGLE_LED_1   (GPIO_ToggleBits(GPIOB, GPIO_Pin_3))
#define TOUGLE_LED_2   (GPIO_ToggleBits(GPIOB, GPIO_Pin_4))
#define TOUGLE_LED_3   (GPIO_ToggleBits(GPIOB, GPIO_Pin_5))

#define SCHEDULE_SIZE   8       /* Schedule size */
#define QUEUE_SIZE      8       /* Queue size   */

#define DEBUG;          /* Comment it out for disable debug options */

#ifdef DEBUG
uint32_t counter[SCHEDULE_SIZE]; /* for live whatch IAR debug */
#endif

#endif 