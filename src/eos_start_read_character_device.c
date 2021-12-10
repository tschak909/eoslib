#include <arch/z80.h>

/**
 * @brief Start asynchronous read of character device of requested # of bytes
 * @param dev device #
 * @param buf target buffer
 * @param len requested # of bytes
 * @return error code if not 0
 */
unsigned char eos_start_read_character_device(unsigned char dev, void *buf, unsigned short len)
{
  Z80_registers r;

// 9238 ;***************************************************************************************
// 9239 ;* THIS ROUTINE IS RESPONSIBLE FOR SETTING UP A DEVICE DCB TO DO A READ.
// 9240 ;* THE LAST THING DONE IN THIS ROUTINE IS TO ISSUE THE COMMAND TO READ
// 9241 ;* A KEY FROM  THE KEYBOARD.
// 9242 ;*      INPUT:   A  ===>  CONTAINS THE DEVICE ID
// 9243 ;*               DE ===>  DESTINATION ADDRESS
// 9244 ;*               BC ===>  NUMBER OF BYTES TO READ
// 9245 ;*      OUTPUT:   CONDITION FLAGS
// 9246 ;*               Z:       THE READ DATA FROM KEYBOARD COMMAND HAS BEEN SENT
// 9247 ;*               NZ:      ERROR OCCURED
// 9248 ;*                        A ===>  ERROR CODE
// 9249 ;***************************************************************************************

  r.Bytes.A = dev;
  
  r.UWords.BC = len;
  r.UWords.DE = buf;
  
  AsmCall(0xFCA5,&r,REGS_ALL,REGS_ALL);
  
  return r.Bytes.A;
}
