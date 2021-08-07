#include <arch/z80.h>
#include "eos.h"

/** 
 * @brief Soft reset device
 * @param dev the device number.
 * @return status code 128 = complete
 *
 */

unsigned char eos_soft_reset_device(unsigned char dev)
{
  Z80_registers r;

  r.Bytes.A = dev;
  
  AsmCall(0xFC90,&r,REGS_AF,REGS_AF);
  
  return r.Bytes.A;
}
