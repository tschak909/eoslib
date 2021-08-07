#include <arch/z80.h>

/**
 * @brief end asynchronous read of block (check for data)
 * @param dev device #
 * @return error code if not 0
 */
unsigned char eos_end_read_one_block(unsigned char dev)
{
  Z80_registers r;
  
  r.Bytes.A = dev;
    
  AsmCall(0xFC45,&r,REGS_ALL,REGS_ALL);
  
  return r.Bytes.A;
}
