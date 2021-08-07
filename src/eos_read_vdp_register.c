#include <arch/z80.h>

/** 
 * @brief Read value from VDP control register
 */

unsigned char eos_read_vdp_register(unsigned char reg, unsigned char val)
{
  Z80_registers r;
  
  AsmCall(0xFD23,&r,REGS_AF,REGS_AF);

  return r.Bytes.A;
}
