#include <arch/z80.h>

/** 
 * @brief Write sprite table
 * @param Number of sprites to write
 * @param Pointer to sprite attribute table
 * @param Pointer to sprite priority table
 * @todo structures for attr and priority tables
 */

void eos_write_sprite_table(unsigned short num, void* attr, void* priority)
{
  Z80_registers r;

  r.Bytes.A = num;
  r.UWords.DE = attr;
  r.UWords.HL = priority;
  
  AsmCall(0xFD3B,&r,REGS_ALL,REGS_ALL);
}
