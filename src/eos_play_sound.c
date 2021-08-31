#include <arch/z80.h>

/** 
 * @brief Play Sound
 */

unsigned char eos_play_sound(void)
{
  Z80_registers r;
  
  AsmCall(0xFD59,&r,REGS_ALL,REGS_ALL);

  return r.Flags.Z;
}
