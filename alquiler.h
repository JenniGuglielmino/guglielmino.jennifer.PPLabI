#include "fecha.h"
#include "juegos.h"
#include "cliente.h"
#ifndef ALQUILER_H_INCLUDED
#define ALQUILER_H_INCLUDED
typedef struct
{
    int codigoAlquiler;
    int codigoJuego;
    int codigoCliente;
    int isEmpty;
    eFecha fecha;
}eAlquiler;

/** \brief Busca un lugar indice libre para cargar un nuevo alquiler
 *
 * \param alquiler[] eAlquiler
 * \param tamA int
 * \return int retorna el numero del indice, si es -1 no hay lugar
 *
 */
int buscarLibreAlquiler(eAlquiler alquiler[], int tamA);

/** \brief Inicializa todos los valores de alquileres en vacio
 *
 * \param alquileres[] eAlquiler
 * \param tamA int
 * \return void
 *
 */
void inicializarAlquileres(eAlquiler alquileres[], int tamA);

/** \brief Pide los datos necesarios para dar de alta un alquiler
 *
 * \param alquiler[] eAlquiler
 * \param tamA int
 * \param clientes[] eCliente
 * \param tamCli int
 * \param juegos[] eJuego
 * \param tamJ int
 * \param pIdAlquiler int*
 * \param categorias[] eCategoria
 * \param tamC int
 * \return int 1 = todoOk / 0 = no se pudo hacer
 *
 */
int altaAlquiler(eAlquiler alquiler[], int tamA, eCliente clientes[], int tamCli, eJuego juegos[], int tamJ, int* pIdAlquiler, eCategoria categorias[], int tamC, eLocalidad localidades[], int taml);

/** \brief Baja logica del alquiler
 *
 * \param alquileres[] eAlquiler
 * \param tama int
 * \param clientes[] eCliente
 * \param tam int
 * \return int 1 = todoOk / 0 = no se pudo hacer
 *
 */
int bajaAlquilerXCliente(eAlquiler alquileres[], int tama, eCliente clientes[], int tam);


/** \brief Muestra un solo alquiler
 *
 * \param alquiler eAlquiler
 * \param tamA int
 * \param clientes[] eCliente
 * \param tamCli int
 * \param juegos[] eJuego
 * \param tamJ int
 * \return int 1 = todoOk / 0 = no se pudo hacer
 *
 */
int mostrarAlquiler(eAlquiler alquiler, int tamA, eCliente clientes[], int tamCli, eJuego juegos[], int tamJ);

/** \brief Muestra una lista de alquileres
 *
 * \param alquileres[] eAlquiler
 * \param tamA int
 * \param clientes[] eCliente
 * \param tamCli int
 * \param juegos[] eJuego
 * \param tamJ int
 * \return int 1 = todoOk / 0 = no se pudo hacer
 *
 */
int mostrarAlquileres(eAlquiler alquileres[], int tamA, eCliente clientes[], int tamCli, eJuego juegos[], int tamJ);
#endif // ALQUILER_H_INCLUDED
