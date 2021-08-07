#include <arch/z80.h>
#include "eos.h"

/** 
 * @brief Open file with requested mode
 * @param dev The requested device #
 * @param filename The filename and type to check (terminated by \x03)
 * @param mode the requested mode
 * @param fileno the file number
 * @return Z flag set = successful
*/

unsigned char eos_open_file(unsigned char dev, const char *filename, unsigned char mode, unsigned char *fileno)
{
  Z80_registers r;

  r.Bytes.A = dev;
  r.Bytes.B = mode;
  r.UWords.HL = filename;
  
  AsmCall(0xFCC0,&r,REGS_ALL,REGS_ALL);

  if (fileno != NULL)
    *fileno = r.Bytes.A;
  
  return r.Flags.Z;
}
