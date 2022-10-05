#include <stdio.h>
#include <conio.h>
long factorial(long num)
{
	long x=1;
	for(;num>=1;num--)
	{	x*=num;		}
	return x;
}
int lee_entero()
{
	long res;
	char num[20];
	gets(num);
	res=atoi(num);
	return res;
}
main()
{
	long num;
	clrscr();
	printf("\nPROGRAMA PARA CALCULAR EL FACTORIAL DE UN NUMERO\n\
	\nIntroduce el numero para calcular el factorial: ");
	num=lee_entero();
	num=factorial(num);
	printf("\nEl factorial del numero introducido es: %ld",num);
}
