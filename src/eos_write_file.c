#include <arch/z80.h>
#include "eos.h"

/** 
 * @brief Write requested # of bytes to opened file
 * @param fileno file number
 * @param len length of output buffer
 * @return Actual # of bytes write
*/

unsigned char eos_write_file(unsigned char fileno, unsigned short len, void *buf)
{
  Z80_registers r;

  r.Bytes.A = fileno;
  r.UWords.BC = len;
  r.UWords.HL = buf;
  
  AsmCall(0xFCD5,&r,REGS_ALL,REGS_ALL);
  
  return r.Bytes.A;
}
