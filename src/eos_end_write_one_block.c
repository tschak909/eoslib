#include <arch/z80.h>

/**
 * @brief end asynchronous write of block (check for data)
 * @param dev device #
 * @return error code if not 0
 */
unsigned char eos_end_write_one_block(unsigned char dev)
{
  Z80_registers r;
  
  r.Bytes.A = dev;
    
  AsmCall(0xFC4E,&r,REGS_ALL,REGS_ALL);
  
  return r.Bytes.A;
}
