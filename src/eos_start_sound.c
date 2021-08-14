#include <arch/z80.h>

/** 
 * @brief Start sound playback of sound number #
 * @param soundno sound number
 * @param pointer to end of sound data
 * @param pointer to next note
 * @param pointer to sound data table
 * @return =0 if successful, any other value means sound in progress
*/

unsigned char eos_start_sound(unsigned char soundno, void* end, void* nextnote, void* table)
{
  Z80_registers r;

  r.Bytes.B = soundno;
  r.UWords.HL = end;
  
  AsmCall(0xFC56,&r,REGS_ALL,REGS_ALL);

  nextnote = r.UWords.HL;
  table = r.UWords.IX;
  
  return r.Bytes.A;
}
