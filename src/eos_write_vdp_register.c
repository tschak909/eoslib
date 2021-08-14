#include <arch/z80.h>

/** 
 * @brief Write value to specified VDP register
 * @param reg The target register
 * @param val New value
 */

void eos_write_vdp_register(unsigned char reg, unsigned char val)
{
  Z80_registers r;

  r.Bytes.B = reg;
  r.Bytes.C = val;
  
  AsmCall(0xFD20,&r,REGS_ALL,REGS_ALL);
}
