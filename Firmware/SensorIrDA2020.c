/*   ////
 * Project Name:
 * Copyright:

 * Revision History:
 * New Version:
*/

#include <DefineSensor.h>

const char TamanhoFrame=15;

char    ADCTx='0',
        FrameCompletoUART1=0,
        FlagCommIHM=1,
        FrameIHM[]="*0000000000000#",
        IndiceFrameIHM=0,
        strIHM[]="*0000000000000#",
        strHex[6];
        
unsigned eedata;

unsigned long eeAddr;
//-----------------------------------------------------------------------------

void main() {
unsigned i;

  // ADC setup
  TRISB   = 0xFFFF;                       // set pin as input - needed for ADC to work     */
  ADCON1  = 0x00E2;                      // Auto-stop sampling, unsigned integer out
  ADCON2  = 0x0000;
  ADCON3  = 0x1F3F;    //0x1F20;         // Sampling time= 3*Tad, minimum Tad selected  0x021A;
  ADPCFG  = 0xFFFE;                      // Configure RB0 as ADC input port
  ADCHS   = 0x0000;                      // Sample input on RB0
  ADCSSL  = 0;                           // No input scan


// Interrupts setup
  IFS0    = 0;                            // Clear flags int.
  IFS1    = 0;
  IFS2    = 0;
  INTCON1 = 0x8000;                      // Nested interrupts DISABLED
  INTCON2 = 0;
  IEC0    = 0x0808;                      // Timer1 and ADC interrupts ENABLED
  IPC0.F12= 1;                           // Timer1 interrupt priority level = 1
  IPC2.F13= 1;                           // ADC interrupt priority level = 2


  // Timer1 setup
  PR1     = 0x4E20;                      // Sampling 0x4E20 = 1000Hz ---- 0x07D0 = 10000 Hz. Value of PR1 is dependent on clock.
  T1CON   = 0x8000;                      // Timer1 ON, internal clock FCY, prescaler 1:1

  T1IF_bit = 0;                          // Clear T1IF
  T1IE_bit = 1;                        // Enable Timer1 interrupts

  // Timer2 setup
  PR2     = 0x4C4B;
                                         // Sampling 0x4C4B =  4Hz ---- 250ms    para 80MHz
  T2CON   = 0x8030;                      // Timer2 ON, internal clock FCY, prescaler 1:256

  T2IF_bit = 0;
  T2IE_bit = 1;

//Timer3 usado no pwm


  // Timer4 setup                        // Sampling 0x4C4B =  4Hz ---- 250ms    para 80MHz
  PR4     = 0x4C4B;
  T4CON   = 0x8030;                      // Timer4 ON, internal clock FCY, prescaler 1:256
  T4IF_bit = 0;                          // Clear T4IF
  T4IE_bit = 0;                        // Enable Timer4 interrupts

//Configurações das Portas PWM =0

  TRISB=0B1110111000001001;
  TRISD=0B1111111111111000;
  TRISA=0B1111111111111111;
  TRISF=0B1111111110010001;
  TRISC=0B1101111111111111;
  
  while (1){

//1
    if (FrameCompletoUART1==1){

        if (FrameIHM[1]=='z')  ADCTx=FrameIHM[13];
        if ((FrameIHM[1]>='A')&&(FrameIHM[1]<='y') ){
             
             FlagCommIHM=1;
             eeAddr=0x7FFC00+FrameIHM[1]*2;
             for (i=1; i<=4;i++) strHex[i] = FrameIHM[9+i];
             eeData = xtoi(strHex);
             FlagCommIHM=0;
             
             EEPROM_Write(eeAddr, eeData);
             while(WR_bit);
        }
    }
  }
}//~!