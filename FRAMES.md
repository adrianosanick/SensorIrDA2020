# 1. Frames do sistema:

***USART1 - RS232 56700bps***

***UARST2 COM RS485 É ESTÁVEL COM TAXA MÁX. DE 4800bps***

## **1.1 FRAME DE CONFIGURAÇÃO (USART1):**  

### DESCRIÇÃO DOS PARÂMETROS

**Frequência de Amostragem:**
* ***fs = 80.000.00/(4 * PR1)***
* **PR1:** Freq

## TABELA DE FREQUÊNCIAS

|  Frequência (Hz) |  PR1   |
| ------|-----|
| 	305   | 0xFFFF  |
| 	500   | 0x9C40  |
| 	750   | 0x682A  |
|   1000	| 0x4E20  |
|   2000	| 0x2710  |
|   3000	| 0x1A0A  |
|   4000	| 0x1388  |
|   5000	| 0x0FA0  |
|   6000	| 0x0D05  |
|   7000	| 0x0B29  |
|   8000	| 0x09C4  |
|   9000	| 0x08AE  |
|   10000	| 0x07D0  |


**Filtros do ADC:**

* **SomaDiff:** Somatório das diferenças
* **Ref:** Menor valor da Referência para o Trigger

**Parâmetro Monitorado com ADCTx:**
* **---0:** ADCTx <= Desabilita
* **---1:** ADCTx <= FPB
* **---2:** ADCTx <= Mediana
* **---3:** ADCTx <=
* **---4:** ADCTx <=
* **---5:** ADCTx <=
* **---6:** ADCTx <=
* **---7:** ADCTx <=

### FrameIHM[1]= A-Z : FrameIHM[10-13]= Parâmetro

**exemplo: * A_XXXX_XXXX_PR1#**

**Frequência de amostragem**

* **Z:** PR1 <= Determinação da frequência de amostragem

* **A:**
* **B:**

**Monitoração**
* **z:** ADCTx


## **1.2 FRAME COMUNICAÇÃO BROADCAST (USART1):**  

* FrameIHM[1]=
* FrameIHM[2-5]=
* FrameIHM[6-9]=
* FrameIHM[10] =
* FrameIHM[11] =
* FrameIHM[12] =
* FrameIHM[13] =

**exemplo:**  *0000500010A00#


## **1.3 FRAME COMUNICAÇÃO INDIVIDUAL (USART1 E USART2):**

* FrameIHM[1]= Endereco .. * E_XXXX_XXXX_XXXX#
* FrameIHM[2-5]=
* FrameIHM[6-9]=
* FrameIHM[10] =
* FrameIHM[11] =
* FrameIHM[12] =
* FrameIHM[13] =

**exemplo:**  *702FF01FF2322#
