#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void borde (char campo[25][60]);
int bajar (char campo[25][60]);
void nave(char campo[25][60],int navex, int navey);
void meteorito(char campo[25][60]);
void imprimir(char campo[25][60]);
void draw(char campo[25][60]);
void gameloop(char campo[25][60],int navex, int navey);
void input(char campo[25][60],int *navex, int *navey);
int main(){
	char campo[25][60];
	int navex=22,navey=30;
	borde(campo);
	nave(campo,navex,navey);
	imprimir(campo);
	gameloop(campo,navex,navey);
	return 0;
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
void gameloop(char campo[25][60],int navex, int navey){
	int lose=0, d=1;
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
	}while(lose==0);
	return;
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
			campo[i][j]=campo[i-1][j];
			campo[i-1][j]=' ';
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
			if((*navey-1)!=1){
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
