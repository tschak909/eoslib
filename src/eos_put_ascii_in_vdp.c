#include <arch/z80.h>

/** 
 * @brief Put ASCII in VDP
 * @param num number of characters
 * @param addr address in VRAM to start at
 * @param ch Character number to start at
 *
 */

void eos_put_ascii_in_vdp(unsigned short num, unsigned short addr, unsigned short ch)
{
  Z80_registers r;

  r.UWords.BC = num;
  r.UWords.DE = addr;
  r.UWords.HL = ch;
  
  AsmCall(0xFD17,&r,REGS_ALL,REGS_ALL);
}
