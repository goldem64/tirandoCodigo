#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int nredes;
int nbred;
char *ip;
char **redes;
char clase;

void convertirACerosDesdeHasta(int desde,int hasta,int r){
	int i;
	for(i = desde; i <= hasta; i++){
		redes[r][i] = '0';
	}
	
}
void inicializarMatrizRedes(char **matriz, int fila, int columna){
	int i;
	
	matriz = (char**)malloc(sizeof(char*)*fila);
	for(i = 0; i < fila; i++){
		matriz[i] = (char*)malloc(sizeof(char)*columna);
	
		strcpy(matriz[i],ip);
	}
	if (matriz == NULL){
		printf("Intento fallido de reserva de memoria");
	}
	
	redes = matriz;

}
void imprimirRedes(){
	int binicio;
	int i=0;
	int r=0;
	inicializarMatrizRedes(redes,nredes,35);
	switch(clase){
		case 'A':
			binicio = 8;
			break;
		case 'B':
			binicio = 17;
			break;
		case 'C':
			binicio = 26;
			break;
	}
		i = binicio + nbred;
		int primeravuelta = 1;
		int finalBloque = 0;
	for (r; r<nredes; r++){
		for(i; i>binicio; i--){
			redes[r][i] = '1';
			if (primeravuelta){
				r++;
				primeravuelta = 0;
				continue;
			}
			convertirACerosDesdeHasta(i+1,binicio+nbred,r);
			
			
			
		}
		i = binicio += nbred;
	}
}


int main(){
	nredes = 8;
	clase = 'C';
	nbred = ceil(log(nredes)/log(2));
	ip = (char*)malloc(sizeof(char)*35);
	if (ip == NULL){
		printf("Fallo la reserva de la memoria");
		return 0;
	}
	ip = "11000000.10101000.00000001.00000000";
	imprimirRedes();
	
	int k;
	for(k = 0; k < nredes; k++){
		
		printf("red[%d]: %s\n",k+1,redes[k]);
	}
	
}
