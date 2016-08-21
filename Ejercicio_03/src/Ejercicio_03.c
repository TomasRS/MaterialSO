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
	char* nombreYApellido;
	int edad;
	int nroTelefono;
	int saldo;
	struct Persona *sig;
}t_persona;

t_persona* persona;

int main(int argc, char** argv) {

	FILE *archivo;
	t_persona *persona = malloc(sizeof(t_persona));

	archivo = fopen("personas.txt","r");

	while(!feof(archivo)){

		registrarPersonaEnLista(&persona);
		printf("Nombre: ", persona->nombreYApellido);

	}



	//Escribir en el archivo de salida
	free(persona);
	fclose(archivo);
	return 0;
}


void registrarPersonaEnLista(t_persona* persona){

	persona->nombreYApellido = "Mauro";

}
