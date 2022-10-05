#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include "biblio.h"

main()
{
	char nombre[NUM_NOMBRE],opcion;
	BOOLEAN condicion1,condicion2;
	int i;
	E_Biblio biblioteca;
	inicializar_biblioteca_a(&biblioteca);
	while(1)
	{
		pedir_nombre_a(nombre);
		condicion1=FALSE;condicion2=FALSE;
		if(stricmp(nombre,"adm"))
		{
			while (condicion1==FALSE)
			{
				clrscr();
				gotoxy(10,10);
				printf("***********************MENU PRINCIPAL***********************");
				gotoxy(10,12);
				printf("a. Buscar libro por titulo");
				gotoxy(10,13);
				printf("b. Buscar libro por autor");
				gotoxy(10,14);
				printf("c. Consultar libros de la biblioteca");
				gotoxy(10,15);
				printf("d. Salir del programa");
				gotoxy(11,17);
				printf("Elige una opcion: ");
				opcion=getch();
				switch(opcion)
				{
					case 'a': buscar_titulo_a(&biblioteca);break;
					case 'b': buscar_autor_a(&biblioteca);break;
					case 'c': consultar_libros_a(&biblioteca);break;
					case 'd': condicion1=TRUE;break;
					default: clrscr();
						 gotoxy(10,10);
						 printf("­Error! Elige otra opcion");
						 gotoxy(10,12);
						 printf("ENTER para continuar...");
						 getch();
						 break;
				}
			}
		}
		else
		{
			while (condicion1==FALSE)
			{
				i=0;
				do
				{
					condicion2=pedir_codigo_a(&biblioteca);
					if (condicion2==TRUE) break;
					i++;
				}while(i<3);
				if (condicion2==FALSE) break;
				while (condicion2==TRUE)
				{
					clrscr();
					gotoxy(10,10);
					printf("**********************MENU PRINCIPAL***********************");
					gotoxy(10,12);
					printf("a. A¤adir libro\n");
					gotoxy(10,13);
					printf("b. Eliminar libro\n");
					gotoxy(10,14);
					printf("c. Editar libro\n");
					gotoxy(10,15);
					printf("d. Acabar el programa\n");
					gotoxy(10,16);
					printf("e. Consultar libros de la biblioteca\n");
					gotoxy(10,17);
					printf("f. Salir del programa");
					gotoxy(11,19);
					printf("\n\nElige una opcion: ");
					opcion='\0';
					opcion=getch();
					switch(opcion)
					{
						case 'a': anyadir_libro_a(&biblioteca);break;
						case 'b': eliminar_libro_a(&biblioteca);break;
						case 'c': editar_libro_a(&biblioteca);break;
						case 'd': acabar_programa_a(&biblioteca);break;
						case 'e': consultar_libros_a(&biblioteca);break;
						case 'f': condicion1=TRUE;condicion2=FALSE;break;
						default: clrscr();
							 gotoxy(10,10);
							 printf("­Error! Elige otra opcion");
							 gotoxy(10,12);
							 printf("ENTER para continuar...");
							 getch();
							 break;
					}
				}
			}
		}
		clrscr();
		gotoxy(10,10);
		printf("Desea acabar (s/n): ");
		opcion=getch();
		if (opcion=='s') break;
	}
	clrscr();
}

