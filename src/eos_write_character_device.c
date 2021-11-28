#include "eos.h"

/**
 * @brief Start synchronous write of character device of requested # of bytes
 * @param dev device #
 * @param buf target buffer
 * @param len requested # of bytes
 * @return error code if not 0
 */
unsigned char eos_write_character_device(unsigned char dev, void* buf, unsigned short len)
{
  unsigned char r = 0;
  
  while(1) // this loop spins until break.
    {
      r = eos_start_write_character_device(dev,buf,len);
      
      while ((r = eos_end_write_character_device(dev)) < 0x80);

      if (r == 0x9B) // upper nibble being 9 = we timed out. We restart the loop.
	continue;
      else
	break; // Otherwise, we're done.
    }
  
  return r; // return the first byte of DCB, which will be either 0x80 or 0x88
}
