#include <arch/z80.h>

/**
 * @brief End asynchronous write of character device of requested # of bytes
 * @param dev device #
 * @return error code if not 0
 */
unsigned char eos_end_write_character_device(unsigned char dev)
{
  Z80_registers r;
  
  r.Bytes.A = dev;
  
  AsmCall(0xFC51,&r,REGS_ALL,REGS_ALL);
  
  return r.Bytes.A;
}
