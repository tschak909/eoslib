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

// 4618 ;------------------------------------------------------------------------------
// 4619 ;                                                                           
// 4620 ;  READ FILE   -- read some data from a file into the user’s buffer.
// 4621 ;
// 4622 ; ENTRY PARAMETERS:   device number in A; buffer address in HL;
// 4623 ;                Desired number of bytes in BC.
// 4624 ;
// 4625 ; EXIT PARAMETERS:   no  errors  -- Z = 1; A = 0
// 4626 ;                    {f  errors  -- Z = 0; A = error code;
// 4627 ;                BC  = number of bytes transferred
// 4628 ;
// 4629 ;------------------------------------------------------------------------------

  r.Bytes.A = fileno;
  r.UWords.BC = len;
  r.UWords.HL = buf;
  
  AsmCall(0xFCD2,&r,REGS_ALL,REGS_ALL);

  if (errorcode != NULL)
    *errorcode = r.Bytes.A;
  
  return r.UWords.BC;
}
