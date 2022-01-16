#include <arch/z80.h>

/** 
 * @brief Get Printer Status. 
 * @return Error code, non-zero = error
*/

unsigned char eos_printer_status(void)
{
  Z80_registers r;

// 7259 ;******************************************************************
// 7260 ;*THIS ROUTINE REQUESTS THE STATUS ON THE PRINTER
// 7261 ;    INPUT:   NONE
// 7262 ;    OUTPUT:
// 7263 ;           CONDITION FLAGS
// 7264 ;                    Z  : NO ERROR
// 7265 ;                   NZ  : ERROR OCCURRED
// 7266 ;                         A ===> ERROR CODE
// 7267 * 
// 7268 ;******************************************************************
  
  AsmCall(0xFC84,&r,REGS_ALL,REGS_ALL);
  
  return r.Bytes.A;
}
