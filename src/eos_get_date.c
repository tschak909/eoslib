#include <arch/z80.h>

/** 
 * @brief Get system date from EOS
 * @param day day in BCD format
 * @param month month in BCD format
 * @param year year in BCD format
 * @return error code
 *
 */

unsigned char eos_get_date(unsigned char *day, unsigned char *month, unsigned char *year)
{
  Z80_registers r;
  
// 5139 ;---------------------------------------------------------------------------
// 5140 ;
// 5141 ; __GET_DATE  -- Reads the  current date.
// §142 ;
// $143 ; ENTRY PARAMETERS: none
// 5144 ;
// 6145 ; EXIT PARAMETERS: no errors  -- Z = 1; A=O
// $146 ;                                B = day
// 6147 ;                                C = month
// 6148 ;                                D = year
// 6149 ;
// $150 ;                  error  (date never set) -- Z = 0; A = error code
// 6151 ;                                B = O
// 6152 ;                                C = O
// §153 ;                                D = O
// 6154 ;---------------------------------------------------------------------------
                         
  AsmCall(0xFCDB,NULL,REGS_ALL,REGS_ALL);

  if (day != NULL)
    *day = r.Bytes.B;

  if (month != NULL)
    *month = r.Bytes.C;

  if (year != NULL)
    *year = r.Bytes.D;
  
  return r.Bytes.A;
}
