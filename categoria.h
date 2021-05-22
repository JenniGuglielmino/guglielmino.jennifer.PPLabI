#ifndef CATEGORIA_H_INCLUDED
#define CATEGORIA_H_INCLUDED
typedef struct
{
    int id;
    char descripcion[51];
}eCategoria;

/** \brief Reemplaza el id de la categoria por su nombre
 *
 * \param idCategoria int
 * \param categorias[] eCategoria
 * \param tamC int
 * \param char*nombreCategoria
 * \return int 1 si esta todo bien/0 si algo salio mal
 *
 */
int cargarNombreCategoria(int idCategoria, eCategoria categorias[], int tamC, char*nombreCategoria);

/** \brief Muestra las categorias
 *
 * \param categorias[] eCategoria
 * \param tamc int
 * \return void
 *
 */
void mostrarCategorias(eCategoria categorias[], int tamc);

/** \brief Muestra una categoria
 *
 * \param categoria eCategoria
 * \return void
 *
 */
void mostrarCategoria(eCategoria categoria);
#endif // CATEGORIA_H_INCLUDED
