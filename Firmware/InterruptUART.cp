#line 1 "C:/Users/aluno/Sanick Dropbox/Adriano Padilha/Sanick/Sanick2020/SensorIrDA2020/Firmware/InterruptUART.c"
#line 1 "c:/users/aluno/sanick dropbox/adriano padilha/sanick/sanick2020/sensorirda2020/firmware/definesensor.h"
sbit TEST at LATB2_bit;

sbit LED at LATB1_bit;
sbit Sel485 at LATD1_bit;

sbit BotaoOperacao at RB3_bit;

sbit In11 at RB9_bit;
sbit In12 at RB10_bit;
sbit In13 at RB11_bit;


sbit Out11 at RB12_bit;
sbit Out12 at RB4_bit;
sbit Out13 at LATD2_bit;


extern const char TamanhoFrame;

extern char ADCTx,
 FrameCompletoUART1,
 FlagCommIHM,
 FrameIHM[],
 IndiceFrameIHM,
 strIHM[],
 strHex[];

extern unsigned eedata;

extern unsigned long eeAddr;
#line 3 "C:/Users/aluno/Sanick Dropbox/Adriano Padilha/Sanick/Sanick2020/SensorIrDA2020/Firmware/InterruptUART.c"
void UART1_RXINT() iv IVT_ADDR_U1RXINTERRUPT ics ICS_AUTO {
char uart_rd;

 U1RXIF_bit=0;

 while (UART1_Data_Ready()) {
 uart_rd = UART1_Read();

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





void UART2_RXINT() iv IVT_ADDR_U2RXINTERRUPT ics ICS_AUTO {
char uart_rd;

 U2RXIF_bit=0;

 if (UART2_Data_Ready()) {
 uart_rd = UART2_Read();

 }
}
