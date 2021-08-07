#include <arch/z80.h>
#include "eos.h"

/** 
 * @brief Read requested # of bytes from opened file
 * @param fileno file number
 * @param len requested length
 * @param error ptr to returned error code
 * @return Actual # of bytes read
*/

unsigned short eos_read_file(unsigned char fileno, unsigned short len, void *buf, unsigned char *errorcode)
{
  Z80_registers r;

  r.Bytes.A = fileno;
  r.UWords.BC = len;
  r.UWords.HL = buf;
  
  AsmCall(0xFCD2,&r,REGS_ALL,REGS_ALL);

  if (errorcode != NULL)
    *errorcode = r.Bytes.A;
  
  return r.UWords.BC;
}
