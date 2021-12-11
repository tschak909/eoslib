#include <arch/z80.h>

/** 
 * @brief Put buffer to VRAM
 * @param table VDP_TABLE_* to update
 * @param first First entry (offset) to update
 * @param buf Pointer to buffer in main RAM
 * @param len number of entries to move
 * @return new offset
 *
 */

unsigned short eos_put_vram(unsigned char table, unsigned short first, void* buf, unsigned short len)
{
  Z80_registers r;

// 1591  ;   Name:                PUT_VRAM
// 1592  ;
// 1593  ;   Function:            Gets a block of data from a user buffer and puts it into VRAM.
// 1594  ;                        The following table codes are used to identify which VRAM table
// 1595  ;                        is being referenced:
// 1596  ;
// 1597  ;                          O  - SPRITE ATTRIBUTE TABLE      (SAT)
// 1598  ;                          1  - SPRITE GENERATOR TABLE      (SGT)
// 1599  ;                          2  - PATTERN NAME TABLE          (PNT)
// 1600  ;                          3  - PATTERN GENERATOR TABLE     (PGT)
// 1601  ;                          4  - PATTERN COLOR TABLE         (PCT)
// 1602  ;
// 1603  ;   Entry:               A  -  table code (see above)
// 1604  ;                        DE -  starting index into the table
// 1605  ;                        HL -  address of user buffer
// 1606  ;                        IY -  block size (or byte count)
// 1607  ;
// 1608  ;   Exit:                None.
// 1609  ;
// 1610  ;   Registers    used:   AF, DE, HL, IY

  r.Bytes.A = table;
  r.UWords.DE = first;
  r.UWords.HL = buf;
  r.UWords.IY = len;
  
  AsmCall(0xFD2C,&r,REGS_ALL,REGS_ALL);

  return r.UWords.HL;
}
