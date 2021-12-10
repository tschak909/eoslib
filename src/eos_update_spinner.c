#include <arch/z80.h>

/** 
 * @brief Update spinner
 */

void eos_update_spinner(void)
{

// 2413 ;Update_Spinner   - Controller spin switch interrupt  service routine
// 2414 ;
// 2415 ;  This routine  processes the spinner switch interrupt and updates
// 2416 ;    the data needed by both DECODER and POLLER
// 2417 ;
// 2418 ; Ram area used:  Updates SPIN_SW0_CNT and SPIN_SW1_CNT
// 2419 ;
// 2420 ; The spinner switch maskable interrupt is RST 38H
// 2421 ;

  AsmCall(0xFD41,NULL,REGS_NONE,REGS_NONE);
}
