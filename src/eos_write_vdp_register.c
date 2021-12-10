#include <arch/z80.h>

/** 
 * @brief Write value to specified VDP register
 * @param reg The target register
 * @param val New value
 */

void eos_write_vdp_register(unsigned char reg, unsigned char val)
{
  Z80_registers r;

// 1370   ;   Name:                 WRITE_REGISTER
// 1371   ;
// 1372   ;   Function:             Writes a data byte vaiue to a desired VDP register
// 1373   ;
// 1374   ;   Entry:                B - register number to write to
// 1375   ;                         C - data byte value to be written
// 1376   ;
// 1377   ;   Exit:                 if register number = 0 or 1, the  respective byte
// 1378   ;                         of the VDP_MODE_WORD is updated.
// 1379   ;
                            1380   ;   Registers     used:   A,BC,E

  r.Bytes.B = reg;
  r.Bytes.C = val;
  
  AsmCall(0xFD20,&r,REGS_ALL,REGS_ALL);
}
