#include "fecha.h"
#include "cliente.h"
#include "alquiler.h"
#ifndef DATAWAREHOUSE_H_INCLUDED
#define DATAWAREHOUSE_H_INCLUDED

/** \brief Carga datos en la estructura eAlquiler para realizar pruebas de programa
 *
 * \param alquileres[] eAlquiler
 * \param tam int
 * \param cant int
 * \param pIdAlquiler int*
 * \return int 1 = todoOk / 0 = no se pudo hacer
 *
 */
int harcodearAlquileres(eAlquiler alquileres[], int tam, int cant, int* pIdAlquiler);

/** \brief Carga datos en la estructura eAlquiler para realizar pruebas de programa
 *
 * \param clientes[] eCliente
 * \param tam int
 * \param cant int
 * \param pCodigoCliente int*
 * \return int 1 = todoOk / 0 = no se pudo hacer
 *
 */
int harcodearClientes(eCliente clientes[], int tam, int cant, int* pCodigoCliente);
#endif // DATAWAREHOUSE_H_INCLUDED
