#include <arch/z80.h>

/** 
 * @brief Initialize Sound player
 * @param number of entries to create (0-255)
 * @param pointer to sound table
 */

void eos_sound_init(unsigned char entries, void* sound_table)
{
  Z80_registers r;

// 2861  ;****************************
// 2862  ;*       INIT_SOUND         *
// 2863  ;****************************
// 2864 
// 2865  ;See Users’ Manuai for description;   includes ENTRY_POINT_ALL_OFF
// 2866  ;addr LST_OF_SND_ADDRS passed in HL
// 2867  ;n = # of song data areas to init, passed in B

  r.Bytes.B = entries;
  r.UWords.HL = sound_table;
  
  AsmCall(0xFD50,NULL,REGS_ALL,REGS_ALL);
}
