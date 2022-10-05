#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "biblio.h"

void inicializar_biblioteca_a(E_Biblio *b)
{
	inicializar_lista(b);
	if (llegir_de_fitxer(b,"datos.bib")==0)
	{
		clrscr();
		gotoxy(10,10);
		printf("­­No se puede acceder a la base de datos!!");
		gotoxy(10,12);
		printf("ENTER para continuar...");
		getch();
	}
}

void pedir_nombre_a(char *nombre)
{
	clrscr();
	gotoxy(10,10);
	printf("Introduce tu nombre (max. 9 caracteres): ");
	gets(nombre);
}

void buscar_titulo_a(E_Biblio *b)
{
	char *cadena1,*cadena2,titulo[NUM_NOMBRE];
	int lista[NUM_LIBROS],i=0;
	clrscr();
	gotoxy(10,10);
	printf("Introduce el titulo o parte de el a buscar: ");
	gets(titulo);
	buscar_titulo(b,titulo,lista);
	if (lista[i]!=-1)
	{
		clrscr();
		gotoxy(10,10);
		printf("Se ha encontrado en los titulos:\n\n\n");
		for(;lista[i]!=-1;i++)
		{
			cadena1=ver_titulo(b,lista[i]);
			cadena2=ver_autor(b,lista[i]);
			printf("%s  -  %s\n",cadena1,cadena2);
		}
		printf("\n\nENTER para continuar...");
		getch();
	}
	else
	{
		clrscr();
		gotoxy(10,10);
		printf("­­El titulo no se encuentra!!");
		gotoxy(10,12);
		printf("ENTER para continuar...");
		getch();
	}
}

void buscar_autor_a(E_Biblio *b)
{
	char *cadena1,*cadena2,autor[NUM_NOMBRE];
	int lista[NUM_LIBROS],i=0;
	clrscr();
	gotoxy(10,10);
	printf("Introduce el nombre del autor a buscar: ");
	gets(autor);
	buscar_autor(b,autor,lista);
	if (lista[i]!=-1)
	{
		clrscr();
		gotoxy(10,10);
		printf("Se ha encontrado en los autores:\n\n\n");
		for (;lista[i]!=-1;i++)
		{
			cadena1=ver_autor(b,lista[i]);
			cadena2=ver_titulo(b,lista[i]);
			printf("%s  -  %s\n",cadena1,cadena2);
		}
		printf("\n\nENTER para continuar...");
		getch();
	}
	else
	{
		clrscr();
		gotoxy(10,10);
		printf("­­No se ha encontrado el autor!!");
		gotoxy(10,12);
		printf("ENTER para continuar...");
		getch();
	}
}

void consultar_libros_a(E_Biblio *b)
{
	char *cadena1,*cadena2;
	int i=0;
	clrscr();
	gotoxy(10,10);
	printf("Los libros que hay en la biblioteca son:\n\n\n");
	for(;i<cantidad_libros(b);i++)
	{
		cadena1=ver_titulo(b,i);
		cadena2=ver_autor(b,i);
		printf("Titulo: %s\n",cadena1);
		printf("   Autor: %s\n",cadena2);
	}
	printf("\n\nENTER para continuar...");
	getch();
}

void anyadir_libro_a(E_Biblio *b)
{
	int lista[NUM_LIBROS],ident;
	char titulo[NUM_NOMBRE],autor[NUM_NOMBRE],opcion;
	if (cantidad_libros(b)<NUM_LIBROS)
	{
		clrscr();
		gotoxy(10,10);
		printf("Introduce el titulo del libro nuevo: ");
		gets(titulo);
		gotoxy(10,12);
		printf("Introduce el nombre de su autor: ");
		gets(autor);
		buscar_titulo(b,titulo,lista);
		if(lista[0]!=-1)
		{
			clrscr();
			gotoxy(10,10);
			printf("El libro ya existe, desea a¤adirlo? (s/n): ");
			opcion=getch();
			if(opcion=='s')
			{
				ident=nuevo_libro(b);
				editar_libro(b,ident,titulo,autor);
			}
		}
		else
		{
			ident=nuevo_libro(b);
			editar_libro(b,ident,titulo,autor);
		}
	}
	else
	{
		clrscr();
		gotoxy(10,10);
		printf("­­Base de datos llena!!");
		gotoxy(10,12);
		printf("ENTER para continuar...");
		getch();
	}
}

