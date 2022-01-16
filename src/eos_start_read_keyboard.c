#include <arch/z80.h>

/** 
 * @brief start background reading of keyboard 
 * @return Error code, non-zero = error
*/

unsigned char eos_start_read_keyboard(void)
{
  Z80_registers r;

// 6835 ;***********************************************************************************
// 6836 ;* THIS ROUTINE  WILL START A READ DATA COMMAND ON THE KEYBOARD
// 6837 ;*      INPUT:   NOTHING
// 6838 ;*      OUTPUT:  CONDITION FLAGS
// 6839 ;*               Z :     NO ERROR
// 6840 ;*               NZ:     ERROR OCCURRED
// 6841 ;*                        A ===> ERROR CODE
// 6842 ;***********************************************************************************

AsmCall(0xFCA8,&r,REGS_ALL,REGS_ALL);
  
  return r.Bytes.A;
}
