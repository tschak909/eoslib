#include <arch/z80.h>

/** 
 * @brief End Sound
 */

void eos_end_sound(void)
{
  AsmCall(0xFD5C,NULL,REGS_NONE,REGS_NONE);
}
