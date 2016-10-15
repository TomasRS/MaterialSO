#include<stdio.h>
#include<ncurses.h>

//Variables globales
int max[100][100];
int alloc[100][100];
int need[100][100];
int avail[100];
int n,r;

//Encabezados de funciones
void input();
void cal();


int main(){
	printf("********** Algoritmo de deteccion de Deadlock ************\n");
	input();
	cal();
	getch();
	return 0;
}

void input(){
	int i,j;
	printf("Ingresar la Cantidad de Procesos (filas)\t");
	scanf("%d",&n);
	printf("Ingresar la Cantidad de Recursos (columnas)\t");
	scanf("%d",&r);
	printf("Ingresar la Matriz de Maximos\n");
	for(i=0;i<n;i++){
		for(j=0;j<r;j++){
			scanf("%d",&max[i][j]);
		}
	}
	printf("Ingresar la Matriz de Asignacion\n");
	for(i=0;i<n;i++){
		for(j=0;j<r;j++){
			scanf("%d",&alloc[i][j]);
		}
	}
	printf("Ingresar Vector de Recursos Disponibles\n");
	for(j=0;j<r;j++){
		scanf("%d",&avail[j]);
	}
}

void cal(){
	int finish[100],temp,need[100][100],flag=1,k,c1=0;
	int dead[100];
	int safe[100];
	int i,j;
	for(i=0;i<n;i++){
		finish[i]=0;
	}
	//find need matrix
	for(i=0;i<n;i++){
		for(j=0;j<r;j++){
			need[i][j]=max[i][j]-alloc[i][j];
		}
	}
	while(flag){
		flag=0;
		for(i=0;i<n;i++){
			int c=0;
			for(j=0;j<r;j++){
				if((finish[i]==0)&&(need[i][j]<=avail[j])){
					c++;
					if(c==r){
						for(k=0;k<r;k++){
							avail[k]+=alloc[i][j];
							finish[i]=1;
							flag=1;
						}
						//printf("\nP%d",i);
						if(finish[i]==1){
							i=n;
						}
					}
				}
			}
		}
	}
	j=0;
	flag=0;
	for(i=0;i<n;i++){
		if(finish[i]==0){
			dead[j]=i;
			j++;
			flag=1;
		}
	}
	if(flag==1){
		printf("\n\nEl sistema esta en Deadlock y los procesos en Deadlock son:\n");
		for(i=0;i<n;i++){
			printf("P%d\t",dead[i]);
		}
		printf("\n");
		printf("------------------------------------------------------------------");
		printf("\n");
	}
	else{
		printf("\nNo ocurrio Deadlock\n");
	}
}
