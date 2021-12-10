#include <arch/z80.h>

/** 
 * @brief Load ASCII patterns into VDP
 *
 */

void eos_load_ascii_in_vdp(void)
{

// 1832  ; _LOAD_ASCII
// 1833  ;
// 1834  ;     Loads the ASCII character generators into VRAM at the
// 1835  ;     current pattern generator table (NOTE - INIT_TABLE must
// 1836  ;     have been called prior to this).  Only the characters
// 1837  ;     from the space to the DEL (20h to 7Fh) are loaded.
// 1838  ;
// 1839  ;Input   Parameters:
// 1840  ;   NONE
// 1841  ;
// 1842  ;Returns:
// 1843  ;   A, 8C, HL, DE are destroyed
// 1844  ;
// 1845  ;  Falls into _PUT_ASCII
  
  AsmCall(0xFD38,NULL,REGS_NONE,REGS_NONE);
}
