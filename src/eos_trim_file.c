#include <arch/z80.h>
#include "eos.h"

/** 
 * @brief Trim file to current size (for files made with 0 size)
 * @param dev The requested device #
 * @param filename The filename and type to check (terminated by \x03)
 * @return non zero = error
*/

unsigned char eos_trim_file(unsigned char dev, const char *filename)
{
  Z80_registers r;

// 6104 ;*******************************************************************************************************
// 6105 ;*
// 6106 ;*
// 6107 ;*   __TRIM_FILE    RELEASES THE UNUSED BLOCKS IN THE SPECIFIED FILE
// 6108 ;*
// 6109 ;*   NOTE:    IF FILE BEING TRIMMED IS THE LAST FILE, THE UNUSED BLOCKS ARE
// 6110 ;*            ALLOCATED AS PART OF THE REMAINING AVAILABLE BLOCKS (RETURNED
// 6111 ;*            TO THE HOLE).
// 6112 ;*
// 6113 ;*        INPUT:     A         DEVICE ID
// 6114 ;*                  DE         POINTER TO FILE NAME STRING
// 6115 ;*
// 6116 ;*        OUTPUT:
// 6117 ;*                   CONDITION FLAGS
// 6118 ;*                   Z:        NO ERRORS
// 6119 ;*                  NZ:        ERRORS
// 6120 ;*                             A  -  ERROR  CODE
// 6121 ;*
// 6122 ;*******************************************************************************************************

  r.Bytes.A = dev;
  r.UWords.DE = filename;
  
  AsmCall(0xFCED,&r,REGS_ALL,REGS_ALL);

  return r.Bytes.A;
}
