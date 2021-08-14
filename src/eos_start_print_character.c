#include <arch/z80.h>

/** 
 * @brief start background sending of character to printer. 
 * @param c Character to send to printer
 * @return Error code, non-zero = error
*/

unsigned char eos_start_print_character(char c)
{
  Z80_registers r;

  r.Bytes.A = c;
  
  AsmCall(0xFC9F,&r,REGS_ALL,REGS_ALL);
  
  return r.Bytes.A;
}
