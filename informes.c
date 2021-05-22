#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "informes.h"
#include "utn_guglielmino.h"
//2
void mostrarAlquileresPorClientes(eCliente clientes[], int tamcli, eJuego juegos[], int tamj, eAlquiler alquiler[], int tama, eLocalidad localidades[], int taml){
    int idCliente;
    printf("\n\n\t\t\tAlquileres por cliente\n");
    printf("\t\t\t======================");
    int flag = 0;
    mostrarClientes(clientes, tamcli, localidades, taml);
    pedirNumero(&idCliente, "\tIngrese el codigo del cliente: ", "Error, valor incorrecto", 199, 5000, 10);
    while(buscarCliente(clientes, tamcli, idCliente)==-1)
    {
        pedirNumero(&idCliente, "Ingrese el codigo del cliente: ", "Error, valor incorrecto", 199, 5000, 10);
    }

    for(int i=0; i<tama; i++)
    {
        if(alquiler[i].codigoCliente == idCliente && !alquiler[i].isEmpty)
        {
            mostrarAlquiler(alquiler[i], tama, clientes, tamcli, juegos, tamj);
            flag = 1;
        }
    }
    if(!flag)
    {

        printf("\n\tNo hay alquileres para mostrar");
    }
}
//1
int juegosPorCategoriaMesa(eJuego juegos[], int tamj, eCategoria categorias[], int tamc){
    int todoOk=0;
    int idCategoria = 100;
    system("cls");
    printf("\n\t\t\tInforme de juegos de mesa \n");
    printf("\t\t---------------------------------------\n");
    for(int i = 0; i<tamj; i++)
    {
        if(juegos[i].idCategoria.id == idCategoria)
        {
            printf("\n\t\t%s\n", juegos[i].descripcion);
            todoOk=1;
        }
    }
    return todoOk;
}
//3
int acumularImportePorCliente(eCliente clientes[], int tamcli, eJuego juegos[], int tamj, eAlquiler alquileres[], int tamA, eLocalidad localidades[], int taml){
    int idCliente;
    printf("\n\n\t\t\tAlquileres por cliente\n");
    printf("\t\t\t======================");
    int flag = 0;
    float total;
    mostrarClientes(clientes, tamcli, localidades, taml);
    pedirNumero(&idCliente, "\tIngrese el codigo del cliente: ", "Error, valor incorrecto", 199, 5000, 10);
    while(buscarCliente(clientes, tamcli, idCliente)==-1)
    {
        pedirNumero(&idCliente, "Ingrese el codigo del cliente: ", "Error, valor incorrecto", 199, 5000, 10);
    }

    for(int i=0; i<tamcli; i++)
    {
        total = 0;
        for(int j=0; j<tamA; j++)
        {
            if(alquileres[j].codigoCliente == idCliente && !alquileres[i].isEmpty)
            {
                for(int k=0; k<tamj; k++)
                {
                    if(juegos[j].codigo == alquileres[i].codigoJuego)
                    {
                        total += juegos[j].importe;
                        flag = 1;
                    }
                }
            }
        }
    }
    printf("\n\tEl total por este cliente es %.2f\n", total);
    if(!flag)
    {

        printf("\n\tNo hay alquileres para mostrar");
    }
    return flag;
}

//10
void recaudacionPorFecha(eAlquiler alquileres[], int tamA, eJuego juegos[],int tamJ){
    float totalGanancia = 0;
    eFecha auxfecha;
    pedirNumero(&auxfecha.dia, "\t\tIngrese el dia: ", "\t\tError dia invalido\n", 1, 31, 10);
    pedirNumero(&auxfecha.mes, "\t\tIngrese el mes: ", "\t\tError mes invalido\n", 1, 12, 10);
    pedirNumero(&auxfecha.anio, "\t\tIngrese el año: ", "\t\tError año invalido\n", 1990, 2021, 10);
    for(int i = 0; i < tamA; i++){//busco alquileres en esa fecha
        if (alquileres[i].fecha.anio == auxfecha.anio && alquileres[i].fecha.mes == auxfecha.mes && alquileres[i].fecha.dia == auxfecha.dia)
            {
            for(int j= 0; j < tamJ; j++){//obtengo juego para ese alquiler
                if (juegos[j].codigo == alquileres[i].codigoJuego){
                    totalGanancia += juegos[j].importe;
                }
            }
        }
    }
    if (totalGanancia > 0){
        printf("\t\tGanancia de la fecha %d/%d/%d: %.2f\n", auxfecha.dia, auxfecha.mes, auxfecha.anio ,totalGanancia);
    }
    else {
        printf("\t\tSin ganancias el dia %d/%d/%d\n", auxfecha.dia, auxfecha.mes, auxfecha.anio);
    }
}

