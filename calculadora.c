#include<iostream>
#include<math.h>
#include <string> 
#include <stdio.h>
#include <sstream>
#include <cmath>
#define NUM_BITS 8
#define BITS 8
using namespace std;

void menu_class_ip();
int validate_class(int class_ip, int octeto);
void binary(int num, char result_convert[]);
int binaryAND(char numero_1[], char numero_2[], char result[]);
int binaryOR(char num_1[], char num_2[], char result_final[]);
void bintodecimal(int num);
void invertBinary(char character[], char resultado[]);
void printAuthors();
void print_class_c(int octeto1, int octeto2, int octeto3, int octeto4);

int main (int argc, char *argv[]) {
	int option_address, octeto1, octeto2, octeto3, octeto4, is_valid;
	printf("Digite el primer octeto de la IP Adress: \n");
	scanf("%d", &octeto1);
	do {
		menu_class_ip();
		scanf("%d", &option_address);
		is_valid = validate_class(option_address, octeto1);
		if (is_valid != 0) {
			printf("Digite el segundo octeto de la IP Address: \n");
			scanf("%d", &octeto2);
			printf("Digite el tercer octeto de la IP Address: \n");
			scanf("%d", &octeto3);
			printf("Digite el cuarto octeto de la IP Address: \n");
			scanf("%d", &octeto4);
			if (is_valid == 3) {
				print_class_c(octeto1, octeto2, octeto3, octeto4);
				return EXIT_SUCCESS;
			}
		}
	} while(option_address != 4);
	return 0;
}

void menu_class_ip() {
	cout << "\n Selecciona la clase la cual pertenece la IP Address Digitada: \n"
		<< "1 Clase A \n"
		<< "2 Clase B \n"
		<< "3 Clase C \n"
		<< "4 Salir \n";
}

int validate_class(int class_ip, int octeto) {
	// printf("ip del octeto  %d y clase digitada %d", class_ip, octeto);
	if ((octeto >= 0 && octeto <= 127) && class_ip == 1) {
		return 1;
	} else if ((octeto >= 128 && octeto <= 191) && class_ip == 2) {
		return 2;
	} else if ((octeto >= 192 && octeto <= 223) && class_ip == 3) {
		return 3;
	}
	return 0;
}
int binaryAND(char numero_1[], char numero_2[], char result[]){
	int i, j,  bit_1, bit_2, t = 0, m;
	for (i = NUM_BITS; i > 0; i--){
		bit_1 = numero_1[i - 1] - '0';
		bit_2 = numero_2[i - 1] - '0';
		result[i] = bit_1 & bit_2;
	}
	int respuesta = 0, increment;
	for (j = 8; j > 0; j--) {
		int base = 2,  sol=1;
		for (m=0;m<t;m++)
		{
			sol=sol*base;
			
		}
		
		increment = (result[j] * sol);
		respuesta = increment + respuesta;
		t++;
	}
	return respuesta;
}


void binary(int num, char result_convert[]){
	int D,D1,D2,D3,D4,D5,D6,D7,R1,R2,R3,R4,R5,R6,R7,R8;
	D = num;
	D1= D/2;R1=D%2;
	D2=D1/2;R2=D1%2;
	D3=D2/2;R3=D2%2;
	D4=D3/2;R4=D3%2;
	D5=D4/2;R5=D4%2;
	D6=D5/2;R6=D5%2;
	D7=D6/2;R7=D6%2;
	R8=D7%2;
	sprintf(result_convert, "%d%d%d%d%d%d%d%d", R8, R7, R6, R5, R4, R3, R2, R1);
}

void invertBinary(char character[], char resultado[]){
	int j, bit;
	for (j = NUM_BITS; j > 0; j--){
		bit = character[j - 1] - '0';
		if (bit == 0) {
			resultado[j] = 1;
		} else {
			resultado[j] = 0;
		}
	}
}
int binaryOR(char num_1[], char num_2[], char result_final[]){
	int i, j,  bit_1, bit_2, t = 0, m;
	for (i = NUM_BITS; i > 0; i--){
		bit_1 = num_1[i - 1] - '0';
		bit_2 = num_2[i];
		result_final[i] = bit_1 | bit_2;
	}
	int respuesta = 0, increment;
	for (j = 8; j > 0; j--) {
		int base = 2,  sol=1;
		for (m=0;m<t;m++)
		{
			sol=sol*base;
			
		}
		
		increment = (result_final[j] * sol);
		respuesta = increment + respuesta;
		t++;
	}
	return respuesta;
}
void printAuthors(){
	cout << "------------------------------------------ \n" << endl;
	cout << "\t \t Autores" << endl;
	cout << "------------------------------------------ \n" << endl;
	cout << "\t Angela Lorena Pantoja" << endl;
	cout << "\t Alver Alexader Grisales" << endl;
	cout << "------------------------------------------ \n" << endl;
}
void print_class_c(int octeto1, int octeto2, int octeto3, int octeto4){
	int mascara;
	char result_ip[NUM_BITS+1];
	char result_mascara[NUM_BITS+1];
	char result[NUM_BITS];
	char binaryinvert[NUM_BITS + 1];
	char resultinvert[NUM_BITS];
	string numfinal;
	printf("Digite la mascara de subred 255.255.255.");
	scanf("%d", &mascara);
	binary(octeto4, result_ip);
	binary(mascara, result_mascara);
	invertBinary(result_mascara, binaryinvert);
	int subred;
	int broadcast;
	subred = binaryAND(result_ip, result_mascara, result);
	broadcast = binaryOR(result_ip, binaryinvert, resultinvert);
	cout << "------------------------------------------" << endl;
	cout << " \t  \t  Resultado" << endl;
	cout << "------------------------------------------" << endl;
	cout << "\t Address: " << octeto1 << "." << octeto2 << "." << octeto3 << "." << octeto4 << endl;
	cout << "\t Netmask: 255.255.255." << mascara << endl;
	cout << "\t Network: " << octeto1 << "." << octeto2 << "." << octeto3 << "." << subred << endl;
	cout << "\t Host min: " << octeto1 << "." << octeto2 << "." << octeto3 << "." << (subred + 1)<< endl;
	cout << "\t Host max: " << octeto1 << "." << octeto2 << "." << octeto3 << "." << (broadcast - 1 )<< endl;
	cout << "\t Brodcast: " << octeto1 << "." << octeto2 << "." << octeto3 << "." << broadcast << endl;
	cout << "------------------------------------------ \n" << endl;
	printAuthors();
}
