#include <arch/z80.h>

/** 
 * @brief Read game controller
 * @param controller bitmap containing controller/spinners to read
 *                   bit 0 controller 0
 *                   bit 1 controller 1
 *                   bit 7 enable spinner for selected controllers
 * @param table pointer to destination buffer containing decode table
*/

void eos_read_game_controller(unsigned char controllers, void* decode)
{
  Z80_registers r;

  r.Bytes.A = controllers;
  r.UWords.IX = decode;

  AsmCall(0xFD3E,&r,REGS_ALL,REGS_ALL);
  
  return r.Bytes.A;
}
