
_main:
	MOV	#2048, W15
	MOV	#6142, W0
	MOV	WREG, 32
	MOV	#1, W0
	MOV	WREG, 52
	MOV	#4, W0
	IOR	68
	LNK	#2

;SensorIrDA2020.c,26 :: 		void main() {
;SensorIrDA2020.c,30 :: 		TRISB   = 0xFFFF;                       // set pin as input - needed for ADC to work     */
	PUSH	W10
	PUSH	W11
	PUSH	W12
	MOV	#65535, W0
	MOV	WREG, TRISB
;SensorIrDA2020.c,31 :: 		ADCON1  = 0x00E2;                      // Auto-stop sampling, unsigned integer out
	MOV	#226, W0
	MOV	WREG, ADCON1
;SensorIrDA2020.c,32 :: 		ADCON2  = 0x0000;
	CLR	ADCON2
;SensorIrDA2020.c,33 :: 		ADCON3  = 0x1F3F;    //0x1F20;         // Sampling time= 3*Tad, minimum Tad selected  0x021A;
	MOV	#7999, W0
	MOV	WREG, ADCON3
;SensorIrDA2020.c,34 :: 		ADPCFG  = 0xFFFE;                      // Configure RB0 as ADC input port
	MOV	#65534, W0
	MOV	WREG, ADPCFG
;SensorIrDA2020.c,35 :: 		ADCHS   = 0x0000;                      // Sample input on RB0
	CLR	ADCHS
;SensorIrDA2020.c,36 :: 		ADCSSL  = 0;                           // No input scan
	CLR	ADCSSL
;SensorIrDA2020.c,40 :: 		IFS0    = 0;                            // Clear flags int.
	CLR	IFS0
;SensorIrDA2020.c,41 :: 		IFS1    = 0;
	CLR	IFS1
;SensorIrDA2020.c,42 :: 		IFS2    = 0;
	CLR	IFS2
;SensorIrDA2020.c,43 :: 		INTCON1 = 0x8000;                      // Nested interrupts DISABLED
	MOV	#32768, W0
	MOV	WREG, INTCON1
;SensorIrDA2020.c,44 :: 		INTCON2 = 0;
	CLR	INTCON2
;SensorIrDA2020.c,45 :: 		IEC0    = 0x0808;                      // Timer1 and ADC interrupts ENABLED
	MOV	#2056, W0
	MOV	WREG, IEC0
;SensorIrDA2020.c,46 :: 		IPC0.F12= 1;                           // Timer1 interrupt priority level = 1
	BSET	IPC0, #12
;SensorIrDA2020.c,47 :: 		IPC2.F13= 1;                           // ADC interrupt priority level = 2
	BSET	IPC2, #13
;SensorIrDA2020.c,51 :: 		PR1     = 0x4E20;                      // Sampling 0x4E20 = 1000Hz ---- 0x07D0 = 10000 Hz. Value of PR1 is dependent on clock.
	MOV	#20000, W0
	MOV	WREG, PR1
;SensorIrDA2020.c,52 :: 		T1CON   = 0x8000;                      // Timer1 ON, internal clock FCY, prescaler 1:1
	MOV	#32768, W0
	MOV	WREG, T1CON
;SensorIrDA2020.c,54 :: 		T1IF_bit = 0;                          // Clear T1IF
	BCLR	T1IF_bit, BitPos(T1IF_bit+0)
;SensorIrDA2020.c,55 :: 		T1IE_bit = 1;                        // Enable Timer1 interrupts
	BSET	T1IE_bit, BitPos(T1IE_bit+0)
;SensorIrDA2020.c,58 :: 		PR2     = 0x4C4B;
	MOV	#19531, W0
	MOV	WREG, PR2
;SensorIrDA2020.c,60 :: 		T2CON   = 0x8030;                      // Timer2 ON, internal clock FCY, prescaler 1:256
	MOV	#32816, W0
	MOV	WREG, T2CON
;SensorIrDA2020.c,62 :: 		T2IF_bit = 0;
	BCLR	T2IF_bit, BitPos(T2IF_bit+0)
;SensorIrDA2020.c,63 :: 		T2IE_bit = 1;
	BSET	T2IE_bit, BitPos(T2IE_bit+0)
;SensorIrDA2020.c,69 :: 		PR4     = 0x4C4B;
	MOV	#19531, W0
	MOV	WREG, PR4
;SensorIrDA2020.c,70 :: 		T4CON   = 0x8030;                      // Timer4 ON, internal clock FCY, prescaler 1:256
	MOV	#32816, W0
	MOV	WREG, T4CON
;SensorIrDA2020.c,71 :: 		T4IF_bit = 0;                          // Clear T4IF
	BCLR	T4IF_bit, BitPos(T4IF_bit+0)
;SensorIrDA2020.c,72 :: 		T4IE_bit = 0;                        // Enable Timer4 interrupts
	BCLR	T4IE_bit, BitPos(T4IE_bit+0)
;SensorIrDA2020.c,76 :: 		TRISB=0B1110111000001001;
	MOV	#60937, W0
	MOV	WREG, TRISB
;SensorIrDA2020.c,77 :: 		TRISD=0B1111111111111000;
	MOV	#65528, W0
	MOV	WREG, TRISD
;SensorIrDA2020.c,78 :: 		TRISA=0B1111111111111111;
	MOV	#65535, W0
	MOV	WREG, TRISA
;SensorIrDA2020.c,79 :: 		TRISF=0B1111111110010001;
	MOV	#65425, W0
	MOV	WREG, TRISF
;SensorIrDA2020.c,80 :: 		TRISC=0B1101111111111111;
	MOV	#57343, W0
	MOV	WREG, TRISC
;SensorIrDA2020.c,82 :: 		while (1){
L_main0:
;SensorIrDA2020.c,85 :: 		if (FrameCompletoUART1==1){
	MOV	#lo_addr(_FrameCompletoUART1), W0
	MOV.B	[W0], W0
	CP.B	W0, #1
	BRA Z	L__main16
	GOTO	L_main2
L__main16:
;SensorIrDA2020.c,87 :: 		if (FrameIHM[1]=='z')  ADCTx=FrameIHM[13];
	MOV	#lo_addr(_FrameIHM+1), W0
	MOV.B	[W0], W1
	MOV.B	#122, W0
	CP.B	W1, W0
	BRA Z	L__main17
	GOTO	L_main3
L__main17:
	MOV	#lo_addr(_ADCTx), W1
	MOV	#lo_addr(_FrameIHM+13), W0
	MOV.B	[W0], [W1]
L_main3:
;SensorIrDA2020.c,88 :: 		if ((FrameIHM[1]>='A')&&(FrameIHM[1]<='y') ){
	MOV	#lo_addr(_FrameIHM+1), W0
	MOV.B	[W0], W1
	MOV.B	#65, W0
	CP.B	W1, W0
	BRA GEU	L__main18
	GOTO	L__main14
L__main18:
	MOV	#lo_addr(_FrameIHM+1), W0
	MOV.B	[W0], W1
	MOV.B	#121, W0
	CP.B	W1, W0
	BRA LEU	L__main19
	GOTO	L__main13
L__main19:
L__main12:
;SensorIrDA2020.c,90 :: 		FlagCommIHM=1;
	MOV	#lo_addr(_FlagCommIHM), W1
	MOV.B	#1, W0
	MOV.B	W0, [W1]
;SensorIrDA2020.c,91 :: 		eeAddr=0x7FFC00+FrameIHM[1]*2;
	MOV	#lo_addr(_FrameIHM+1), W0
	ZE	[W0], W0
	SL	W0, #1, W0
	MOV	W0, W3
	ASR	W3, #15, W4
	MOV	#64512, W1
	MOV	#127, W2
	MOV	#lo_addr(_eeAddr), W0
	ADD	W1, W3, [W0++]
	ADDC	W2, W4, [W0--]
;SensorIrDA2020.c,92 :: 		for (i=1; i<=4;i++) strHex[i] = FrameIHM[9+i];
	MOV	#1, W0
	MOV	W0, [W14+0]
L_main7:
	MOV	[W14+0], W0
	CP	W0, #4
	BRA LEU	L__main20
	GOTO	L_main8
L__main20:
	MOV	#lo_addr(_strHex), W1
	ADD	W14, #0, W0
	ADD	W1, [W0], W2
	MOV	[W14+0], W0
	ADD	W0, #9, W1
	MOV	#lo_addr(_FrameIHM), W0
	ADD	W0, W1, W0
	MOV.B	[W0], [W2]
	MOV	#1, W1
	ADD	W14, #0, W0
	ADD	W1, [W0], [W0]
	GOTO	L_main7
L_main8:
;SensorIrDA2020.c,93 :: 		eeData = xtoi(strHex);
	MOV	#lo_addr(_strHex), W10
	CALL	_xtoi
	MOV	W0, _eedata
;SensorIrDA2020.c,94 :: 		FlagCommIHM=0;
	MOV	#lo_addr(_FlagCommIHM), W2
	CLR	W1
	MOV.B	W1, [W2]
;SensorIrDA2020.c,96 :: 		EEPROM_Write(eeAddr, eeData);
	MOV	W0, W12
	MOV	_eeAddr, W10
	MOV	_eeAddr+2, W11
	CALL	_EEPROM_Write
;SensorIrDA2020.c,97 :: 		while(WR_bit);
L_main10:
	BTSS	WR_bit, BitPos(WR_bit+0)
	GOTO	L_main11
	GOTO	L_main10
L_main11:
;SensorIrDA2020.c,88 :: 		if ((FrameIHM[1]>='A')&&(FrameIHM[1]<='y') ){
L__main14:
L__main13:
;SensorIrDA2020.c,99 :: 		}
L_main2:
;SensorIrDA2020.c,100 :: 		}
	GOTO	L_main0
;SensorIrDA2020.c,101 :: 		}//~!
L_end_main:
	POP	W12
	POP	W11
	POP	W10
	ULNK
L__main_end_loop:
	BRA	L__main_end_loop
; end of _main
