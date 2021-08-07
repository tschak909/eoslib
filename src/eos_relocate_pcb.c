#include <arch/z80.h>

/**
 * @brief Relocate PCB
 * @aaram pcb Pointer to new PCB address 
 */
void eos_relocate_pcb(void *pcb)
{
  Z80_registers r;

  r.UWords.HL = pcb;
  
  AsmCall(0xFC7B,&r,REGS_ALL,REGS_ALL);
}
