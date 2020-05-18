# EEPROM  

## MAPA DA EEPROM  
Os dados são gravados na memória com dois bytes **DataLo:DataHi** , por exemplo, o valor 0x1388 gravado no endereço *0x7FFC0*:
* **EEPROM(** *0x7FFC0* **)** = 0x88
* **EEPROM(** *0x7FFC1* **)** = 0x13


*******************************************************************************************************************************

## ENDEREÇO DOS PARÂMETROS DE OPERAÇÃO

### TABELA DE ENDEREÇOS

|  eeAddr   |  eeData   |  DESCRIÇÃO   |
| ------|-----|-----|
| ***0x7FFC20***  	|  0x0000    |  |
| ***0x7FFC22***  	|  0x0005    |  |
| ***0x7FFC24***  	|  0x0003    |  |
| ***0x7FFC26***  	|  0x0004    |  |
| ***0x7FFC28***  	|  0x0008    |  |
| ***0x7FFC2A***  	|  0x0005    |  |
| ***0x7FFC2C***  	|  0x0000    |  |
| ***0x7FFC30***  	|  0x01FF    |  |
| ***0x7FFC32***  	|  0x01C2    |  |
| ***0x7FFC34***  	|  0x0032    |  |


*******************************************************************************************************************************

## ENDEREÇO DOS PARÂMETROS DE CONFIGURAÇÃO

### MÉTODO DE SELEÇÃO DOS ENDEREÇOS
Para facilitar a configuração de parâmetro, utiliza-se o Frame de configuração.
* exemplo: *A_ XXXX_ XXXX_DADO#

assim:

Endereço = 0x7FFC0+'A' * 2 => eeAddr = *0x7FFC82*

## TABELA DE ENDEREÇOS

### **FREQUÊNCIA DE AMOSTRAGEM**

|  eeAddr   |  eeData   |  DESCRIÇÃO   |  FRAME |
| ------|-----|-----|-----|
| ***0x7FFCB4***  	|  0x1388    |  Freq       | *Z-------eeData#   |

### **REFERÊNCIA**

|  eeAddr   |  eeData   |  DESCRIÇÃO   |  FRAME |
| ------|-----|-----|-----|
| ***0x7FFCB2***  	|  0x0010    |  Ref       | *Y-------eeData#   |
