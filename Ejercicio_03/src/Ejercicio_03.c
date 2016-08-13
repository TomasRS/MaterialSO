#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <commons/txt.h>
#include <commons/collections/node.h>
#include <commons/string.h>
#include <stdbool.h>

void registrarPersonaEnLista();

//Nodo Persona para la lista
typedef struct Persona{
	char* region;
	char nombreYApellido[30];
	int edad;
	int nroTelefono;
	int saldo;
	struct Persona *sig;
}t_persona;



int main(int argc, char** argv) {

	FILE *archivo;
	char* filaDelArchivo;
	FILE *archivoFinal;
	t_persona *persona = malloc(sizeof(t_persona));

	archivo = fopen("personas.txt","r");
	archivoFinal = fopen("personasFinales.txt","w");


	while(fgets(filaDelArchivo, sizeof(filaDelArchivo), archivo)){

			registrarPersonaEnLista(filaDelArchivo, persona);

		}

	//Ordenar la lista por region y edad (usar funcion de las commons)

	//Escribir en el archivo de salida
	free(persona);
	fclose(archivo);
	return 0;
}


void registrarPersonaEnLista(char* filaDelArchivo, t_persona* persona){

	char* search = ";";
	string_split(filaDelArchivo,search);

}
