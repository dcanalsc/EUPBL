#include <stdio.h>
#include <math.h>
main()
{
   float C,F;
   printf("\nCONVERSOR DE GRADOS CELSIUS A FARENHEID");
   printf("\nIntroduzca el valor en grados Celsius:");
   scanf("%f",&C);
   F=(C+32)*9/4;
   printf("\nEl valor en grados Farenheid es: %f",F);
}

