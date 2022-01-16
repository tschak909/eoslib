#include <arch/z80.h>

/**
 * @brief Start asynchronous Read requested block into buffer
 * @param dev device #
 * @param blockno block number
 * @param buf target buffer
 * @return error code if not 0
 */
unsigned char eos_start_read_one_block(unsigned char dev, unsigned long blockno, void* buf)
{
  Z80_registers r;

// 8887  ; *      __START_RD_1_BLOCK WILL SEND A READ COMMAND TO READ A BLOCK
// 8888  ; *      OF DATA FROM A BLOCK DEVICE TO A BUFFER SPECIFIED BY REGISTER  HL
// 8889  ; *
// 8890  ; *      INPUT:    A        DEVICE ID
// 8891  ; *                         LOW NIBBLE  - DEVICE ADDRESS
// 8892  ; *                         HI NIBBLE   - SECONDARY DEVICE ID
// 8893  ; *
// 8894  ; *                HL       DESTINATION ADDRESS IN RAM
// 8895  ; *
// 8896  ; *                REGISTER  PAIR:
// 8897  ; *                          BC DE      - SECTOR NUMBER ON DEVICE
// 8898  ; *
// 8899  ; *     THE TRANSFER BYTE COUNT IS DEFINED BY “DCB_MAX_MESS_LEN" WHICH
// 8900  ; *     IS FOUND IN THE DEVICE DCB.
// 8901  ;
// 8902  ; *     OUTPUT :
// 8903  ; *                CONDITION  BITS:
// 8904  ; *                        Z:  NO ERRORS
// 8905  ; *                       NZ:  ERRORS OCCURRED
// 8906  ; *                                 A - ERROR  CODE
// 8907  ; *
// 8908  ; *      ALL REGISTERS ARE PRESERVED  

  r.Bytes.A = dev;
  
  r.UWords.BC = blockno >> 16;
  r.UWords.DE = blockno & 0x0000FFFF;

  r.UWords.HL = buf;
  
  AsmCall(0xFCA2,&r,REGS_ALL,REGS_ALL);
  
  return r.Bytes.A;
}
