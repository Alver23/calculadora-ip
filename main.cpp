#include <string>
#include <iostream>

using namespace std;
string binary(int num);
void instrucciones();
void print_number(int num);
string convierteBin(int);

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
			case 6:
				printf("Fin");
				exit(0);
				return 0;
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

void instrucciones()
{
	cout << "\n Escriba una de las siguentes opciones:\n"
		<< " 1 Sumar\n"
		<< " 2 Restar\n"
		<< " 3 Multiplicar\n"
		<< " 4 Dividir\n"
		<< " 5 Direccionamiento IP\n"
		<< " 6 para terminar \n";
}

double Suma (double a, double b)
{
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

double Resta (double a, double b)
{
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

double Multiplicacion (double a, double b)
{
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

double Division (double a, double b)
{
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
