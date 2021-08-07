#include <arch/z80.h>

/** 
 * @brief Send character to printer. 
 * @param c Character to send to printer
 * @return Error code, non-zero = error
*/

unsigned char eos_print_character(char c)
{
  Z80_registers r;

  r.Bytes.A = c;
  
  AsmCall(0xFC66,&r,REGS_AF,REGS_AF);
  
  return r.Bytes.A;
}
