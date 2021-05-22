#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "localidad.h"
int cargarNombreLocalidad(int idLocalidad, eLocalidad localidades[], int taml, char* nombreLocalidad){
        int todoOk = 0;
        if(idLocalidad >= 1 && idLocalidad <=6 && localidades !=NULL && taml > 0 && nombreLocalidad != NULL){
            for(int i=0; i<taml; i++){
                if(localidades[i].id == idLocalidad){
                    strcpy(nombreLocalidad, localidades[i].descripcion);
                    todoOk = 1;
                    break;
                }
            }
        }
        return todoOk;
}

void mostrarLocalidad(eLocalidad localidades){
    printf("\n\t|%10d|%20s|",    localidades.id, localidades.descripcion);
}

void mostrarLocalidades(eLocalidad localidades[], int tam){
    printf("\n\n\t\tLista de localidadess\n");
    printf("\t\t===================\n");
    printf("\n\t\tId\tDescripcion\n");
    printf("\t---------------------------------");
    for(int i=0;i<tam;i++){
        mostrarLocalidad(localidades[i]);
    }
    printf("\n\n");
}
