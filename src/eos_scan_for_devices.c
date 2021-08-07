#include <arch/z80.h>

/**
 * @brief SCAN for Devices
  */
unsigned char eos_scan_for_devices(void)
{
  AsmCall(0xFC8A,NULL,REGS_NONE,REGS_NONE);
}
