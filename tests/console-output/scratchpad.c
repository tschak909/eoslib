/**
 * Coleco Adam Scratchpad
 */

#include <eos.h>

void main(void)
{
  int i=0;
  eos_set_vdp_ports();
  eos_write_vdp_register(0,0);
  eos_write_vdp_register(1,0xE0);
  eos_write_vdp_register(7,0xF5);
  eos_set_vram_table_address(0,0x1b00);
  eos_set_vram_table_address(1,0x3800);
  eos_set_vram_table_address(2,0x1800);
  eos_set_vram_table_address(3,0x0000);
  eos_set_vram_table_address(4,0x2000);
  eos_load_ascii_in_vdp();
  eos_fill_vram(0xF5,768,0x2000);
  eos_console_init(31,23,0,0,0x1800);
  for (;;) { eos_console_display_regular(i++); }
}
