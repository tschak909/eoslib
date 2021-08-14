#include <arch/z80.h>

/** 
 * @brief Decrement low nibble in byte
 * @param pointer to low byte 
 * @return byte with low nibble decremented
 */

void eos_init(void)
{
  AsmCall(0xFC30,NULL,REGS_NONE,REGS_NONE);
}
