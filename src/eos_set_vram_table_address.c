#include <arch/z80.h>

/** 
 * @brief Set VRAM table addresses
 * @param table Table number
 * @param addr VDP Address
 *
 */

void eos_set_vram_table_address(unsigned char table, unsigned short addr)
{
  Z80_registers r;

// 1480   ;   Name:                  INIT_TABLE
// 1481   ;
// 1482   ;   Function:              INIT TABLE initializes the addresses of the VRAM tabies.
// 1483   ;                          The passed address is converted to the correct format needed
// 1484   ;                          to setup the VDP address registers. The following tabie codes
// 1485   ;                          are use to identify which table address is being setup:
// 1486   ;
// 1487   ;                            O  - SPRITE ATTRIBUTE TABLE    (SAT)
// 1488   ;                            1  - SPRITE GENERATOR TABLE    (SGT)
// 1489   ;                            2  - PATTERN NAME TABLE        (PNT)
// 1490   ;                            3  - PATTERN GENERATOR TABLE   (PGT)
// 1491   ;                            4  - PATTERN COLOR TABLE       (PCT)
// 1492   ;
// 1493   ;   Entry:                A   -  table code (see above)
// 1494   ;                         HL  -  table address
// 1495   ;
// 1496   ;   Exit:                 None.
// 1497   ;
// 1498   ;   Registers     used:   AF,  BC,   HL,  IX,   IY

  r.Bytes.A = table;
  r.UWords.HL = addr;
  
  AsmCall(0xFD29,&r,REGS_ALL,REGS_ALL);
}
