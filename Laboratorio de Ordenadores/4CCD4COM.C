#include <stdio.h>
#include <conio.h>
#define M 200
#define N 200
main()
{
	char a[M],b[N];
	int i;
	clrscr();
	printf("\PROGRAMA PARA COMPARAR CADENAS DE CARACTERES\n\
	\nIntroduzca las dos cadenas a comparar(max.199 caracteres):\n");
	gets(a);
	gets(b);
	i=0;
	do{
		if (a[i]<b[i])
		{	printf("\nLa cadena -%s- es menor que la cadena -%s-",a,b);
			exit(1);
		}
		if (a[i]>b[i])
		{	printf("\nLa cadena -%s- es mayor que la cadena -%s-",a,b);
			exit(1);
		}
		i++;
	}while (a[i]!='\0'&&b[i]!='\0');
	if (a[i]=='\0'&&b[i]!='\0')
	{	printf("\nLa cadena -%s- es menor que la cadena -%s-",a,b);
		exit(1);
	}
	if (b[i]=='\0'&&a[i]!='\0')
	{	printf("\nLa cadena -%s- es mayor que la cadena -%s-",a,b);
		exit(1);
	}
	if (a[i]=='\0'&&b[i]=='\0') printf("\nLas cadenas introducidas -%s- son iguales",a);
}