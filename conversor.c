#include <getopt.h>

#include "conversor.h"

static struct option long_options[] = {
	{"binary"	,no_argument	,0	,'b'},
	{"decimal"	,no_argument	,0	,'d'},
	{"octal"	,no_argument	,0	,'o'},
	{"hexadecimal"	,no_argument	,0	,'h'},
	{"number"	,required_argument,	0,'n'},
	{0, 0, 0, 0}
};

void set_option(char options[], char c, int index){
	if(index <= 1)
		options[index] = c;
	else
		exit(EXIT_FAILURE);
}

void chose_option(int option, char* numero){
	int n = 0;
	switch(option){

		case 1:
			printf("%d\n", binario_decimal(numero));
		break;

		case 2:
			binario_octal(numero);
		break;

		case 3:
			binario_hexadecimal(numero);
		break;

		case 4:
			printf("%s\n", decimal_binario(atoi(numero)));
		break;
		
		case 5:
			decimal_octal(atoi(numero));
		break;
		
		case 6:
			decimal_hexadecimal(atoi(numero));
		break;
		
		case 7:
			octal_binario(atoi(numero));
		break;
		
		case 8:
			octal_decimal(atoi(numero));
		break;
		
		case 9:
			octal_hexadecimal(atoi(numero));
		break;
		
		case 10:
			hexadecimal_binario(numero);
		break;

		case 11:
			hexadecimal_decimal(numero);
		break;
		
		case 12:
			hexadecimal_octal(numero);
		break;

	}
}

int main(int argc, char *argv[]){

	int option = 0;
	char options[2];
	int opt = 0;
	int index = 0;
	char* numero = "";

	while(1){

		int option_index = 0;
		option = getopt_long(argc, argv, "bdohn:", long_options, &option_index);
		
		if(option == -1)
			break;
		
		switch(option){
		
			case 'b':
				set_option(options, 'b', index);
				index++;
			break;
			
			case 'd':
				set_option(options, 'd', index);
				index++;
			break;
			
			case 'o':
				set_option(options, 'o', index);
				index++;
			break;
			
			case 'h':
				set_option(options, 'h', index);
				index++;
			break;
			
			case 'n':
				numero = optarg;
			break;
			
			default:
				printf("Error\n");
				exit(EXIT_FAILURE);
		}
	}

	if(options[0] == 'b' && options[1] == 'd')
		opt = 1;
	if(options[0] == 'b' && options[1] == 'o')
		opt = 2;
	if(options[0] == 'b' && options[1] == 'h')
		opt = 3;

	if(options[0] == 'd' && options[1] == 'b')
		opt = 4;
	if(options[0] == 'd' && options[1] == 'o')
		opt = 5;
	if(options[0] == 'd' && options[1] == 'h')
		opt = 6;

	if(options[0] == 'o' && options[1] == 'b')
		opt = 7;
	if(options[0] == 'o' && options[1] == 'd')
		opt = 8;
	if(options[0] == 'o' && options[1] == 'h')
		opt = 9;

	if(options[0] == 'h' && options[1] == 'b')
		opt = 10;
	if(options[0] == 'h' && options[1] == 'd')
		opt = 11;
	if(options[0] == 'h' && options[1] == 'o')
		opt = 12;

	chose_option(opt, numero);
}
