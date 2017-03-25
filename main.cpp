#include <iostream>
#include <math.h>
#include <string> 
#include <stdio.h>
#include <sstream>
#include <cmath>
#define NUM_BITS 8
#define BITS 8

using namespace std;

void instrucciones();
void print_number(int num);
void addressing_ip();
	string convierteBin(int);
string binary(int num);

int main() {
	int numero1;
	int numero2;
	int opcion;
	int result;
	string binario = "";
	string binario1 = "";
	string binario2 = "";
	double Suma (double , double );
	double Resta (double , double );
	double Multiplicacion (double , double );
	double Division (double , double );
	do {
		instrucciones();
		scanf("%d", &opcion);
		switch(opcion) {
		case 1:
			result = Suma(numero1, numero2);
			break; /* optional */
			
		case 2:
			result = Resta(numero1, numero2);
			break; /* optional */
		case 3:
			result = Multiplicacion(numero1, numero2);
			break; /* optional */
			
		case 4:
			if (numero2 != 0)/* Si el divisor es distinto de 0 realizara la operacion */
			{
				result = Division(numero1, numero2);
			} else {
				printf("\n No se puede realizar esa division porque el divisor es 0!!");  /* Si el divisor es igual a 0 muestra este mensaje de error */
			}
			break; /* optional */
		case 5:
			addressing_ip();
			break;
		case 6:
			return EXIT_SUCCESS;
			break; /* optional */
			
			/* you can have any number of case statements */
			default : /* Optional */
				printf("No escojio ninguna opcion");
		}
		binario = binary(result);
		printf("El resultado de la operacion en decimal es: \n %i \n", result);
		cout << "El resultado de la operacion en binario es: \n" << binario;
	} while(opcion != 6);
}

string binary(int num) {
	int numero = num;
	string binario = "";
	if (numero > 0) {
		while (numero > 0) {
			if (numero%2 == 0) {
				binario = "0"+binario;
			} else {
				binario = "1"+binario;
			}
			numero = (int) numero/2;
		}
	} else if (numero == 0) {
		binario = "0";
	} else {
		binario = "No se puede realizar la conversion. Ingrese solo numeros positivos";
	}
	return binario;
}

void instrucciones() {
	cout << "\n Escriba una de las siguentes opciones:\n"
		<< " 1 Sumar\n"
		<< " 2 Restar\n"
		<< " 3 Multiplicar\n"
		<< " 4 Dividir\n"
		<< " 5 Direccionamiento IP\n"
		<< " 6 para terminar \n";
}

double Suma (double a, double b) {
	double c;
	printf("****** Suma de 2 numeros ****** \n");
	printf("\n Introduce el numero 1: \n");
	scanf ("%lf", &a);
	print_number(a);
	printf("\n Introduce el numero 2: \n");
	scanf ("%lf", &b);
	print_number(b);
	c = a + b;
	return (c); //así asignamos a la variable Suma, el valor de c=a+b
}

double Resta (double a, double b) {
	double c;
	printf("****** Resta de 2 numeros ****** \n");
	printf("\n Introduce el numero 1: \n");
	scanf ("%lf", &a);
	print_number(a);
	printf("\n Introduce el numero 2: \n");
	scanf ("%lf", &b);
	print_number(b);
	c = a - b;
	return (c); //así asignamos a la variable Suma, el valor de c=a+b
}

double Multiplicacion (double a, double b) {
	double c;
	printf("****** Multiplicacion de 2 numeros ****** \n");
	printf("\n Introduce el numero 1: \n");
	scanf ("%lf", &a);
	print_number(a);
	printf("\n Introduce el numero 2: \n");
	scanf ("%lf", &b);
	print_number(b);
	c = a * b;
	return (c); //así asignamos a la variable Suma, el valor de c=a+b
}

double Division (double a, double b) {
	double c;
	printf("****** Division de 2 numeros ****** \n");
	printf("\n Introduce el numero 1: \n");
	scanf ("%lf", &a);
	print_number(a);
	printf("\n Introduce el numero 2: \n");
	scanf ("%lf", &b);
	print_number(b);
	c = a / b;
	return (c); //así asignamos a la variable Suma, el valor de c=a+b
}

