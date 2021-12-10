#include <arch/z80.h>

/** 
 * @brief Set VDP ports
 * @return Current BANK_CONFIG_*
 */

unsigned char eos_set_vdp_ports(void)
{
  Z80_registers r;
  
// 1961 ;    Port collection must be calied during initialization
// 1962 ;    It switches to OS7 ROM grabs the ports and switches back  

  AsmCall(0xFD11,&r,REGS_ALL,REGS_ALL);
  
  return r.Bytes.A;
}
