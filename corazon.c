#include <stdio.h>
#include <stdlib.h>

int main() {
   int a, b, line = 4;
   for (a = line/2; a <= line; a = a+2) { //Para la parte superior del corazon
      for (b = 1; b < line-a; b = b+2) //crear espacio antes de la primera prominencia
         printf(" ");
      for (b = 1; b <= a; b++) //imprimir la primera prominencia
         printf("*");
      for (b = 1; b <= line-a; b++) //crear espacio antes de la segunda prominencia
         printf(" ");
      for (b = 1; b <= a-1; b++) //imprimir la segunda prominencia
         printf("*");
      printf("\n");
   }
   for (a = line; a >= 0; a--) { //la base del corazon es un triangulo invertido
      for (b = a; b < line; b++) //generar espacio antes del triangulo
         printf(" ");
      for (b = 1; b <= ((a * 2) - 1); b++) //imprimir el triangulo
         printf("*");
      printf("\n");
   }
   return 0;
}
