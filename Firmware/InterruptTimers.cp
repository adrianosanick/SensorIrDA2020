#line 1 "C:/Users/aluno/Sanick Dropbox/Adriano Padilha/Sanick/Sanick2020/SensorIrDA2020/Firmware/InterruptTimers.c"
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
#line 3 "C:/Users/aluno/Sanick Dropbox/Adriano Padilha/Sanick/Sanick2020/SensorIrDA2020/Firmware/InterruptTimers.c"
void Timer1_Interrup() iv IVT_ADDR_T1INTERRUPT ics ICS_AUTO {
 T1IF_bit = 0;

 ADCON1.F1 = 1;
 ADCON1.F15 = 1;

}


void Timer2_Interrup() iv IVT_ADDR_T2INTERRUPT ics ICS_AUTO {
 T2IF_bit = 0;
 asm CLRWDT;
}

void Timer4_Interrup() iv IVT_ADDR_T4INTERRUPT ics ICS_AUTO {
 T4IF_bit = 0;
}
