#include <DefineSensor.h>

void Timer1_Interrup() iv IVT_ADDR_T1INTERRUPT ics ICS_AUTO {     //TEMPO DE 1ms
  T1IF_bit = 0;             // Clear T1IF

  ADCON1.F1  = 1;                        // Start sampling
  ADCON1.F15 = 1;                        // Start conversion
  
}


void Timer2_Interrup() iv IVT_ADDR_T2INTERRUPT ics ICS_AUTO {  //250ms
  T2IF_bit = 0;             // Clear T2IF
  asm CLRWDT;               // asm line, clear WatchDog Timer
}

void Timer4_Interrup() iv IVT_ADDR_T4INTERRUPT ics ICS_AUTO {
 T4IF_bit = 0;
}