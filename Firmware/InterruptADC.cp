#line 1 "C:/Users/aluno/Sanick Dropbox/Adriano Padilha/Sanick/Sanick2020/SensorIrDA2020/Firmware/InterruptADC.c"
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
#line 9 "C:/Users/aluno/Sanick Dropbox/Adriano Padilha/Sanick/Sanick2020/SensorIrDA2020/Firmware/InterruptADC.c"
void ADC1Int() org 0x2A {
char ADCTxx=0;
unsigned IrDA;

 IFS0.F11 = 0;
 TEST=1;

 IrDA=ADCBUF0;

 if ((UART1_Tx_Idle()==1)) UART1_Write(ADCTxx);

 TEST=0;
}
