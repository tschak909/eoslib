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

// 5659 ;*******************************************************************************
// S660 ;
// 5661 ; MODE_CHECK:  sees if an attribute byte matches a permission request.
// 5662 ;
// 5663 ; ENTRY PARAMETERS: IX- FCB POINTER
// 5664 ;                   HL- DIR ENTRY
// 5665 ; EXIT PARAMETERS:  2=1=0K
// 5666 ;                   Z=0=NO WAY
// 5667 ;                   A=TRASH
// 5668 ;                   IX AND HL PRESERVED
// 5669 ; DLS(8/30/83)
// 5670 ;*******************************************************************************

  r.UWords.HL = filename;
  r.UWords.IX = fcb;

  AsmCall(0xFCF9,&r,REGS_ALL,REGS_ALL);

  return r.Bytes.A;
}
