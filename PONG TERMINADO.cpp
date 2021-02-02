#include<stdio.h>
#include<stdlib.h>
#include <windows.h>
#include<conio.h>
#define V 21
#define H 120

void inicio(int pelX, int pelY,char campo[V][H],int inijug, int finjug,int iniia,int finia);
void borde(char campo[V][H]);
void raqueta(char campo[V][H], int inijug, int finjug);
void raqueta2(char campo[V][H], int iniia, int finia);
void pelota(char campo[V][H], int pelX, int pelY);
void lectura(char campo[V][H]);
void gameloop(int pelX, int pelY,char campo[V][H],int inijug, int finjug,int iniia,int finia,int modX,int modY, int modIA);
void draw(char campo[V][H]);
void input(int *pelX, int *pelY, char campo[V][H], int *inijug, int *finjug, int *iniia, int *finia, int *modX, int *modY, int *gol, int *modIA);
void update(int pelX, int pelY,char campo[V][H],int inijug, int finjug,int iniia,int finia);

int main(void){

char campo[V][H];

int pelX=60;
int pelY=10;

int inijug=8;
int finjug=12;

int iniia=8;
int finia=12;


int modX,modY,modIA;
modX=-1;
modY=-1;
modIA=-1;

inicio(pelX,pelY,campo,inijug,finjug,iniia,finia);
gameloop(pelX,pelY,campo,inijug,finjug,iniia,finia,modX,modY,modIA);

return 0;	
}

void inicio(int pelX, int pelY,char campo[V][H],int inijug, int finjug,int iniia,int finia){
	borde(campo);
	raqueta(campo,inijug,finjug);
	raqueta2(campo,iniia,finia);
	pelota(campo,pelX,pelY);
}

void borde(char campo[V][H]){
	int i;
	int j;
	
	for(i=0;i<V;i++){
		for(j=0;j<H;j++){
			if(i == 0 || i == V-1){
				campo[i][j] = '-';
			}
			else if (j == 0 || j == H-1){
				campo[i][j] = '|';
			}
			else{
				campo[i][j] = ' ';
			}
		}
	}
}

void raqueta(char campo[V][H], int inijug, int finjug){
	int i;
	int j;
	
	for(i=inijug;i<=finjug;i++){
		for(j=2;j<=3;j++){
			campo[i][j]='X';
			
		}
	}	
}

void raqueta2(char campo[V][H], int iniia, int finia){
	int i,j;
	
	for(i=iniia;i<=finia;i++){
		for(j=H-4;j<=H-3;j++){
			campo[i][j]='X';
		}
	}
}

void pelota(char campo[V][H], int pelX, int pelY){
	campo[pelY][pelX]='O';	
}
	
void lectura(char campo[V][H]){
	int i,j;
	
	for(i=0;i<V;i++){
		for(j=0;j<H;j++){
			printf("%C",campo[i][j]);
		}
	}
	printf("\n");
}
	
void gameloop(int pelX, int pelY,char campo[V][H],int inijug, int finjug,int iniia,int finia,int modX,int modY, int modIA){
	int gol;
	gol=0;
	
	do{
		draw(campo);
		input(&pelX, &pelY,campo,&inijug,&finjug,&iniia,&finia,&modX,&modY,&gol,&modIA);
		update(pelX, pelY,campo,inijug,finjug,iniia,finia);
		Sleep(10);
		
	}while(gol==0);
}

void draw(char campo[V][H]){
	system("cls");
	lectura(campo);
}

void input(int *pelX, int *pelY, char campo[V][H], int *inijug, int *finjug, int *iniia, int *finia, int *modX, int *modY, int *gol,int *modIA){
	int i;
	char key;

	if(*pelY==1 || *pelY==V-2){
	    *modY *= -1;
    }
	
	if(*pelX==1|| *pelX==H-2){
		*gol=1; 
	} 
	
	if(*pelX == 4){
		for (i = (*inijug); i < (*finjug); i++){
			if (i == (*pelY)){
				*modX *= -1;
			}
		}
	}
	
	if(*pelX == H-5){
		for (i = (*iniia); i<(*finia);i++){
			if (i == (*pelY)){
				*modX *= -1;
			}
		}
	}
	
	if(*iniia == 1 || *finia == V-1){
		*modIA *= -1;	
	}
	
	if (*gol == 0){
	*pelX += *modX;
	*pelY += *modY;
	

    *iniia += *modIA;
    *finia += *modIA;
    }
	
	if(kbhit() == 1){
	key = getch();
	
	if(key == 'w'){
		if(*inijug != 1){
			*inijug -= 1;
			*finjug -= 1;
		}
	}
	if (key == 's'){
		if(*finjug != V-2){
			*inijug += 1;
			*finjug +=1;
		}
	}	
	}	
}

void update(int pelX, int pelY,char campo[V][H],int inijug, int finjug,int iniia,int finia){
	borde(campo);
	raqueta(campo,inijug,finjug);
	raqueta2(campo,iniia,finia);
	pelota(campo,pelX,pelY);
}

