#include <arch/z80.h>
#include "eos.h"

/** 
 * @brief Find file of given name (matching any type)
 * @param filename The filename and type to check (terminated by \x03)
 * @param blockno pointer to long int for block number if found
 * @param directory entry
 * @return Error code, non-zero = not found
*/

unsigned char eos_find_file_2(const char *filename, DirectoryEntry *entry, unsigned long *block)
{
  Z80_registers r;

  r.UWords.DE = filename;
  r.UWords.HL = entry;
  
  AsmCall(0xFCFF,&r,REGS_ALL,REGS_ALL);

  if (block != NULL)
    {
      *block  = r.UWords.BC << 16;
      *block |= r.UWords.DE & 0x0000FFFF;
    }
  
  return r.Bytes.A;
}
