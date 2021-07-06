/**
  ******************************************************************************
  * @file    queue.c
  * @author  Pichugin N.A
  * @version V1.0.0
  * @date    06-07-2021
  * @brief   simple queue realisation (without linked list)
  ******************************************************************************
  */ 

#include "kernel.h"

struct queue_t{
  void_task_t qu[QUEUE_SIZE];
  uint8_t rear, frnt;
}queue;

void QueueInit() 
{
  queue.frnt = 1;
  queue.rear = 0;
}

uint8_t QueueInsert(void_task_t x) 
{
  if(queue.rear < QUEUE_SIZE - 1) {
    queue.rear++;
    queue.qu[queue.rear]=x;
    return 1;
  }
  else
  {
    return 0;
  }
}

static uint8_t QueueIsEmpty() 
{
  if(queue.rear < queue.frnt)
  {
    return 1;
  }    
  else  
  {
    return 0;
  }
}

int QueueRemove(void_task_t *ret_func) 
{
  uint8_t i = 0;
  if(QueueIsEmpty() == 1) 
  {
    return 0;
  }
  
  *ret_func = queue.qu[queue.frnt];
  for(i = queue.frnt; i < queue.rear; i++) {
    queue.qu[i] = queue.qu[i + 1];
  }
  queue.rear--;
  return 1;
}