
_ADC1Int:
	PUSH	52
	PUSH	RCOUNT
	PUSH	W0
	MOV	#2, W0
	REPEAT	#12
	PUSH	[W0++]

;InterruptADC.c,9 :: 		void ADC1Int() org 0x2A {              // ADC interrupt handler
;InterruptADC.c,10 :: 		char ADCTxx=0;
	PUSH	W10
; ADCTxx start address is: 2 (W1)
	CLR	W1
;InterruptADC.c,13 :: 		IFS0.F11 = 0;                          // Clear AD1IF
	BCLR	IFS0, #11
;InterruptADC.c,14 :: 		TEST=1;
	BSET	LATB2_bit, BitPos(LATB2_bit+0)
;InterruptADC.c,18 :: 		if ((UART1_Tx_Idle()==1)) UART1_Write(ADCTxx);
	CALL	_UART1_Tx_Idle
	CP	W0, #1
	BRA Z	L__ADC1Int2
	GOTO	L_ADC1Int0
L__ADC1Int2:
	ZE	W1, W10
; ADCTxx end address is: 2 (W1)
	CALL	_UART1_Write
L_ADC1Int0:
;InterruptADC.c,20 :: 		TEST=0;
	BCLR	LATB2_bit, BitPos(LATB2_bit+0)
;InterruptADC.c,21 :: 		}//~
L_end_ADC1Int:
	POP	W10
	MOV	#26, W0
	REPEAT	#12
	POP	[W0--]
	POP	W0
	POP	RCOUNT
	POP	52
	RETFIE
; end of _ADC1Int
