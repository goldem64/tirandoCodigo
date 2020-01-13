#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define true 1
#define false !(true)
char **redes;
int **ipredes;

char **primerHost;
int **ipPrimerHost;
int **ipUltimoHost;
int **ipBroadcast;
char **ultimoHost;
char **broadcast;
char clase;
char ip[35];
int nredes;
int bits;

void imprimirMatriz(int **matriz,int filas, int columnas){
	int i = 0;int j = 0;
	for(i; i<filas; i++){
		printf("red");
		for(j; j<columnas; j++){
			printf("%d.",matriz[i][j]);
			printf("asasas");
		}
		printf("\n");
		
	}
}


int** convertirMADecimal(char **matriz){
	
	int **conversion;

	conversion = (int**)malloc(sizeof(int*)*nredes);

	int i = 0; int j = 0; int r;
	int valor = 0;
	int potencia = 0;
	int posicion = 3;

	for (i = 0; i<nredes; i++){
		conversion[i] = (int*)malloc(sizeof(int)*4);
		for(j = 34; j > 0; j--){
			for(r = 0; r < 8; r++){
				//printf("valor: %c",matriz[i][j]);
				if(matriz[i][j] == '1'){
				valor += pow(2,potencia);
			
			}
			//printf("\nj = %d",j);
			j--;
			potencia++;
			
			}
			//printf("\nfor de 8 termina");
			
			conversion[i][posicion] = valor;
			potencia = 0;
			posicion--;
			valor = 0;
			
		}
		//printf("\nfor de j termina");
		
		posicion = 3;
		
	}
	

	for(i = 0; i< nredes; i++){
		for(j = 0; j<4; j++){
			printf("%d ",conversion[i][j]);
		}
		printf("\n");
	}
	
	return conversion;
	
}

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
	//ip2 = (int**)malloc(sizeof(int*)*nredes);
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
//	for (i = 0; i<nredes; i++){
//		ip2[i] = (int*)malloc(sizeof(int)*4);
//	}
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
	//printf("\naaaaaaprimerared : %s",redes[0]);
	
	
	
}




int main(){
	int **temp;
	int i = 0;
	temp = (int**)malloc(sizeof(int*)*nredes);
	
		for(i = 0; i<nredes; i++){
		temp[i] = malloc(sizeof(int)*4);
	}
	
	
	clase = 'C';
	nredes = 5;
	bits = 3;
	strcpy(ip,"10111111.00001010.00000000.00000000");
	inicializarMatriz();
	//imprimirRedes();
	printf("\n..........................\n");
	crearRedes();
	//printf("\nprimeraaaaaaaaaaaaaaaaaaaaared : %s",redes[0]);

//	printf("\nprimera red: %s",redes[0]);
	temp = convertirMADecimal(redes);
	printf("\n");
	temp = convertirMADecimal(primerHost);
	printf("\n");
	temp = convertirMADecimal(ultimoHost);
	printf("\n");
	temp = convertirMADecimal(broadcast);
	


	
	

	imprimirRedes();
	
	
	
	
	
	
	
	return 0;
}