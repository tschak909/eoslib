#include <arch/z80.h>

/**
 * @brief Synchronize AdamNet and host clocks. 
 */
void eos_synchronize_clocks(void)
{
  AsmCall(0xFCB1,NULL,REGS_NONE,REGS_NONE);
}
