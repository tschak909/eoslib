#include <arch/z80.h>

/** 
 * @brief Set VRAM table addresses
 * @param table Table number
 * @param addr VDP Address
 *
 */

void eos_set_vram_table_address(unsigned char table, unsigned short addr)
{
  Z80_registers r;

  r.Bytes.A = table;
  r.UWords.HL = addr;
  
  AsmCall(0xFD29,&r,REGS_ALL,REGS_ALL);
}
