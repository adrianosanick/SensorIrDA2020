#include <DefineSensor.h>

//PR1, ADCON3

void EEPROM(void) {

//------------------------------------------------------------------------------
//LEITURA DOS PARÂMETROS DO SENSOR

//Tamanho parafuso
  eeAddr=0x7FFC20;
  TamanhoParafuso = EEPROM_Read(eeAddr);

 switch (TamanhoParafuso){
 //Grande 0%
         case '0':      eeAddr=0x7FFC00;
                        Area = EEPROM_Read(eeAddr+2*'A');
                        Min_cont = EEPROM_Read(eeAddr*2*'B');
                        Max_cont = EEPROM_Read(eeAddr+2*'C');
                        MIN_TIMER =  EEPROM_Read(eeAddr+2*'D');
                        ADCON3  = 0x1F3F;
                        RefPar = EEPROM_Read(eeAddr+2*'Y');
                        PR1 = EEPROM_Read(eeAddr+2*'Z'); break;
 //Grande 20%
         case '1':      eeAddr=0x7FFC00;
                        Area = EEPROM_Read(eeAddr+2*'E');
                        Min_cont = EEPROM_Read(eeAddr+2*'F');
                        Max_cont = EEPROM_Read(eeAddr+2*'G');
                        Min_Timer =  EEPROM_Read(eeAddr+2*'H');
                        ADCON3  = 0x1F3F;
                        RefPar = EEPROM_Read(eeAddr+2*'Y');
                        PR1 = EEPROM_Read(eeAddr+2*'Z'); break;
 //Grande 40%
         case '2':      eeAddr=0x7FFC00;
                        Area = EEPROM_Read(eeAddr+2*'I');
                        Min_cont = EEPROM_Read(eeAddr+2*'J');
                        Max_cont = EEPROM_Read(eeAddr+2*'K');
                        Min_Timer =  EEPROM_Read(eeAddr+2*'L');
                        ADCON3  = 0x1F3F;
                        RefPar = EEPROM_Read(eeAddr+2*'Y');
                        PR1 = EEPROM_Read(eeAddr+2*'Z'); break;
 //Grande 60%
         case '3':      eeAddr=0x7FFC00;
                        Area = EEPROM_Read(eeAddr+2*'M');
                        Min_cont = EEPROM_Read(eeAddr+2*'N');
                        Max_cont = EEPROM_Read(eeAddr+2*'O');
                        Min_Timer =  EEPROM_Read(eeAddr+2*'P');
                        ADCON3  = 0x1F3F;
                        RefPar = EEPROM_Read(eeAddr+2*'Y');
                        PR1 = EEPROM_Read(eeAddr+2*'Z'); break;
 //Grande 80%
         case '4':      eeAddr=0x7FFC00;
                        Area = EEPROM_Read(eeAddr+2*'Q');
                        Min_cont = EEPROM_Read(eeAddr+2*'R');
                        Max_cont = EEPROM_Read(eeAddr+2*'S');
                        Min_Timer =  EEPROM_Read(eeAddr+2*'T');
                        ADCON3  = 0x1F3F;
                        RefPar = EEPROM_Read(eeAddr+2*'Y');
                        PR1 = EEPROM_Read(eeAddr+2*'Z'); break;
 //Grande 100%
         case '5':      eeAddr=0x7FFC00;
                        Area = EEPROM_Read(eeAddr+2*'U');
                        Min_cont = EEPROM_Read(eeAddr+2*'V');
                        Max_cont = EEPROM_Read(eeAddr+2*'W');
                        Min_Timer =  EEPROM_Read(eeAddr+2*'X');
                        ADCON3  = 0x1F3F;
                        RefPar = EEPROM_Read(eeAddr+2*'Y');
                        PR1 = EEPROM_Read(eeAddr+2*'Z'); break;
//------------------------------------------------------------------------------
 //Pequeno 0%
         case '6':      eeAddr=0x7FFC00;
                        Area = EEPROM_Read(eeAddr+2*'a');
                        Min_cont = EEPROM_Read(eeAddr+2*'b');
                        Max_cont = EEPROM_Read(eeAddr+2*'c');
                        Min_Timer =  EEPROM_Read(eeAddr+2*'d');
                        ADCON3  = 0x1F3F;
                        RefPar = EEPROM_Read(eeAddr+2*'y');
                        PR1 = EEPROM_Read(eeAddr+2*'z'); break;
 //Pequeno 20%
         case '7':      eeAddr=0x7FFC00;
                        Area = EEPROM_Read(eeAddr+2*'e');
                        Min_cont = EEPROM_Read(eeAddr+2*'f');
                        Max_cont = EEPROM_Read(eeAddr+2*'g');
                        Min_Timer =  EEPROM_Read(eeAddr+2*'h');
                        ADCON3  = 0x1F3F;
                        RefPar = EEPROM_Read(eeAddr+2*'y');
                        PR1 = EEPROM_Read(eeAddr+2*'z'); break;
 //Pequeno 40%
         case '8':      eeAddr=0x7FFC00;
                        Area = EEPROM_Read(eeAddr+2*'i');
                        Min_cont = EEPROM_Read(eeAddr+2*'j');
                        Max_cont = EEPROM_Read(eeAddr+2*'k');
                        Min_Timer =  EEPROM_Read(eeAddr+2*'l');
                        ADCON3  = 0x1F3F;
                        RefPar = EEPROM_Read(eeAddr+2*'y');
                        PR1 = EEPROM_Read(eeAddr+2*'z'); break;
 //Pequeno 60%
         case '9':      eeAddr=0x7FFC00;
                        Area = EEPROM_Read(eeAddr+2*'m');
                        Min_cont = EEPROM_Read(eeAddr+2*'n');
                        Max_cont = EEPROM_Read(eeAddr+2*'o');
                        Min_Timer =  EEPROM_Read(eeAddr+2*'p');
                        ADCON3  = 0x1F3F;
                        RefPar = EEPROM_Read(eeAddr+2*'y');
                        PR1 = EEPROM_Read(eeAddr+2*'z'); break;
 //Pequeno 80%
         case 'A':      eeAddr=0x7FFC00;
                        Area = EEPROM_Read(eeAddr+2*'q');
                        Min_cont = EEPROM_Read(eeAddr+2*'r');
                        Max_cont = EEPROM_Read(eeAddr+2*'s');
                        Min_Timer =  EEPROM_Read(eeAddr+2*'t');
                        ADCON3  = 0x1F3F;
                        RefPar = EEPROM_Read(eeAddr+2*'y');
                        PR1 = EEPROM_Read(eeAddr+2*'z'); break;
 //Pequeno 100%
         case 'B':      eeAddr=0x7FFC00;
                        Area = EEPROM_Read(eeAddr+2*'u');
                        Min_cont = EEPROM_Read(eeAddr+2*'v');
                        Max_cont = EEPROM_Read(eeAddr+2*'w');
                        Min_Timer =  EEPROM_Read(eeAddr+2*'x');
                        ADCON3  = 0x1F3F;
                        RefPar = EEPROM_Read(eeAddr+2*'y');
                        PR1 = EEPROM_Read(eeAddr+2*'z'); break;
//------------------------------------------------------------------------------
 //Grande 60%
         default:       eeAddr=0x7FFC00;
                        Area = EEPROM_Read(eeAddr+2*'M');
                        Min_cont = EEPROM_Read(eeAddr+2*'N');
                        Max_cont = EEPROM_Read(eeAddr+2*'O');
                        Min_Timer =  EEPROM_Read(eeAddr+2*'P');
                        ADCON3  = 0x1F3F;
                        RefPar = EEPROM_Read(eeAddr+2*'Y');
                        PR1 = EEPROM_Read(eeAddr+2*'Z'); break;

  }

  FlagTrocaTAMANHO=0;

}