#include <DefineSensor.h>


//---------------------------------------------------------------------------
// This is ADC interrupt handler.
// Analogue input is sampled and the value is stored into input buffer.
// Input buffer is then passed through filter.
// Finally, the resulting output sample is sent to DAC.
void ADC1Int() org 0x2A {              // ADC interrupt handler
char ADCTxx=0;
unsigned IrDA;

  IFS0.F11 = 0;                          // Clear AD1IF
  TEST=1;

  IrDA=ADCBUF0;                          //Leitura do ADC

  if ((UART1_Tx_Idle()==1)) UART1_Write(ADCTxx);

  TEST=0;
}//~