//9
void listarClientesPorJuego(eCliente clientes[], int tamC, eJuego juegos[], int tamJ, eAlquiler alquileres[], int tamA)
{
     int flag = 0;
    int flagPorJuego = 0;
    for (int i = 0; i < tamJ; i++)//Juegos
    {
        flagPorJuego = 0;
        printf("\n\t\tJuego: %s\n", juegos[i].descripcion);
        for (int j = 0; j < tamA; j++)//Alquileres
        {
            if (alquileres[j].codigoJuego == juegos[i].codigo)
            {
                for (int k = 0; k < tamC; k++)//clientes
                {
                    if (alquileres[j].codigoCliente == clientes[k].codigo){
                        printf("\n\t\tCliente: %s %s\n", clientes[k].nombre, clientes[k].apellido);
                        flagPorJuego = 1;
                        flag = 1;
                    }
                }
            }
        }
        if (!flagPorJuego)
        {
            printf("\t\tNo se encontraron clientes cargados para este juego\n\n");
        }
        else {
            printf("\n\t\t---------------------------------------\n");
        }
    }
    if (!flag)
    {
        printf("\t\tNo se encontraron clientes cargados para ningun juego\n\n");
    }

}

//6
void telefonoPorFecha(eAlquiler alquileres[], int tamA, eJuego juegos[],int tamJ, eCliente clientes[], int tamCli){
    eFecha auxfecha;
    int flag = 0;
    pedirNumero(&auxfecha.dia, "\t\tIngrese el dia: ", "\t\tError dia invalido\n", 1, 31, 10);
    pedirNumero(&auxfecha.mes, "\t\tIngrese el mes: ", "\t\tError mes invalido\n", 1, 12, 10);
    pedirNumero(&auxfecha.anio, "\t\tIngrese el año: ", "\t\tError año invalido\n", 1990, 2021, 10);
    for(int i = 0; i < tamA; i++){//busco alquileres en esa fecha
        if (alquileres[i].fecha.anio == auxfecha.anio && alquileres[i].fecha.mes == auxfecha.mes && alquileres[i].fecha.dia == auxfecha.dia)
        {
                for (int k = 0; k < tamCli; k++)//clientes
                {
                    if (alquileres[i].codigoCliente == clientes[k].codigo)
                    {
                        printf("\n\t\tTelefono/s del cliente/s %s %s que alquilo el dia %d/%d/%d: %s \n", clientes[k].nombre, clientes[k].apellido, auxfecha.dia, auxfecha.mes, auxfecha.anio, clientes[k].telefono);
                        flag = 1;
                    }
                }
        }
    }
    if(!flag)
    {
            printf("\t\tNo se encontraron clientes cargados para la fecha %d/%d/%d", auxfecha.dia, auxfecha.mes, auxfecha.anio);
    }
    else {
            printf("\n\t\t---------------------------------------\n");
    }

}
int buscarJuegoPorId(eJuego juegos[], int tamJ, int idBuscado)
{
    int ret = -1;
    if (juegos != NULL && tamJ > 0 && idBuscado > 0)
        for (int i = 0; i < tamJ; i++)
        {
            if (juegos[i].codigo == idBuscado)
            {
                ret = i;
            }
        }
    return ret;
}
//8
void listarJuegosMasAlquiladosPorHombre(eCliente clientes[], int tamC, eJuego juegos[], int tamJ, eAlquiler alquileres[], int tamA)
{
    int contadorJuegos[tamJ];
    for(int i=0; i<tamJ; i++)
    {
        contadorJuegos[i]= 0;
    }
    int juegoIndex = -1;
    int flagAlquiler = 0;
    for(int i = 0; i < tamC; i++)//clientes
    {
        if (clientes[i].sexo == 'm') //hombres
        {
            for(int j = 0; j < tamA; j++)
            {
                if (alquileres[j].codigoCliente == clientes[i].codigo)
                {
                    for(int k = 0; k < tamJ; k++) //juegos
                    {
                        if (juegos[k].codigo == alquileres[j].codigoJuego)
                        {
                            juegoIndex = buscarJuegoPorId(juegos, tamJ, alquileres[j].codigoJuego);
                            if (juegoIndex != -1) //acumulo
                            {
                                   contadorJuegos[juegoIndex]++;
                                flagAlquiler = 1;
                            }
                        }
                    }
                }
            }
        }
    }
    int mayor = contadorJuegos[0];
    int mayorIndex = 0;
    for(int i = 0; i < tamJ; i++)
    {
        if (contadorJuegos[i] > mayor)
        {
            mayor = contadorJuegos[i];
            mayorIndex = i;
        }
    }
    if (flagAlquiler)
    {
        printf("\n\t\tJuego mas alquilado por hombres: %s \n\n", juegos[mayorIndex].descripcion);
    }
    else
    {
        printf("No hubo juegos alquilados por hombres\n\n");
    }
}

