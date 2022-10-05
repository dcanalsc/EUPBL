#include <stdio.h>
#include <conio.h>
#define N 11
typedef struct
{
	char nombre[50];
	int edad;
}  t_persona;
main()
{
	t_persona vec[N],vecaux[1];
	int i,j,k,a;
	char aux[N],nom[50];
	clrscr();
	i=-1;
	printf("\nBASE DE DATOS(max. 10 personas)");
	do
	{	printf("\nIntroducir nuevas personas? (1-a¤adir/0-salir):");
		scanf("%d%c",&a,&aux);
		switch (a)
		{
			case 0: break;
			case 1: i++;
				printf("\nIntroduce el nombre: ");
				gets(vec[i].nombre);
				printf("\nIntroduce la edad: ");
				scanf("%d%c",&vec[i].edad,&aux);
				break;
		}
	}while (i<N&&a!=0);
	clrscr();
	for (k=0;k<=i;k++)
		for(j=N-1;j>0;j--)
			if (vec[j-1].edad>vec[j].edad)
			{
				vecaux[1].edad=vec[j].edad;
				strcpy(vecaux[1].nombre,vec[j].nombre);
				vec[j].edad=vec[j-1].edad;
				strcpy(vec[j].nombre,vec[j-1].nombre);
				vec[j-1].edad=vecaux[1].edad;
				strcpy(vec[j-1].nombre,vecaux[1].nombre);
			}
	for (k=0;k<=i;k++)
	{	printf("\nPersona%d: -Nombre: %s\n\
		-Edad: %d",k,vec[k].nombre,vec[k].edad);
	}
}