#include <stdio.h>
#include <math.h>
main()
{

	float A,B,C,R,S;
	printf("\nPROGRAMA PARA CALCULAR LAS RAICES DE UN POLINOMIO DE SEGUNDO GRADO");
	printf("\nIntroduzca el valor de a:");
	scanf("%f",&A);
	printf("\nIntroduzca el valor de b:");
	scanf("%f",&B);
	printf("\nIntroduzca el valor de c:");
	scanf("%f",&C);
	if ((B*B-(4*A*C))<0) printf("\nEl valor de la raiz cuadrada es un numero negativo");
	if ((B*B-(4*A*C))<0) exit(1);
	R=(-B+sqrt(B*B-(4*A*C)))/2*A;
	S=(-B-sqrt(B*B-(4*A*C)))/2*A;
	printf("\nEl resultado de la primera raiz es: %f y la segunda: %f",R,S);
}

