#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "juegos.h"
#define BOLDRED     "\033[1m\033[31m"
#define RESET   "\033[0m"
int mostrarJuego(eJuego juego, eCategoria categorias[], int tamC){
    char nombreCategoria[20];
    int todoOk = 0;
    if(cargarNombreCategoria(juego.idCategoria.id, categorias,tamC, nombreCategoria))
    {
        printf("\n\t|%10d|%20s|%20.2f|%10s|",   juego.codigo, juego.descripcion, juego.importe, nombreCategoria);
        todoOk = 1;
    }
    return todoOk;
}

void mostrarJuegos(eJuego juegos[], int tamJ, eCategoria categorias[], int tamC){
    int flag = 0;
    printf("\n\n\t\t\t\tLista de juegos\n");
    printf("\t=================================================================");
     printf("\n\t  Codigo\t\tJuegos\t\tImporte\t\tCategoria\n");
    printf("\t-----------------------------------------------------------------");
    if(juegos != NULL && tamJ > 0)
    {
        for(int i=0;i<tamJ;i++)
        {
            flag = mostrarJuego(juegos[i], categorias, tamC);
        }
    }
    if(!flag){
        printf(BOLDRED"\n\tNo hay juegos para mostrar"RESET);
    }
    printf("\n\n");
}

int buscarJuegos(eJuego juegos[], int tamJ, int id){
    int indice = -1;
    if(juegos != NULL && tamJ > 0)
    {
        for(int i = 0; i < tamJ ; i++)
        {
            if(juegos[i].codigo == id)
            {
               indice = i;
               break;
            }
        }
    }
    return indice;
}

int cargarNombreJuegos(int idJuego, eJuego juegos[], int tam, char* nombreJuego ){
     int todoOk = 0;
        if(idJuego >= 1000 && idJuego <=2000 && juegos !=NULL && tam  > 0 && nombreJuego != NULL){
            for(int i=0; i<tam; i++){
                if(juegos[i].codigo== idJuego){
                    strcpy(nombreJuego, juegos[i].descripcion);
                    todoOk = 1;
                    break;
                }
            }
        }
        return todoOk;
}
