#include <arch/z80.h>

/**
 * @brief Start asynchronous write of character device of requested # of bytes
 * @param dev device #
 * @param buf target buffer
 * @param len requested # of bytes
 * @return error code if not 0
 */
unsigned char eos_start_write_character_device(unsigned char dev, void *buf, unsigned short len)
{
  Z80_registers r;
  
  r.Bytes.A = dev;
  
  r.UWords.BC = len;
  r.UWords.HL = buf;
  
  AsmCall(0xFCAE,&r,REGS_ALL,REGS_ALL);
  
  return r.Bytes.A;
}
