
_UART1_RXINT:
	PUSH	52
	PUSH	RCOUNT
	PUSH	W0
	MOV	#2, W0
	REPEAT	#12
	PUSH	[W0++]

;InterruptUART.c,3 :: 		void UART1_RXINT() iv IVT_ADDR_U1RXINTERRUPT ics ICS_AUTO {
;InterruptUART.c,6 :: 		U1RXIF_bit=0;
	BCLR	U1RXIF_bit, BitPos(U1RXIF_bit+0)
;InterruptUART.c,8 :: 		while (UART1_Data_Ready()) {     // If data is received,
L_UART1_RXINT0:
	CALL	_UART1_Data_Ready
	CP0	W0
	BRA NZ	L__UART1_RXINT18
	GOTO	L_UART1_RXINT1
L__UART1_RXINT18:
;InterruptUART.c,9 :: 		uart_rd = UART1_Read();     // read the received data,
	CALL	_UART1_Read
; uart_rd start address is: 4 (W2)
	MOV.B	W0, W2
;InterruptUART.c,11 :: 		if (uart_rd=='*') IndiceFrameIHM=0;
	MOV.B	#42, W1
	CP.B	W0, W1
	BRA Z	L__UART1_RXINT19
	GOTO	L_UART1_RXINT2
L__UART1_RXINT19:
	MOV	#lo_addr(_IndiceFrameIHM), W1
	CLR	W0
	MOV.B	W0, [W1]
	GOTO	L_UART1_RXINT3
L_UART1_RXINT2:
;InterruptUART.c,12 :: 		else IndiceFrameIHM++;
	MOV.B	#1, W1
	MOV	#lo_addr(_IndiceFrameIHM), W0
	ADD.B	W1, [W0], [W0]
L_UART1_RXINT3:
;InterruptUART.c,14 :: 		if (IndiceFrameIHM<TamanhoFrame) strIHM[IndiceFrameIHM]=uart_rd;
	MOV	#lo_addr(_IndiceFrameIHM), W0
	MOV.B	[W0], W1
	MOV.B	#_TamanhoFrame, W0
	CP.B	W1, W0
	BRA LTU	L__UART1_RXINT20
	GOTO	L_UART1_RXINT4
L__UART1_RXINT20:
	MOV	#lo_addr(_IndiceFrameIHM), W0
	ZE	[W0], W1
	MOV	#lo_addr(_strIHM), W0
	ADD	W0, W1, W0
	MOV.B	W2, [W0]
	GOTO	L_UART1_RXINT5
L_UART1_RXINT4:
;InterruptUART.c,15 :: 		else IndiceFrameIHM=TamanhoFrame;
	MOV	#lo_addr(_IndiceFrameIHM), W1
	MOV.B	#_TamanhoFrame, W0
	MOV.B	W0, [W1]
L_UART1_RXINT5:
;InterruptUART.c,17 :: 		if ((uart_rd=='#')&&(IndiceFrameIHM==TamanhoFrame-1)&&(FlagCommIHM==0)){
	MOV.B	#35, W0
	CP.B	W2, W0
	BRA Z	L__UART1_RXINT21
	GOTO	L__UART1_RXINT16
L__UART1_RXINT21:
; uart_rd end address is: 4 (W2)
	MOV	#_TamanhoFrame, W0
	SUB	W0, #1, W1
	MOV	#lo_addr(_IndiceFrameIHM), W0
	ZE	[W0], W0
	CP	W0, W1
	BRA Z	L__UART1_RXINT22
	GOTO	L__UART1_RXINT15
L__UART1_RXINT22:
	MOV	#lo_addr(_FlagCommIHM), W0
	MOV.B	[W0], W0
	CP.B	W0, #0
	BRA Z	L__UART1_RXINT23
	GOTO	L__UART1_RXINT14
L__UART1_RXINT23:
L__UART1_RXINT13:
;InterruptUART.c,18 :: 		for (IndiceFrameIHM=0; IndiceFrameIHM<TamanhoFrame;IndiceFrameIHM++){
	MOV	#lo_addr(_IndiceFrameIHM), W1
	CLR	W0
	MOV.B	W0, [W1]
L_UART1_RXINT9:
	MOV	#lo_addr(_IndiceFrameIHM), W0
	MOV.B	[W0], W1
	MOV.B	#_TamanhoFrame, W0
	CP.B	W1, W0
	BRA LTU	L__UART1_RXINT24
	GOTO	L_UART1_RXINT10
L__UART1_RXINT24:
;InterruptUART.c,19 :: 		FrameIHM[IndiceFrameIHM]=strIHM[IndiceFrameIHM];
	MOV	#lo_addr(_IndiceFrameIHM), W0
	ZE	[W0], W1
	MOV	#lo_addr(_FrameIHM), W0
	ADD	W0, W1, W2
	MOV	#lo_addr(_IndiceFrameIHM), W0
	ZE	[W0], W1
	MOV	#lo_addr(_strIHM), W0
	ADD	W0, W1, W0
	MOV.B	[W0], [W2]
;InterruptUART.c,18 :: 		for (IndiceFrameIHM=0; IndiceFrameIHM<TamanhoFrame;IndiceFrameIHM++){
	MOV.B	#1, W1
	MOV	#lo_addr(_IndiceFrameIHM), W0
	ADD.B	W1, [W0], [W0]
;InterruptUART.c,20 :: 		}
	GOTO	L_UART1_RXINT9
L_UART1_RXINT10:
;InterruptUART.c,21 :: 		FrameCompletoUART1=1;
	MOV	#lo_addr(_FrameCompletoUART1), W1
	MOV.B	#1, W0
	MOV.B	W0, [W1]
;InterruptUART.c,22 :: 		IndiceFrameIHM=0;
	MOV	#lo_addr(_IndiceFrameIHM), W1
	CLR	W0
	MOV.B	W0, [W1]
;InterruptUART.c,17 :: 		if ((uart_rd=='#')&&(IndiceFrameIHM==TamanhoFrame-1)&&(FlagCommIHM==0)){
L__UART1_RXINT16:
L__UART1_RXINT15:
L__UART1_RXINT14:
;InterruptUART.c,24 :: 		}
	GOTO	L_UART1_RXINT0
L_UART1_RXINT1:
;InterruptUART.c,25 :: 		}
L_end_UART1_RXINT:
	MOV	#26, W0
	REPEAT	#12
	POP	[W0--]
	POP	W0
	POP	RCOUNT
	POP	52
	RETFIE
; end of _UART1_RXINT

_UART2_RXINT:
	PUSH	52
	PUSH	RCOUNT
	PUSH	W0
	MOV	#2, W0
	REPEAT	#12
	PUSH	[W0++]

;InterruptUART.c,31 :: 		void UART2_RXINT() iv IVT_ADDR_U2RXINTERRUPT ics ICS_AUTO {
;InterruptUART.c,34 :: 		U2RXIF_bit=0;
	BCLR	U2RXIF_bit, BitPos(U2RXIF_bit+0)
;InterruptUART.c,36 :: 		if (UART2_Data_Ready()) {     // If data is received,
	CALL	_UART2_Data_Ready
	CP0	W0
	BRA NZ	L__UART2_RXINT26
	GOTO	L_UART2_RXINT12
L__UART2_RXINT26:
;InterruptUART.c,37 :: 		uart_rd = UART2_Read();     // read the received data,
	CALL	_UART2_Read
;InterruptUART.c,39 :: 		}
L_UART2_RXINT12:
;InterruptUART.c,40 :: 		}
L_end_UART2_RXINT:
	MOV	#26, W0
	REPEAT	#12
	POP	[W0--]
	POP	W0
	POP	RCOUNT
	POP	52
	RETFIE
; end of _UART2_RXINT
