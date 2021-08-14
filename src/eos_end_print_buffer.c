#include <arch/z80.h>

/** 
 * @brief end background sending of buffer to printer. 
 * @param c Character to send to printer
 * @return Error code, non-zero = error
*/

unsigned char eos_end_print_buffer(char c)
{
  Z80_registers r;

  AsmCall(0xFC3F,&r,REGS_ALL,REGS_ALL);
  
  return r.Bytes.A;
}
