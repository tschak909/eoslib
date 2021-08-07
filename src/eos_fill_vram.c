#include <arch/z80.h>

/** 
 * @brief Fill VRAM with value
 * @param val the value to fill
 * @param count # of bytes to fill
 * @param addr VDP address to start.
 *
 */

void eos_fill_vram(unsigned short val, unsigned short count, unsigned short addr)
{
  Z80_registers r;

  r.Bytes.A = val;
  r.UWords.DE = count;
  r.UWords.HL = addr;
    
  AsmCall(0xFD26,&r,REGS_ALL,REGS_ALL);
}
