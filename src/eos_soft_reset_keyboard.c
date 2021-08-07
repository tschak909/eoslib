#include <arch/z80.h>
#include "eos.h"

/** 
 * @brief Soft reset keyboard
 * @return status code 128 = complete
 *
 */

unsigned char eos_soft_reset_keyboard(void)
{
  Z80_registers r;
  
  AsmCall(0xFC93,&r,REGS_AF,REGS_AF);
  
  return r.Bytes.A;
}
