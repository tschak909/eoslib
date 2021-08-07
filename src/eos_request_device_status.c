#include <arch/z80.h>
#include "eos.h"

/** 
 * @brief Request device status
 * @param dev the device number.
 * @return pointer to the DCB
 *
 */

unsigned char eos_request_device_status(unsigned char dev, DCB *dcb)
{
  Z80_registers r;

  r.Bytes.A = dev;
  
  AsmCall(0xFC7E,&r,REGS_ALL,REGS_ALL);
  
  dcb = (DCB *)r.UWords.IY;

  return r.Bytes.A;
}
