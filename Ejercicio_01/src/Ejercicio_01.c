#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

char* string_concat();

int main(int argc, char** argv) {

	char* nombre = "Richie";

	char* saludo = string_concat("Hola ", nombre);

	printf("%s", saludo);

    return 0;
 }

char* string_concat(char* unString, char* otroString){

	char* resultadoFinal = malloc(strlen(unString)+strlen(otroString)+1); //+1 es por el /0 final del array

	strcpy(resultadoFinal, unString);
	strcat(resultadoFinal, otroString);

	return resultadoFinal;
}
