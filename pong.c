#include <stdio.h>
#include<windows.h>
#define Vertical 21
#define Horizontal 75

void inicio(char campo[Vertical][Horizontal], int pelX, int pelY, int inijug, int finjug, int iniia, int finia);
void bordePong (char campo[Vertical][Horizontal]);
void raqjug(char campo[Vertical][Horizontal], int inijug, int finjug);
void raqia(char campo[Vertical][Horizontal], int iniia, int finia);
void pel( char campo[Vertical][Horizontal], int pelX, int pelY );
void leercamp(char campo[Vertical][Horizontal]);
int gameloopPong(char campo[Vertical][Horizontal], int pelX, int pelY, int inijug, int finjug, int iniia, int finia, int modX, int modY, int modia);
void drawPong(char campo[Vertical][Horizontal]);
void inputPong(char campo[Vertical][Horizontal], int*pelX,int *pelY, int *inijug,int *finjug, int *iniia, int *finia, int *modX, int *modY, int *modia, int *gol);
void update(char campo[Vertical][Horizontal], int pelX, int pelY, int inijug, int finjug, int iniia, int finia);
int pong();

int main () {
	printf("%d", pong());
	system("pause");
	
}

int pong () {
	int pelX,pelY,inijug,finjug,iniia,finia;//posicion
	int modX, modY, modia;//modificacion
	char campo[Vertical][Horizontal];
	int final = 0;
	//posicion
	pelX = 37; 
	pelY=10;
	
	inijug = 8;
	finjug = 12;
	
	iniia = 5;
	finia = 18;
	
	//modificacion
	
	modX = -1;
	modY = -1;
	
	modia = -1;
	
	inicio (campo,pelX,pelY,inijug,finjug,iniia,finia);
	final = gameloopPong (campo, pelX,pelY,inijug,finjug,iniia,finia,modX,modY,modia);
	system("cls");
	if (final==1){
		return 0;
	}
	if (final==2){
		return 1;
	}
}

void inicio(char campo[Vertical][Horizontal], int pelX, int pelY, int inijug, int finjug, int iniia, int finia){
	bordePong(campo);
	raqjug(campo, inijug, finjug);
	raqia(campo, iniia, finia); 
	pel(campo, pelX, pelY);
}

void bordePong (char campo[Vertical][Horizontal]){
	int i,j;
	for(i = 0; i < Vertical; i++){
		for(j = 0; j < Horizontal; j++){
			if(i == 0 || i==Vertical-1){
				campo[i][j] = '-';
			}
			else if (j == 0 || j == Horizontal-1){
				campo[i][j] = '|';
			}
			else{
				campo[i][j] = ' ';
			}
		}
	}
}

void raqjug(char campo[Vertical][Horizontal], int inijug, int finjug){
	int i, j;
	for(i = inijug; i <= finjug; i++){
		for(j = 2; j <= 3; j++){
			campo[i][j] = 'X';
		}
	}
}
void raqia(char campo[Vertical][Horizontal], int iniia, int finia){
	int i,j;
	for(i = iniia; i < finia; i++){
		for(j = Horizontal-4; j <= Horizontal - 3; j++){
			campo[i][j] = 'X';	
		}
	}
}
void pel ( char campo[Vertical][Horizontal], int pelX, int pelY ){
	campo[pelY][pelX] = 'O';
}
void leercamp(char  campo[Vertical][Horizontal]){
int i,j;
for(i = 0;i<Vertical;i++){
	for(j= 0; j<Horizontal;j++){
		printf ("%c", campo[i][j]);
	}
	printf("\n");
	}
}

int gameloopPong(char campo[Vertical][Horizontal], int pelX, int pelY, int inijug, int finjug, int iniia, int finia, int modX, int modY, int modia){
	int gol;
	gol = 0;
	int res = 0;
	do{
		drawPong (campo);//dibujar en pantalla
		inputPong (campo,&pelX,&pelY,&inijug,&finjug,&iniia,&finia,&modX,&modY,&modia, &gol);//verificar y modificar posiciones
		update (campo,pelX,pelY,inijug,finjug,iniia,finia);	//actualizar matriz de campo
	
	}while (gol == 0);
	
	if(pelX==1){
			res = 1;
		}
		else{
			res = 2;
		}
	return res;
	
}		
void drawPong(char campo[Vertical][Horizontal]){
	system("cls");
	leercamp(campo);
}

void inputPong(char campo[Vertical][Horizontal], int*pelX,int *pelY, int *inijug,int *finjug, int *iniia, int *finia, int *modX, int *modY, int *modia, int *gol){
	int i;
	char key;
	//verificacion
	if (*pelY == 1|| *pelY== Vertical-2){
		*modY *=-1;
	}
	
	if (*pelX == 1|| *pelX == Horizontal - 2){
		*gol = 1;
	}
	
	if (*pelX == 4){
		for(i== (*inijug); i <= (*finjug); i++){
			if(i==(*pelY)){
				*modX *= -1;
			}
		}
	}
	
	if (*pelX == Horizontal - 5){
		for( i = (*iniia); i <= (*finia); i++){
		 *modX *=-1;
		}
	}
	
	if(*iniia=1 || *finia ==Vertical-1){
		*modia *=-1;
	}
	
	//Modificacion
	
	if (*gol == 0){
	
		//Pelota:
		*pelX += (*modX);
		*pelY += (*modY);
	
		//Raqueta ia:
	
		*iniia += (*modia);
		*finia += (*modia);
		
		//Raqueta jug:
		if(kbhit() == 1){
			key = getch();
			
			if(key == 'w'){
				if(*inijug != 1){
					*inijug -= 1;
					*finjug -=1;
				}
			}
			
			if(key == 's'){
				if(*finjug != Vertical-2){
					*inijug +=1;
					*finjug += 1;
				}
			}
		}
	}
}

void update(char campo[Vertical][Horizontal], int pelX, int pelY, int inijug, int finjug, int iniia, int finia){
	bordePong(campo);
	raqjug(campo, inijug, finjug);
	raqia(campo, iniia, finia); 
	pel(campo, pelX, pelY);
}
