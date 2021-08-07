#include <arch/z80.h>

/** 
 * @brief Return address of PCB
 * @return PCB address
 *
 */

unsigned short eos_find_pcb(void)
{
  Z80_registers r;
  
  AsmCall(0xFC5A,&r,REGS_ALL,REGS_ALL);
  
  return r.UWords.IY;
}
