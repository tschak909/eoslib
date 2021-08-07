#include <arch/z80.h>

/** 
 * @brief Play Sound
 */

void eos_play_sound(void)
{
  AsmCall(0xFD59,NULL,REGS_NONE,REGS_NONE);
}
