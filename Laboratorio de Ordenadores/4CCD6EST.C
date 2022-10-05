#include <stdio.h>
#define N 201
typedef struct
{
	char calle[N];
	int numero;
	int piso;
} t_direccion;
typedef struct
{
	t_direccion direccion;
	char nombre[N];
	long telefono;
	float altura;
} t_amiga;
main()
{
	t_amiga amiga,*am;
	char aux[50];
	clrscr();
	printf("\nIntroduce los siguientes datos de tu amiga:\n\
	\nPrimero introduce su nombre: ");
	gets(amiga.nombre);
	printf("\nSegundo escribe su direccion en el siguiente orden:\n\
		-calle: ");
	gets(amiga.direccion.calle);
	printf("\n		-numero: ");
	scanf("%d%c",&amiga.direccion.numero,&aux);
	printf("\n		-piso: ");
	scanf("%d%c",&amiga.direccion.piso,&aux);
	printf("\nAhora escribe el telefono: ");
	scanf("%l%c",&amiga.telefono,&aux);
	printf("\nPor ultimo escribe su altura: ");
	scanf("%f%c",&amiga.altura,&aux);
	am=&amiga;
	clrscr();
	printf("\nLos datos introducidos de tu amiga son:\n\
	\n	-Nomre: %s\n\
	-Direccion:	-calle: %s\n\
			-numero: %d\n\
			-piso: %d\n\
	-Telefono: %l\n\
	-Altura: %f",am->nombre,am->direccion.calle,am->direccion.numero,am->direccion.piso,am->telefono,am->altura);
}