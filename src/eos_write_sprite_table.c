#include <arch/z80.h>

/** 
 * @brief Write sprite table
 * @param Number of sprites to write
 * @param Pointer to sprite attribute table
 * @param Pointer to sprite priority table
 * @todo structures for attr and priority tables
 */

void eos_write_sprite_table(unsigned short num, void* attr, void* priority)
{
  Z80_registers r;

// 2004 ;  Name:              WR_SPR_ATTRIBUTE
// 2005 ;
// 2006 ;  Function:          Transfers the local copy of the sprite attribute table
// 2007 ;                     to VRAM.   WR_SPR_ATTRIBUTE will also reorder the
// 2008 ;                     sprite table to reduce 5th sprite priority problems.
// 2009 ;
// 2010 ;  Entry:             DE - address of Local Sprite Table
// 2011 ;                     HL - address of Priority table
// 2012 ;                      A - number of sprites to be transfered (length of Local Sprite
// 2013 ;                            table divided by 4
// 2014 ;  Exit:              None.
// 2015 ;
// 2016 ;  Registers   usec:  AF, BC,  DE, Hi.

  r.Bytes.A = num;
  r.UWords.DE = attr;
  r.UWords.HL = priority;
  
  AsmCall(0xFD3B,&r,REGS_ALL,REGS_ALL);
}
