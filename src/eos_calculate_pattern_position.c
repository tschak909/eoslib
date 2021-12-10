#include <arch/z80.h>

/** 
 * @brief Calculate pattern position
 * @param Y position
 * @param X position
 * @return pattern position
 *
 */


unsigned short eos_calculate_pattern_position(unsigned char y, unsigned char x)
{
  Z80_registers r;

// 1747   ;*******************      CALC  OFFSET    *****************************************************************
// 1748   ;
// 1749   ;DESCRIPTION:         THIS ROUTINE CALCULATES THE PROPER OFFSET INTO THE NAME TABLE
// 1750   ;                     FOR THE PATTERN POSITION GIVEN BY X PAT_POS, Y_PAT_POS. THE
// 1751   ;                     FORMULA USED IS:   OFFSET =  32*Y_PAT_POS + XPAT_POS
// 1752   ;
// 1753   ;INPUT:               D  =   X_PAT_POS
// 1754   ;                     E  =   Y_PaT_POS
// 1755   ;
// 1756   ;OUTPUT  -            DE =   OFFSET
// 1757   ;
// 1758   ;**********************************************************************************************************


  r.Bytes.D = y;
  r.Bytes.E = x;

  AsmCall(0xFD32,&r,REGS_ALL,REGS_ALL);

  return r.UWords.DE;
}
