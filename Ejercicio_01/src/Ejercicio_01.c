#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

char* string_concat();
void string_concat_dynamic();
void mail_split();

int main(int argc, char** argv) {
//Parte1
	char* nombre = "Richie";

	char* saludo = string_concat("Hola ", nombre);

	printf("%s\n", saludo);

	printf("-------------------------\n");

//Parte2
	char* nombre2 = "Richie";
	char* saludo2;

	string_concat_dynamic("Hola ", nombre2, &saludo2);

	printf("%s\n", saludo2);

	printf("-------------------------\n");

//Parte3
	//Aca necesito usar la funcion strdup porque strtok modifica el string (mail),
	//asi que no puedo mandarle el puntero asi nomas a la funcion mail_split

	char* mail = strdup("ritchie@ansic.com.ar");
	char* user;
	char* dominio;

	mail_split(mail, &user, &dominio);

	printf("User: %s\n", user);
	printf("Dominio: %s", dominio);


    return 0;
 }



//Funciones auxiliares
char* string_concat(char* unString, char* otroString){

	char* resultadoFinal = malloc(strlen(unString)+strlen(otroString)+1); //+1 es por el /0 final del array

	strcpy(resultadoFinal, unString);
	strcat(resultadoFinal, otroString);

	return resultadoFinal;
}
	//En char** saludo va ** porque me llega un puntero por parametro
void string_concat_dynamic(char* unString, char* otroString, char** saludo){

	//Reuso la funcion hecha anteriormente para no repetir codigo
	*saludo = string_concat(unString, otroString);

}

void mail_split(const char* mail, char** user, char** dominio){

	char* search = "@";

	*user = strtok(mail, search);
	*dominio = strtok(NULL, search);

}
