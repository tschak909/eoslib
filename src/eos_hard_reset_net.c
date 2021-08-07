#include <arch/z80.h>

/**
 * @brief HARD RESET NET
 */
void eos_hard_reset_net(void)
{
  AsmCall(0xFC60,NULL,REGS_NONE,REGS_NONE);
}
