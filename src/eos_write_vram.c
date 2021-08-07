#include <arch/z80.h>

/** 
 * @brief Write buffer to VRAM
 * @param num number of characters
 * @param addr address in VRAM to start at
 * @param ch Character number to start at
 *
 */

void eos_write_vram(unsigned short num, unsigned short addr, unsigned short buf)
{
  Z80_registers r;

  r.UWords.BC = num;
  r.UWords.DE = addr;
  r.UWords.HL = buf;
  
  AsmCall(0xFD1A,&r,REGS_ALL,REGS_ALL);
}
