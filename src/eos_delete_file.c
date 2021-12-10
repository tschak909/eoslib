#include <arch/z80.h>
#include "eos.h"

/** 
 * @brief Delete file
 * @param dev The requested device #
 * @param filename The filename and type to check (terminated by \x03)
 * @return Error code, non-zero = error
*/

unsigned char eos_delete_file(unsigned char dev, const char *filename, unsigned long size)
{
  Z80_registers r;

// 5789  ;****************************************************************
// 5790  ;***********************  EOS_DELETE_FILE  **********************
// 5791  ;
// 5792  ;   ON ENTRY:    A = DEVICE NUMBER  (8=TAPE1)
// 5793  ;               HL = POINTER  TO FILENAME
// 5794  ;
// 5795  ;    ON EXIT:     Z =  1,FILE DELETED,     A = 0
// 5796  ;                 Z =  O,FILE NOT DELETED, A = ERROR CODE
// $797  ;
// 5798  ;****************************************************************
                          
  r.Bytes.A = dev;
  r.UWords.HL = filename;
  
  AsmCall(0xFCE1,&r,REGS_ALL,REGS_ALL);

  return r.Bytes.A;
}
