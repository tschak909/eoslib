/**
 * Set up display for a SmartKeys application
 */

#include <eos.h>

void smartkeys_init(void)
{
  eos_set_vdp_ports();

  // set up for Graphics II mode
  eos_write_vdp_register(0,1);
  eos_write_vdp_register(1,0xE0);

  // Set the border color (text isn't used).
  eos_write_vdp_register(7,0x07);

  // Set up VRAM addresses
  eos_set_vram_table_address(0,0x1b00);
  eos_set_vram_table_address(1,0x3800);
  eos_set_vram_table_address(2,0x1800);
  eos_set_vram_table_address(3,0x0000);
  eos_set_vram_table_address(4,0x2000);

  // Set up system font into VDP
  eos_load_ascii_in_vdp();

  // And clear screen.
  eos_fill_vram(0xF5,768,0x2000);
}
