#include "types.h"
#include "uart.h"
#include "gio.h"
#include "cpu.h"
#include "irq.h"
#include "framebuf.h"
#include "malloc.h"
#include "channel.h"
#include "font.h"

extern void *__bss_end__;

int notmain ( void )
{
  uart_init();
  print_buf("\nBare Metal Programming For The Win!!\n");

  print_buf("\n Initializing.\n");

  enable_irq();
  malloc_init(__bss_end__);
  framebuf_init();
  task_init();

  print_buf("\n Initialization complete.\n");
  draw_char('A', 0, 0, 0xffffffff);

  while(1);
  return 0;
}
