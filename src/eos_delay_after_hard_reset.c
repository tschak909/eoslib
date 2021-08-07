#include <arch/z80.h>

/**
 * @brief Delay 114 clock cycles after eos_hard_reset_net() 
 */
void eos_delay_after_hard_reset_net(void)
{
  AsmCall(0xFC3C,NULL,REGS_NONE,REGS_NONE);
}
