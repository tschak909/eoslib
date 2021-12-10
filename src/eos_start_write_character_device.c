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
  
// 9207  ;*******************************************************************************************
// 9208  ;* START_WR_CH_DEV ALLOWS THE CALLER TO SEND A PRINT COMMAND BY SPECIFYING
// 9209  ;* THE BUFFER OF THE STRING AND THE NUMBER OF BYTES TO PRINT.
// 9210  ;*        INPUT:     A  ==>    DEVICE ID
// 9211  ;*                   BC  =>    NUMBER OF BYTES TO WRITE
// 9212  ;*                   HL  =>    SOURCE OF DATA
// 9213  ;*        OUTPUT:
// 9214  ;*                   CONDITION FLAGS
// 9215  ;*                            Z :        NO ERRORS
// 9216  ;*                            NZ:        ERROR  OCCURED
// 9217  ;*                                       A ===>  ERROR   CODE
// 9218  ;*******************************************************************************************

  r.Bytes.A = dev;
  
  r.UWords.BC = len;
  r.UWords.HL = buf;
  
  AsmCall(0xFCAE,&r,REGS_ALL,REGS_ALL);
  
  return r.Bytes.A;
}
