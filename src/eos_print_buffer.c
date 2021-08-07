#include <arch/z80.h>

/** 
 * @brief Send buffer to printer. terminated by \x03
 * @param c Character buffer to send to printer
 * @return Error code, non-zero = error
*/

unsigned char eos_print_buffer(const char *c)
{
  Z80_registers r;

  r.UWords.HL = c;
  
  AsmCall(0xFC63,&r,REGS_ALL,REGS_ALL);
  
  return r.Bytes.A;
}
