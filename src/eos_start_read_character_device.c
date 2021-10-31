#include <arch/z80.h>

/**
 * @brief Start asynchronous read of character device of requested # of bytes
 * @param dev device #
 * @param buf target buffer
 * @param len requested # of bytes
 * @return error code if not 0
 */
unsigned char eos_start_read_character_device(unsigned char dev, void *buf, unsigned short len)
{
  Z80_registers r;
  
  r.Bytes.A = dev;
  
  r.UWords.BC = len;
  r.UWords.DE = buf;
  
  AsmCall(0xFCA5,&r,REGS_ALL,REGS_ALL);
  
  return r.Bytes.A;
}
