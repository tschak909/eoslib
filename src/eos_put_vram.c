#include <arch/z80.h>

/** 
 * @brief Put buffer to VRAM
 * @param table VDP_TABLE_* to update
 * @param first First entry (offset) to update
 * @param buf Pointer to buffer in main RAM
 * @param len number of entries to move
 * @return new offset
 *
 */

unsigned short eos_put_vram(unsigned char table, unsigned short first, void* buf, unsigned short len)
{
  Z80_registers r;

  r.Bytes.A = table;
  r.UWords.DE = first;
  r.UWords.HL = buf;
  r.UWords.IY = len;
  
  AsmCall(0xFD2C,&r,REGS_ALL,REGS_ALL);

  return r.UWords.HL;
}
