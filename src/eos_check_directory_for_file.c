#include <arch/z80.h>

/** 
 * @brief Check directory for file (exists) 
 * @param filename The filename to check
 * @param blockno pointer to long int for block number if found
 * @return Error code, non-zero = not found
*/

unsigned char eos_check_directory_for_file(const char *filename, unsigned long *block)
{
  Z80_registers r;

  r.UWords.HL = filename;
  
  AsmCall(0xFCFC,&r,REGS_ALL,REGS_ALL);

  if (block != NULL)
    {
      *block  = r.UWords.BC << 16;
      *block |= r.UWords.DE & 0x0000FFFF;
    }
  
  return r.Bytes.A;
}
