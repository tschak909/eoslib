#include <arch/z80.h>
#include "eos.h"

/** 
 * @brief Request device status
 * @param dev the device number.
 * @return pointer to the DCB
 *
 */

unsigned char eos_request_device_status(unsigned char dev, DCB *dcb)
{
  Z80_registers r;

// 6628  ;********************************************************************************************
// 6629  ;* THIS ROUTINE WILL INITIATE A STATUS REQUEST COMMAND, AND WILL RETURN
// 6630  ;* THE RESULT OF THE COMMAND.
// 6631  ;*      INPUT:    A==>     DEVICE  ID
// 6632  ;*      OUTPUT:   CONDITION BITS
// 6633  ;*                Z:       NO ERRORS
// 6634  ;*                         IY CONTAINS START ADDRESS OF DCB
// 6635  ;*                NZ:      ERROR OCCURED
// 6636  ;*                         A ==> ERROR CODE
// 6637  ;*                         IY IS DESTROYED (MAY BE ADDRESS OF DCB
// 6638  ;*                         UNDER CERTAIN ERROR CONDITIONS)
// 6639  ;*
// 6640  ;********************************************************************************************

  r.Bytes.A = dev;
  
  AsmCall(0xFC7E,&r,REGS_ALL,REGS_ALL);
  
  dcb = (DCB *)r.UWords.IY;

  return r.Bytes.A;
}
