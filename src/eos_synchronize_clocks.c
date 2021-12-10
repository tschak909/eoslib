#include <arch/z80.h>

/**
 * @brief Synchronize AdamNet and host clocks. 
 */
void eos_synchronize_clocks(void)
{
//  8416  ; ENTRY:           __SYNC
//  8417  ; NEEDS:           [CURRENTPCB] SET TO ADDRESS OF CURRENTLY OPERATING PCB
//  8418  ; RETURNS:         NETWORK MASTER NODE IN SYNC WITH Z80
//  8419  ;                  NUMBER OF DCB’S = O  (SO MASTER NODE IS NOT SCANNING
//  8420  ;                   ANY DCB’S -  SO A __SCAN_ACTIVE NEEDS TO BE DONE
//  8421  ;                   TO ESTABLISH DCB’S)
  
  AsmCall(0xFCB1,NULL,REGS_NONE,REGS_NONE);
}
