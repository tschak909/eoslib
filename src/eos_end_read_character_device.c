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

// 9173 ;******************************************************************************************
// 9174 ;* THIS ROUTINE WILL INITIATE A READ COMMAND ON A CHARACTER DEVICE.   THE
// 9175 ;* ROUTINE WILL WAIT FOR THE COMMAND TO BE COMPLETED.    IF THE COMMAND
// 9176 ;* COMPLETED WITH NO ERRORS, THEN THE FLAG WILL BE ZERO. IF THERE
// 9177 ;* WERE ERRORS   THEN THE FLAG WILL BE NON-ZERO.
// 9178 ;*       INPUT:   A ==>   DEVICE  ID
// 9179 ;*                DE =>   DESTINATION  ADDRESS
// 9180 ;*                BC =>   NUMBER  OF BYTES TO READ
// 9161 ;*      OUTPUT:
// 9182 ;*                CONDITION FLAGS
// 9183 ;*                        Z:       NO ERROR
// 9184 ;*                                 A ===> KEY READ
// 9185 ;*                       NZ:       ERROR OCCURED
// 9186 ;*                                 A ===> ERROR CODE
// 9187 ;******************************************************************************************
  
  AsmCall(0xFC48,&r,REGS_ALL,REGS_ALL);
  
  return r.Bytes.A;
}
