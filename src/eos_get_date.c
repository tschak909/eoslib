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
  
  AsmCall(0xFCDB,NULL,REGS_AF,REGS_AF);

  if (day != NULL)
    *day = r.Bytes.B;

  if (month != NULL)
    *month = r.Bytes.C;

  if (year != NULL)
    *year = r.Bytes.D;
  
  return r.Bytes.A;
}
