/**
  ******************************************************************************
  * @file    main.h
  * @author  Pichugin N.A
  * @version V1.0.0
  * @date    06-07-2021
  * @brief   Main routine
  ******************************************************************************
  */
#include "inc/system_functions.h"
#include "inc/defines.h"
#include "inc/kernel.h"
#include "inc/queue.h"

/* Tasks for tougle leds */
void Led_1(void)
{
  TOUGLE_LED_1;
}

void Led_2(void)
{
  TOUGLE_LED_2;
}

void Led_3(void)
{
  TOUGLE_LED_3;
}

int main(void)
{
  /* System initialisation */
  SysInit();
  TimerInit();
  /* Queue initialisation */
  QueueInit();
  AddFunc(Led_1, 1000); /* 1 time per sec */
  AddFunc(Led_2, 500);  /* 2 time per sec */
  AddFunc(Led_3, 250);  /* 4 time per sec */
  /* Run schedule cycle */
  SchedulerRoutine();
}
