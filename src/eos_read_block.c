#include <arch/z80.h>

/**
 * @brief Read requested block into buffer
 * @param dev device #
 * @param blockno block number
 * @param buf target buffer
 * @return error code if not 0
 */

unsigned char eos_read_block(unsigned char dev, unsigned long blockno, void* buf)
{
  Z80_registers r;

// 5837 ;******************************************************************************************
// 5838 ;*
// 5839 ;*
// 5840 ;*      READ_BLOCK:
// 5841 ;*                1)    READS 1 BLOCK OFF OF SPECIFIED DEVICE ,
// 5842 ;*                2)    REQUESTS FOR THE STATUS
// 5843 ;*                3)    AND SENDS ANOTHER READ TO THE DEVICE
// 5844 ;*
// 5845 ;*      INPUT:    SAME AS FOR  _RD_1_BLOCK
// 5846 ;*                A          DEVICE ID
// 5847 ;*                           LOW NIBBLE   -  DEVICE ADDRESS
// 5848 ;*                           HI NIBBLE    -  SECONDARY DEVICE ID
// 5849 ;*
// 5850 ;*                HL         DESTINATION IN RAM
// 5851 ;*
// 5852 ;*                REGISTER PAIR  BC DE
// 5853 ;*                           SECTOR NUMBER ON DEVICE
// 5854 ;*
// 5855 ;*
// 5856 ;*      OUTPUT:   CONDITION FLAGS
// 5857 ;*                           Z:   NO ERRORS
// 5858 ;«                          NZ:   ERROR OCCURED
// 5859 ;*                                     A - ERROR  CODE
// 5860 ;*
// 5861 ;*      ALL REGISTERS ARE PRESERVED EXCEPT FOR AF
// 5862 ;*
// 5863 ;******************************************************************************************
  
  r.Bytes.A = dev;
  
  r.UWords.BC = blockno >> 16;
  r.UWords.DE = blockno & 0x0000FFFF;

  r.UWords.HL = buf;
  
  AsmCall(0xFCF3,&r,REGS_ALL,REGS_ALL);
  
  return r.Bytes.A;
}
