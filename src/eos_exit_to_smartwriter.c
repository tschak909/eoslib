#include <arch/z80.h>

/**
 * @brief Exit to SmartWriter 
 */
void eos_exit_to_smartwriter(void)
{
  AsmCall(0xFCE7,NULL,REGS_NONE,REGS_NONE);
}
