#include <arch/z80.h>
#include "eos.h"

/** 
 * @brief Update file information in directory with directory entry data in file manager (e.g. from Find File)
 * @param dev The requested device #
 * @param filename The filename and type to check (terminated by \x03)
 * @param fcb Destination buffer for FCB
 * @return Error code, non-zero = error
*/

unsigned char eos_update_file_in_directory(unsigned char dev, const char *filename, FCB *fcb)
{
  Z80_registers r;

  r.Bytes.A = dev;
  r.UWords.DE = filename;
  r.UWords.HL = fcb;
  
// 3583   ;-----------------------------------------------------------------
// 3584   ;
// 3585   ;  _SET_FILE    --   Re-write the file’s directory entry.
// 3586   ;
// 3587   ; CALLING  PARAMETERS:      Device number in A
// 3588   ;                           address of name string in DE
// 3589   ;                           address of buffer in HL
// 3590   ;
// 3591   ; EXIT  PARAMETERS:      tf no  errors    --  Z = 1; A = 0;
// 3592   ;                             directory entry updated
// 3593   ;                        if errors        --  Z = 0; A =  error code;
// 3594   ;                             directory entry unchanged
// 3595   ;
// 3596   ;-----------------------------------------------------------------

  AsmCall(0xFCCF,&r,REGS_ALL,REGS_ALL);

  return r.Bytes.A;
}
