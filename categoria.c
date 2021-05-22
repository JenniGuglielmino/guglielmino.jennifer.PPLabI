#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "categoria.h"
int cargarNombreCategoria(int idCategoria, eCategoria categorias[],int tamC, char*nombreCategoria){
        int todoOk = 0;
        if(idCategoria >= 100 && idCategoria <=500 && categorias!=NULL && tamC > 0 && nombreCategoria != NULL){
            for(int i=0; i<tamC; i++){
                if(categorias[i].id == idCategoria){
                    strcpy(nombreCategoria, categorias[i].descripcion);
                    todoOk = 1;
                    break;
                }
            }
        }
        return todoOk;
}

void mostrarCategoria(eCategoria categoria){
    printf("\n\t|%10d|%20s|",    categoria.id, categoria.descripcion);
}

void mostrarCategorias(eCategoria categoria[], int tam){
    printf("\n\n\t\tLista de categorias\n");
    printf("\t\t===================\n");
    printf("\n\t\tId\tDescripcion\n");
    printf("\t---------------------------------");
    for(int i=0;i<tam;i++){
        mostrarCategoria(categoria[i]);
    }
    printf("\n\n");
}
