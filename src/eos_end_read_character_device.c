#include <arch/z80.h>

/**
 * @brief End asynchronous read of character device of requested # of bytes
 * @param dev device #
 * @return error code if not 0
 */
unsigned char eos_end_read_character_device(unsigned char dev)
{
  Z80_registers r;
  
  r.Bytes.A = dev;

// 928O   ;*****************************************************************************
// 9281   ;* THIS ROUTINE WILL CHECK THE  DEVICES DCB COM/STATUS BYTE AND RETURN
// 9282   ;* THE RESULT OF THE CHECK.
// 9283   ;*      INPUT:  A  ===> DEVICE  ID
// 9284   ;*      OUTPUT: CONDITION FLAGS
// 9285   ;*              C :     COMMAND HAS FINISHED
// 9286   ;*             NC :     COMMAND HAS NOT BEEN PROCESSED
// 9287   ;«              Z :     NO ERROR OCCURRED
// 9288   ;*             NZ :      ERROR OCCURRED
// 9289   ;*                      A ===> ERROR CODE
// 9290   ;*
// 9291   ;*****************************************************************************
  
  AsmCall(0xFC48,&r,REGS_ALL,REGS_ALL);
  
  return r.Bytes.A;
}
