#include <arch/z80.h>
#include "eos.h"

/** 
 * @brief Return address of DCB for given device number
 * @param dev the device number.
 * @return DCB address.
 *
 */
DCB *eos_find_dcb(unsigned char dev)
{
  Z80_registers r;

  r.Bytes.A = dev;
  
  AsmCall(0xFC54,&r,REGS_ALL,REGS_ALL);
  
  return r.UWords.IY;
}
