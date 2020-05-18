#include <DefineSensor.h>

void UART1_RXINT() iv IVT_ADDR_U1RXINTERRUPT ics ICS_AUTO {
char uart_rd;
    
    U1RXIF_bit=0;
    
    while (UART1_Data_Ready()) {     // If data is received,
      uart_rd = UART1_Read();     // read the received data,

      if (uart_rd=='*') IndiceFrameIHM=0;
      else IndiceFrameIHM++;

      if (IndiceFrameIHM<TamanhoFrame) strIHM[IndiceFrameIHM]=uart_rd;
      else IndiceFrameIHM=TamanhoFrame;

      if ((uart_rd=='#')&&(IndiceFrameIHM==TamanhoFrame-1)&&(FlagCommIHM==0)){
         for (IndiceFrameIHM=0; IndiceFrameIHM<TamanhoFrame;IndiceFrameIHM++){
             FrameIHM[IndiceFrameIHM]=strIHM[IndiceFrameIHM];
         }
         FrameCompletoUART1=1;
         IndiceFrameIHM=0;
      }
    }
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------


void UART2_RXINT() iv IVT_ADDR_U2RXINTERRUPT ics ICS_AUTO {
char uart_rd;

    U2RXIF_bit=0;

    if (UART2_Data_Ready()) {     // If data is received,
       uart_rd = UART2_Read();     // read the received data,

    }
}