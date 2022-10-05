#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "biblio.h"

void inicializar_lista(E_Biblio *b)
{
	int i=0;
	b->n_libros=0;
	for(;i<NUM_LIBROS;i++)
	{
		b->libro[i].titulo[0]='\0';
		b->libro[i].autor[0]='\0';
	}
	b->codigo=1111;
}

int nuevo_libro(E_Biblio *b)
{
	int i;
	i=b->n_libros++;
	return i;
}

void borrar_libro(E_Biblio *b,int identificador)
{
	int i;
	b->libro[identificador].titulo[0]='\0';
	b->libro[identificador].autor[0]='\0';
	if (identificador!=NUM_LIBROS)
	{
		for (i=identificador;i<NUM_LIBROS;i++)
		{
			strcpy(b->libro[i].titulo,b->libro[i+1].titulo);
			strcpy(b->libro[i].autor,b->libro[i+1].autor);
		}
	}
	b->n_libros--;
}

void editar_libro(E_Biblio *b,int identificador,char *titulo,char *autor)
{
	strcpy(b->libro[identificador].titulo,titulo);
	strcpy(b->libro[identificador].autor,autor);
}

char *ver_titulo(E_Biblio *b,int identificador)
{
	return b->libro[identificador].titulo;
}

char *ver_autor(E_Biblio *b,int identificador)
{
	return b->libro[identificador].autor;
}

void buscar_titulo(E_Biblio *b,char *titulo,int *lista)
{
	int i,j=0;
	for (i=0;i<NUM_LIBROS;i++)
	{
		if (strstr(b->libro[i].titulo,titulo))
		{
			lista[j]=i;
			j++;
		}
	}
	lista[j]=-1;
}

void buscar_autor(E_Biblio *b,char *autor,int *lista)
{
	int i,j=0;
	for (i=0;i<NUM_LIBROS;i++)
	{
		if (strstr(b->libro[i].autor,autor))
		{
			lista[j]=i;
			j++;
		}
	}
	lista[j]=-1;
}

BOOLEAN comprobar_codigo(E_Biblio *b,int codigo)
{
	if (codigo==b->codigo) return TRUE;
	return FALSE;
}

int cantidad_libros(E_Biblio *b)
{
	return b->n_libros;
}
