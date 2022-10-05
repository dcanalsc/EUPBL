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
	t_persona vec[N];
	int i,j,a;
	char aux[N],nom[50];
	clrscr();
	i=-1;
	do
	{	printf("\nIntroducir nuevos datos? (1-a¤adir/0-salir):");
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
	}while (i<=10&&a!=0);
	clrscr();
	printf("\nIntroduce ahora el nombre que desea buscar:\n");
	gets(nom);
	for(j=0;j<=i;j++)
	{	strcmp(nom,vec[j].nombre);  }
	if (nom==vec[j].nombre) printf("\nSu edad es %d",vec[j].edad);
	if (nom!=vec[j].nombre)	printf("\nEl nombre introducido no se ha encontrado.");
}
