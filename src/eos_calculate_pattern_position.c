#include <arch/z80.h>

/** 
 * @brief Calculate pattern position
 * @param Y position
 * @param X position
 * @return pattern position
 *
 */

unsigned short eos_calculate_pattern_position(unsigned char y, unsigned char x)
{
  Z80_registers r;

  r.Bytes.D = y;
  r.Bytes.E = x;
  
  AsmCall(0xFD32,&r,REGS_ALL,REGS_ALL);

  return r.UWords.DE;
}
