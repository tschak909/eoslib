#include <arch/z80.h>

/**
 * @brief Read one requested block into buffer
 * @param dev device #
 * @param blockno block number
 * @param buf target buffer
 * @return error code if not 0
 */
unsigned char eos_read_one_block(unsigned char dev, unsigned long blockno, void* buf)
{
  Z80_registers r;
  
// 8775 ;***************************************************************************************
// 8776 ;*
// 8777 ;*   __RD_1_BLOCK  WILL READ ONE BLOCK OF DATA FROM A BLOCK  DEVICE
// 8778 ;*   TO A LOCATION SPECIFIED BY REGISTER HL
// 8779 ;*
// 8780 ;*      INPUT:   A       DEVICE ID
// 8781 ;*                       LOW NIBBLE  - DEVICE ADDRESS
// 8782 ;*                       HI NIBBLE   - SECONDARY DEVICE ID
// 8783 ;*
// 8784 ;*               HL      DESTINATION ADDRESS IN RAM
// 8785 ;*
// 8786 ;*               REGISTER PAIR.
// 8787 ;*                       BC DE       - SECTOR NUMBER ON DEVICE
// 8788 ;*
// 8789 ;*      THE TRANSFER BYTE COUNT IS DEFINED BY "DCB_MAX_MESS_LEN" WHICH
// 8790 ;*      IS FOUND IN THE DEVICE DCB.
// 8791 ;*
// 8792 ;*      OUTPUT:
// 8793 ;*               CONDITION BITS:
// 8794 ;*                       Z: NO ERRORS  
// 8795 ;*                      NZ: ERRORS  OCCURRED
// 8796 ;*                                A - ERROR CODE
// 8797 ;*
// 8798 ;*      ALL REGISTERS ARE PRESERVED
// 8799 ;*
// 8800 ;***************************************************************************************

  r.Bytes.A = dev;
  
  r.UWords.BC = blockno >> 16;
  r.UWords.DE = blockno & 0x0000FFFF;

  r.UWords.HL = buf;
  
  AsmCall(0xFC69,&r,REGS_ALL,REGS_ALL);
  
  return r.Bytes.A;
}
