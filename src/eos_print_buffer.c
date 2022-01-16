#include <arch/z80.h>

/** 
 * @brief Send buffer to printer. terminated by \x03
 * @param c Character buffer to send to printer
 * @return Error code, non-zero = error
*/

unsigned char eos_print_buffer(const char *c)
{
  Z80_registers r;

// 6956 ;********************************************************************************************
// 6957 ;*
// 6958 ;*  PRINT_BUFFER    ALLOWS THE CALLER TO PRINT AN ASCII ETX-TERMINATED STRING
// 6959 ;*        INPUT:    HL  ==>   ADDRESS OF ETX-TERMINATED STRING
// 6960 ;*        OUTPUT:   CONDITION FLAGS
// 6961 ;*                  Z:        NO ERROR
// 6962 ;*                  NZ:       ERROR OCCURRED
// 6963 ;*                            A ===> ERROR CODE
// 6964 ;*
// 6965 ;********************************************************************************************

  r.UWords.HL = c;
  
  AsmCall(0xFC63,&r,REGS_ALL,REGS_ALL);
  
  return r.Bytes.A;
}
