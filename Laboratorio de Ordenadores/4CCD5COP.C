#include <stdio.h>
#define N 201
main()
{
	char v1[N],v2[N],*p1,*p2;
	int i;
	clrscr();
	printf("\nPROGRAMA PARA COPIAR UNA CADENA DE CARACTERES\n\
	\nIntroduzca la cadena de caracteres(max. 200 caracteres):\n");
	gets(v1);
	p1=v1;
	p2=v2;
	for (i=0;*(p1+i)!='\0';i++)
	{
		*(p2+i)=*(p1+i);
	}
	*(p2+i)='\0';
	printf("\nLa cadena -%s- ha sido copiada.",p2);
}