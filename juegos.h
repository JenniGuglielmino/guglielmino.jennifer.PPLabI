#include "categoria.h"
#ifndef JUEGOS_H_INCLUDED
#define JUEGOS_H_INCLUDED
typedef struct
{
    int codigo;
    char descripcion[20];
    float importe;
    eCategoria idCategoria;
}eJuego;

/** \brief Muestra un juego
 *
 * \param juego eJuego
 * \param categorias[] eCategoria
 * \param tamC int
 * \return int 1 = todo ok / 0 = No hay juegos
 *
 */
int mostrarJuego(eJuego juego, eCategoria categorias[], int tamC);

/** \brief Muestra una lista de juegos
 *
 * \param juegos[] eJuego
 * \param tamJ int
 * \param categorias[] eCategoria
 * \param tamC int
 * \return void
 *
 */
void mostrarJuegos(eJuego juegos[], int tamJ, eCategoria categorias[], int tamC);

/** \brief Busca un juego por su codigo
 *
 * \param juegos[] eJuego
 * \param tamJ int
 * \param id int
 * \return int 1 = todo ok / 0 = algo salio mal
 *
 */
int buscarJuegos(eJuego juegos[], int tamJ, int id);

/** \brief Reemplaza el codigo del juego por su descripcion
 *
 * \param idJuego int
 * \param juegos[] eJuego
 * \param tams int
 * \param nombreJuego char*
 * \return int 1 = todo ok / 0 = algo salio mal
 *
 */
int cargarNombreJuegos(int idJuego, eJuego juegos[], int tams, char* nombreJuego);
#endif // JUEGOS_H_INCLUDED
