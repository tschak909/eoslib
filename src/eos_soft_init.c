#include <arch/z80.h>

/**
 * @brief EOS Soft init
 * @param pcb new PCB address
 */

void soft_init(void *pcb)
{
  Z80_registers r;

  r.UWords.HL = pcb;
  
  AsmCall(0xFC8D,&r,REGS_ALL,REGS_ALL);
}
