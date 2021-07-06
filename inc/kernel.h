/**
  ******************************************************************************
  * @file    kernel.h
  * @author  Pichugin N.A
  * @version V1.0.0
  * @date    06-07-2021
  * @brief   kernel header with all functions accessible for user
  ******************************************************************************
  */

#ifndef __KERNEL_H
#define __KERNEL_H
#include "defines.h"
typedef void (*void_task_t)(void);

bool AddFunc(void_task_t task, uint32_t time_ms);
void AddToQueue(void);
void SchedulerRoutine(void);
#endif