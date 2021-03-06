#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int elevar(int n, int e){
	if (e == 0) return 1;
	return n * elevar(n, e-1);
}

char* invertir_texto(char* str, int len){
	char* i = str;
	char* j = str + len - 1;
	while (i < j) {
		char aux = *i;
		*i++ = *j;
		*j-- = aux;
	}
	return str;
}

int resolver_exp(char* numero, int base){
	int resultado = 0;
	for (int i = strlen(numero) - 1, j = 0; i >= 0; i--, j++){
		int n = numero[i] - '0';//Convierte char a int
		int m = elevar(base, j);
		int r = n * m;
		resultado += r;
	}
	return resultado;
}

char* resolver_div(int numero, int dividendo){
	char* resultado;
	char aux[100];
	for (int i = numero, j = 0; i > 0; i /= dividendo, j++){
		int res = i % dividendo;
		aux[j] = res + '0'; // Convierte int a char
		aux[j+1] = '\0';
	}
	resultado = aux;
	return invertir_texto(resultado, strlen(resultado));
}

char letras(int n){
	switch (n){
		case 10: return 'A';
		case 11: return 'B';
		case 12: return 'C';
		case 13: return 'D';
		case 14: return 'E';
		case 15: return 'F';
		default: return '\0';
	}
}

int numeros(char c){
	switch (c){
		case 'A': return 10;
		case 'B': return 11;
		case 'C': return 12;
		case 'D': return 13;
		case 'E': return 14;
		case 'F': return 15;
		default: return 0;
	}
}

int binario_decimal(char* numero){
	return resolver_exp(numero, 2);
}

char* decimal_binario(int numero){
	return resolver_div(numero, 2);
}

int octal_decimal(char* numero){
	return resolver_exp(numero, 8);
}

char* decimal_octal(int numero){
	return resolver_div(numero, 8);
}

int hexadecimal_decimal(char* numero){
	char hexa[100];
	char letras[] = "ABCDEF";
	int len = strlen(numero);
	int oremun[len];
	int decimal = 0;

	for (int i = 0; i < len; i++){
		oremun[i] = 0;
		hexa[i] = toupper(numero[i]);
		for (int j = 0; j < strlen(letras); j++){
			if (hexa[i] == letras[j]){
				oremun[i] = numeros(hexa[i]);
				hexa[i] = '0';
			}
		}
		if (hexa[i] != '0')
			oremun[i] = hexa[i] - '0';
	}

	for (int i = len - 1, j = 0; i >= 0; i--, j++)
		decimal += oremun[i] * elevar(16, j);

	return decimal;
}

char* decimal_hexadecimal(int numero){
	char* resultado;
	char aux[100];
	for (int i = numero, j = 0; i > 0; i /= 16, j++){
		int res = i % 16;
		if (res >= 10)
			aux[j] = letras(res);
		else
			aux[j] = res + '0';
		aux[j+1] = '\0';
	}

	resultado = aux;
	return invertir_texto(resultado, strlen(resultado));
}

char* binario_octal(char* numero){
	int oremun = binario_decimal(numero);
	return decimal_octal(oremun);
}

char* octal_binario(char* numero){
	int oremun = octal_decimal(numero);
	return decimal_binario(oremun);
}

char* binario_hexadecimal(char* numero){
	int oremun = binario_decimal(numero);
	return decimal_hexadecimal(oremun);
}

char* octal_hexadecimal(char* numero){
	int oremun = octal_decimal(numero);
	return decimal_hexadecimal(oremun);
}

char* hexadecimal_binario(char* numero){
	int oremun = hexadecimal_decimal(numero);
	return decimal_binario(oremun);
}

char* hexadecimal_octal(char* numero){
	int oremun = hexadecimal_decimal(numero);
	return decimal_octal(oremun);
}
