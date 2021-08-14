#include <arch/z80.h>

/** 
 * @brief point to pattern position
 * @param offset
 * @return pattern position
 *
 */

unsigned char eos_point_to_pattern_position(unsigned short offset)
{
  Z80_registers r;

  r.UWords.DE = offset;
  AsmCall(0xFD35,&r,REGS_ALL,REGS_ALL);

  return r.Bytes.E;
}
