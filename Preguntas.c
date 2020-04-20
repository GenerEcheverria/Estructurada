#include<stdio.h>
#include<stdlib.h>
int preguntas();
int main () {
	printf("%d", preguntas());
	
	
	return 0;
}
int preguntas() {
	int punto=0, opcion, respuesta;
	opcion=0; // para probar
	//opcion=rand()%1; //cambiar dependiendo del numero de preguntas
	switch (opcion) {
		case 0: puts("El resultado de 7 x 8 es:");
			fflush(stdin);
			scanf("%d",&respuesta);
			if (respuesta==56) {
				punto=1;
			} system ("cls"); break;
	}
	return punto;
}
