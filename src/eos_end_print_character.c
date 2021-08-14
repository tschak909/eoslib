#include <arch/z80.h>

/** 
 * @brief end background sending of character to printer. 
 * @param c Character to send to printer
 * @return Error code, non-zero = error
*/

unsigned char eos_end_print_character(char c)
{
  Z80_registers r;

  AsmCall(0xFC42,&r,REGS_ALL,REGS_ALL);
  
  return r.Bytes.A;
}
