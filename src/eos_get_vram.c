#include <arch/z80.h>

/** 
 * @brief Get buffer to VRAM
 * @param table VDP_TABLE_* to update
 * @param first First entry (offset) to update
 * @param buf Pointer to buffer in main RAM
 * @param len number of entries to move
 * @return new offset
 *
 */

unsigned short eos_get_vram(unsigned char table, unsigned short first, void* buf, unsigned short len)
{
  Z80_registers r;

// 1632  ;   Name:             GET_VRAM
// 1633  ;
// 1634  ;   Function:         Gets a block of data from VRAM and stores it into a user buffer.
// 1635  ;                     The following table codes are used to identify which vRAM table
// 1636  ;                     is being referenced:
// 1637  ;
// 1638  ;                       O - SPRITE ATTRIBUTE TABLE   (SAT).
// 1639  ;                       1 - SPRITE GENERATOR TABLE   (SGT)
// 1640  ;                       2 - PATTERN NAME TABLE       (PNT)
// 1641  ;                       3 - PATTERN GENERATOR TABLE  (PGT)
// 1642  ;                       4 - PATTERN COLOR TABEL      (PCT)
// 1643  ;
// 1644  ;   Entry:            A - table code (see above)
// 1645  ;                     DE - starting index into the table
// 1646  ;                     HL - address of user buffer
// 1647  ;                     IY - block size (or byte count)
// 1648  ;
// 1649  ;   Exit:             None.
// 1650  ;
// 1651  ;   Registers  used:  AF, DE, HL, IY
// 1652  ;
// 1653  ;   Routines  used:   SET_COUNT
// 1654  ;
// 1655  ;   Size:             ROM - O bytes
// 1656  ;                     RAM - O bytes

  r.Bytes.A = table;
  r.UWords.DE = first;
  r.UWords.HL = buf;
  r.UWords.IY = len;
  
  AsmCall(0xFD2F,&r,REGS_ALL,REGS_ALL);

  return r.UWords.HL;
}
