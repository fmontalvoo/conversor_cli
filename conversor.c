#include <getopt.h>

#include "conversor.h"

void usage(){
	puts("Modo de uso: conversor [OPCIÓN]... [ARGUMENTO]\n");
	puts("Realiza conversiones entre los distintos sistemas numéricos");
	puts("opciones -bdohn");
	puts("\n");
	puts(" -b,	--binary		Establece el sistema binario.");
	puts(" -d,	--decimal		Establece el sistema decimal.");
	puts(" -o,	--octal			Establece el sistema octal.");
	puts(" -h,	--hexadecimal		Establece el sistema hexadecimal.");
	puts(" -n,	--number		Parámetro obligatorio que indica el número a convertir.");
	puts("\n");
	puts("Ejemplo:");
	puts("	$ conversor --decimal --binary --number 10");
	puts("	$ conversor -dbn 10");
}

static struct option long_options[] = {
	{"help"	,no_argument	,0	,0},
	{"binary"	,no_argument	,0	,'b'},
	{"decimal"	,no_argument	,0	,'d'},
	{"octal"	,no_argument	,0	,'o'},
	{"hexadecimal"	,no_argument	,0	,'h'},
	{"number"	,required_argument,	0,'n'},
	{0,		0,		0,	0}
};

void set_option(char options[], char c, int index){
	if(index <= 1){
		options[index] = c;
	}
	else{
		usage();
		exit(EXIT_FAILURE);
	}
	
}

void chose_option(int option, char* numero){
	int n = 0;
	putchar('\0');
	switch(option){
		case 1:
			printf("%d\n", binario_decimal(numero));
		break;

		case 2:
			printf("%s\n", binario_octal(numero));
		break;

		case 3:
			printf("%s\n", binario_hexadecimal(numero));
		break;

		case 4:
			printf("%s\n", decimal_binario(atoi(numero)));
		break;
		
		case 5:
			printf("%s\n", decimal_octal(atoi(numero)));
		break;
		
		case 6:
			printf("%s\n", decimal_hexadecimal(atoi(numero)));
		break;
		
		case 7:
			printf("%s\n", octal_binario(numero));
		break;
		
		case 8:
			printf("%d\n", octal_decimal(numero));
		break;
		
		case 9:
			printf("%s\n", octal_hexadecimal(numero));
		break;
		
		case 10:
			printf("%s\n", hexadecimal_binario(numero));
		break;

		case 11:
			printf("%d\n", hexadecimal_decimal(numero));
		break;
		
		case 12:
			printf("%s\n", hexadecimal_octal(numero));
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
				usage();
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
