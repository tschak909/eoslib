#include <arch/z80.h>

/** 
 * @brief Initialize Console for output
 * @param cols Desired # of columns
 * @param rows Desired # of rows
 * @param left leftmost column 
 * @param top topmost row
 * @param VDP address of pattern name table
 */

void eos_console_init(unsigned char cols, unsigned char rows, unsigned char left, unsigned char top, unsigned short addr)
{
  Z80_registers r;

  r.Bytes.B = cols;
  r.Bytes.C = rows;
  r.Bytes.D = left;
  r.Bytes.E = top;
  r.UWords.HL = addr;
  
  AsmCall(0xFC36,&r,REGS_ALL,REGS_ALL);
}
