#include <arch/z80.h>

/** 
 * @brief End Sound
 * @param pointer to sound number
 * @param pointer to next note
 * @param pointer to sound table
 */

void eos_end_sound(unsigned short* soundno, unsigned short* nextnote, void* soundtable)
{
  Z80_registers r;

  r.UWords.DE = soundno;
  r.UWords.HL = nextnote;
  r.UWords.IX = soundtable;
  
  AsmCall(0xFD5C,NULL,REGS_ALL,REGS_ALL);
}
