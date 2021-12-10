#include <arch/z80.h>

/**
 * @brief EOS Soft init
 * @param pcb new PCB address
 */

void soft_init(void *pcb)
{
  Z80_registers r;

// 8313 ; ENTRY:         __SOFT_INIT
// 8314 ; NEEDS:         HL = PCB ADDRESS SET UP FOR USE
// 8315 ; RETURNS:       [CURRENT_PCB]  = HL
// 8316 ;                HARD RESET APPLIED TO NETWORK
// 8317 ;                NETWORK MASTER NODE IN SYNC WITH Z80         
// 8318 ;                1 DCB ALLOTTED FOR EACH DEVICE ANSWERING A STATUS REQUEST
// 8319 ;                 CORRECTLY
// 8320 ;                MASTER NODE SCANNING EACH OF THESE DOCB’S FOR WORK TO DO

  r.UWords.HL = pcb;
  
  AsmCall(0xFC8D,&r,REGS_ALL,REGS_ALL);
}
