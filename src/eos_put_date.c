#include <arch/z80.h>

/** 
 * @brief Put system date from EOS
 * @param day day in BCD format
 * @param month month in BCD format
 * @param year year in BCD format
 * @return error code
 *
 */

unsigned char eos_put_date(unsigned char day, unsigned char month, unsigned char year)
{
  Z80_registers r;

// 5116  ; _SET_DATE   -- Set the  current   date.
// S117  ;        
// 5116  ; ENTRY PARAMETERS:   B  = day   (1..31)
// 5119  ;                     C  = month (1..12)
// 5120  ;                     D  = year  (83. .99)
// 5121  ;
// 5122  ; EXIT PARAMETERS:   none

  r.Bytes.B = day;
  r.Bytes.C = month;
  r.Bytes.D = year;
  
  AsmCall(0xFCD8,NULL,REGS_ALL,REGS_ALL);

  return r.Bytes.A;
}
