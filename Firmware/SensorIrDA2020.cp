#line 1 "C:/Users/aluno/Sanick Dropbox/Adriano Padilha/Sanick/Sanick2020/SensorIrDA2020/Firmware/SensorIrDA2020.c"
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
#line 11 "C:/Users/aluno/Sanick Dropbox/Adriano Padilha/Sanick/Sanick2020/SensorIrDA2020/Firmware/SensorIrDA2020.c"
const char TamanhoFrame=15;

char ADCTx='0',
 FrameCompletoUART1=0,
 FlagCommIHM=1,
 FrameIHM[]="*0000000000000#",
 IndiceFrameIHM=0,
 strIHM[]="*0000000000000#",
 strHex[6];

unsigned eedata;

unsigned long eeAddr;


void main() {
unsigned i;


 TRISB = 0xFFFF;
 ADCON1 = 0x00E2;
 ADCON2 = 0x0000;
 ADCON3 = 0x1F3F;
 ADPCFG = 0xFFFE;
 ADCHS = 0x0000;
 ADCSSL = 0;



 IFS0 = 0;
 IFS1 = 0;
 IFS2 = 0;
 INTCON1 = 0x8000;
 INTCON2 = 0;
 IEC0 = 0x0808;
 IPC0.F12= 1;
 IPC2.F13= 1;



 PR1 = 0x4E20;
 T1CON = 0x8000;

 T1IF_bit = 0;
 T1IE_bit = 1;


 PR2 = 0x4C4B;

 T2CON = 0x8030;

 T2IF_bit = 0;
 T2IE_bit = 1;





 PR4 = 0x4C4B;
 T4CON = 0x8030;
 T4IF_bit = 0;
 T4IE_bit = 0;



 TRISB=0B1110111000001001;
 TRISD=0B1111111111111000;
 TRISA=0B1111111111111111;
 TRISF=0B1111111110010001;
 TRISC=0B1101111111111111;

 while (1){


 if (FrameCompletoUART1==1){

 if (FrameIHM[1]=='z') ADCTx=FrameIHM[13];
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
}
