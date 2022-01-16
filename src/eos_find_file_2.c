#include <arch/z80.h>
#include "eos.h"

/** 
 * @brief Find file of given name (matching any type)
 * @param filename The filename and type to check (terminated by \x03)
 * @param blockno pointer to long int for block number if found
 * @param directory entry
 * @return Error code, non-zero = not found
*/

unsigned char eos_find_file_2(const char *filename, DirectoryEntry *entry, unsigned long *block, unsigned char device_number)
{
  Z80_registers r;

// WE ARE FILE_QUERY

// 3516    ;-------------------------------------------------------------------------------------------------
// 3517    ;
// 3518    ;  __QUERY_FILE -- Read the file’s directory entry.  (USES STRCMP FOR FILE NAME COMPARISONS)
// 3519    ;  __FILE_QUERY -- SAME AS ABOVE BUT SETS UP SCAN_FOR_FILE FOR BASE COMPARES ( USES BASECMP )
// 3520    ;
// 3521    ;  CALLING PARAMETERS:        Device number in A
// 3522    ;                             address of name string in DE
// 3523    ;                             address of buffer in HL
// 3524    ;
// 3525    ;  EXIT PARAMETERS:       if no errors -- Z = 1;  A = 0; BCDE = file’s start block:
// 3526    ;                                  directory entry in caller’s buffer
// 3527    ;                         if errors    -- Z = 0;  A = error code;  DE =  junk;
// 3528    ;                                  caller’s buffer undefined
// 3529    ;
// 3530    ;-------------------------------------------------------------------------------------------------

  r.Bytes.A = device_number;
  r.UWords.DE = filename;
  r.UWords.HL = entry;
  
  AsmCall(0xFCFF,&r,REGS_ALL,REGS_ALL);

  if (block != NULL)
    {
      *block  = r.UWords.BC << 16;
      *block |= r.UWords.DE & 0x0000FFFF;
    }
  
  return r.Bytes.A;
}
