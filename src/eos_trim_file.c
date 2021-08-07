#include <arch/z80.h>
#include "eos.h"

/** 
 * @brief Trim file to current size (for files made with 0 size)
 * @param dev The requested device #
 * @param filename The filename and type to check (terminated by \x03)
 * @return non zero = error
*/

unsigned char eos_trim_file(unsigned char dev, const char *filename)
{
  Z80_registers r;

  r.Bytes.A = dev;
  r.UWords.DE = filename;
  
  AsmCall(0xFCED,&r,REGS_ALL,REGS_ALL);

  return r.Bytes.A;
}