void print_number(int num){
	string binario = "";
	binario = binary(num);
	cout << "El numero introducido en binario es: \n" << binario << "\n";
}

string convierteBin(int num) { 
	int digits[30], ultimo = 0, div; 
	string cadena = ""; 
	div = num; 
	
	do { 
		digits[ultimo++] = div % 2; 
		div /= 2; 
	} while (div > 0); 
	
	if (ultimo > 0) { 
		while (ultimo > 0) { 
			char digit = digits[--ultimo] + '0'; 
			cadena.push_back(digit); 
		} 
		
		return cadena; 
	} else { 
		return "0"; 
	} 
}

void addressing_ip() {
	
	int validate_class(int class_ip, int octeto);
	int binaryAND(char numero_1[], char numero_2[]);
	int binaryOR(char num_1[], char num_2[]);
	void binary(int num, char result_convert[]);
	void menu_class_ip();
	void bintodecimal(int num);
	void invertBinary(char character[], char resultado[]);
	void printAuthors();
	void print_class_c(int octeto1, int octeto2, int octeto3, int octeto4);
	void print_class_b(int octeto1, int octeto2, int octeto3, int octeto4);
	void print_class_a(int octeto1, int octeto2, int octeto3, int octeto4);
	
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
				exit(0);
			} else if(is_valid == 2){
				print_class_b(octeto1, octeto2, octeto3, octeto4);
				exit(0);
			} else if (is_valid == 1) {
				print_class_a(octeto1, octeto2, octeto3, octeto4);
				exit(0);
			}
		}
	} while(option_address != 4);
	exit(0)  ;
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
int binaryAND(char numero_1[], char numero_2[]){
	int i, j,  bit_1, bit_2, t = 0, m;
	char result[NUM_BITS];
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
int binaryOR(char num_1[], char num_2[]){
	int i, j,  bit_1, bit_2, t = 0, m;
	char result_final[NUM_BITS];
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
	char binaryinvert[NUM_BITS + 1];
	printf("Digite la mascara de subred 255.255.255.");
	scanf("%d", &mascara);
	binary(octeto4, result_ip);
	binary(mascara, result_mascara);
	invertBinary(result_mascara, binaryinvert);
	int subred;
	int broadcast;
	subred = binaryAND(result_ip, result_mascara);
	broadcast = binaryOR(result_ip, binaryinvert);
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

void print_class_b(int octeto_1, int octeto_2, int octeto_3, int octeto_4) {
	int netmask_1, netmask_2, network_1, network_2, broadcast_1, broadcast_2;
	char binary_octeto_1[NUM_BITS], binary_octeto_2[NUM_BITS], binary_netmask_1[NUM_BITS], binary_netmask_2[NUM_BITS], binary_invert_netmask_1[NUM_BITS],
		binary_invert_netmask_2[NUM_BITS];
	printf("Digite el tercer octeto de la mascara de subred 255.255.");
	scanf("%d", &netmask_1);
	printf("Digite el cuarto octeto de la mascara de subred 255.255.%d.", netmask_1);
	scanf("%d", &netmask_2);
	binary(octeto_3, binary_octeto_1);
	binary(octeto_4, binary_octeto_2);
	binary(netmask_1, binary_netmask_1);
	binary(netmask_2, binary_netmask_2);
	invertBinary(binary_netmask_1, binary_invert_netmask_1);
	invertBinary(binary_netmask_2, binary_invert_netmask_2);
	network_1 = binaryAND(binary_octeto_1, binary_netmask_1);
	network_2 = binaryAND(binary_octeto_2, binary_netmask_2);
	broadcast_1 = binaryOR(binary_octeto_1, binary_invert_netmask_1);
	broadcast_2 = binaryOR(binary_octeto_2, binary_invert_netmask_2);
	
	cout << "------------------------------------------" << endl;
	cout << " \t  \t  Resultado" << endl;
	cout << "------------------------------------------" << endl;
	cout << "\t Address: " << octeto_1 << "." << octeto_2 << "." << octeto_3 << "." << octeto_4 << endl;
	cout << "\t Netmask: 255.255." << netmask_1 << "." << netmask_2 << endl;
	cout << "\t Network: " << octeto_1 << "." << octeto_2 << "." << network_1 << "." << network_2 << endl;
	cout << "\t Host min: " << octeto_1 << "." << octeto_2 << "." << network_1 << "." << (network_2 + 1)<< endl;
	cout << "\t Host max: " << octeto_1 << "." << octeto_2 << "." << broadcast_1 << "." << (broadcast_2 - 1 ) << endl;
	cout << "\t Brodcast: " << octeto_1 << "." << octeto_2 << "." << broadcast_1 << "." << broadcast_2 << endl;
	cout << "------------------------------------------ \n" << endl;
	printAuthors();
}

void print_class_a(int octeto_1, int octeto_2, int octeto_3, int octeto_4) {
	int netmask_1, netmask_2, netmask_3, network_1, network_2, network_3, broadcast_1, broadcast_2, broadcast_3;
	char binary_octeto_1[NUM_BITS], binary_octeto_2[NUM_BITS], binary_octeto_3[NUM_BITS], binary_netmask_1[NUM_BITS], binary_netmask_2[NUM_BITS],
		binary_netmask_3[NUM_BITS], binary_invert_netmask_1[NUM_BITS], binary_invert_netmask_2[NUM_BITS], binary_invert_netmask_3[NUM_BITS];
	printf("Digite el segundo octeto de la mascara de subred 255.");
	scanf("%d", &netmask_1);
	printf("Digite el tercer octeto de la mascara de subred 255.%d.", netmask_1);
	scanf("%d", &netmask_2);
	printf("Digite el cuarto octeto de la mascara de subred 255.%d.%d.", netmask_1, netmask_2);
	scanf("%d", &netmask_3);
	binary(octeto_2, binary_octeto_1);
	binary(octeto_3, binary_octeto_2);
	binary(octeto_4, binary_octeto_3);
	binary(netmask_1, binary_netmask_1);
	binary(netmask_2, binary_netmask_2);
	binary(netmask_3, binary_netmask_3);
	invertBinary(binary_netmask_1, binary_invert_netmask_1);
	invertBinary(binary_netmask_2, binary_invert_netmask_2);
	invertBinary(binary_netmask_3, binary_invert_netmask_3);
	network_1 = binaryAND(binary_octeto_1, binary_netmask_1);
	network_2 = binaryAND(binary_octeto_2, binary_netmask_2);
	network_3 = binaryAND(binary_octeto_3, binary_netmask_3);
	broadcast_1 = binaryOR(binary_octeto_1, binary_invert_netmask_1);
	broadcast_2 = binaryOR(binary_octeto_2, binary_invert_netmask_2);
	broadcast_3 = binaryOR(binary_octeto_3, binary_invert_netmask_3);
	
	cout << "------------------------------------------" << endl;
	cout << " \t  \t  Resultado" << endl;
	cout << "------------------------------------------" << endl;
	cout << "\t Address: " << octeto_1 << "." << octeto_2 << "." << octeto_3 << "." << octeto_4 << endl;
	cout << "\t Netmask: 255." << netmask_1 << "." << netmask_2 << "." << netmask_3 << endl;
	cout << "\t Network: " << octeto_1 << "." << network_1 << "." << network_2 << "." << network_3 << endl;
	cout << "\t Host min: " << octeto_1 << "." << network_1 << "." << network_2 << "." << (network_3 + 1)<< endl;
	cout << "\t Host max: " << octeto_1 << "." << broadcast_1 << "." << broadcast_2 << "." << (broadcast_3 - 1 ) << endl;
	cout << "\t Brodcast: " << octeto_1 << "." << broadcast_1 << "." << broadcast_2 << "." << broadcast_2 << endl;
	cout << "------------------------------------------ \n" << endl;
	printAuthors();
}
