#include <stdio.h>
#include <math.h>
#define M 3
#define N 3
#define A 128
main()
{
	char a[M][N];
	int i,j,b,c[A];
	clrscr();
	printf("LECTOR DE MATRICES 3*3\n\
	\nIntroduzca los caracteres de la matriz:\n");
	for (i=0;i<127;i++)
	{	c[i]=0;      }
	for (i=0;i<3;i++)
	{	for (j=0;j<3;j++)
		{
			scanf ("%c",&a[i][j]);
		}
	}

	for (i=0;i<3;i++)
	{	for (j=0;j<3;j++)
		{
			b=a[i][j];
			c[b]++;
		 }
	}
	for (i=0;i<127;i++)
	{       if (c[i]>0)
		printf("\nEl caracter %c se encuentra en la matriz %d veces",i,c[i]);
	}
}