#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define true 1
#define false !(true)
char **redes;
char **primerHost;
char **ultimoHost;
char **broadcast;
char clase;
char ip[35];
int nredes;
int bits;

void inicializarMatriz(){
	int nb,i=0;
	if (clase == 'A'){
		nb = 8;
	}else if(clase == 'B'){
		nb = 17;
	}else{
		nb = 18;
	}
	redes = (char**)malloc(sizeof(char*)*nredes);
	for (i; i<nredes; i++){
		redes[i] = (char*)malloc(sizeof(char)*35);
		strcpy(redes[i],"00000000.00000000.00000000.00000000");
		strncpy(redes[i],ip,nb);
	}
}

void imprimirRedes(){
	int i = 0;
	for (i; i < nredes; i++){
		printf("\n[%d]  %s[ %s - %s]: %s",i,redes[i],primerHost[i],ultimoHost[i],broadcast[i]);
	}
}
void crearHost(int bitInicio){
	int i;int j;
	primerHost = (char**)malloc(sizeof(char*)*nredes);
	ultimoHost = (char**)malloc(sizeof(char*)*nredes);
	broadcast = (char**)malloc(sizeof(char*)*nredes);
	for(i = 0; i<nredes; i++){
		primerHost[i] = (char*)malloc(sizeof(char)*35);
		ultimoHost[i] = (char*)malloc(sizeof(char)*35);
		broadcast[i] = (char*)malloc(sizeof(char)*35);
		strcpy(primerHost[i],redes[i]);
		primerHost[i][34] = '1';
		strcpy(ultimoHost[i],redes[i]);
		for(j = (bitInicio+1); j < 34; j++){
			
			ultimoHost[i][j] = '1';
		}
		strcpy(broadcast[i],ultimoHost[i]);
		broadcast[i][34] = '1';
	}
}
void crearRedes(){
	int i = 0, j = 0, k = 0;
	int bitInicio;
	int cambio = 0;
	int elemento = false;
	int tope;
	int bitRecorrido = 0;
	if (clase == 'A'){
		bitInicio = 8 + bits;
		if (bits > 8 && bits < 17){
			bitInicio += 1;
		}else if(bits > 16){
			bitInicio += 2;
		}else;
		tope = 8;
	}else if(clase == 'B'){
		bitInicio = 17 + bits;
		if (bits > 8){
			bitInicio += 1;
		}
		tope = 17;
		
	}else{
		bitInicio =26 + bits;
		tope = 26;
	
	}
	for(j = bitInicio; j > tope; j--){ //recorrido de las redes
		if ( j == 8 || j == 17 || j == 26){
			continue;
		}
		for (i = 0; i < nredes; i++){ //recorrido posiciones
			if(cambio == pow(2,bitRecorrido)){
				if (elemento == true){
					cambio = 0;
					elemento = false;
				}else{
					elemento = true;
					cambio = 0;
				}
			}
			if (elemento == true){
				redes[i][j] = '1';
			}else{
				redes[i][j] = '0';
			}
			cambio++;
			
		}
		bitRecorrido++;
		cambio = 0;
		elemento = false;
	}
	
	crearHost(bitInicio);
}




int main(){
	int i = 0;
	clase = 'C';
	nredes = 5;
	bits = 3;
	strcpy(ip,"10111111.00001010.00000000.00000000");
	inicializarMatriz();
	//imprimirRedes();
	printf("\n..........................");
	crearRedes();

	imprimirRedes();
	
	
	
	
	return 0;
}
