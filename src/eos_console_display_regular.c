#include <arch/z80.h>

/** 
 * @brief Display character on console. 
 * @param c Character to display 
 */

void eos_console_display_regular(char c, unsigned char col, unsigned char row)
{
  Z80_registers r;

// 7420    ;
// 7421    ; __CONS_DISP      -  This entry point will put all chars onto the screen
// 7422    ;                     no matter what, no checking is done for control chars
// 7423    ;
// 7424    ;  
// 7425    ;Input Parameters:
// 7426    ;   A  - character to emit
// 7427    ;
// 7428    ;  optionally
// 7429    ;   E  - Y location to goto (must be in window)
// 7430    ;   D  - X location to goto (must be in window)
// 7431    ;
// 7432    ;
// 7433    ;   Saves   all   registers
// 7434    ;

  r.Bytes.A = c;
  r.Bytes.D = col;
  r.Bytes.E = row;

  AsmCall(0xFC33,&r,REGS_ALL,REGS_ALL);
}
