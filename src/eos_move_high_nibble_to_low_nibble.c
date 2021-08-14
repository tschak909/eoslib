#include <arch/z80.h>

/** 
 * @brief move high nibble to low nibble
 * @param pointer to byte
 * @return byte with high nibble moved to low nibble
 */

void eos_move_high_nibble_to_low_nibble(unsigned char *b)
{
  Z80_registers r;

  r.UWords.HL = b;
  AsmCall(0xFD4A,&r,REGS_ALL,REGS_ALL);
}