void eliminar_libro_a(E_Biblio *b)
{
	char titulo[NUM_NOMBRE],autor[NUM_NOMBRE],opcion;
	int i=0,j=0,listatitulos[NUM_LIBROS],listaautores[NUM_LIBROS];
	clrscr();
	gotoxy(10,10);
	printf("Introduce el titulo del libro a eliminar: ");
	gets(titulo);
	gotoxy(10,12);
	printf("Introduce el nombre de su autor: ");
	gets(autor);
	buscar_titulo(b,titulo,listatitulos);
	buscar_autor(b,autor,listaautores);
	if (listatitulos[0]==-1||listaautores[0]==-1)
	{
		clrscr();
		gotoxy(10,10);
		printf("­­El libro no existe!!");
		gotoxy(10,12);
		printf("ENTER para continuar...");
		getch();
	}
	else
	{
		for(;listatitulos[i]!=-1;i++)
			for(;listaautores[j]!=-1;j++)
			{
				if(listatitulos[i]==listaautores[j])
				{
					clrscr();
					gotoxy(10,10);
					printf("­­El libro sera eliminado!!");
					gotoxy(10,11);
					printf("Estas seguro(s/n): ");
					opcion=getch();
					if(opcion=='s') borrar_libro(b,listatitulos[i]);
				}
			}
		clrscr();
		gotoxy(10,10);
		printf("ENTER para continuar...");
		getch();
	}
}

void editar_libro_a(E_Biblio *b)
{
	char titulo[NUM_NOMBRE],autor[NUM_NOMBRE],titulonuevo[NUM_NOMBRE],autornuevo[NUM_NOMBRE];
	int listatitulos[NUM_LIBROS],listaautores[NUM_LIBROS],i=0,j=0,ident;
	clrscr();
	gotoxy(10,10);
	printf("Introduce el titulo que quiere modificar: ");
	gets(titulo);
	gotoxy(10,12);
	printf("Introduce el nombre del autor: ");
	gets(autor);
	buscar_titulo(b,titulo,listatitulos);
	buscar_autor(b,autor,listaautores);
	if (listatitulos[i]!=-1&&listaautores[j]!=-1)
		for(;listatitulos[i]!=-1;i++)
			for(;listaautores[j]!=-1;j++)
				if(listatitulos[i]==listaautores[j])
				{
					ident=listatitulos[i];
					clrscr();
					gotoxy(10,10);
					printf("Introduce el titulo nuevo: ");
					gets(titulonuevo);
					gotoxy(10,12);
					printf("Introduce el nuevo autor: ");
					gets(autornuevo);
					if(titulonuevo[0]!='\0'&&autornuevo[0]!='\0')
					{
						editar_libro(b,ident,titulonuevo,autornuevo);
						clrscr();
						gotoxy(10,10);
						printf("Libro editado...");
						gotoxy(10,12);
						printf("ENTER para continuar...");
						getch();
					}
					else
					{
						clrscr();
						gotoxy(10,10);
						printf("­­El libro no se ha modificado!!");
						gotoxy(10,12);
						printf("ENTER para continuar...");
						getch();
					}
				}
	else
	{
		clrscr();
		gotoxy(10,10);
		printf("­­El libro no se encuentra en la base de datos!!");
		gotoxy(10,12);
		printf("ENTER para continuar...");
		getch();
	}
}

void acabar_programa_a(E_Biblio *b)
{
	clrscr();
	gotoxy(10,10);
	printf("Los cambios seran guardados");
	gotoxy(10,12);
	printf("ENTER para continuar...");
	getch();
	escriure_a_fitxer(b,"datos.bib");
	if (escriure_a_fitxer(b,"datos.bib")==0)
	{
		clrscr();
		gotoxy(10,10);
		printf("­Error al grabar los cambios!");
		gotoxy(10,12);
		printf("ENTER para continuar...");
		getch();
	}
	else
	{
		clrscr();
		gotoxy(10,10);
		printf("Operacion finalizada");
		gotoxy(10,12);
		printf("ENTER para continuar...");
		getch();
	}
}

BOOLEAN pedir_codigo_a(E_Biblio *b)
{
	char codig[4];
	int codigo,i=0;
	clrscr();
	gotoxy(10,10);
	printf("Introduce el codigo de acceso: ");
	for(;i<4;i++)
	{
		codig[i]=getch();
		printf("*");
	}
	codigo=atoi(codig);
	if(comprobar_codigo(b,codigo)==TRUE)
	{
		gotoxy(10,12);
		printf("Codigo correcto");
		gotoxy(10,14);
		printf("ENTER para continuar...");
		getch();
		return TRUE;
	}
	gotoxy(10,12);
	printf("­­Codigo incorrecto!!");
	gotoxy(10,14);
	printf("ENTER para continuar...");
	getch();
	return FALSE;
}