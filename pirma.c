// LSP numeris: 2110582, el. paštas: krupaviciusvy@gmail.com, 1 užduotis, 1 variantas
#include <stdio.h>

int main() {
   int sk;
   int senas = -1410065407;
   int sum = 0, i = 0;
   printf("Iveskite sekos skaicius: ");

   while (1 > 0)
   {
      if ((scanf("%d", &sk) == 1) && (getchar() == '\n'))
      {
            if (sk < senas)
                  break;
         
            sum += sk;
            i++;
            senas = sk;
      }

      else
      {
            while (getchar() != '\n');
            printf("Ivedete netinkama simboli, prasome iveskite skaiciu: ");
            continue;
            
      }
   }

   double vid = (double) sum / i;

   printf("Sekos nariu skaicius: %d, sekos aritmetinis vidurkis: %0.2lf.", i, vid);
   printf("\n");
   return 0;
}