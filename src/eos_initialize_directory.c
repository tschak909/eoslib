#include <arch/z80.h>
#include <string.h>
#include "eos.h"

/** 
 * @brief Write a new directory to the specified device
 * @param dev The requested device #
 * @param dirsize Size of directory in kilobytes
 * @param mediumsize Size of medium in kilobytes
 * @param volumename The volume name (12 bytes)
 * @return Error code, non-zero = error
*/

unsigned char eos_initialize_directory(unsigned char dev, unsigned char dirsize, unsigned short mediumsize, const char *volumename)
{
  Z80_registers r;

// 6298 ;***************************************************************************
// 6299 ;*
// 6300 ;*      __INIT_TP_DIR   INITIALIZES THE TAPE DIRECTORY
// 6301 ;*
// 6302 ;*      INPUT:    A       DEVICE ID
// 6303 ;*                        LOW NIBBLE   - DEVICE ADDRESS
// 6304 ;*                        HI NIBBLE    - SECONDARY DEVICE ID
// 6305 ;*
// 6306 ;*                C       NUMBER OF SECTORS IN DIRECTORY
// 6307 ;*                OE      NUMBER OF SECTORS ON DEVICE
// 6308 ;*
// 6309 ;*                HL      POINTER TO ASCII ETX TERMINATED STRING  
// 6310 ;*                        ( VOLUME ID ) (SHOULD BE BLANK-PADDED IF
// 63i1 ;*                        LESS THAN 12 CHARACTERS)
// 6312 ;*      OUTPUT:
// 6313 ;*                CONDITION FLAGS
// 6314 ;*                2       NO ERROR
// 6315 ;*               NZ       ERROR
// 6316 ;*                        A = ERROR  CODE
// 6317 ;*
// 6631 ;***************************************************************************

  volumename[strlen(volumename)-1]=0x03;
  
  r.Bytes.A = dev;
  r.Bytes.C = dirsize;
  r.UWords.DE = mediumsize;
  r.UWords.HL = volumename;

    
  AsmCall(0xFCBD,&r,REGS_ALL,REGS_ALL);

  return r.Bytes.A;
}
