#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datawarehouse.h"

static char nombres[10][20]={
            "Mac",
            "Alasteir",
            "Gardener",
            "Fede",
            "Pablo",
            "Had",
            "Wilhelmina",
            "Eadith",
            "Normy",
            "Aileen"
};

static char apellido[10][20]={
            "Gonzales",
            "Juarez",
            "Gutierrez",
            "Gomez",
            "Gonzales",
            "Alamo",
            "Garcia",
            "Alonso",
            "Valdez",
            "Paz"
};

static char telefono[10][20]={
            "4243-8021",
            "2345-1234",
            "1164357854",
            "4314-2344",
            "15467843",
            "4235-5635",
            "8432-5229",
            "1234-1234",
            "4532-1345",
            "125533464"
};

static char sexos[10]={'f','m','m','m','f','f','m','f','f','m'};

static int idCodigoJuego[10]={1000, 1001, 1000, 1003, 1000, 1001, 1002, 1001, 1004, 1002};

static int codCliente[10]={200, 201, 202, 204, 205, 206, 207, 208, 209, 210};

static int idLocalidad[10]={2, 1, 3, 4, 1, 2, 3, 2, 3, 1};

static eFecha fechasA[10]={{1,3,2021}, {2,4,2021}, {4,5,2009}, {26,04,2008}, {3,7,2010}, {1,12,2010}, {1,11,2016}, {5,3,2018}, {7,3,2017}, {2,4,2015}};

int harcodearClientes(eCliente clientes[], int tam, int cant, int* pCodigoCliente){
        int total = 0;
        if (clientes != NULL && tam > 0 && cant >= 0 && cant <= tam && pCodigoCliente != NULL ){
            for (int i = 0; i<cant; i++){
                clientes[i].codigo = *pCodigoCliente;
                (*pCodigoCliente)++;
                strcpy(clientes[i].nombre, nombres[i]);
                strcpy(clientes[i].apellido, apellido[i]);
                clientes[i].sexo = sexos[i];
                strcpy(clientes[i].telefono, telefono[i]);
                clientes[i].localidad.id = idLocalidad[i];
                clientes[i].isEmpty = 0;
                total++;
            }
        }
        return total;
}

int harcodearAlquileres(eAlquiler alquileres[], int tam, int cant, int* pIdAlquiler){
        int total = 0;
        if (alquileres != NULL && tam > 0 && cant >= 0 && cant <= tam && pIdAlquiler != NULL ){
            for (int i = 0; i<cant; i++){
                alquileres[i].codigoAlquiler = *pIdAlquiler;
                (*pIdAlquiler)++;
                alquileres[i].codigoJuego = idCodigoJuego[i];
                alquileres[i].codigoCliente = codCliente[i];
                alquileres[i].fecha = fechasA[i];
                alquileres[i].isEmpty = 0;
                total++;
            }
        }
        return total;
}

