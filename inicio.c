#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void titulo ();
int main (){
	char tecla=1;
	int i;
	while (tecla!=0){
		system("color 02");
		titulo ();
		puts("\t\t\tSelecciona:");
		printf("\t\t\t->"); puts(" Empezar");
		printf("\t\t\t  "); puts(" Puntuaciones");
		printf("\t\t\t  "); puts(" Salir");
		puts("\n\t\t\t\t\t\tWCORP. 2020.");
		tecla=getch();
		system("cls");
		if (tecla=='s'||tecla=='S') {
			titulo();
			puts("\t\t\tSelecciona:");
			printf("\t\t\t  "); puts(" Empezar");
			printf("\t\t\t->"); puts(" Puntuaciones");
			printf("\t\t\t  "); puts(" Salir");
			puts("\n\t\t\t\t\t\tWCORP. 2020.");
			tecla=getch();
			system("cls");
			if (tecla==13){
					puts("puntuacion");
					system("pause");
					system("cls");
					tecla=1;
			}
			if (tecla=='w'||tecla=='W'){
				continue;
			}
		}
		if (tecla=='s'||tecla=='S') {
			titulo();
			puts("\t\t\tSelecciona:");
			printf("\t\t\t  "); puts(" Empezar");
			printf("\t\t\t  "); puts(" Puntuaciones");
			printf("\t\t\t->"); puts(" Salir");
			puts("\n\t\t\t\t\t\tWCORP. 2020.");
			tecla=getch();
			system("cls");
			if (tecla==13){
				break;
			}
			if (tecla=='w'||tecla=='W'){
				titulo();
				puts("\t\t\tSelecciona:");
				printf("\t\t\t  "); puts(" Empezar");
				printf("\t\t\t->"); puts(" Puntuaciones");
				printf("\t\t\t  "); puts(" Salir");
				puts("\n\t\t\t\t\t\tWCORP. 2020.");
				tecla=getch();
				system("cls");
				if (tecla==13){
					puts("puntuacion");
					system("pause");
					system("cls");
					tecla=1;
					//puntuacion;
				}
				if (tecla=='w'||tecla=='W'){
					continue;
				}
			}
		}
		if (tecla==13) {
			//pantalla vida puntos en 0 y comienza partida
			system("cls");
			puts("hola");
			/*system("cls");
			selec();
			system("cls");*/
			system("pause");//prueba
			system("cls");
		}
	}
	return 0;
}
void titulo (){
	puts("\n");
	puts("\t===================================================\n");
	puts("\t   #####            ##         ##  ##");
	puts("\t ##     ##                     ## ##    ##");
	puts("\t ##     ##  ##  ##  ##  #####  ####    #  #  # ###");
	puts("\t ##     ##  ##  ##  ##  ##     ####    ####  ##"); 
	puts("\t ##   # ##  ##  ##  ##  ##     ## ##   #     ##");
	puts("\t   #####    ######  ##  #####  ##  ##  ####  ##");
	puts("\t        #   ");
	puts("\t===================================================\n");
}
