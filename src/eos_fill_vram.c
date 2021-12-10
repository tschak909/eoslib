#include <arch/z80.h>

/** 
 * @brief Fill VRAM with value
 * @param val the value to fill
 * @param count # of bytes to fill
 * @param addr VDP address to start.
 *
 */

void eos_fill_vram(unsigned short val, unsigned short count, unsigned short addr)
{
  Z80_registers r;

// 1443  ;   Name:               FILL_VRAM
// 1444  ;
// 1445  ;   Function:           Fill a VRAM memory buffer with a constant byte value.
// 1446  ;
// 1447  ;   Entry:              A - constant byte vaiue to be written
// 1448  ;                       DE - number of bytes in the VRAM memory buffer
// 1449  ;                       HL - starting VRAM address to be written to
// 1450  ;
// 1451  ;   Exit:               None.
// 1452  ;
// 1453  ;   Registers    used:  AF, C, DE
// 1454  ;
// 1455  ;    Size:               ROM - 18 bytes
// 1456  ;                        RAM - O bytes
// 1457  ;                     
// 1458  ;    Comments:           This version of FILL_VRAM is provided for stand alone operation.
// 1459  ;                        This routine does a direct access to the COLECOVISION I/O ports.

  r.Bytes.A = val;
  r.UWords.DE = count;
  r.UWords.HL = addr;
    
  AsmCall(0xFD26,&r,REGS_ALL,REGS_ALL);
}
