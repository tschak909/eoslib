#include <arch/z80.h>
#include "eos.h"

/** 
 * @brief Rename file
 * @param dev The requested device #
 * @param oldname old filename (terminated by \x03)
 * @param newname new filename (terminated by \x03)
 * @return Error code, non-zero = error
*/

unsigned char eos_rename_file(unsigned char dev, const char *oldname, const char *newname)
{
  Z80_registers r;

// 5725   ;*****************************************************************************************
// 5726   ;********************            EQS  RENAME   FILE     **********************************
// 5727   ;
// 5728   ;    ON ENTRY:      A   = DEVICE NUMBER    (8=TAPE1)
// 5729   ;                   DE  = POINTER TO OLD FILENAME
// $730   ;                   HL  = POINTER TO NEW FILENAME
// 5731   ;                               |
// 5732   ;    ON EXIT:        Z  =  1,  FILE RENAMED,     A = 0
// $733   ;                    Z  =  O,  FILE NOT RENAMED, A = ERROR CODE
// 5734   ;*****************************************************************************************

  r.Bytes.A = dev;
  r.UWords.DE = oldname;
  r.UWords.HL = newname;
  
  AsmCall(0xFCDE,&r,REGS_ALL,REGS_ALL);

  return r.Bytes.A;
}
