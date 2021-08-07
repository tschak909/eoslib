#include <arch/z80.h>
#include "eos.h"

/** 
 * @brief Close opened file
 * @param fileno file number.
 * @return Error code
*/

unsigned char eos_close_file(unsigned char fileno)
{
  Z80_registers r;

  r.Bytes.A = fileno;
  
  AsmCall(0xFCC3,&r,REGS_ALL,REGS_ALL);

  return r.Bytes.A;
}
