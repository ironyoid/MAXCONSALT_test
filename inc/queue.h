/**
  ******************************************************************************
  * @file    queue.h
  * @author  Pichugin N.A
  * @version V1.0.0
  * @date    06-07-2021
  * @brief   simple queue realisation (without linked list)
  ******************************************************************************
  */
#ifndef __QUEUE_H
#define __QUEUE_H
#include "defines.h"
void QueueInit();
uint8_t QueueInsert(void_task_t x);
int QueueRemove(void_task_t *ret_func);
#endif