#include <arch/z80.h>

/**
 * @brief EOS Hard init
 */

void hard_init(void)
{
  AsmCall(0xFC5D,NULL,REGS_NONE,REGS_NONE);
}
