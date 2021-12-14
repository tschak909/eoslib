#include <arch/z80.h>

/** 
 * @brief Check directory for file (exists) 
 * @param filename The filename to check
 * @param blockno pointer to long int for block number if found
 * @return Error code, non-zero = not found
*/

unsigned char eos_check_directory_for_file(const char *filename, unsigned long *block, unsigned char device_number)
{
  Z80_registers r;

// 5231 ;*********************************************************************************
// 5232 ;
// 5233 ; SCAN_FOR_FILE  -- Look  in the directory for a file name.
// 5234 ;                Reads each block of the directory into a buffer
// 5235 ;                (in the system’s FCB) and scans through for a
// 5236 ;                match with the caller’s string.
// 5237 ;
// 5238 ; ENTRY PARAMETERS:  address of name string in HL;  device # in A
// 5239 ;         ASSUMES  FILENAME_CMP SET UP FOR FILE COMPARES
// 5240 ;         O  - USE STRCMP ,  NOT O  - USE BASECMP   FOR FILE NAME COMPARISIONS
// 5241 ;
// 5242 ; EXIT PARAMETERS:  if match found  --Z =  1; A = 0; file’s start
// 5243 ;                block in BCDE; directory block left in buffer,
// 5244 ;                address of entry left in FCB_POINTER.
// 5245 ;
// 5246 ;                   if mo match found -- Z = 0;  A = error code;
// 5247 ;                BCDE = junk; other stuff = junk.
// 5248 ;
// 5249 ;*********************************************************************************

  r.UWords.HL = filename;
  r.Bytes.A = device_number;
  
  AsmCall(0xFCFC,&r,REGS_ALL,REGS_ALL);

  if (block != NULL)
    {
      *block  = r.UWords.BC << 16;
      *block |= r.UWords.DE & 0x0000FFFF;
    }
  
  return r.Bytes.A;
}
