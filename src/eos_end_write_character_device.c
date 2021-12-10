#include <arch/z80.h>

/**
 * @brief End asynchronous write of character device of requested # of bytes
 * @param dev device #
 * @return error code if not 0
 */
unsigned char eos_end_write_character_device(unsigned char dev)
{
  Z80_registers r;


// 7208  ;*************************************************************************************************************
// 7209  ;*
// 7210  ;*        __END_PR_BUFF CHECKS THE DCB COMM/STATUS BYTE AND RETURNS THE  RESULT
// 7211  ;*        OF THE CHECK
// 7212  ;*
// 7213  ;*        INPUT:     NONE
// 7214  ;*
// 7215  ;*         OUTPUT:   CONDITION FLAGS
// 7216  ;*                   C:          COMMAND COMPLETED
// 7217  ;*                  NC:          COMMAND NOT COMPLETED
// 7218  ;*                   2:          NO ERRORS OCCURED
// 7219  ;*                  NZ:          ERRORS
// 7220  ;*                               A = ERROR CODE
// 7221  ;*
// 7222  ;*        ALL        REGISTERS ARE PRESERVED
// 7223  ;*
// 7224  ;*************************************************************************************************************

  r.Bytes.A = dev;
  
  AsmCall(0xFC51,&r,REGS_ALL,REGS_ALL);
  
  return r.Bytes.A;
}
