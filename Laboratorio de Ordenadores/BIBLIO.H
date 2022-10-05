#define NUM_LIBROS 10 /* n£mero m ximo de libros */

/* Tipo booleano */
typedef enum { TRUE = (0 == 0), FALSE = ( 1 == 0) } BOOLEAN;


#define NUM_NOMBRE 30 /* n£mero m ximo de caracteres de los t¡tulos y nombres
						 de autor */
/* Tipo libro */
typedef struct
{
	char titulo[NUM_NOMBRE],autor[NUM_NOMBRE];
} E_Libro;

/* Tipo biblioteca */
typedef struct
{
	int     n_libros, /* es el n£mero de libros que hay en la base de datos*/
		codigo; /* c¢digo secreto del administrador, ponedlo a 1111 */
	E_Libro libro[NUM_LIBROS]; /* vector con los libros de la base de datos*/
} E_Biblio;

/* Funciones de alto nivel de los lectores */
void buscar_titulo_a(E_Biblio *b);
void buscar_autor_a(E_Biblio *b);

/* Funciones de alto nivel del administrador */
BOOLEAN pedir_codigo_a(E_Biblio *b);
void anyadir_libro_a(E_Biblio *b);
void eliminar_libro_a(E_Biblio *b);
void editar_libro_a(E_Biblio *b);
void acabar_programa_a(E_Biblio *b);

/* Funciones de alto nivel de ambos */
void pedir_nombre_a(char *n);
void consultar_libros_a(E_Biblio *b);
void inicializar_biblioteca_a(E_Biblio *b);

/* Funciones b sicas */
void inicializar_lista(E_Biblio *b);
int nuevo_libro(E_Biblio *b);
void borrar_libro(E_Biblio *b,int identificador);
void editar_libro(E_Biblio *b,int identificador,char *titulo,char *autor);
char *ver_titulo(E_Biblio *b,int identificador);
char *ver_autor(E_Biblio *b,int identificador);
void buscar_titulo(E_Biblio *b,char *titulo,int *lista);
void buscar_autor(E_Biblio *b,char *autor,int *lista);
BOOLEAN comprobar_codigo(E_Biblio *b,int codigo);
int cantidad_libros(E_Biblio *b);

/* Fichero */
int llegir_de_fitxer(E_Biblio *bib, char *filename);
int escriure_a_fitxer(E_Biblio *bib, char *filename);
