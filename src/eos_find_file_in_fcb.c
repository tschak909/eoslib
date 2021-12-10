#include <arch/z80.h>
#include "eos.h"

/** 
 * @brief Find file of given name and type in open FCBs
 * @param filename The filename and type to check (terminated by \x03)
 * @param mode file mode if found
 * @param fcb FCB if found
*/

unsigned char eos_find_file_in_fcb(const char *filename, unsigned char *filemode, FCB *fcb)
{
  Z80_registers r;

// 5549  ;*******************************************************************************
// 5550  ;*
// 5551  ;*
// 5552  ;*   THIS ROUTINE CHECKS TO SEE IF THE FILENAME (POINTED TO BY HL)
// 5553  ;*   IS ALREADY OPEN AND EXIST IN THE FCB
// 5554  ;*
// 5555  ;*               INPUT:   HL        POINTER TO FILENAME (ETX TERMINATED)
// 5556  ;*
// 5557  ;*               OUTPUT:  CONDITION FLAGS
// 5558  ;*                        NZ        NOT IN FCB (NOT OPENED)
// 5559  ;*                                  A = ERROR CODE
// 5560  ;*                                  HL = ORIGINAL POINTER TO FILENAME
// 5561  ;*                         Z        IN FCB
// 5562  ;*                                  A = FILE NUMBER
// 5563  ;*                                  B = MODE               
// 5564  ;*                                 HL = POINTER TO START OF FCB  *   
// 5565  ;*
// 5566  ;*******************************************************************************
                       
  r.UWords.HL = filename;
  
  AsmCall(0xFCF0,&r,REGS_ALL,REGS_ALL);

  if (filemode != NULL)
    {
      *filemode = r.Bytes.B;
    }

  if (fcb != NULL)
    {
      fcb = (FCB *)r.UWords.HL;
    }
  
  return r.Bytes.A;
}
