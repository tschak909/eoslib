#include <arch/z80.h>
#include "eos.h"

/** 
 * @brief Return address of DCB for given device number
 * @param dev the device number.
 * @return DCB address.
 *
 */
DCB *eos_find_dcb(unsigned char dev)
{
  Z80_registers r;

// 6564   ;****************************************************************************************
// 6565   ;* THIS ROUTINE WILL FIND THE DCB FOR THE DEVICE DESIRED
// 6566   ;*
// 6567   ;*      INPUT:     A ==>  POINTS TO THE DEVICE ID
// 6568   ;+      OUTPUT:
// 6569   ;*                 CONDITION FLAG:
// 6570   ;*                           Z  : NO ERRORS
// 6571   ;*                                IY  ==>  POINTS TO THE START OF THE DEVICE DCB
// 6572   ;*                          NZ  : ERROR OCCURRED
// 6573   ;*                                IY  ==>  IS DESTROYED
// 6574   ;*
// 6575   ;****************************************************************************************
                       
  r.Bytes.A = dev;
  
  AsmCall(0xFC54,&r,REGS_ALL,REGS_ALL);
  
  return r.UWords.IY;
}
