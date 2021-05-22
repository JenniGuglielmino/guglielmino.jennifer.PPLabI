#include "localidad.h"
#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
typedef struct
{
    int codigo;
    char nombre[51];
    char apellido[51];
    char sexo;
    char telefono[21];
    eLocalidad localidad;
    int isEmpty;
}eCliente;

/** \brief Por defecto vacia la esctructura cliente
 *
 * \param clientes[] eCliente
 * \param tam int
 * \return int 1 = todoOk / 0 = no se pudo hacer
 *
 */
int inicializarCliente(eCliente clientes[], int tam);

/** \brief Pide los datos necesarios para cargar un nuevo cliente, hace incremental el id y setea el isEmpty en 0
 *
 * \param clientes[] eCliente
 * \param tam int
 * \param pId int*
 * \return int 1 = todoOk / 0 = no se pudo hacer
 *
 */
int altaCliente(eCliente clientes[], int tam, int* pId, eLocalidad localidades[], int taml);

/** \brief Busca un lugar libre para cargar un nuevo cliente
 *
 * \param clientes[] eCliente
 * \param tam int
 * \return int retorna el indice libre. Si es -1, no hay lugar
 *
 */
int buscarLibre(eCliente clientes[], int tam);

/** \brief Muestra una lista de clientes
 *
 * \param cliente[] eCliente
 * \param tam int
 * \return int 1 = todoOk / 0 = no se pudo hacer
 *
 */
int mostrarClientes(eCliente cliente[], int tam,eLocalidad localidades[], int taml);

/** \brief Muestra un solo cliente
 *
 * \param cliente eCliente
 * \return void
 *
 */
void mostrarCliente(eCliente cliente,eLocalidad localidades[], int taml);

/** \brief Busca un cliente ingresando su id
 *
 * \param clientes[] eCliente
 * \param tam int
 * \param codigo int
 * \return int 1 = todoOk / 0 = no se pudo hacer
 *
 */
int buscarCliente(eCliente clientes[], int tam, int codigo);

/** \brief Baja logica de un cliente
 *
 * \param clientes[] eCliente
 * \param tam int
 * \return int 1 = todoOk / 0 = no se pudo hacer
 *
 */
int bajaCliente(eCliente clientes[], int tam, eLocalidad localidades[], int taml);

/** \brief Modifica segun lo requerido los datos de un cliente
 *
 * \param clientes[] eCliente
 * \param tam int
 * \return int 1 = todoOk / 0 = no se pudo hacer
 *
 */
int modificarUno(eCliente clientes[], int tam, eLocalidad localidades[], int taml);

/** \brief Muestra un menu de modificaciones y pide el valor de la opcion
 *
 * \return int
 *
 */
int menuModificar();

/** \brief Ordena los clientes de manera descreciente por apellido y nombre
 *
 * \param clientes[] eCliente
 * \param tam int
 * \return int 1 = todoOk / 0 = no se pudo hacer
 *
 */
int ordenarClientes(eCliente clientes[], int tam);

/** \brief Toma una cadena de caracteres y la pasa a minusculas
 *
 * \param vect[] char
 * \return int 1 = todoOk / 0 = no se pudo hacer
 *
 */
int pasarStringAMinuscula(char vect[]);

/** \brief Reemplaza el id del cliente por su nombre
 *
 * \param codigoCliente int
 * \param clientes[] eCliente
 * \param tamC int
 * \param nombreCliente char*
 * \return int 1 = todoOk / 0 = no se pudo hacer
 *
 */
int cargarNombreCliente(int codigoCliente, eCliente clientes[], int tamC, char* nombreCliente);
#endif // CLIENTE_H_INCLUDED
