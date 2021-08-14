#include <arch/z80.h>
#include "eos.h"

/** 
 * @brief Reset (rewind) file to beginning
 * @param fileno file number.
 * @return Error code
*/

unsigned char eos_reset_file(unsigned char fileno)
{
  Z80_registers r;

  r.Bytes.A = fileno;
  
  AsmCall(0xFCC6,&r,REGS_ALL,REGS_ALL);

  return r.Bytes.A;
}
