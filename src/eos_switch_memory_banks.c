#include <arch/z80.h>

/** 
 * @brief Switch MIOC memory banks
 * @param bconfig Bank Configuration
 * @return current bank configuration
 *
 * See BANK_CONFIG_* defines in eos.h for proper values.
 */

unsigned char eos_switch_memory_banks(unsigned char bconfig)
{
  Z80_registers r;

// 1920  ;    Switch_mem:  memory bank switching routine
// 1921  ;
// 1922  ;    Inputs:
// 1923  ;                 A = Appropriate input from  SWITCH TABLE
// 1924  ;
// 1925  ;                  Example:
// 1926  ;     Switch Table  Offset    Memory  configuration
// 1927  ;    *************************************************************************
// 1928  ;
// 1929  ;             0 -          Boot ROM and Alpha Roms
// 1930  ;             1 -          Intrinsic RAM (OOOOH  thru 7FFFH)
// 1931  ;             2 -          Expansion memory (OOOOH thru 7FFFH)
// 1932  ;             3 -          OS_7 and Intrinsic RAM (2000H thru 7FFFH)
// 1933  ;             4
// 1934  ;             .
// 1935  ;             D
// 1936  ;             E
// 1937  ;             F
// 1938  ;
// 1939  ;   *** Note: The values in the table are subject to change in future
// 1940  ;             releases of ADAM  hardware.
// 1941  ;
// 1942  ;   For an example  of the use  of SWITCH MEM   see PORT COLLECTION    below.
// 1943  ;
// 1944  ;
// 1945  ;    Outputs:
// 1946  ;                  CUR_BANK, a defined memory location will contain
// 1947  ;                  the updated input parameter for applications and
// 1948  ;                  EOS routines which need to determine  which
// 1949  ;                  memory space is currently active.

  r.Bytes.A = bconfig;
  
  AsmCall(0xfd14,&r,REGS_ALL,REGS_ALL);
}
