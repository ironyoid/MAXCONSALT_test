/**
  ******************************************************************************
  * @file    kernel.c
  * @author  Pichugin N.A
  * @version V1.0.0
  * @date    06-07-2021
  * @brief   kernel source with all functions accessible for user
  ******************************************************************************
  */
#include "kernel.h"
#include "queue.h"
uint8_t pointer = 0;

typedef struct
{
  void_task_t pt;        /* Pointer on function   */
  uint32_t delay;        /* Function delay        */
  uint32_t time_counter; /* Function time counter */
} function_t;

struct functions_list_t
{
  function_t func[SCHEDULE_SIZE]; /* functions array   */
  uint8_t length;                 /* array length      */
} functions_list;

/* Add any void fenction to schedule with ms period */
bool AddFunc(void_task_t task, uint32_t time_ms)
{
  if ((functions_list.length != SCHEDULE_SIZE) && (time_ms))
  {
    functions_list.func[functions_list.length].pt = task;
    functions_list.func[functions_list.length].delay = time_ms;
    functions_list.func[functions_list.length].time_counter = 0;
    functions_list.length++;
    return 1;
  }
  return 0;
}

/* Main scheduler loop */
void SchedulerRoutine(void)
{
  void_task_t ret_function;
  while (1)
  {
    if (QueueRemove(&ret_function)) /* If we have got func in queue... */
    {
      ret_function(); /* Run it! */
    }
  }
}
/* Use from timer itr for check functions ready for add to queue */
void AddToQueue(void)
{
  for (uint8_t i = 0; i < functions_list.length; i++)
  {
#ifdef DEBUG
    counter[i] = functions_list.func[i].time_counter;
#endif
    if (functions_list.func[i].time_counter == functions_list.func[i].delay)
    {
      if (QueueInsert(functions_list.func[i].pt))
      {
        functions_list.func[i].time_counter = 0; /* Reset counter if successfuly added */
      }
    }
    else
    {
      functions_list.func[i].time_counter++;
    }
  }
}