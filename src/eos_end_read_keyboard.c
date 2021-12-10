#include <arch/z80.h>

/** 
 * @brief check if background keyboard read got anything, and return it.. 
 * @return character from keyboard if waiting 
*/

unsigned char eos_end_read_keyboard(void)
{
  Z80_registers r;

// 6865   ;******************************************************************************************
// 6866   ;*  THIS ROUTINE WILL CHECK THE RESULT OF A COMMAND THAT WAS SENT.  IF THE
// 6867   ;*  RESULT IS A NAK THEN THE ROUTINE WILL ISSUE A NEW READ COMMAND.
// 6868   ;*           INPUT:       NOTHING
// 6869   ;*           OUTPUT:      CONDITION FLAG
// 6870   ;*                        C:           COMMAND HAS FINISHED
// 6871   ;*                        NC:          COMMAND HAS NOT BEEN FINISHED
// 6872   ;*                        a:           NO ERROR OCCURED
// 6873   ;*                        NZ:          ERROR OCCURED
// 6874   ;*                                     A ===> ERROR CODE
// 6875   ;******************************************************************************************
                                           
  AsmCall(0xFC4B,&r,REGS_ALL,REGS_ALL);
  
  return r.Bytes.A;
}
