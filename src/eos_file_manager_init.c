#include <arch/z80.h>
#include "eos.h"

/** 
 * @brief Initialize EOS file manager 
 * @param fcb_buf pointer to 3K of FCB buffers
 * @return pointer to three FCB entries
 */

FCB* eos_file_manager_init(void *fcb_buf)
{
  Z80_registers r;

// 5198   ;*************************************************************************************************************
// 5199   ;
// 5200   ;  __FMGR_INIT:   sets up everything to start  with.
// 5201   ;
// 5202   ;  ENTRY  PARAMETERS:   DE  contains address to place FCB buffers,
// 5203   ;                  and  HL contains address to place FCS headers.
// 5204   ;
// 5205   ;  EXIT  PARAMETERS:   none.
// 5206   ;
// 5207   ;*************************************************************************************************************

  r.UWords.DE = fcb_buf;
  
  AsmCall(0xFCBA,&r,REGS_ALL,REGS_ALL);

  return (FCB *)r.UWords.HL;
}
