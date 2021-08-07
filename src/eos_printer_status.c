#include <arch/z80.h>

/** 
 * @brief Get Printer Status. 
 * @return Error code, non-zero = error
*/

unsigned char eos_printer_status(void)
{
  Z80_registers r;

  AsmCall(0xFC84,&r,REGS_AF,REGS_AF);
  
  return r.Bytes.A;
}
