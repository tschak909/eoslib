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

//  7376 ;__CONS_INIT
//  7377 ;
//  7378 ;      Sets up the window sizes for the CONSOLE_OUT routine
//  7379 ;
//  7380 ;Input Parameters:
//  7381 ;  B - number of columns in the window  -  1, 0..31
//  7382 ;  C - number of lines in the window    -  1, 0..23
//  7383 ;  D - Absolute (0 based) X coord of  upper left corner  of. window,  0..31
//  7384 ;  E - Absolute (0 based) Y coord of  upper left corner  of  window,  0..23
//  7385 ; HL - Pattern Name Table (PNT) starting  address
//  7386 ;
//  7387 :NOTE- User  must  initialize the vVOP

  r.Bytes.B = cols;
  r.Bytes.C = rows;
  r.Bytes.D = left;
  r.Bytes.E = top;
  r.UWords.HL = addr;
  
  AsmCall(0xFC36,&r,REGS_ALL,REGS_ALL);
}
