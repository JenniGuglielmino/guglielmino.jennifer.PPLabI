#include "cliente.h"
#include "alquiler.h"
#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

/** \brief Acumular la cantidad de juegos que hay en una categoria e informarlo
 *
 * \param juegos[] eJuego
 * \param tamj int
 * \param categorias[] eCategoria
 * \param tamc int
 * \return int return 1 si esta todo bien y 0 si no se pudo hacer
 *
 */
int juegosPorCategoriaMesa(eJuego juegos[], int tamj, eCategoria categorias[], int tamc);

/** \brief Informa el importa de cada cliente
 *
 * \param clientes[] eCliente
 * \param tamcli int
 * \param juegos[] eJuego
 * \param tamj int
 * \param alquileres[] eAlquiler
 * \param tamA int
 * \return void
 *
 */
int acumularImportePorCliente(eCliente clientes[], int tamcli, eJuego juegos[], int tamj, eAlquiler alquileres[], int tamA, eLocalidad localidades[], int taml);

/** \brief Busca los alquileres que tiene un cliente por id y los informa
 *
 * \param clientes[] eCliente
 * \param tamcli int
 * \param juegos[] eJuego
 * \param tamj int
 * \param alquiler[] eAlquiler
 * \param tama int
 * \return void
 *
 */
void mostrarAlquileresPorClientes(eCliente clientes[], int tamcli, eJuego juegos[], int tamj, eAlquiler alquiler[], int tama, eLocalidad localidades[], int taml);

/** \brief Recaudacion en cierta fecha ingresada
 *
 * \param alquileres[] eAlquiler
 * \param tamA int
 * \param juegos[] eJuego
 * \param tamJ int
 * \return void
 *
 */
void recaudacionPorFecha(eAlquiler alquileres[], int tamA, eJuego juegos[],int tamJ);

/** \brief Muestra la recaudacion por la localidad que ingrese el usuario
 *
 * \param alquileres[] eAlquiler
 * \param tamA int
 * \param juegos[] eJuego
 * \param tamJ int
 * \param clientes[] eCliente
 * \param tamcli int
 * \param localidades[] eLocalidad
 * \param tamlo int
 * \return void
 *
 */
void recaudacionPorLocalidad(eAlquiler alquileres[], int tamA, eJuego juegos[],int tamJ, eCliente clientes[], int tamcli, eLocalidad localidades[], int tamlo);

/** \brief lista los clientes con su respectivo juego alquilado
 *
 * \param clientes[] eCliente
 * \param tamC int
 * \param juegos[] eJuego
 * \param tamJ int
 * \param alquileres[] eAlquiler
 * \param tamA int
 * \return void
 *
 */
void listarClientesPorJuego(eCliente clientes[], int tamC, eJuego juegos[], int tamJ, eAlquiler alquileres[], int tamA);

/** \brief muestra los telefonos de los clientes que alquilaron en cierta fecha
 *
 * \param alquileres[] eAlquiler
 * \param tamA int
 * \param juegos[] eJuego
 * \param tamJ int
 * \param clientes[] eCliente
 * \param tamCli int
 * \return void
 *
 */
void telefonoPorFecha(eAlquiler alquileres[], int tamA, eJuego juegos[],int tamJ, eCliente clientes[], int tamCli);


/** \brief Busca un juego solo ingresando su id
 *
 * \param juegos[] eJuego
 * \param tamJ int
 * \param idBuscado int
 * \return int
 *
 */
int buscarJuegoPorId(eJuego juegos[], int tamJ, int idBuscado);


/** \brief Muestra los juegos mas alquilados por hombres
 *
 * \param clientes[] eCliente
 * \param tamC int
 * \param juegos[] eJuego
 * \param tamJ int
 * \param alquileres[] eAlquiler
 * \param tamA int
 * \return void
 *
 */
void listarJuegosMasAlquiladosPorHombre(eCliente clientes[], int tamC, eJuego juegos[], int tamJ, eAlquiler alquileres[], int tamA);


/** \brief Gestionar el menu de informes segun la opcion ingresada
 *
 * \param clientes[] eCliente
 * \param tamcli int
 * \param juegos[] eJuego
 * \param tamj int
 * \param alquileres[] eAlquiler
 * \param tama int
 * \param categorias[] eCategoria
 * \param tamca int
 * \return void
 *
 */
void informes(eCliente clientes[], int tamcli, eJuego juegos[], int tamj, eAlquiler alquileres[], int tama, eCategoria categorias[], int tamca, eLocalidad localidades[], int taml);


/** \brief Muestra la cantidad de clientes que hay en la localidad ingresada
 *
 * \param clientes[] eCliente
 * \param tamcli int
 * \param localidades[] eLocalidad
 * \param tamlo int
 * \return void
 *
 */
void cantidadClientesPorLocalidades(eCliente clientes[], int tamcli, eLocalidad localidades[], int tamlo);

/** \brief Muestra el menu de informes y pide una opcion
 *
 * \return int
 *
 */
int menuInformes();


/** \brief Enlista los juegos que fueron alquilados por mujeres
 *
 * \param clientes[] eCliente
 * \param tamC int
 * \param juegos[] eJuego
 * \param tamJ int
 * \param alquileres[] eAlquiler
 * \param tamA int
 * \return void
 *
 */
void listarJuegosAlquiladosPorMujeres(eCliente clientes[], int tamC, eJuego juegos[], int tamJ, eAlquiler alquileres[], int tamA);

/** \brief Muestra los juegos que no fueron alquilados
 *
 * \param juegos[] eJuego
 * \param tamJ int
 * \param alquileres[] eAlquiler
 * \param tamA int
 * \return void
 *
 */
void listarJuegosSinAlquiler(eJuego juegos[], int tamJ, eAlquiler alquileres[], int tamA);

/** \brief Muestra los clientes que no alquilaron ningun juego
 *
 * \param clientes[] eCliente
 * \param tamJ int
 * \param alquileres[] eAlquiler
 * \param tamA int
 * \return void
 *
 */
void listarClientesSinAlquiler(eCliente clientes[], int tamJ, eAlquiler alquileres[], int tamA);

#endif // INFORMES_H_INCLUDED
