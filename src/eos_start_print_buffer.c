#include <arch/z80.h>

/** 
 * @brief Start asynchronous Send buffer to printer. terminated by \x03
 * @param c Character buffer to send to printer
 * @return Error code, non-zero = error
*/

unsigned char eos_start_print_buffer(const char *c)
{
  Z80_registers r;

// 7136   ;************************************************************************************************
// 7137   ;*  __START_PR_BUFF        ALLOWS THE CALLER TO PRINT AN ASCII ETX-TERMINATED STRING
// 7138   ;*        INPUT:       HL  ==>     ADDRESS OF ETX-TERMINATED STRING
// 7139   ;©        OUTPUT:      CONDITION FLAGS
// 7140   ;*                      Z:         NO ERROR
// 7141   ;*                     NZ:         ERROR OCCURRED
// 7142   ;*                                 A  ===> ERROR CODE
// 7143   ;*
// 7144   ;************************************************************************************************


  r.UWords.HL = c;
  
  AsmCall(0xFC9C,&r,REGS_ALL,REGS_ALL);
  
  return r.Bytes.A;
}
