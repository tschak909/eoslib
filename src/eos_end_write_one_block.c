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

// 9062 ;*************************************************************************************************************
// 9063 ;*
// 9064 ;*       __ENO_WR_1_BLOCK WILL CHECK THE STATUS OF THE LAST OPERATION
// 9065 ;*       EXECUTED
// 9066 ;*
// 9067 ;*       INPUT:
// 9068 ;*               A        DEVICE ID
// 9069 ;*                         LOW NIBBLE  - DEVICE ADDRESS
// 9070 ;*                         HI NIBBLE   - SECONDARY DEVICE ID
// 9071 ;*
// 9072 ;*       OUTPUT:
// 9073 ;*                CONOITON  FLAGS
// 9074 ;*                         C         OPERATION COMPLETED
// 9075 ;*                        NC         OPERATION NOT COMPLETED
// 9076 ;*                         Z         NO ERRORS
// 9077 ;*                        NZ         ERRORS
// 9078 ;*                                   A = ERROR CODE
// 9079 ;*
// 9080 ;*       ALL REGISTERS ARE PRESERVED
// 9081 ;*
// 9082 ;*************************************************************************************************************    

  AsmCall(0xFC4E,&r,REGS_ALL,REGS_ALL);
  
  return r.Bytes.A;
}
