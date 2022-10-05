#include <stdio.h>
#include <conio.h>
typedef char cadena[50];
main()
{
	cadena str1,str2;
	int actual1,actual2,i;
	clrscr();
	printf("\nIntroduce la cadena mas larga:\n");
	gets(str2);
	printf("\nIntroduce la cadena mas corta:\n");
	gets(str1);
	if (strlen(str1)>strlen(str2)) printf("\nLas cadenas introducidas son incorrectas.");
	else
	{       actual1=0;
		actual2=0;
		while (str2[actual2]!='\0')
		{       while (str1[actual1]!='\0'&&str2[actual2]!='\0')
			{       if (str1[actual1]==str2[actual2])
				{	actual1++;
					actual2++;
				}
				else
				{	actual1=0;
					actual2++;
				}
				if (str1[actual1]=='\0')
				{       i=actual2;
					do{     str2[i-actual1]=str2[i];
						i++;
					}while (str2[i]!='\0');
				}
			}
			actual1=0;
		}
	}
	printf("\nLa nueva cadena es:\n%s",str2);
}
