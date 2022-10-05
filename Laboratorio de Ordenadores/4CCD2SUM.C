#include <stdio.h>
#include <math.h>
main()
{
	float numeroa,numerob;
	int i;
	printf("\nIntroduzca el numero deseado:");
	scanf("%f",&numeroa);
	printf("\nIntroduzca el numero de veces a efectuar la suma:");
	scanf("%d",&i);
	if (i<0)
	{
		printf("\n\bEl valor introducido es incorrecto!");
		exit(1);
	}
	else
	{
		numeroa=numeroa*numeroa;
		numerob=numeroa;
		while (i!=0)
		{
			numerob=numerob+numeroa;
			i--;
		}
		printf("El resultado de la suma es: %f",numerob);
	}
}