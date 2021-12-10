#include <arch/z80.h>

/** 
 * @brief End Sound
 * @param pointer to sound number
 * @param pointer to next note
 * @param pointer to sound table
 */

void eos_end_sound(unsigned short* soundno, unsigned short* nextnote, void* soundtable)
{
  Z80_registers r;

// 3163 ;**********************************
// 3164 :*      LEAVE_EFFECT/EFFECT_OVER  *
// 3165 ;**********************************
// 3166
// 3167 ;LEAVEEFFECT,  called by a special sound effect routine when it’s finished,
// 3168 ;restores the SONGNO of the song to which the effect note belongs to B5 - BO  of
// 3169 ;byte 0 in the effect’s data area, and loads bytes 1 and 2 with the address  of
// 3170 ;the next note in the  song.  The address of the 1 byte SONGNO (saved by the
// 3171 ;effect when first called) is passed in DE.  The 2 byte address of the next note
// 3172 ;in the song, also saved by the effect, is passed in HL.  IX is assumed to  be
// 3173 ;pointing to byte O of the data area to which the song number is to be restored.
// 3174 ;Bits 7 and 6 of the saved SONGNO are ignored, and therefore may be used by the
// 3175 ;effect to store flag information during the course of the note.

  r.UWords.DE = soundno;
  r.UWords.HL = nextnote;
  r.UWords.IX = soundtable;
  
  AsmCall(0xFD5C,NULL,REGS_ALL,REGS_ALL);
}
