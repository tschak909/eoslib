#include <arch/z80.h>

/** 
 * @brief start background reading of keyboard 
 * @return Error code, non-zero = error
*/

unsigned char eos_start_read_keyboard(void)
{
  Z80_registers r;

  AsmCall(0xFCA8,&r,REGS_ALL,REGS_ALL);
  
  return r.Bytes.A;
}
