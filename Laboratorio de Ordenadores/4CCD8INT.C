#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define N 50                       

void interseccio(char *c1,char *c2,char *r)
{
	int i,j,k=0,s,condicion;
	char marca='ú';
	for(i=0;c1[i]!='\0';i++)
		for(j=0;c2[j]!='\0';j++)
		{
			if (c1[i]==c2[j])
			{
				condicion=1;
				for(s=0;s<=k;s++)
					if (r[s]==c1[i]||r[s]==c2[j]) condicion=0;
				if (condicion==1)
				{
					r[k]=c1[i];
					k++;
				}
				c2[j]=marca;break;
			}
		}
	r[k]='\0';
}

main()
{
	char cadena1[N],cadena2[N],resultado[N];
	clrscr();
	printf("\nINTERSECCION DE DOS CADENAS \n\
	\nIntroduce la primera cadena: ");
	gets(cadena1);
	printf("\nIntroduce la segunda cadena: ");
	gets(cadena2);
	interseccio(cadena1,cadena2,resultado);
	printf("\nLa interseccion de las dos cadenas es: %s",resultado);
}
