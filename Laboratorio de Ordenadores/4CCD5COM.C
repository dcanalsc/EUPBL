#include <stdio.h>
#define N 201
main()
{
	int i;
	char v1[N],v2[N],*p1,*p2;
	clrscr();
	printf("\nPROGRAMA PARA COMPARAR CADENAS DE CARACTERES\n\
	\nIntroduzca las cadenas de caracteres(max. 200 caracteres):\n");
	gets(v1);
	gets(v2);
	p1=v1;
	p2=v2;
	i=0;
	do{
	    if (*(p1+i)>*(p2+i))
	    {	printf("\nLa cadena -%s- es mayor que la cadena -%s-",p1,p2);
		exit(1);
	    }
	    if (*(p1+i)<*(p2+i))
	    {	printf("\nLa cadena -%s- es menor que la cadena -%s-",p1,p2);
		exit(1);
	    }
	    i++;
	}while (*(p1+i)!='\0'&&*(p2+i)!='\0');
	if (*(p1+i)=='\0'&&*(p2+i)!='\0')
	{	printf("\nLa cadena -%s- es menor que la cadena -%s-",p1,p2);
		exit(1);
	}
	if (*(p1+i)!='\0'&&*(p2+i)=='\0')
	{	printf("\nLa cadena -%s- es mayor que la cadena -%s-",p1,p2);
		exit(1);
	}
	if (*(p1+i)=='\0'&&*(p2+i)=='\0')
		printf("\nLas dos cadenas son iguales: -%s-",p1);
}