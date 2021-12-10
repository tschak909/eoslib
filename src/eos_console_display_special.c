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

// 7416    ;
// 7417    ; __CONS_OUT       -  This entry point will check special chars such as
// 7418    ;                     Carriage Return and performs their normal functions
// 7419    ;                     all other, printable, chars are put onto the screen
// 7420    ;
// 7425    ;Input Parameters:
// 7426    ;   A  - character to emit
// 7427    ;
// 7428    ;  optionally
// 7429    ;   E  - Y location to goto (must be in window)
// 7430    ;   O  - X location to goto (must be in window)
// 7431    ;
// 7432    ;
// 7433    ;   Saves   all   registers
// 7434    ;

  r.Bytes.A = c;
  r.Bytes.D = col;
  r.Bytes.E = row;
  
  AsmCall(0xFC39,&r,REGS_ALL,REGS_ALL);
}
