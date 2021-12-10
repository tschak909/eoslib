#include <arch/z80.h>
#include "eos.h"

/** 
 * @brief Create file of requested size (0 = use remainder of tape)
 * @param dev The requested device #
 * @param filename The filename and type to check (terminated by \x03)
 * @param size requested size in bytes
 * @return Error code, non-zero = error
*/

unsigned char eos_make_file(unsigned char dev, const char *filename, unsigned long size)
{
  Z80_registers r;

// 3640   ;---------------------------------------------------------------------------------
// 3641   ;
// 3642   ;  _MAKE_FILE: creates a file in the directory.
// 3643   ;
// 3644   ;  ENTRY PARAMETERS:   called with device ID in A:  address of name
// 3645   ;                  string in HL;  file size (in bytes) in BC DE.
// 3646   ;
// 3647   ;   NOTE:    IF FILE SIZE = O (BC DE), THEN THE REMAINDER OF THE TAPE IS
// 3648   ;            ALLOCATED TO THE FILE
// 3649   ;
// 3650   ;  EXIT PARAMETERS:  CONDITION   FLAGS
// 3651   ;                       Z    -   NO  ERRORS
// 3652   ;                      NZ    -   ERRORS
// 3653   ;                                 A  = ERROR CODE
// 3654   ;
// 3655   ;        ALL REGISTERS ARE PRESERVED EXCEPT AF
// 3656   ;                                       
// 3657   ;---------------------------------------------------------------------------------

  r.Bytes.A = dev;
  r.UWords.BC = size >> 16;
  r.UWords.DE = size & 0x0000FFFF;
  r.UWords.HL = filename;
  
  AsmCall(0xFCC9,&r,REGS_ALL,REGS_ALL);

  return r.Bytes.A;
}
