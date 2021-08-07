#include <arch/z80.h>
#include "eos.h"

/** 
 * @brief check file mode against opened FCB 
 * @param filename The filename and type to check (terminated by \x03)
 * @param fcb FCB if found
 * @return non-zero = error
 */

unsigned char eos_check_file_mode(const char *filename, FCB *fcb)
{
  Z80_registers r;

  r.UWords.HL = filename;
  r.UWords.IX = fcb;

  AsmCall(0xFCF9,&r,REGS_ALL,REGS_ALL);

  return r.Bytes.A;
}
