
_Timer1_Interrup:
	PUSH	52
	PUSH	RCOUNT
	PUSH	W0
	MOV	#2, W0
	REPEAT	#12
	PUSH	[W0++]

;InterruptTimers.c,3 :: 		void Timer1_Interrup() iv IVT_ADDR_T1INTERRUPT ics ICS_AUTO {     //TEMPO DE 1ms
;InterruptTimers.c,4 :: 		T1IF_bit = 0;             // Clear T1IF
	BCLR	T1IF_bit, BitPos(T1IF_bit+0)
;InterruptTimers.c,6 :: 		ADCON1.F1  = 1;                        // Start sampling
	BSET.B	ADCON1, #1
;InterruptTimers.c,7 :: 		ADCON1.F15 = 1;                        // Start conversion
	BSET	ADCON1, #15
;InterruptTimers.c,9 :: 		}
L_end_Timer1_Interrup:
	MOV	#26, W0
	REPEAT	#12
	POP	[W0--]
	POP	W0
	POP	RCOUNT
	POP	52
	RETFIE
; end of _Timer1_Interrup

_Timer2_Interrup:
	PUSH	52
	PUSH	RCOUNT
	PUSH	W0
	MOV	#2, W0
	REPEAT	#12
	PUSH	[W0++]

;InterruptTimers.c,12 :: 		void Timer2_Interrup() iv IVT_ADDR_T2INTERRUPT ics ICS_AUTO {  //250ms
;InterruptTimers.c,13 :: 		T2IF_bit = 0;             // Clear T2IF
	BCLR	T2IF_bit, BitPos(T2IF_bit+0)
;InterruptTimers.c,14 :: 		asm CLRWDT;               // asm line, clear WatchDog Timer
	CLRWDT
;InterruptTimers.c,15 :: 		}
L_end_Timer2_Interrup:
	MOV	#26, W0
	REPEAT	#12
	POP	[W0--]
	POP	W0
	POP	RCOUNT
	POP	52
	RETFIE
; end of _Timer2_Interrup

_Timer4_Interrup:
	PUSH	52
	PUSH	RCOUNT
	PUSH	W0
	MOV	#2, W0
	REPEAT	#12
	PUSH	[W0++]

;InterruptTimers.c,17 :: 		void Timer4_Interrup() iv IVT_ADDR_T4INTERRUPT ics ICS_AUTO {
;InterruptTimers.c,18 :: 		T4IF_bit = 0;
	BCLR	T4IF_bit, BitPos(T4IF_bit+0)
;InterruptTimers.c,19 :: 		}
L_end_Timer4_Interrup:
	MOV	#26, W0
	REPEAT	#12
	POP	[W0--]
	POP	W0
	POP	RCOUNT
	POP	52
	RETFIE
; end of _Timer4_Interrup
