#include <stdio.h>
#define N 201
main()
{
	char cadena1[N],cadena2[N],*cad1,*cad2;
	int i,a;
	clrscr();
	printf("\nPROGRAMA DE INVERSION ENTRE MINUSCULAS Y MAYUSCULAS\n\
	\nIntroduzca la cadena deseada(max. 200 caracteres):\n");
	gets(cadena1);
	cad1=cadena1;
	cad2=cadena2;
	for (i=0;*(cad1+i)!='\0';i++)
	{
		if (*(cad1+i)>='a'&&*(cad1+i)<='z')
		{
			a=*(cad1+i);
			*(cad2+i)=a+('A'-'a');
		}
		if (*(cad1+i)>='A'&&*(cad1+i)<='Z')
		{
			a=*(cad1+i);
			*(cad2+i)=a-('A'-'a');
		}
		if (*(cad1+i)<'a'&&*(cad1+i)>'z'&&*(cad1+i)<'A'&&*(cad1+i)>'Z'&&*(cad1+i)==' ')
		{	*(cad2+i)=*(cad1+i);	}
	}
	*(cad2+i)='\0';
	printf("\nLa nueva cadena de caracteres es:\n\
	%s",cad2);
}
