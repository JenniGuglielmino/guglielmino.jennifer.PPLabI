#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alquiler.h"
#include "juegos.h"

#define RESET   "\033[0m"
#define BOLDRED     "\033[1m\033[31m"
int altaAlquiler(eAlquiler alquiler[], int tamA, eCliente clientes[], int tamCli, eJuego juegos[], int tamJ, int* pIdAlquiler, eCategoria categorias[], int tamC, eLocalidad localidades[], int taml){
    int todoOk = 0;
    int indice;
    int codigo;
    int idJuegos;
    eAlquiler nuevoAlquiler;
    if(alquiler != NULL && tamA > 0 && pIdAlquiler != NULL){
        system("cls");
        printf("\n\n\t\t\t11.Alta alquiler\n");
        printf("\t\t\t================\n");
        printf("\n\tIdAlquiler: %d\n", *pIdAlquiler);

        indice = buscarLibreAlquiler(alquiler, tamA);
        if(indice == -1)
        {
            printf(BOLDRED "\n\t\tNo hay lugar para mas alquileres\n" RESET);
        }
        else{
                nuevoAlquiler.codigoAlquiler= *pIdAlquiler;

                if(mostrarClientes(clientes, tamCli, localidades, taml)){
                    pedirNumero(&codigo, "\tIngrese el codigo del cliente: ", "\t\tError codigo invalido\n", 200, 1000000, 20);

                    nuevoAlquiler.codigoCliente = codigo;

                    mostrarJuegos(juegos, tamJ, categorias, tamC);
                    printf("\t\tIngrese el id del juego: ");
                    scanf("%d", &idJuegos);

                    nuevoAlquiler.codigoJuego= idJuegos;

                    pedirNumero(&nuevoAlquiler.fecha.dia, "\t\tIngrese el dia: ", "\t\tError dia invalido\n", 1, 31, 10);
                    pedirNumero(&nuevoAlquiler.fecha.mes, "\t\tIngrese el mes: ", "\t\tError mes invalido\n", 1, 12, 10);
                    pedirNumero(&nuevoAlquiler.fecha.anio, "\t\tIngrese el año: ", "\t\tError año invalido\n", 1990, 2021, 10);

                    nuevoAlquiler.isEmpty = 0;
                    alquiler[indice] = nuevoAlquiler;

                    (*pIdAlquiler)++;
                    todoOk = 1;
                }
        }
    }
    return todoOk;
}


void inicializarAlquileres(eAlquiler alquileres[], int tamA){
    for(int i = 0; i<tamA; i++){
        alquileres[i].isEmpty = 1;
    }
}

int buscarLibreAlquiler(eAlquiler alquiler[], int tamA){
    int indice = -1;
    if(alquiler!= NULL && tamA > 0)
    {
        for(int i=0; i<tamA; i++)
        {
            if(alquiler[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int bajaAlquilerXCliente(eAlquiler alquileres[], int tama, eCliente clientes[], int tam){
    if(alquileres != NULL && tama>0 && clientes != NULL && tam>0){
        for(int i=0; i<tama; i++){
            if(alquileres[i].codigoCliente == clientes[i].codigo && clientes[i].isEmpty == 0){
                alquileres[i].isEmpty = 1;
            }
        }

    }
    return 1;
}

int mostrarAlquiler(eAlquiler alquiler, int tamA, eCliente clientes[], int tamCli, eJuego juegos[], int tamJ){
    char nombreJuego[20];
    int todoOk = 0;
    char nombreCliente[20];
    if(cargarNombreJuegos(alquiler.codigoJuego,juegos,tamJ,nombreJuego)&& cargarNombreCliente(alquiler.codigoCliente, clientes, tamCli, nombreCliente))
    {
        printf("\t| %10d|%20s|%20s|\t%02d/%02d/%d|\n",    alquiler.codigoAlquiler, nombreJuego, nombreCliente, alquiler.fecha.dia, alquiler.fecha.mes, alquiler.fecha.anio);
        todoOk = 1;
    }
    return todoOk;
}

int mostrarAlquileres(eAlquiler alquileres[], int tamA, eCliente clientes[], int tamCli, eJuego juegos[], int tamJ){
    int flag = 1;
    system("cls");
    printf("\n\n\t\t\t\tLista de alquileres\n");
    printf("\t-----------------------------------------------------------------\n");
    printf("\t\tCodigo\t\tJuego\t\tCliente\t\t  Fecha\n");
    printf("\t-----------------------------------------------------------------\n");
    if(alquileres != NULL && tamA > 0 && clientes != NULL && tamCli > 0 && juegos != NULL && tamJ > 0){
        for(int i=0; i<tamA; i++)
        {
            if( !alquileres[i].isEmpty && mostrarAlquiler(alquileres[i], tamA, clientes, tamCli, juegos, tamJ))
            {
                flag = 0;
            }
        }
    }
    if(flag){
        printf(BOLDRED "\n\tNo hay alquileres registrados\n" RESET);
    }
    printf("\n\n");
}


