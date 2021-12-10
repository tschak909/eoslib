#include <arch/z80.h>

/** 
 * @brief Write buffer to VRAM
 * @param num number of characters
 * @param addr address in VRAM to start at
 * @param ch Character number to start at
 *
 */

void eos_write_vram(unsigned short num, unsigned short addr, unsigned short buf)
{
  Z80_registers r;

// 1267   ;   Name:                WRITE_VRAM
// 1268   ;
// 1269   ;   Function:            Writes to VRAM the contents of the data in a buffer area.
// 1270   ;
// 1271   ;   Entry:               BC  -  number of bytes to be written
// 1272   ;                        DE  -  starting VRAM address to be written to
// 1273   ;                        HL  -  address of buffer containing the  data
// 1274   ;
// 1275   ;   Exit:                None.
// 1276   ;
// 1277   ;   Registers    used:   AF,  BC,   DE,   HL

  r.UWords.BC = num;
  r.UWords.DE = addr;
  r.UWords.HL = buf;
  
  AsmCall(0xFD1A,&r,REGS_ALL,REGS_ALL);
}
