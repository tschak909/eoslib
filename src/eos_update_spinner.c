#include <arch/z80.h>

/** 
 * @brief Update spinner
 */

void eos_update_spinner(void)
{
  AsmCall(0xFD41,NULL,REGS_NONE,REGS_NONE);
}
