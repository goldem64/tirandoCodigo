#include <stdio.h>
#include <string.h>
#include <math.h>
int ip[4];
int mascara[4];
char mascaraAdaptada[35];
int bitsRed;
char clase;
void convertirMAADecimal(){
	int i;
	int b = 0;
	int numero = 0;
	int potencia = 0;
	int octeto = 0;
	for (i = 34; i >=0 ; i--){
		b++;
		if (b == 9){
			b = 0;
			mascara[3-octeto] = numero;
			numero = 0;
			octeto++;
			potencia  = 0;
			continue;
		}
		
		if (mascaraAdaptada[i] == '1'){
			numero += pow(2,potencia);
			
		}
		
		if (i == 0){
			b = 0;
			mascara[3-octeto] = numero;
			numero = 0;
			octeto++;
			potencia  = 0;
			
		}
		potencia++;
		
		
		
		
	}
}
int main(){
	
	bitsRed = 3;
	clase = 'C';
	int i;
	 
	 
	
	if(clase == 'A'){
		i = 9;
		strcpy(mascaraAdaptada,"11111111.00000000.00000000.00000000");
		
		
	}else if(clase == 'B'){
		i = 17;
		strcpy(mascaraAdaptada,"11111111.11111111.00000000.00000000");
	}else{
		i = 26;
		strcpy(mascaraAdaptada,"11111111.11111111.11111111.00000000");
	}
	printf("mascara %s",mascaraAdaptada);
	int temp = bitsRed;
	int inicio = i;
	for (i; i<(inicio+bitsRed); i++){
		if (i == 17 || i == 26){
			bitsRed++;
			continue;
					
		}
		mascaraAdaptada[i] = '1';
	}
	bitsRed = temp;
	
	printf("\nmascaraAdapada %s",mascaraAdaptada);
	
	convertirMAADecimal();
	printf("\nMascaraAdaptada %d.%d.%d.%d",mascara[0],mascara[1],mascara[2],mascara[3]);

}
