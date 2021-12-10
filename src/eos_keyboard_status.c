#include <arch/z80.h>

/** 
 * @brief Get Keyboard Status. 
 * @return Error code, non-zero = error
*/

unsigned char eos_keyboard_status(void)
{
  Z80_registers r;

// 6816  ;**********************************************************************************
// 6817  ;* THIS ROUTINE WILL  REQUEST  A STATUS  ON THE KEYBOARD
// 6818  ;*      INPUT:  NOTHING
// 6819  ;*      OUTPUT: CONDITION FLAG
// 6820  ;*              Z:       NO ERRORS
// 6821  ;*              NZ:      ERROR OCCURED
// 6822  ;*                       A ===> ERROR CODE
// 6823  ;*
// 6824  ;**********************************************************************************

  AsmCall(0xFC81,&r,REGS_ALL,REGS_ALL);
  
  return r.Bytes.A;
}
