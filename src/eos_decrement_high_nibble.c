#include <arch/z80.h>

/** 
 * @brief Decrement high nibble in byte
 * @param pointer to high nibble 
 * @return byte with high nibble decremented
 */

void eos_decrement_high_nibble(unsigned char *b)
{
  Z80_registers r;

  r.UWords.HL = b;
  AsmCall(0xFD47,&r,REGS_ALL,REGS_ALL);
}
