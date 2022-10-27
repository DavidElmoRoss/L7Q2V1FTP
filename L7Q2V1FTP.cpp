/*
    When the PIR MOTION DETECTOR detects motion it should say
    STOP on the 4 digit display and then scroll  Covid19 
    
    Where it says PUT YOUR STATEMENT HERE, put the statement that will
    make this interaction work. There may be more than one version of 
    this statement that will work.            
*/

// Include Section
#include "mbed.h"                   
#include "DigitDisplay.h"           

// Hardware definitions
DigitDisplay segment(D2,D3);          

// Global variables
unsigned char mess[]= {0x00,0x00,0x00,0x00,           
                       0x39,0x5c,0x1c,0x04,0x5e,
                       0x06,0x67,                 
                       0x00,0x00,0x00,0x00}; 
unsigned short i;
InterruptIn PIR(D6);                          
// Global Variables
short motion_detected=0;                      

// Asynchronous Interrupt Service Routine
void LOW(void)
{
   motion_detected=1;                       
} 
int main(void)
{
                                      // PUT YOUR STATEMENT HERE
    segment.clear();                
    segment.setColon(0);            
    segment.setBrightness(4);       
    
    for(;;)
    { 
       if(motion_detected==1)        
       {                                           
          segment.writeRaw(0,0x6d);    
          segment.writeRaw(1,0x78);
          segment.writeRaw(2,0x3f);
          segment.writeRaw(3,0x73);  
          wait_ms(500);
          for(i=0;i<=11;++i)             
          {
             segment.writeRaw(&mess[i]); 
               wait_ms(250);
          }
          wait_ms(1000);                
          motion_detected=0;  
        }
    }                       
}