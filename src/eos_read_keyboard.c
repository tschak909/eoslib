#include <arch/z80.h>

/** 
 * @brief Read character from keyboard. 
 * @return character from keyboard 
*/

unsigned char eos_read_keyboard(void)
{
  Z80_registers r;

  AsmCall(0xFC6C,&r,REGS_ALL,REGS_ALL);
  
  return r.Bytes.A;
}
