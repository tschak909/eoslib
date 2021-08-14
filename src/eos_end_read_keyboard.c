#include <arch/z80.h>

/** 
 * @brief check if background keyboard read got anything, and return it.. 
 * @return character from keyboard if waiting 
*/

unsigned char eos_end_read_keyboard(void)
{
  Z80_registers r;

  AsmCall(0xFC4B,&r,REGS_ALL,REGS_ALL);
  
  return r.Bytes.A;
}