//informe localidades 1
void cantidadClientesPorLocalidades(eCliente clientes[], int tamcli, eLocalidad localidades[], int tamlo){
    int idLocalidad;
    int contador = 0;
    char descripcion[20];
    system("cls");
    printf("\n\t\tInforme clientes por localidad\n");
    mostrarLocalidades(localidades, tamlo);
    printf("\n\t\tIngrese id de la localidad: ");
    scanf("%d", &idLocalidad);
    cargarNombreLocalidad(idLocalidad, localidades, tamlo, descripcion);
    for(int i = 0; i<tamcli; i++){
        if(clientes[i].localidad.id == idLocalidad && clientes[i].isEmpty == 0){
            contador++;
        }
    }
    if(contador == 0){
        printf("\n\t\tNo hay clientes de la localidad de %s\n", descripcion);
    }
    else{
        printf("\n\t\tCantidad de clientes en %s es: %d\n", descripcion, contador);
    }
}

//7
void listarJuegosAlquiladosPorMujeres(eCliente clientes[], int tamC, eJuego juegos[], int tamJ, eAlquiler alquileres[], int tamA)
{
    int flagPorMujer = 0;
    int flag;
    for (int i = 0; i < tamC; i++)//Clientes
    {
        flagPorMujer = 0;
        if (clientes[i].sexo == 'f' && !clientes[i].isEmpty)
        {
            printf("\t\tCliente %s:\n", clientes[i].nombre);
            for(int j = 0; j < tamA; j++) //alquileres
            {
                if (clientes[i].codigo == alquileres[j].codigoCliente && !alquileres[j].isEmpty)
                {
                    for(int k = 0; k < tamJ; k ++) //juegos
                    {
                        if (juegos[k].codigo == alquileres[j].codigoJuego)
                        {
                            printf("\t\tJuego: %s\n", juegos[k].descripcion);
                            flagPorMujer = 1;
                            flag = 1;
                        }
                    }
                }
            }
        }
        if (flagPorMujer)
        {
             printf("\n\t\t---------------------------------------\n");
        }
    }
}
//informe localidad 2
void recaudacionPorLocalidad(eAlquiler alquileres[], int tamA, eJuego juegos[],int tamJ, eCliente clientes[], int tamcli, eLocalidad localidades[], int tamlo){
    float totalGanancia = 0;
    int idLocalidad;
    char descripcion[21];
    mostrarLocalidades(localidades, tamlo);
    pedirNumero(&idLocalidad, "\tIngrese el codigo de la localidad: ", "Error, valor incorrecto", 1, 6, 10);
    cargarNombreLocalidad(idLocalidad, localidades, tamlo, descripcion);
    for(int i = 0; i < tamcli; i++){//busco alquileres en esa fecha
        if (clientes[i].localidad.id == idLocalidad)
        {
            for(int j= 0; j < tamA; j++){//obtengo juego para ese alquiler
                if (clientes[i].codigo == alquileres[j].codigoCliente)
                {
                    for(int k= 0; k < tamJ; k++)
                    {
                        if (juegos[k].codigo == alquileres[j].codigoJuego)
                        {
                            totalGanancia += juegos[k].importe;
                        }
                    }
                }
            }
        }
    }
    if (totalGanancia > 0){
        printf("\t\tGanancia de la localidad de %s: %.2f\n",  descripcion ,totalGanancia);
    }
    else {
        printf("\t\tSin ganancias en %s \n", descripcion);
    }
}

