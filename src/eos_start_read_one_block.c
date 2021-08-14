#include <arch/z80.h>

/**
 * @brief Start asynchronous Read requested block into buffer
 * @param dev device #
 * @param blockno block number
 * @param buf target buffer
 * @return error code if not 0
 */
unsigned char eos_start_read_one_block(unsigned char dev, unsigned long blockno, void* buf)
{
  Z80_registers r;
  
  r.Bytes.A = dev;
  
  r.UWords.BC = blockno >> 16;
  r.UWords.DE = blockno & 0x0000FFFF;

  r.UWords.HL = buf;
  
  AsmCall(0xFCA2,&r,REGS_ALL,REGS_ALL);
  
  return r.Bytes.A;
}
