#include <arch/z80.h>

/**
 * @brief end asynchronous read of block (check for data)
 * @param dev device #
 * @return error code if not 0
 */
unsigned char eos_end_read_one_block(unsigned char dev)
{
  Z80_registers r;
  
// 8944   ;*****************************************************************************
// 8945   ;*
// 8946   ;*       __END_RD_1_  BLOCK CHECKS THE STATUS AFTER A __START_RD_1_BLOCK
// 8947   ;*       IS EXECUTED
// 8948   ;*
// 8949   ;*        INPUT:   A         DEVICE   ID
// 8950   ;*                            LOW NIBBLE   - DEVICE ADDRESS
// 8951   ;*                            HI NIBBLE    - SECONDARY DEVICE ID
// 8952   ;*
// 8953   ;*       OUTPUT:   CONDITION FLAGS
// 8954   ;*                 C:   OPERATION COMPLETED
// 8955   ;*                NC:   OPERATION NOT COMPLETED
// 8956   ;*                 Z:   NO ERRORS
// 8957   ;*                NZ:   ERRORS
// 8958   ;«                           A = ERROR  CODE
// 8959   ;*
// 8960   ;*       ALL REGISTERS ARE SAVED
// 8961   ;*
// 8962   ;*****************************************************************************

  r.Bytes.A = dev;
    
  AsmCall(0xFC45,&r,REGS_ALL,REGS_ALL);
  
  return r.Bytes.A;
}
