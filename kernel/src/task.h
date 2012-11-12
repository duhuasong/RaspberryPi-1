#ifndef TASK_H
#define TASK_H

#include "types.h"
#include "msg.h"
#include "list.h"

typedef struct task_t {
  uint32 sp;
  struct msg_t  *msg;
} task_t;

void task_init();
struct task_t *task_current();

extern struct list_t* active_tasks;
extern struct list_t* inactive_tasks;
extern struct list_node_t* current_task_it;

#endif
