#include <DefineSensor.h>

void ImprimeFrame1(void){
char Indice, txt1[5];

          FlagCommIHM=1;

          FrameIHM[0]=':';
          FrameIHM[1]='1';

          WordToHex(Num_sem, txt1);
          FrameIHM[2]=txt1[0];
          FrameIHM[3]=txt1[1];
          FrameIHM[4]=txt1[2];
          FrameIHM[5]=txt1[3];
          
          WordToHex(Num_Lote, txt1);
          FrameIHM[6]=txt1[0];
          FrameIHM[7]=txt1[1];
          FrameIHM[8]=txt1[2];
          FrameIHM[9]=txt1[3];
          
          FrameIHM[10]=Erro[0];
          FrameIHM[11]=Erro[1];
          FrameIHM[12]=Erro[2];
          FrameIHM[13]=Erro[3];
          FrameIHM[14]='#';

          for (Indice=0; Indice<TamanhoFrame;Indice++)  UART1_Write(FrameIHM[Indice]);
          FlagCommIHM=0;
}

void ImprimeFrame0(void){
char Indice, txt1[5];

          FlagCommIHM=1;

          FrameIHM[0]=':';
          FrameIHM[1]='0';

          WordToHex(Aux_referencia, txt1);
          FrameIHM[2]=txt1[0];
          FrameIHM[3]=txt1[1];
          FrameIHM[4]=txt1[2];
          FrameIHM[5]=txt1[3];
          
          WordToHex(Aux_out, txt1);
          FrameIHM[6]=txt1[0];
          FrameIHM[7]=txt1[1];
          FrameIHM[8]=txt1[2];
          FrameIHM[9]=txt1[3];

          WordToHex(ContTX, txt1);
          FrameIHM[10]=txt1[0];
          FrameIHM[11]=txt1[1];
          FrameIHM[12]=txt1[2];
          FrameIHM[13]=txt1[3];
          FrameIHM[14]='#';

          for (Indice=0; Indice<TamanhoFrame;Indice++)  UART1_Write(FrameIHM[Indice]);
          FlagCommIHM=0;
}

void ImprimeFramePAR(void){
char Indice, txt1[5];

          FlagCommIHM=1;

          for (Indice=0; Indice<TamanhoFrame;Indice++)  UART1_Write(FrameIHM[Indice]);
          FlagCommIHM=0;
}
//----------------------------------------------

void ImprimeFrame2(void){
char Indice, txt1[5];

          Delay_ms(10);                                                         //Tempo para o Mestre devolver o barramento

          Sel485=1;
          Delay_ms(2);

          FlagCommContador=1;

          FrameContador[0]=':';
          FrameContador[1]='1';

          WordToHex(Num_sem, txt1);
          FrameContador[2]=txt1[0];
          FrameContador[3]=txt1[1];
          FrameContador[4]=txt1[2];
          FrameContador[5]=txt1[3];

          WordToHex(Num_Lote, txt1);
          FrameContador[6]=txt1[0];
          FrameContador[7]=txt1[1];
          FrameContador[8]=txt1[2];
          FrameContador[9]=txt1[3];

          FrameContador[10]=Erro[0];
          FrameContador[11]=Erro[1];
          FrameContador[12]=Erro[2];
          FrameContador[13]=Erro[3];
          FrameContador[14]='#';

          for (Indice=0; Indice<TamanhoFrame;Indice++)  UART2_Write(FrameContador[Indice]);
          FlagCommContador=0;

          Delay_ms(4);
          Sel485=0;
}





//----------------------------------------------
void AcionaDumper(void){
//Tempo do Dumper aberto
           FlagTimerDUMPER=1;
           Cont_TimerDUMPER=0;
           ContadorPronto=0;
           T4IF_bit = 0;
           T4IE_bit = 1;
           Dumper=1;
}