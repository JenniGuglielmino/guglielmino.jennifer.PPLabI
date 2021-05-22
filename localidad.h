
#ifndef LOCALIDAD_H_INCLUDED
#define LOCALIDAD_H_INCLUDED
typedef struct
{
    int id;
    char descripcion[20];
}eLocalidad;


/** \brief Muestra una lista de localidades
 *
 * \param localidades[] elocalidades
 * \param tam int
 * \return void
 *
 */
void mostrarLocalidades(eLocalidad localidades[], int tam);

/** \brief Muestra las localidades de acuerdo a su id
 *
 * \param localidades[] elocalidades
 * \param tam int
 * \return void
 *
 */
int cargarNombreLocalidad(int idLocalidad, eLocalidad localidades[], int taml, char* nombreLocalidad);


/** \brief Muestra una localidad
 *
 * \param localidades eLocalidad
 * \return void
 *
 */
void mostrarLocalidad(eLocalidad localidad);
#endif // LOCALIDAD_H_INCLUDED
