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

  r.Bytes.B = day;
  r.Bytes.C = month;
  r.Bytes.D = year;
  
  AsmCall(0xFCD8,NULL,REGS_AF,REGS_AF);

  return r.Bytes.A;
}
