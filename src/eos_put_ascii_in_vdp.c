#include <arch/z80.h>

/** 
 * @brief Put ASCII in VDP
 * @param num number of characters
 * @param addr address in VRAM to start at
 * @param ch Character number to start at
 *
 */

void eos_put_ascii_in_vdp(unsigned short num, unsigned short addr, unsigned short ch)
{
  Z80_registers r;

// 1860 ;  __PUT_ASCII
// 1861 ;
// 1862 ;       Copys a specified number of ASCII character generators into VRAM.
// 1863 ;       Swaps to ROM that contains the generators then swaps back, keeps
// 1864 ;       track of callers stack and uses a local stack that is known to
// 1865 ;       be in RAM when the ROM is swapped in.
// 1866 ;
// 1867 ;Input  Parameters:
// 1868 ;  HL  - Character to 1st  load (generally in range O..FFH)
// 1869 ;  BC  - Number of characters to load  (Not the number of bytes)
// 1870 ;  DE  - Address in VRAM  to load the 1st generator
// 1871 ;
// 1872 ;  A,  BC, HL,  DE, IX  are  destroyed
// 1873 ;
// 1874 ;  Calis  WRITE_VRAM
// 1875 ;         SWITCH_MEM

  r.UWords.BC = num;
  r.UWords.DE = addr;
  r.UWords.HL = ch;
  
  AsmCall(0xFD17,&r,REGS_ALL,REGS_ALL);
}
