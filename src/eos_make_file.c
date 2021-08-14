#include <arch/z80.h>
#include "eos.h"

/** 
 * @brief Create file of requested size (0 = use remainder of tape)
 * @param dev The requested device #
 * @param filename The filename and type to check (terminated by \x03)
 * @param size requested size in bytes
 * @return Error code, non-zero = error
*/

unsigned char eos_make_file(unsigned char dev, const char *filename, unsigned long size)
{
  Z80_registers r;

  r.Bytes.A = dev;
  r.UWords.BC = size >> 16;
  r.UWords.DE = size & 0x0000FFFF;
  r.UWords.HL = filename;
  
  AsmCall(0xFCC9,&r,REGS_ALL,REGS_ALL);

  return r.Bytes.A;
}
