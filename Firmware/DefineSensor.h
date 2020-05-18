sbit TEST at LATB2_bit;

sbit LED at LATB1_bit;
sbit Sel485 at LATD1_bit;

sbit BotaoOperacao at RB3_bit;        //Entrada

sbit In11 at RB9_bit;                 //Entrada  In11
sbit In12 at RB10_bit;                //Entrada In12
sbit In13 at RB11_bit;                //Entrada In13


sbit Out11  at RB12_bit;      //Saída Out11
sbit Out12  at RB4_bit;       //Saída Out12
sbit Out13  at LATD2_bit;     //Saída Out13


extern const char TamanhoFrame;

extern char    ADCTx,
               FrameCompletoUART1,
               FlagCommIHM,
               FrameIHM[],
               IndiceFrameIHM,
               strIHM[],
               strHex[];

extern unsigned eedata;

extern unsigned long eeAddr;