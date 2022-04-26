/********************************************************************************************* 
Funkcija hexToChar gauna skaičių digit, kurio reikšmė turi būti tarp 0 ir 15 imtinai, 
ir grąžina tą skaičių atitinkančio šešioliktainės sistemos skaitmens simbolio ASCII kodą. 
Parametras type nurodo raidės dydį, tiems atvejams, kai digit > 9, tokiu atveju, teigiama type reikšmė reiškia didžiąją, 
o neteigiama - mažąją. Funkcija grąžina simbolio ASCII kodą; jei digit nepatenka į nurodytus rėžius, funkcija grąžina 0. 
Pavyzdžiai: hexToChar(5,1) grąžina ’5’, hexToChar(10,1) grąžina ‘A’, hexToChar(0xF,-2) grąžina ‘f‘
*********************************************************************************************/
unsigned char hexToChar (int digit, char type){
     // YOUR CODE GOES HERE
     if(0 <= digit <= 9)
          return digit;
     if(10 <= digit <= 15)
     {
          if (type < '0')
               return (digit + 87);
          else 
               return (digit + 55);
     }
}