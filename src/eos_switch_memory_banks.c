#include <arch/z80.h>

/** 
 * @brief Switch MIOC memory banks
 * @param bconfig Bank Configuration
 * @return current bank configuration
 *
 * See BANK_CONFIG_* defines in eos.h for proper values.
 */

unsigned char eos_switch_memory_banks(unsigned char bconfig)
{
  Z80_registers r;

  r.Bytes.A = bconfig;
  
  AsmCall(0xfd14,&r,REGS_ALL,REGS_ALL);
}
