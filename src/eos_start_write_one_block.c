#include <arch/z80.h>

/**
 * @brief Start asynchronous Write requested block into buffer
 * @param dev device #
 * @param blockno block number
 * @param buf target buffer
 * @return error code if not 0
 */
unsigned char eos_start_write_one_block(unsigned char dev, unsigned long blockno, void* buf)
{
  Z80_registers r;
  
// 9OO1   ;******************************************************************************
// 9002   ;*
// 9003   ;*      __START_WR_1_BLOCK WILL SEND A WRITE COMMAND TO WRITE A BLOCK
// 9004   ;*      OF DATA TO A BLOCK DEVICE FROM A LOCATION SPECIFIED BY REGISTER HL
// 9005   ;*
// 9006   ;*      INPUT:
// 9007   ;*               A       DEVICE ID
// 9008   ;*                       LOW NIBBLE - DEVICE ADDRESS
// 9009   ;*                       HI NIBBLE  - SECONDARY DEVICE ID
// 9010   ;*
// 9011   ;*               HL      SOURCE ADDRESS IN RAM
// 9012   ;*
// 9013   ;*               REGISTER PAIR:
// 9014   ;*                       BC DE  -  SECTOR NUMBER ON DEVICE
// 9015   ;*
// 9016   ;*
// 9017   ;«      THE TRANSFER  BYTE COUNT IS DEFINED BY “DCB _MAX_MESS LEN"
// 9018   ;*      WHICH  IS FOUND IN THE DEVICE OCB
// 9019   ;*
// 9020   ;*      OUTPUT:
// 9021   ;*               CONDITION BITS:
// 9022   ;*                       Z:  NO ERRORS
// 9023   ;*                      NZ:  ERRORS OCCURRED
// 9024   ;*                              A - ERROR CODE
// 9025   ;*
// 9026   ;*      ALL REGISTERS ARE PRESERVED
// 9027   ;*
// 9028   ;******************************************************************************

  r.Bytes.A = dev;
  
  r.UWords.BC = blockno >> 16;
  r.UWords.DE = blockno & 0x0000FFFF;

  r.UWords.HL = buf;
  
  AsmCall(0xFCAB,&r,REGS_ALL,REGS_ALL);
  
  return r.Bytes.A;
}
