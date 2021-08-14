#include <arch/z80.h>

/** 
 * @brief Get Keyboard Status. 
 * @return Error code, non-zero = error
*/

unsigned char eos_keyboard_status(void)
{
  Z80_registers r;

  AsmCall(0xFC81,&r,REGS_ALL,REGS_ALL);
  
  return r.Bytes.A;
}
