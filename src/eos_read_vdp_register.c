#include <arch/z80.h>

/** 
 * @brief Read value from VDP control register
 */

unsigned char eos_read_vdp_register(unsigned char reg, unsigned char val)
{
  Z80_registers r;
  
// 1416  ;     Name :                READ_REGISTER
// 1417  ;
// 1418  ;     Function:             Reads a data byte value from the Colecovision CTRL_PORT.
// 1419  ;
// 1420  ;     Entry:                None.
// 1421  ; 
// 1422  ;     Exit:                 A  -  data byte value read in
// 1423  ;
// 1424  ;     Registers used:       A,C
// 1425  ;

  AsmCall(0xFD23,&r,REGS_ALL,REGS_ALL);

  return r.Bytes.A;
}
