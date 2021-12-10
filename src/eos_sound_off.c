#include <arch/z80.h>

/** 
 * @brief Shut down sound engine
 *
 */

void eos_sound_off(void)
{
  
  AsmCall(0xFD53,NULL,REGS_NONE,REGS_NONE);
}
