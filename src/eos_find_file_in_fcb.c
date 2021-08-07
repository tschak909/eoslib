#include <arch/z80.h>
#include "eos.h"

/** 
 * @brief Find file of given name and type in open FCBs
 * @param filename The filename and type to check (terminated by \x03)
 * @param mode file mode if found
 * @param fcb FCB if found
*/

unsigned char eos_find_file_in_fcb(const char *filename, unsigned char *filemode, FCB *fcb)
{
  Z80_registers r;

  r.UWords.HL = filename;
  
  AsmCall(0xFCF0,&r,REGS_ALL,REGS_ALL);

  if (filemode != NULL)
    {
      *filemode = r.Bytes.B;
    }

  if (fcb != NULL)
    {
      fcb = (FCB *)r.UWords.HL;
    }
  
  return r.Bytes.A;
}
