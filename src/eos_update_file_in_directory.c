#include <arch/z80.h>
#include "eos.h"

/** 
 * @brief Update file information in directory with directory entry data in file manager (e.g. from Find File)
 * @param dev The requested device #
 * @param filename The filename and type to check (terminated by \x03)
 * @param fcb Destination buffer for FCB
 * @return Error code, non-zero = error
*/

unsigned char eos_update_file_in_directory(unsigned char dev, const char *filename, FCB *fcb)
{
  Z80_registers r;

  r.Bytes.A = dev;
  r.UWords.DE = filename;
  r.UWords.HL = fcb;
  
  AsmCall(0xFCCF,&r,REGS_ALL,REGS_ALL);

  return r.Bytes.A;
}
