#include <arch/z80.h>

/**
 * @brief End asynchronous read of character device of requested # of bytes
 * @param dev device #
 * @return error code if not 0
 */
unsigned char eos_end_read_character_device(unsigned char dev)
{
  Z80_registers r;
  
  r.Bytes.A = dev;
  
  AsmCall(0xFC48,&r,REGS_ALL,REGS_ALL);
  
  return r.Bytes.A;
}
