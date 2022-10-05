#include <fcntl.h>
#include <io.h>
#include <sys/stat.h>
#include "biblio.h"
int llegir_de_fitxer(E_Biblio *bib, char *filename)
{
/* llegeix la biblioteca 'biblio' del fitxer 'filename' */
/* Torna 1 si ha pogut llegir-lo, 0 si no ha anat b‚ */

	int handle;

	if ( (handle = open(filename, O_RDONLY | O_BINARY)) == -1 )
		return 0;
	if ( read(handle, bib, sizeof (E_Biblio)) != sizeof(E_Biblio) ) {
		close(handle);
		return 0;
	}
	close(handle);
	return 1;


}

int escriure_a_fitxer(E_Biblio *bib, char *filename)
{
/* escriu la biblioteca 'biblio' al fitxer 'filename'  */
/* Torna 1 si ha anat b‚, 0 si no ha pogut */

	int handle;

	if ( access(filename, 0) == -1 ) {
		/* no existeix */
		handle = open(filename, O_CREAT | O_BINARY, S_IWRITE);
	} else {
		/* existeix */
		handle = open(filename, O_RDWR | O_BINARY, S_IWRITE);
	}
	if ( handle == -1 )
		return 0;
	if ( write(handle, bib, sizeof(E_Biblio)) != sizeof(E_Biblio) ) {
		close(handle);
		return 0;
	}
	close(handle);
	return 1;

}
