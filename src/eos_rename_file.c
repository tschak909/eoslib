#include <arch/z80.h>
#include "eos.h"

/** 
 * @brief Rename file
 * @param dev The requested device #
 * @param oldname old filename (terminated by \x03)
 * @param newname new filename (terminated by \x03)
 * @return Error code, non-zero = error
*/

unsigned char eos_rename_file(unsigned char dev, const char *oldname, const char *newname)
{
  Z80_registers r;

  r.Bytes.A = dev;
  r.UWords.DE = oldname;
  r.UWords.HL = newname;
  
  AsmCall(0xFCDE,&r,REGS_ALL,REGS_ALL);

  return r.Bytes.A;
}
