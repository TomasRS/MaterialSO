#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <commons/txt.h>
#include <commons/collections/node.h>
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

t_persona *persona;

//Lista de personas
typedef struct {
		t_persona *persona;
		int elements_count;
	}t_list;

t_list* list_create();


int main(int argc, char** argv) {

	FILE *archivo;
	char* filaDelArchivo;
	FILE *archivoFinal;

	archivo = fopen("personas.txt","r");
	archivoFinal = fopen("/home/utnso/workspace/MaterialSO/Ejercicio_03/personasFinales.txt","w");

	//Modificar lo de dentro del while
	while(!feof(archivo)){
			//Leer linea entera o leer por partes e ir asignando los datos al nodo

			registrarPersonaEnLista(filaDelArchivo); //solo los menores de 18
			//Loguear persona si correspondiera (saldo menor a 100)
		}


	//Ordenar la lista por region y edad (usar funcion de las commons)

	//Escribir en el archivo de salida

	return 0;
}

//Completar el registro de las personas en la lista (solo los menores de 18)
void registrarPersonaEnLista(char* filaDelArchivo){



	//Cargar datos de la persona en el nodo

	//Insertar nodo en la lista

}
