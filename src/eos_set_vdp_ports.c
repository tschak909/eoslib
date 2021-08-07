#include <arch/z80.h>

/** 
 * @brief Set VDP ports
 * @return Current BANK_CONFIG_*
 */

unsigned char eos_set_vdp_ports(void)
{
  Z80_registers r;
  
  AsmCall(0xFD11,&r,REGS_AF,REGS_AF);
  
  return r.Bytes.A;
}