//5
void listarJuegosSinAlquiler(eJuego juegos[], int tamJ, eAlquiler alquileres[], int tamA)
{
    int huboAlquileres = 0;
    int hayAlquilerPorJuego = 0;
    for(int i = 0; i < tamJ; i ++)
    {
        hayAlquilerPorJuego = 0;
        for(int j = 0; j < tamA; j++)
        {
            if (alquileres[j].codigoJuego == juegos[i].codigo)
            {
                hayAlquilerPorJuego = 1;
                huboAlquileres  = 1;
            }
        }
        if (!hayAlquilerPorJuego)
        {
            printf("\n\t\tJuego: %s, sin alquileres registrados\n\n", juegos[i].descripcion);
        }

    }
    if (!huboAlquileres )
    {
        printf("\n\t\tNo hubo alquileres\n\n");
    }

}
//4
void listarClientesSinAlquiler(eCliente clientes[], int tamcli, eAlquiler alquileres[], int tamA)
{
    int huboAlquileres = 0;
    int hayAlquilerPorCliente = 0;
    for(int i = 0; i < tamcli; i ++)
    {
        hayAlquilerPorCliente = 0;

        for(int j = 0; j < tamA; j++)
        {   if (!alquileres[j].isEmpty){
                huboAlquileres = 1;
            }
            if (alquileres[j].codigoCliente == clientes[i].codigo && !clientes[i].isEmpty && !alquileres[i].isEmpty)
            {
                hayAlquilerPorCliente = 1;
            }
        }
        if (!hayAlquilerPorCliente && !clientes[i].isEmpty)
        {
            printf("\n\t\tCliente: %s, sin alquileres registrados\n\n", clientes[i].nombre);
        }

    }
    if (!huboAlquileres )
    {
        printf("\n\t\tNo hubo alquileres\n\n");
    }

}

int menuInformes(){
    int opcion;
    system("cls");
    printf("\n\n\t\t\tOPCIONES PARA INFORMES\n");
    printf("\t\t\t---------------------");
    printf("\n\t1-Mostrar los alquileres por cliente\n");
    printf("\t2-Mostrar los juegos por categoria\n");
    printf("\t3-Total de todos los importes pagados por cierto cliente\n");
    printf("\t4-Mostrar la recaudacion de una fecha particular\n");
    printf("\t5-Listar clientes que alquilaron un determinado juego\n");
    printf("\t6-Listar los telefonos de los clientes que alquilaron juegos en una determinada fecha\n");
    printf("\t7-Mostrar los juegos mas alquilados por hombres\n");
    printf("\t8-Cantidad de clientes por localidad\n");
    printf("\t9-Listar los juegos alquilados por mujeres\n");
    printf("\t10-Ganancia por localidad\n");
    printf("\t11-Listar los juegos que no han sido alquilados\n");
    printf("\t12-Listar clientes que no hayan alquilado ningun juego\n");
    printf("\t13-Volver a inicio\n");
    pedirNumero(&opcion, "\tIngrese la opcion: ", "Error, reingrese un numero valido: ", 1, 13, 10);
    return opcion;
}

void informes(eCliente clientes[], int tamcli, eJuego juegos[], int tamj, eAlquiler alquileres[], int tama, eCategoria categorias[], int tamca, eLocalidad localidades[], int taml){
    char seguir = 's';
    while(seguir == 's'){
        switch(menuInformes())
        {
        case 1:
            mostrarAlquileresPorClientes(clientes,tamcli,juegos, tamj, alquileres, tama, localidades, taml);
            break;
        case 2:
            juegosPorCategoriaMesa(juegos, tamj, categorias, tamca);
            break;
        case 3:
            acumularImportePorCliente(clientes, tamcli, juegos, tamj, alquileres, tama, localidades, taml);
            break;
        case 4:
            recaudacionPorFecha(alquileres, tama, juegos,tamj);
            break;
        case 5:
            listarClientesPorJuego(clientes, tamcli, juegos, tamj, alquileres, tama);
            break;
        case 6:
            telefonoPorFecha(alquileres, tama, juegos,tamj, clientes,tamcli);
            break;
        case 7:
            listarJuegosMasAlquiladosPorHombre(clientes,tamcli, juegos,tamj,alquileres, tama);
            break;
        case 8:
            cantidadClientesPorLocalidades(clientes,tamcli,localidades, taml);
            break;
        case 9:
            listarJuegosAlquiladosPorMujeres(clientes,tamcli,  juegos,tamj,alquileres, tama);
            break;
        case 10:
            recaudacionPorLocalidad(alquileres, tama, juegos,tamj, clientes,tamcli, localidades, taml);
            break;
        case 11:
            listarJuegosSinAlquiler(juegos,tamj, alquileres, tama);
            break;
        case 12:
            listarClientesSinAlquiler(clientes,tamcli, alquileres, tama);
            break;
        case 13:
                seguir = 'n';
            break;
        default:
            printf("Opcion incorrecta, reingrese una opcion valida");
            break;
        }
        system("pause");
    }

}

