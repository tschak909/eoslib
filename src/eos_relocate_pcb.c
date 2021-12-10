#include <arch/z80.h>

/**
 * @brief Relocate PCB
 * @aaram pcb Pointer to new PCB address 
 */
void eos_relocate_pcb(void *pcb)
{
  Z80_registers r;

// 8594  ; ENTRY:          __RELOC_PCB
// 8595  ; NEEDS:          [CURRENT_PCB] SET TO CURRENTLY OPERATING PCB
// 8596  ;                 HL = ADORESS OF WHERE PCB SHOULD BE RELOCATED TO
// 8597  ; RETURNS:        PCB RELOCATED AS REQUESTED
// 8598  ;                 [CURRENT_PCB] UPDATED TO REFLECT NEW ADDRESS
// 8599

  r.UWords.HL = pcb;
  
  AsmCall(0xFC7B,&r,REGS_ALL,REGS_ALL);
}
