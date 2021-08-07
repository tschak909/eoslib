#include <arch/z80.h>

/** 
 * @brief Initialize EOS
 * @return boot device number
 *
 */

void eos_init(void)
{
  AsmCall(0xFC30,NULL,REGS_NONE,REGS_NONE);
}
