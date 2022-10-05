#include <stdio.h>
main()
{
	int a;
	printf("\n************************MENU USUARIO************************\n\
		\n\
		1. Copiar archivo\n\
		2. Borrar archivo\n\
		3. Comparar archivos\n\
		4. Ver archivo\n\
		5. Editar archivo\n\
		6. Salir al MS-DOS\n");
	printf("\nSeleccione una de las opciones:");
	scanf("%d",&a);
	switch(a)
	{
	case 1: printf("Ha seleccionado la opcion Copiar archivo");
		break;
	case 2: printf("Ha seleccionado la opcion Borrar archivo");
		break;
	case 3: printf("Ha seleccionado la opcion Comparar archivo");
		break;
	case 4: printf("Ha seleccionado la opcion Ver archivo");
		break;
	case 5: printf("Ha seleccionado la opcion Editar archivo");
		break;
	case 6: printf("Ha seleccionado Salir al MS-DOS");
	default: exit(0);
		 break;
	}
}