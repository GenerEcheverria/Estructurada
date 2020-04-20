//puntaje
#include<stdio.h>
#include<stdlib.h>
void puntaje(int puntos, int vidas);

int preguntas();
void resultado (int valor, int *acierto, int *vida);
int main (){
	int acierto=0, vida=3,opcion=0, juego;
	while (vida!=0) {
		puntaje(acierto,vida);
		sleep(2);
		system("cls");
		srand(time(NULL));
		juego = rand()%3;
		switch (juego) {
			case 0: resultado(preguntas(),&acierto,&vida); break;
			case 1: break;
			case 2: break;
		}
		
		
		
		vida=0 //prueba
	}
	
	return 0;
}
void puntaje (int puntos, int vidas){
	switch (vidas){
		case 1:
		system("color 04");
		puts("\t       VIDAS");
		puts("\t__ __");
		puts("\t\\ V /");
		puts("\t \\ /");				
		puts("\t  V");
		printf("\n\t     PUNTAJE: %d",puntos); break;
		case 2:
		system("color 06");
		puts("\t       VIDAS");
		puts("\t__ __  __ __");
		puts("\t\\ V /  \\ V /");
		puts("\t \\ /    \\ /");
		puts("\t  V      V");
		printf("\n\t     PUNTAJE: %d",puntos); break;
		case 3:
		system("color 02");
		puts("\t       VIDAS");
		puts("\t__ __  __ __  __ __");
		puts("\t\\ V /  \\ V /  \\ V /");
		puts("\t \\ /    \\ /    \\ /");
		puts("\t  V      V      V");
		printf("\n\t     PUNTAJE: %d",puntos); break;
	}
}
void resultado (int valor, int *acierto, int *vida){
	if (valor==1){
		*acierto+=1;
	}
	else {
		*vida-=1;
	}
}
