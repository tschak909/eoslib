#include <arch/z80.h>
#include "eos.h"

/** 
 * @brief Get device status (should be called after request drive status)
 * @param dev the device number.
 * @return status code
 *
 */

unsigned char eos_get_device_status(unsigned char dev)
{
  Z80_registers r;

  r.Bytes.A = dev;
  
  AsmCall(0xFCE4,&r,REGS_ALL,REGS_ALL);
  
  return r.Bytes.A;
}
