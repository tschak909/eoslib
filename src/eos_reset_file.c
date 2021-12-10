#include <arch/z80.h>
#include "eos.h"

/** 
 * @brief Reset (rewind) file to beginning
 * @param fileno file number.
 * @return Error code
*/

unsigned char eos_reset_file(unsigned char fileno)
{
  Z80_registers r;

// 4489  ;------------------------------------------------------------------------
// 4490  ;
// 4491  ;  _RESET_FILE   --  rewinds the file back to the first  byte.
// 4492  ;
// 4493  ;  ENTRY  PARAMETERS:    file number in A
// 4494  ;
// 4495  ;  EXIT  PARAMETERS:    no error   --  Z = 1; A=O
// 4496  ;                       if error   --  Z = O; A = error code
// 4497  ;
// 4498  ;------------------------------------------------------------------------

  r.Bytes.A = fileno;
  
  AsmCall(0xFCC6,&r,REGS_ALL,REGS_ALL);

  return r.Bytes.A;
}
