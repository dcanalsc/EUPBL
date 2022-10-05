#include <stdio.h>
#define N 501
main()
{
	int i,j;
	char cadena[N],*cad;
	clrscr();
	printf("\nPROGRAMA PARA CALCULAR EL N§ DE PALABRAS\n\
	\nIntroduzca la cadena de caracteres(max. 500 caracteres):\n");
	gets(cadena);
	cad=cadena;
	j=0;
	for (i=0;*(cad+i)!='\0';i++)
	{
	       if (*(cad+i)==' ')
	       {}
	       if (*(cad+i)!=' ')
	       {	for (;*(cad+i)!=' '&&*(cad+i)!='\0';i++)
			{}
			j++;
	       }
	}
	printf("\nEn la cadena de caracteres hay (%d) palabras.",j);
}


