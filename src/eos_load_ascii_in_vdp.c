#include <arch/z80.h>

/** 
 * @brief Load ASCII patterns into VDP
 *
 */

void eos_load_ascii_in_vdp(void)
{
  AsmCall(0xFD38,NULL,REGS_NONE,REGS_NONE);
}
