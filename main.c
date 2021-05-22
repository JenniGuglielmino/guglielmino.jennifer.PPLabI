#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_guglielmino.h"
#include "cliente.h"
#include "juegos.h"
#include "categoria.h"
#include "alquiler.h"
#include "datawarehouse.h"
#define TAMJ 6
#define TAMCAT 5
#define TAMA 5
#define TAMCLI 5
#define TAMLO 5
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDRED     "\033[1m\033[31m"
#define RESET   "\033[0m"
int menuPrincipal();
int main()
{
    eCategoria categorias[TAMCAT] = {
        {100, "Mesa"},
        {101, "Azar"},
        {102, "Estrategia"},
        {103, "Salon"},
        {104, "Magia"},
    };

    eJuego juegos[TAMJ] = {
        {1000, "Batalla Naval", 500, 102},
        {1001, "Simon dice", 600, 101},
        {1002, "Cartas", 100, 104},
        {1003, "Monopoly", 1200, 100},
        {1004, "Generala", 800, 103},
        {1005, "Pictionary", 1000, 103},
    };

    eLocalidad localidades[TAMLO] = {
        {1, "Lomas de zamora"},
        {2, "Glew"},
        {3, "Lanus"},
        {4, "Banfield"},
        {5, "Avellaneda"},
        {6, "Temperley"}
    };

    char seguir = 's';
    int idClientes = 200;
    int idAlquileres = 5000;
    eCliente clientes[TAMCLI];
    eAlquiler alquileres[TAMA];
    inicializarCliente(clientes, TAMCLI);
    inicializarAlquileres(alquileres, TAMA);
    harcodearClientes(clientes, TAMCLI, 5, &idClientes);
    harcodearAlquileres(alquileres, TAMA, 5, &idAlquileres);
    do
    {
        switch(menuPrincipal())
        {
        case 1:
            if(altaCliente(clientes, TAMCLI, &idClientes, localidades, TAMLO)){
                 printf(BOLDGREEN"\t\t\t\t+------------------------+");
                    printf("\n\t\t\t\t|    Alta exitosa!!!     |\n");
                    printf("\t\t\t\t+------------------------+\n"RESET);
            }
            else{
                 printf(BOLDRED "\n\tHubo un error al dar de alta\n" RESET);
            }
            break;
        case 2:
            if(modificarUno(clientes, TAMCLI, localidades, TAMLO)){
                  printf(BOLDGREEN "\n\t\t\t+-----------------------------+");
                    printf("\n\t\t\t|    Modificacion exitosa!!!  |\n");
                    printf("\t\t\t+-----------------------------+\n" RESET);
            }
            else{
                 printf(BOLDRED "\n\t\tHubo un error al modificar\n" RESET);
            }
            break;
        case 3:
            if(bajaCliente(clientes, TAMCLI, localidades, TAMLO)&& bajaAlquilerXCliente(alquileres, TAMA, clientes, TAMCLI)){
                 printf(BOLDGREEN "\t\t\t\t+------------------------+");
                    printf("\n\t\t\t\t|    Baja exitosa!!!     |\n");
                    printf("\t\t\t\t+------------------------+\n" RESET);
            }
            else{
                 printf(BOLDRED "\n\t\tHubo un error al dar de baja\n"RESET);
            }
            break;
        case 4:
            system("cls");
            ordenarClientes(clientes, TAMCLI);
            mostrarClientes(clientes, TAMCLI, localidades, TAMLO);
            break;
        case 5:
            altaAlquiler(alquileres, TAMA, clientes, TAMCLI, juegos, TAMJ, &idAlquileres, categorias, TAMCAT, localidades, TAMLO);
            break;
        case 6:
            system("cls");
            mostrarAlquileres(alquileres, TAMA, clientes, TAMCLI, juegos, TAMJ);
            break;
        case 7:
            system("cls");
            mostrarJuegos(juegos, TAMJ, categorias, TAMCAT);
            break;
        case 8:
            system("cls");
            mostrarCategorias(categorias, TAMCLI);
            break;
        case 9:
            system("cls");
            informes(clientes, TAMCLI, juegos, TAMJ, alquileres, TAMA, categorias, TAMCAT, localidades, TAMLO);
            break;
        case 10:
            pedirChar(&seguir, "\n\tDesea continuar? s/n :", BOLDRED"\n\tError, por favor ingrese una opcion valida"RESET, 20);
            break;
        default:
            printf(BOLDRED "\n\tOpcion invalida\n\n" RESET);
            break;
        }
    system("pause");
    }
    while(seguir == 's');
    return 0;
}

int menuPrincipal(){
    int opcion;
    system("cls");
    printf("\n\n\t\t\tGestion alquileres de juegos\n");
    printf("\t\t\t----------------------------");
    printf("\n\t1-Alta cliente\n");
    printf("\t2-Modificar cliente\n");
    printf("\t3-Baja cliente\n");
    printf("\t4-Listar clientes\n");
    printf("\t5-Alta alquiler\n");
    printf("\t6-Listar alquileres\n");
    printf("\t7-Lista de juegos\n");
    printf("\t8-Lista de categorias\n");
    printf("\t9-Informes\n");
    printf("\t10-Salir\n");
    pedirNumero(&opcion, "\tIngrese la opcion: ", BOLDRED"\n\tError, reingrese un numero valido\n" RESET, 1, 10, 100);
    return opcion;
}
