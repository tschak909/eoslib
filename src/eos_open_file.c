#include <arch/z80.h>
#include "eos.h"

/** 
 * @brief Open file with requested mode
 * @param dev The requested device #
 * @param filename The filename and type to check (terminated by \x03)
 * @param mode the requested mode
 * @param fileno the file number
 * @return Z flag set = successful
*/

unsigned char eos_open_file(unsigned char dev, const char *filename, unsigned char mode, unsigned char *fileno)
{
  Z80_registers r;

// 4230    ;-----------------------------------------------------------------------------------------
// 4231    ;
// 4232    ;  _OPEN_FILE    --  Sets up an FCB for the caller to access a file.
// 4233    ;
// 4234    ;  CALLING  PARAMETERS: device number in A;   address of name string
// 4235    ;                    in HL;  mode in B.
// 4236    ;
// 4237    ;  EXIT  PARAMETERS:     if no error   --  Z = 1;  A  =  file number                                                                                      '
// 4238    ;                        if error      --  Z = 0;  A  =  error code;    B  =  junk
// 4239    ;
// 4240    ;-----------------------------------------------------------------------------------------
                             
  r.Bytes.A = dev;
  r.Bytes.B = mode;
  r.UWords.HL = filename;
  
  AsmCall(0xFCC0,&r,REGS_ALL,REGS_ALL);

  if (fileno != NULL)
    *fileno = r.Bytes.A;
  
  return r.Flags.Z;
}
