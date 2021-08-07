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

  r.UWords.DE = fcb_buf;
  
  AsmCall(0xFCBA,&r,REGS_ALL,REGS_ALL);

  return (FCB *)r.UWords.HL;
}
