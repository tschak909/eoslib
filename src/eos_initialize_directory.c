#include <arch/z80.h>
#include "eos.h"

/** 
 * @brief Write a new directory to the specified device
 * @param dev The requested device #
 * @param dirsize Size of directory in kilobytes
 * @param mediumsize Size of medium in kilobytes
 * @param volumename The volume name (12 bytes)
 * @return Error code, non-zero = error
*/

unsigned char eos_initialize_directory(unsigned char dev, unsigned char dirsize, unsigned short mediumsize, const char *volumename)
{
  Z80_registers r;

  r.Bytes.A = dev;
  r.Bytes.C = dirsize;
  r.UWords.DE = mediumsize;
  r.UWords.HL = volumename;
  
  AsmCall(0xFCBD,&r,REGS_ALL,REGS_ALL);

  return r.Bytes.A;
}
