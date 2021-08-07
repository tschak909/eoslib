#include <arch/z80.h>

/** 
 * @brief Initialize Sound player
 * @param number of entries to create (0-255)
 * @param pointer to sound table
 */

void eos_sound_init(unsigned char entries, void* sound_table)
{
  Z80_registers r;

  r.Bytes.B = entries;
  r.UWords.HL = sound_table;
  
  AsmCall(0xFD50,NULL,REGS_ALL,REGS_ALL);
}
