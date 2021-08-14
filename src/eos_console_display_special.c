#include <arch/z80.h>

/** 
 * @brief Display character on console, with cursor/editing processing.
 * @param c Character to display 
 * @param col column to place cursor on, for 0x1C place cursor command
 * @param row row to place cursor on, for 0x1C place cursor command
 */

void eos_console_display_special(char c, unsigned char col, unsigned char row)
{
  Z80_registers r;

  r.Bytes.A = c;
  r.Bytes.D = col;
  r.Bytes.E = row;
  
  AsmCall(0xFC39,&r,REGS_ALL,REGS_ALL);
}
