#include <arch/z80.h>

/** 
 * @brief add A to (HL)
 * @param value to add (-127,+127)
 * @param pointer to 16-bit number
 */

void eos_add_a_to_hl(char a, unsigned short* b)
{
  Z80_registers r;

  r.Bytes.A = a;
  r.UWords.HL = b;
  
  AsmCall(0xFD4D,&r,REGS_ALL,REGS_ALL);
}
