#include <arch/z80.h>

/**
 * @brief Write requested block into buffer
 * @param dev device #
 * @param blockno block number
 * @param buf target buffer
 * @return error code if not 0
 */
unsigned char eos_write_block(unsigned char dev, unsigned long blockno, void* buf)
{
  Z80_registers r;
  
// 5973 ;**************************************************************************************************
// 5974 ;*
// 5975 ;*
// 5976 ;*       WRITE_BLOCK:
// 5977 ;*                 1)  WRITES A BLOCK OUT TO TAPE
// 5978 ;*                 2)  AND CHECKS STATUS AFTER WRITE IS COMPLETED
// 5979 ;*
// 5980 ;*       INPUT:    SAME AS FOR  _WR_1_BLOCK
// 5391 ;*
// 5982 ;*                 A        DEVICE ID
// 5983 ;*                          LOW NIBBLE   - DEVICE ADDRESS
// 5984 ;*                          HI NIBBLE    - SECONDARY DEVICE ID
// 5985 ;*
// 5986 ;*                 HL       SOURCE ADDRESS OF BUFFER
// 5987 ;*
// 5988 ;*                 REGISTER PAIR   BC DE
// 5989 ;*                           SECTOR NUMBER ON DEVICE
// 5390 ;*
// 5991 ;*
// 5992 ;*        OUTPUT:   CONDITION FLAGS
// 5993 ;*                           Z:  NO ERRORS
// 5994 ;*                          NZ:  ERRORS OCCURRED
// 5995 ;*                                    A -  ERROR  CODE
// 5996 ;*
// 5997 ;*       ALL REGISTERS PRESERVED EXCEPT FOR AF
// 5998 ;*
// 5999 ;**************************************************************************************************  

  r.Bytes.A = dev;
  
  r.UWords.BC = blockno >> 16;
  r.UWords.DE = blockno & 0x0000FFFF;

  r.UWords.HL = buf;
  
  AsmCall(0xFCF6,&r,REGS_ALL,REGS_ALL);
  return r.Bytes.A;
}
