#include <arch/z80.h>

/** 
 * @brief Read character from keyboard. 
 * @return character from keyboard 
*/

unsigned char eos_read_keyboard(void)
{
  Z80_registers r;

// 6772   ;***************************************************************************************
// 6773   ;* THIS ROUTINE   WILL READ  A  CHARACTER  FROM THE KEYBOARD
// 6774   ;*
// 6775   ;*      INPUT:    NOTHING
// 6776   ;*      OUTPUT:   CONDITION  FLAGS
// 6777   ;*                Z:       NO  ERRORS
// 6778   ;*                           A ===> CONTAINS THE KEY READ
// 6779   ;*                NZ:      ERROR OCCURRED
// 6780   ;*                           A ===> ERROR CODE
// 6781   ;*
// 6782   ;*
// 6783   ;***************************************************************************************

  AsmCall(0xFC6C,&r,REGS_ALL,REGS_ALL);
  
  return r.Bytes.A;
}
