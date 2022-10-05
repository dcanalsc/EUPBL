#include <stdio.h>
#define M 200
main()
{
	char a[M];
	int i,j;
	clrscr();
	printf("\nPROGRAMA PARA CALCULAR LA LONGITUD DE UNA CADENA\n\
	\nIntroduzca la cadena de caracteres:\n");
	gets(a);
	j=0;
	for (i=0;a[i]!='\0';i++)
	{	j++;	}
	printf("\nLa longitud de la cadena -%s- es de %d caracteres",a,j);
}