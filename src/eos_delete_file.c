#include <arch/z80.h>
#include "eos.h"

/** 
 * @brief Delete file
 * @param dev The requested device #
 * @param filename The filename and type to check (terminated by \x03)
 * @return Error code, non-zero = error
*/

unsigned char eos_delete_file(unsigned char dev, const char *filename, unsigned long size)
{
  Z80_registers r;

  r.Bytes.A = dev;
  r.UWords.HL = filename;
  
  AsmCall(0xFCE1,&r,REGS_ALL,REGS_ALL);

  return r.Bytes.A;
}
