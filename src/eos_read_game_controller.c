#include <arch/z80.h>

/** 
 * @brief Read game controller
 * @param controller bitmap containing controller/spinners to read
 *                   bit 0 controller 0
 *                   bit 1 controller 1
 *                   bit 7 enable spinner for selected controllers
 * @param table pointer to destination buffer containing decode table
*/

void eos_read_game_controller(unsigned char controllers, void* decode)
{
  Z80_registers r;

// 2266   ;  __POLLER
// 2267   ;
// 2268   ;   Used to fill a table of values for the 2 controllers
// 2269   ;   Does some debouncing if called twice in succession
// 2270   ;
// 2271   ;   NOTE   - Does not return at bottom of code, return is in middie
// 2272   ;            Interupts will be off for a while when call to DECODE is performed.
// 2273   ;
// 2274   ;   Callers   - This has different input parameters than OS-7 and
// 2275   ;               the controller map is ordered differently.
// 2276   ;
// 2277   :
// 2278   ;Stack Usage:
// 2279   ;  will use 4 words   (2 pushes,  2  call)
// 2280   ;
// 2281   ;Calis:
// 2282   ;  __DECODER
// 2283   ;  DEBOUNCE
// 2284   ;  READ_N_DEBOUNCE      (a routine that is nested in _POLLER)
// 2285   ;
// 2286   ;Input  Parameters:
// 2287   ;  IX  - pointer to 1st byte of users controller map  (10  bytes)
// 2288   ;   A  - controller enabled and spinner enable
// 2289   ;          bit  O  - set if want controller O enabled
// 2290   ;          bit  1  - set if want controller 1 enabled
// 2291   ;          bit  7  - set if want spinner enabled for controllers which are  enabled
// 2292   ;
// 2293   ;Returns:
// 2294   ;
// 2295   ;  Data  in users   controller   map  is  like  this off  of  entry   IX value
// 2296   ;             IX+O   - joystick   O
// 2297   ;             IX+1   - fire  O
// 2298   ;             IX+2   - arm  O
// 2299   ;             IX+3   - keyboard   O
// 2300   ;             IX+4   - spinner   count  O
// 2301   ;             IX+5   - joystick   1
// 2302   ;             IX+6   - fire  1   
// 2303   ;             IX+7   - arm  1
// 2304   ;             IX+8   - keyboard  1
// 2305   ;             IX+9   - spinner count  1
// 2306   ;
// 2307   ;   IX -  points to 1 byte past users data table of highest enabled controller
// 2308   ;
// 2309   ;
// 2310   ;   all  but  IY - destroyed

  r.Bytes.A = controllers;
  r.UWords.IX = decode;

  AsmCall(0xFD3E,&r,REGS_ALL,REGS_ALL);
  
  return r.Bytes.A;
}
