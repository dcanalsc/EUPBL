#include <stdio.h>
#include <stdlib.h>
#define N 56
typedef struct
{
	char nombre[N];
	int edad;
	float altura;
	char sexo;
}t_persona;

void lee_real(float *num)
{
	char numero[N];
	gets(numero);
	*num=atof(numero);
}

t_persona lee_persona(t_persona *p)
{
	char aux[N];
	clrscr();
	printf("\nIntroduce el nombre: ");
	gets(p->nombre);
	printf("\nIntroduce la edad: ");
	scanf("%d%c",&p->edad,&aux);
	printf("\nIntroduce la altura: ");
	lee_real(&p->altura);
	printf("\nIntroduce el sexo (F/M): ");
	scanf("%c",&p->sexo);
}

void imprime_persona(t_persona *p)
{
	clrscr();
	printf("\nLos datos de la persona %s son:\n\
	\n-edad: %d\n\
	\n-altura: %f\n\
	\n-sexo: %c",p->nombre,p->edad,p->altura,p->sexo);
}

main()
{
	t_persona per,vp[N];
	char aux[N];
	int i,j;
	clrscr();
	printf("\nIntroduce el numero de personas para leer: ");
	scanf("%d%c",&i,&aux);
	for (j=0;j<=i-1;j++)
	{
		vp[j]=lee_persona(&per);
	}
	printf("\nIntroduce el numero de la persona que quiere ver (%d personas): ",i);
	{
		scanf("%d%c",&j,&aux);
		imprime_persona(&vp[j-1]);
	}
}