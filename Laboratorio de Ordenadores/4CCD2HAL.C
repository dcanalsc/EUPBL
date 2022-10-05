#include <stdio.h>
#include <math.h>
main()
{
	int numero,operacion,i;
	printf("\nIntroduzca el numero a dividir:");
	scanf("%d",&numero);
	if (numero==0)
	{
		printf("El resultado de la division es zero");
		exit(1);
	}
	else
	{
		i=0;
		if (numero%2==0)
			{
				while (numero/2!=1&&numero/2!=-1&&numero%2==0)
				{
					numero=numero/2;
					printf("\n %d",numero);
					i++;
					printf(" %d\n",i);
				}
			}
			if (numero%2!=0)
			{
				operacion=numero*3+1;
				printf("\n %d  ",operacion);
				while (operacion/2!=1&&operacion/2!=-1&&numero%2==0)
				{
					numero=operacion/2;
					printf("   %d",numero);
					i++;
					printf("  %d\n",i);
				}
			}
	}
}