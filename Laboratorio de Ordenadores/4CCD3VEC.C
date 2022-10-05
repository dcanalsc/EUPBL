#include <stdio.h>
#include <math.h>
#define A 5
main()
{
	int a[A],b[A],i,r;
	for (i=0;i<A;i++)
	{
		printf("\nIntroduzca los elementos del primer vector:");
		scanf("%d",&a[i]);
	}
	for (i=0;i<A;i++)
	{
		printf("\nIntroduzca los elementos del segundo vector:");
		scanf("%d",&b[i]);
	}
	r=0;
	for (i=0;i<A;i++)
	{
		r=r+a[i]*b[i];
	}
	printf("\nEl resultado del producto escalar es: %d",r);
}