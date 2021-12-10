#include <arch/z80.h>

/**
 * @brief SCAN for Devices
  */
unsigned char eos_scan_for_devices(void)
{

// 8509   ; ENTRY:         __SCAN_ACTIVE
// 8510   ; NEEDS:         [CURRENT_PCB] SET TO CURRENTLY OPERATING PCB
// 8511   ; RETURNS:       1 DCB ALLOTTED FOR EACH DEVICE ANSWERING A STATUS REQUEST
// 8512   ;                CORRECTLY
// 6513   ;                MASTER NODE SCANNING EACH OF THESE DCB’S FOR WORK TO DO

  AsmCall(0xFC8A,NULL,REGS_NONE,REGS_NONE);
}
