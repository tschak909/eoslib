#include <arch/z80.h>
#include "eos.h"

/** 
 * @brief Close opened file
 * @param fileno file number.
 * @return Error code
*/

unsigned char eos_close_file(unsigned char fileno)
{
  Z80_registers r;

// 4406 ;******************************************************************************
// 4407 ;
// 4408 ; _CLOSE_FILE -- does the necessary clean-up and marks the FCB
// 4409 ;                as unused.
// 4410 ;
// 4411 ; ENTRY   PARAMETERS   --  file number in A,
// 4412 ;
// 4413 ; EXIT   PARAMETERS   --  if no error -- Z = 1;  A = O
// 4414 ;                         if error    -- Z = 0;  A = error code
// 4415 ;
// 4416 ;******************************************************************************

  r.Bytes.A = fileno;
  
  AsmCall(0xFCC3,&r,REGS_ALL,REGS_ALL);

  return r.Bytes.A;
}
