#include <arch/z80.h>

/** 
 * @brief point to pattern position
 * @param offset
 * @return pattern position
 *
 */

unsigned char eos_point_to_pattern_position(unsigned short offset)
{
  Z80_registers r;

// 1790  ; ********************    PX TO.PTRN.  POS  ***************************************
// 1791  ;DESCRIPTION:       DIVIDES REG DE BY 8, IF SIGNED RESULT > 127 THEN E :=  MAX SIGNED
// 1792  ;                   POSITIVE NUMBER.  IF RESULT < -128,  THEN  E := MIN NEGATIVE NUM
// 1793  ;INPUT:              DE =  16  BIT SIGNED  NUMBER
// 1794  ;OUTPUT:             DE/8 < -128       E =  -128
// 1795  ;        -128   <= DE/8   <=+127      E  = DE/8
// 1796  ;        +127   <  DE/8               E  = +127
// 1797  ; *********************************************************************************  

  r.UWords.DE = offset;
  AsmCall(0xFD35,&r,REGS_ALL,REGS_ALL);

  return r.Bytes.E;
}
