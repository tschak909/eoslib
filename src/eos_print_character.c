#include <arch/z80.h>

/** 
 * @brief Send character to printer. 
 * @param c Character to send to printer
 * @return Error code, non-zero = error
*/

unsigned char eos_print_character(char c)
{
  Z80_registers r;

// 6922 ; *********************************************************************
// 6923 ; * PRINT_CHAR ALLOWS THE CALLER TO PRINT ONE CHARACTER
// 6924 ; +      INPUT:  A ===> CHARACTER  TO  BE PRINTED
// 6925 ; *      OUTPUT: CONDITION FLAGS
// 6926 ; *              Z:      NO ERROR
// 6927 ; *              NZ:     ERROR OCCURED
// 6928 ; *                      A ===> ERROR  CODE
// 6929 ; *
// 6930 ; *********************************************************************

  r.Bytes.A = c;
  
  AsmCall(0xFC66,&r,REGS_ALL,REGS_ALL);
  
  return r.Bytes.A;
}
