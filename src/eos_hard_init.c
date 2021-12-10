#include <arch/z80.h>

/**
 * @brief EOS Hard init
 */

void eos_hard_init(void)
{

// 8263    ;  ENTRY:              __HARD_INIT
// 8264    ;  NEEDS:              NOTHING
// 8265    ;  RETURNS:            DEFAULT PCB ADDRESS SET UP FOR USE([CURRENT_PCB] =  PCB)
// 8266    ;                      HARD RESET APPLIED TO NETWORK
// 8267    ;                      NETWORK MASTER NODE IN SYNC WITH Z80
// 8268    ;                      1 DCB ALLOTTED FOR EACH DEVICE ANSWERING A STATUS REQUEST
// 8269    ;                       CORRECTLY
// 8270    ;                      MASTER NODE SCANNING EACH OF THESE DCB’S FOR WORK TO DO

  AsmCall(0xFC5D,NULL,REGS_NONE,REGS_NONE);
}
