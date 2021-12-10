#include <arch/z80.h>

/** 
 * @brief Initialize EOS
 * @return boot device number
 *
 */

void eos_init(void)
{
// 8049 ;*****************************************************************
// 8050 ;                                                                
// 8051 ;   MODULE NAME;                                                 
// 8052 ;                                                                
// 8053 ;     EOS START                                                  
// 8054 ;                                                                
// 8055 ;   INPUTS:                                                      
// 8056 ;                                                                
// 8057 ;     NONE                                                        
// 8058 ;                                                                 
// 8059 ;   FUNCTION(S):                                                  
// 8060 ;       0. SET STACK.                                              
// 8061 ;       1. TO BANK SELECT OS7 AND 24K RAN.                         
// 8062 ;       2. CALL INIT_EOS TO ALLOW THE 1) THE Z280/6801 SYNCH_UP,    
// 8063 ;          POLL FOR NET DEVICES AND ESTABLISH DCB’S.               
// 8064 ;       3. CHECK FOR THE PRESENCE OF A TAPE. IF PRESENT THEN       
// 8065 ;          LOAD IN A COLD_START_LOADER  AND EXECUTE FROM THERE.     
// 8066 ;       4. IF NO TAPE, THEN BRING UP THE ROM RESIDENT WORD        
// 8067 ;          PROCESSOR BY JUMPING TO OS7.                           
// 8068 ;                                                                 
// 8069 ;   OUTPUTS:                                                     
// 8070 ;                                                                
// 8071 ;      DEVICE ADDR _ REG   B                                       
// 8072 ;                                                                
// 8073 ;   CALLS:                                                       
// 8074 ;                                                                
// 8075 ;     EOS_INIT                                                    
// 8076 ;     EOS_QUERY_DEVICE                                            
// 8077 ;     EOS_READ_BLOCK                                              
// 6078 ;                                                                
// 8079 ;   CALLED BY:                                                   
// 8060 ;                                                                
// 8081 ;     INVOKED BY EOS_BOOT                                         
// 8082 ;                                                                
// 8083 ;   NOTES:                                                       
// 8084 ;                                                                
// 8085 ;     NONE.                                                      
// 8086 ;                                                                
// 8087 ;*****************************************************************
                              
  AsmCall(0xFC30,NULL,REGS_NONE,REGS_NONE);
}
