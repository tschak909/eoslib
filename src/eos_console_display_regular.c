#include <arch/z80.h>

/** 
 * @brief Display character on console. 
 * @param c Character to display 
 */

void eos_console_display_regular(char c)
{
  Z80_registers r;

  r.Bytes.A = c;
  
  AsmCall(0xFC33,&r,REGS_ALL,REGS_ALL);
}
