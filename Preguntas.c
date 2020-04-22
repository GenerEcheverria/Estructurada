#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int preguntas(int acierto);
int main () {
	
	int acierto=7; //para probar aumento de velocidad
	printf("%d", preguntas(acierto));
	return 0;
}
int preguntas(int acierto) {
	int punto=0, opcion, respuesta;
	time_t tiempoInicial=time(NULL);
	float tiempoLimite; 
	srand(time(NULL)); //probar
	opcion=rand()%10; //cambiar dependiendo del numero de preguntas
	if (acierto<=4) {
		tiempoLimite=10.0;
	}
	else {
		if (acierto<=7) {
			tiempoLimite = 8;
		}
		else {
			tiempoLimite=6;
		}
	}
	
	switch (opcion) {
			case 0: puts("El resultado de 7 x 8 es:");
				while ((time(NULL)-tiempoInicial)<tiempoLimite){
					if (kbhit()) {
						scanf("%d",&respuesta);
						if (respuesta==56) {
							punto=1;
							system ("cls"); break;
						} 
						else {
							system ("cls"); break;
						}
					}
				} system ("cls"); break;
			case 1: puts ("El resultado de (5x2)+(6/3) es:");
				while ((time(NULL)-tiempoInicial)<tiempoLimite){
					if (kbhit()) {
						scanf("%d",&respuesta);
						if (respuesta==12) {
							punto=1;
							system ("cls"); break;
						} 
						else {
							system ("cls"); break;
						}
					}
				} system ("cls"); break;
			case 2: puts ("El resultado de 325+78 es:");
				while ((time(NULL)-tiempoInicial)<tiempoLimite){
					if (kbhit()) {
						scanf("%d",&respuesta);
						if (respuesta==303) {
							punto=1;
							system ("cls"); break;
						} 
						else {
							system ("cls"); break;
						}
					}
				} system ("cls"); break;
			case 3: puts ("La raiz cuadrada de 121 es: ");
				while ((time(NULL)-tiempoInicial)<tiempoLimite){
					if (kbhit()) {
						scanf("%d",&respuesta);
						if (respuesta==11) {
							punto=1;
							system ("cls"); break;
						} 
						else {
							system ("cls"); break;
						}
					}
				} system ("cls"); break;
			case 4: puts ("La raiz cuadrada de 144 es: ");
				while ((time(NULL)-tiempoInicial)<tiempoLimite){
					if (kbhit()) {
						scanf("%d",&respuesta);
						if (respuesta==12) {
							punto=1;
							system ("cls"); break;
						} 
						else {
							system ("cls"); break;
						}
					}
				} system ("cls"); break;
			
			case 5: puts ("El resultado de 7+25x4-12 es: ");
				while ((time(NULL)-tiempoInicial)<tiempoLimite){
					if (kbhit()) {
						scanf("%d",&respuesta);
						if (respuesta==95) {
							punto=1;
							system ("cls"); break;
						} 
						else {
							system ("cls"); break;
						}
					}
				} system ("cls"); break;
			case 6: puts ("El resultado de (-50)x(-50) es: ");
				while ((time(NULL)-tiempoInicial)<tiempoLimite){
					if (kbhit()) {
						scanf("%d",&respuesta);
						if (respuesta==2500) {
							punto=1;
							system ("cls"); break;
						} 
						else {
							system ("cls"); break;
						}
					}
				} system ("cls"); break;
			case 7: puts ("El resultado de (3)x(-3)x(3)x(-3) es: ");
				while ((time(NULL)-tiempoInicial)<tiempoLimite){
					if (kbhit()) {
						scanf("%d",&respuesta);
						if (respuesta==81) {
							punto=1;
							system ("cls"); break;
						} 
						else {
							system ("cls"); break;
						}
					}
				} system ("cls"); break;
			case 8: puts ("El resultado de 4*3-2/1 es: ");
				while ((time(NULL)-tiempoInicial)<tiempoLimite){
					if (kbhit()) {
						scanf("%d",&respuesta);
						if (respuesta==10) {
							punto=1;
							system ("cls"); break;
						} 
						else {
							system ("cls"); break;
						}
					}
				} system ("cls"); break;
			case 9: puts ("El resultado de 4*3-2/1 es: ");
				while ((time(NULL)-tiempoInicial)<tiempoLimite){
					if (kbhit()) {
						scanf("%d",&respuesta);
						if (respuesta==10) {
							punto=1;
							system ("cls"); break;
						} 
						else {
							system ("cls"); break;
						}
					}
				} system ("cls"); break;
	}
	
	return punto;
}
