#include <arch/z80.h>

/** 
 * @brief Read buffer to VRAM
 * @param num number of characters
 * @param addr address in VRAM to start at
 * @param ch Character number to start at
 *
 */

void eos_read_vram(unsigned short num, unsigned short addr, unsigned short buf)
{
  Z80_registers r;

// 1319   ;   Name:                   READ_VRAM
// 1320   ;
// 1321   ;   Function:               Reads from VRAM and puts the read data into a buffer area.
// 1322   ;
// 1323   ;   Entry:                  BC  - number of bytes to be read
// 1324   ;                           DE  - starting VRAM address to be read from
// 1325   ;                           HL  - address of buffer to receive the read data
// 1326   ;
// 1327   ;   Exit:                   None.
// 1328   ;
// 1329   ;   Registers      used:    AF,  BC,  DE,   HL

  r.UWords.BC = num;
  r.UWords.DE = addr;
  r.UWords.HL = buf;
  
  AsmCall(0xFD1D,&r,REGS_ALL,REGS_ALL);
}
