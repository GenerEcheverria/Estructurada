/*
Autor: Gener Echeverria, William Cetina, Jesus Estrella
Version 1.0
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
void titulo ();
//selec
void selec();
//puntaje
void resultado (int valor, int *acierto, int *vida);
void puntaje(int puntos, int vidas);
void tresCorazones ();
void dosCorazones();
void unCorazon();
//preguntas
int preguntas(int acierto);
//gato
int gato();
int loop(char tabla [3][3]);
void iniciarTabla(char tabla[3][3]);
void imprimirTabla(char tabla[3][3]);
void introducirFicha(char tabla[3][3]);
void introducirIA(char tabla[3][3]);
int ganador(char tabla[3][3]);
//asteroid
int asteroid ();
void borde (char campo[25][60]);
int bajar (char campo[25][60]);
void nave(char campo[25][60],int navex, int navey);
void meteorito(char campo[25][60]);
void imprimir(char campo[25][60]);
void draw(char campo[25][60]);
int gameloop(char campo[25][60],int navex, int navey);
void input(char campo[25][60],int *navex, int *navey);
//pong

//gameover
void gameOver(int puntos);
int main (){
	char tecla=1;
	int i;
	while (tecla!=0){
		system("color 02");
		titulo ();
		puts("\t\t\tSelecciona:");
		printf("\t\t\t->"); puts(" Empezar");
		printf("\t\t\t  "); puts(" Salir");
		puts("\n\t\t\t\t\t\tWCORP. 2020.");
		tecla=getch();
		system("cls");
		if (tecla=='s'||tecla=='S') {
			titulo();
			puts("\t\t\tSelecciona:");
			printf("\t\t\t  "); puts(" Empezar");
			printf("\t\t\t->"); puts(" Salir");
			puts("\n\t\t\t\t\t\tWCORP. 2020.");
			tecla=getch();
			system("cls");
			if (tecla==13){
				break;
			}
			if (tecla=='w'||tecla=='W'){
				continue;
			}
		}
		if (tecla==13) {
			system("cls");
			selec();
			system("pause");
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
void selec (){
	int acierto=0, vida=3,opcion=0, juego;
	while (vida!=0) {
		puntaje(acierto,vida);
		sleep(2);
		system("cls");
		srand(time(NULL));
		juego = rand()%4; //cambiar dependiendo del numero de juegos
		switch (juego) {
			case 0: resultado(preguntas(acierto),&acierto,&vida); break;
			case 1: resultado(gato(),&acierto,&vida); break;
			case 2: resultado(asteroid(),&acierto,&vida);break;
			//case 3: resultado(pong(),&acierto,&vida);break;
		}
	}
	gameOver(acierto);
}
//puntaje
void puntaje (int puntos, int vidas){
	switch (vidas){
		case 1:
			system("color 04");
			puts("\n\n\t\t     VIDAS\n");
			unCorazon();
			printf("\n\t\t  PUNTAJE: %d",puntos); break;
		case 2:
			system("color 06");
			puts("\n\n\t\t     VIDAS\n");
			dosCorazones();
			printf("\n\t\t  PUNTAJE: %d",puntos); break;
		case 3:
			system("color 02");
			puts("\n\n\t\t     VIDAS\n");
			tresCorazones();
			printf("\n\t\t  PUNTAJE: %d",puntos); break;
	}
}
void resultado (int valor, int *acierto, int *vida){
	if (valor==1){
		*acierto+=1;
	}
	
	if (valor==0){
		*vida-=1;
	}
	
}
void tresCorazones(){
	int a, b, line = 4;
   for (a = line/2; a <= line; a = a+2) { 
     	printf("\t");
      for (b = 1; b < line-a; b = b+2) 
         printf(" ");
      for (b = 1; b <= a; b++) 
         printf("*");
      for (b = 1; b <= line-a; b++)
         printf(" ");
      for (b = 1; b <= a-1; b++) 
         printf("*");
         printf("\t    ");
      for (b = 1; b < line-a; b = b+2) 
         printf(" ");
      for (b = 1; b <= a; b++)
         printf("*");
      for (b = 1; b <= line-a; b++) 
         printf(" ");
      for (b = 1; b <= a-1; b++) 
         printf("*");
         printf("\t");
      for (b = 1; b < line-a; b = b+2) 
         printf(" ");
      for (b = 1; b <= a; b++)
         printf("*");
      for (b = 1; b <= line-a; b++) 
         printf(" ");
      for (b = 1; b <= a-1; b++) 
         printf("*");
         printf("\n");
   }
   for (a = line; a >= 0; a--) { 
   	  printf("\t");
      for (b = a; b < line; b++) 
         printf(" ");
      for (b = 1; b <= ((a * 2) - 1); b++) 
         printf("*");
      printf("\t    ");
         for (b = a; b < line; b++) 
         printf(" ");
      for (b = 1; b <= ((a * 2) - 1); b++) 
         printf("*");
         printf("\t");
         for (b = a; b < line; b++) 
         printf(" ");
      for (b = 1; b <= ((a * 2) - 1); b++) 
         printf("*");
         printf("\n");
        
   }
}
void dosCorazones(){
	int a, b, line = 4;
   for (a = line/2; a <= line; a = a+2) { 
     	printf("\t");
      for (b = 1; b < line-a; b = b+2) 
         printf(" ");
      for (b = 1; b <= a; b++) 
         printf("*");
      for (b = 1; b <= line-a; b++)
         printf(" ");
      for (b = 1; b <= a-1; b++) 
         printf("*");
         printf("\t    ");
      for (b = 1; b < line-a; b = b+2) 
         printf(" ");
      for (b = 1; b <= a; b++)
         printf("*");
      for (b = 1; b <= line-a; b++) 
         printf(" ");
      for (b = 1; b <= a-1; b++) 
         printf("*");
         printf("\n");
   }
   for (a = line; a >= 0; a--) { 
   	  printf("\t");
      for (b = a; b < line; b++) 
         printf(" ");
      for (b = 1; b <= ((a * 2) - 1); b++) 
         printf("*");
      printf("\t    ");
         for (b = a; b < line; b++) 
         printf(" ");
      for (b = 1; b <= ((a * 2) - 1); b++) 
         printf("*");
         printf("\n");
   }
}
void unCorazon(){
	int a, b, line = 4;
   for (a = line/2; a <= line; a = a+2) { 
     	printf("\t");
      for (b = 1; b < line-a; b = b+2) 
         printf(" ");
      for (b = 1; b <= a; b++) 
         printf("*");
      for (b = 1; b <= line-a; b++)
         printf(" ");
      for (b = 1; b <= a-1; b++) 
         printf("*");
         printf("\n");
   }
    for (a = line; a >= 0; a--) { 
   	  printf("\t");
      for (b = a; b < line; b++) 
         printf(" ");
      for (b = 1; b <= ((a * 2) - 1); b++) 
         printf("*");
         printf("\t    ");
         printf("\n");
   }
}
//preguntas
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
//gato
int gato (){
	char tabla[3][3];
	int resu;
	resu=loop(tabla);
	system("cls");
	return resu;
}
int loop (char tabla[3][3]){
	int i=0,j;
	iniciarTabla(tabla);
	do {
		system("cls");
		imprimirTabla(tabla);
		if (i%2==0){
			
			introducirIA(tabla);
		}
		else {
			introducirFicha(tabla);
		}
		j=ganador(tabla);
		i++;
	}while(i<=8 && j==2);
	system("cls");
	imprimirTabla(tabla);
	if (j==1){
		puts("\tGanaste");
		return 1;
	}
	else {
		if (j==0) {
			puts("\tPerdiste"); 
			return 0;
		}
		else {
			puts ("\tEmpate");
			return 2;
		}
	} 
}
void iniciarTabla(char tabla[3][3]){
	int i,j;
	char aux='1';
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			tabla[i][j]=aux++;
		}
	}
}
void imprimirTabla(char tabla[3][3]){
	int i,j;
	puts("\n");
	for (i=0;i<3;i++){
		printf("\t\t");
		for (j=0;j<3;j++){
			if (j<2){
				printf(" %c |",tabla[i][j]);
			}
			else {
				printf(" %c ",tabla[i][j]);
			}
		}
		if (i<2){
			puts("\n\t\t-----------");
		}
	}
	puts("\n\n");
}
void introducirFicha(char tabla[3][3]){
	int i,j,k;
	char ficha;
	do {
		do{
			printf("\tColoca tu ficha: ");
			fflush(stdin);
			scanf("%c", &ficha);
		} while(ficha<'1'||ficha>'9');
		k=0;
		switch (ficha){
			case '1': {
				i=0;
				j=0;
				if (tabla[i][j]=='X' || tabla[i][j]=='O'){
					k=1;
					puts("\tCasilla ocupada");
				}
				break;
			}
			case '2': {
				i=0;
				j=1;
				if (tabla[i][j]=='X' || tabla[i][j]=='O'){
					k=1;
					puts("Casilla ocupada");
				}
				break;
			}
			case '3': {
				i=0;
				j=2;
				if (tabla[i][j]=='X' || tabla[i][j]=='O'){
					k=1;
					puts("\tCasilla ocupada");
				}
				break;
			}
			case '4': {
				i=1;
				j=0;
				if (tabla[i][j]=='X' || tabla[i][j]=='O'){
					k=1;
					puts("\tCasilla ocupada");
				}
				break;
			}
			case '5': {
				i=1;
				j=1;
				if (tabla[i][j]=='X' || tabla[i][j]=='O'){
					k=1;
					puts("\tCasilla ocupada");
				}
				break;
			}
			case '6': {
				i=1;
				j=2;
				if (tabla[i][j]=='X' || tabla[i][j]=='O'){
					k=1;
					puts("\tCasilla ocupada");
				}
				break;
			}
			case '7': {
				i=2;
				j=0;
				if (tabla[i][j]=='X' || tabla[i][j]=='O'){
					k=1;
					puts("\tCasilla ocupada");
				}
				break;
			}
			case '8': {
				i=2;
				j=1;
				if (tabla[i][j]=='X' || tabla[i][j]=='O'){
					k=1;
					puts("\tCasilla ocupada");
				}
				break;
			}
			case '9': {
				i=2;
				j=2;
				if (tabla[i][j]=='X' || tabla[i][j]=='O'){
					k=1;
					puts("\tCasilla ocupada");
				}
				break;
			}
		}
	}while(k==1);
	tabla[i][j]='X';
}
void introducirIA(char tabla[3][3]){
	char aux;
	int i,j,k;
	srand(time(NULL));
	do {
		i=rand()%3;
		j=rand()%3;
		k=0;
		if (tabla[i][j]=='X' || tabla[i][j]=='O'){
			k=1;
		}
	}while (k==1);
	tabla[i][j]='O';
}
int ganador (char tabla[3][3]){
	if (tabla[0][0]=='X' || tabla[0][0]=='O'){
		if (tabla[0][0]==tabla[0][1]&& tabla[0][0]==tabla[0][2]){
			if (tabla[0][0]=='X'){
				return 1; //ganar
			}
			else {
				return 0;
			}
		}
		if (tabla[0][0]==tabla[1][0]&& tabla[0][0]==tabla[2][0]){
			if (tabla[0][0]=='X'){
				return 1; //ganar
			}
			else {
				return 0;
			}
		}
	}
	if (tabla[1][1]=='X' || tabla[1][1]=='O' ) {
		if (tabla[1][1]==tabla[0][0]&& tabla[1][1]==tabla[2][2]){
			if (tabla[1][1]=='X'){
				return 1; 
			}
			else {
				return 0;
			}
		}
		if (tabla[1][1]==tabla[1][0]&& tabla[1][1]==tabla[1][2]){
			if (tabla[1][1]=='X'){
				return 1; 
			}
			else {
				return 0;
			}
		}
		if (tabla[1][1]==tabla[2][0]&& tabla[1][1]==tabla[0][2]){
			if (tabla[1][1]=='X'){
				return 1; 
			}
			else {
				return 0;
			}
		}
		if (tabla[1][1]==tabla[0][1]&& tabla[1][1]==tabla[2][1]){
			if (tabla[1][1]=='X'){
				return 1; 
			}
			else {
				return 0;
			}
		}
	}
	if (tabla[2][2]=='X' || tabla[2][2]=='O'){
		if (tabla[2][2]==tabla[2][0]&& tabla[2][2]==tabla[2][1]){
			if (tabla[2][2]=='X'){
				return 1; 
			}
			else {
				return 0;
			}
		}
		if (tabla[2][2]==tabla[0][2]&& tabla[2][2]==tabla[1][2]){
			if (tabla[2][2]=='X'){
				return 1; 
			}
			else {
				return 0;
			}
		}
	}
	return 2; 
}
//asteroid
int asteroid(){
	char campo[25][60];
	int navex=22,navey=30, resultado;
	borde(campo);
	nave(campo,navex,navey);
	imprimir(campo);
	resultado=gameloop(campo,navex,navey);
	return resultado;
}
void borde (char campo[25][60]){
	int i,j,V=25,H=60;
	for(i=0;i<V;i++){
		for (j=0;j!=H;j++){
			if(i==0||i==V-1){
				campo[i][j]='_';
			}else if(j==0||j==H-1){
				campo[i][j]='|';
			}else{
				campo[i][j]=' ';
			}
		}
	}
	return;
}
void nave (char campo[25][60],int navex, int navey){
	campo[navex][navey]='X';
	campo[navex+1][navey-1]='X';
	campo[navex+1][navey]='X';
	campo[navex+1][navey+1]='X';
	return;
}
void imprimir(char campo[25][60]){
		int i,j,V=25,H=60;
		for(i=0;i<V;i++){
		for (j=0;j!=H;j++){
		printf("%c",campo[i][j]);
		}
		printf("\n");
	}
	return;
}
int gameloop(char campo[25][60],int navex, int navey){
	int lose=0, d=1;
	int resu=0;
	time_t tiempoInicial=time(NULL);
	float tiempoLimite=10;
	do{
	draw(campo);
	if(d==1){
	meteorito(campo);
	d=0;
}
	lose=bajar(campo);
	d++;
	input(campo,&navex,&navey);
	input(campo,&navex,&navey);
	input(campo,&navex,&navey);
	input(campo,&navex,&navey);
	input(campo,&navex,&navey);
	input(campo,&navex,&navey);
	input(campo,&navex,&navey);
	input(campo,&navex,&navey);
	input(campo,&navex,&navey);
	//update();
	}while(lose==0&&(time(NULL)-tiempoInicial)<tiempoLimite);
	if (lose==0) {
		resu=1;
	}
	sleep(1);
	system ("cls");
	return resu;
}
void draw(char campo[25][60]){
	system("cls");
	imprimir(campo);
}
void meteorito(char campo[25][60]){
	int num,a;
	num=2+rand()%(57-2);
	campo[2][num]='@';
	campo[2][num+1]='@';
	campo[2][num-1]='@';
	campo[1][num]='@';
	campo[3][num]='@';

return;
}
int bajar (char campo[25][60]){
	int i,j,V=25,H=60,w=0;
	for(i=23;i>1;i--){
		for(j=H-1;j>1;j--){
			if(campo[i][j]!='X'){
			if(campo[i-1][j]!='X'){
			campo[i][j]=campo[i-1][j];
			campo[i-1][j]=' ';
		}
		}else{
			if(campo[i-1][j]=='@'){
				w=1;
			}
		}
		}
	}
return w;
}
void input(char campo[25][60],int *navex, int *navey){
	//parte de verificar
	char key;
	if (kbhit()==1){
		key=getch();
		if(key=='a'||key=='A'){
			if((*navey-1)!=1){
				campo[*navex][*navey-1]='X';
				campo[*navex][*navey]=' ';
				campo[*navex+1][*navey-2]='X';
	            campo[*navex+1][*navey-1]='X';
	            campo[*navex+1][*navey]='X';
	            campo[*navex+1][*navey+1]=' ';
				*navey=*navey-1;	
			}
		}
		if(key=='d'||key=='D'){
			if((*navey+1)!=59){
				campo[*navex][*navey+1]='X';
				campo[*navex][*navey]=' ';
				campo[*navex+1][*navey+2]='X';
	            campo[*navex+1][*navey+1]='X';
	            campo[*navex+1][*navey]='X';
	            campo[*navex+1][*navey-1]=' ';
				*navey=*navey+1;	
			}
		}
			if(key=='s'||key=='S'){
			if((*navex+1)!=24){
				campo[*navex+2][*navey]='X';
				campo[*navex+1][*navey]='X';
				campo[*navex+2][*navey+1]='X';
				campo[*navex+2][*navey-1]='X';
	            campo[*navex][*navey]=' ';
	            campo[*navex+1][*navey-1]=' ';
	            campo[*navex+1][*navey+1]=' ';
				*navex=*navex+1;	
			}
		}
		    if(key=='W'||key=='w'){
			if((*navex-1)!=7){
				campo[*navex-1][*navey]='X';
				campo[*navex][*navey]='X';
				campo[*navex][*navey+1]='X';
				campo[*navex][*navey-1]='X';
	            campo[*navex+1][*navey]=' ';
	            campo[*navex+1][*navey-1]=' ';
	            campo[*navex+1][*navey+1]=' ';
				*navex=*navex-1;	
			}
		}
	}
return;	
}
//pong

//gameover
void gameOver (int puntos){
	puts("\n\n\t #####");
	puts("\t##       ######  ### ### #####    ##### #  # #####  ####");
	puts("\t## #### ##   ##  ## # ## #####    #   #  # # ##### ##");
	puts("\t##   ## ##   ##  ##   ## ##       #   #   ## ##    ##");
	puts("\t #####   ####### ##   ## #####    #####    # ##### ##");
	printf("\n\t\t\t   PUNTAJE:   %d\n\n\n\t",puntos);
	sleep("4");
	system("cls");
}
