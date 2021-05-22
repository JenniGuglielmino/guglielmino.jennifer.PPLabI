#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn_guglielmino.h"
#include "cliente.h"
#define RESET   "\033[0m"
#define BOLDRED     "\033[1m\033[31m"
int inicializarCliente(eCliente clientes[], int tam){
    int retorno = 0;
    if(clientes != NULL && tam>0){
        for(int i = 0; i<tam; i++){
            clientes[i].isEmpty = 1;
        }
        retorno = 1;
    }
    return retorno;
}

int altaCliente(eCliente clientes[], int tam, int* pId, eLocalidad localidades[], int taml){
    int todoOk = 0;
    int indice;
    eCliente auxCliente;
    if(clientes != NULL && tam > 0 && pId != NULL){
        system("cls");
        printf("\n\n\t\t\t1.Alta cliente\n");
        printf("\t\t\t==============");

        indice = buscarLibre(clientes, tam);
        if(indice == -1)
        {
            printf("\n\tNo hay lugar en el sistema\n");
        }
        else{
                auxCliente.codigo = *pId;

               pedirString(auxCliente.nombre, "\n\t\tIngrese nombre: ", 51);

                pedirString(auxCliente.apellido, "\t\tIngrese apellido: ", 51);

                pedirString(auxCliente.telefono,"\t\tIngrese el numero de telefono: ", 21);

                pedirSexo(&auxCliente.sexo, "\t\tIngrese sexo: ", "\t\tError, sexos validos 'f', 'm'\n", 20);
                mostrarLocalidades(localidades, taml);
                pedirNumero(&auxCliente.localidad.id, "\t\tIngrese id de localidad: ", "\t\tError, id invalido", 1, 10,20);

                auxCliente.isEmpty = 0;
                clientes[indice] = auxCliente;
                (*pId)++;
                todoOk = 1;
        }
    }
    return todoOk;
}

int bajaCliente(eCliente clientes[], int tam, eLocalidad localidades[], int taml){
        int todoOk=0;
        int indice;
        int codigo;
        char confirma;

        system("cls");
        printf("\n\n\t\t\t\t\t\t3.Baja Clientes\n");
        printf("\t\t\t\t\t\t====================\n");
        if(mostrarClientes(clientes, tam, localidades, taml))
        {
            pedirNumero(&codigo, "\n\t\tIngrese el codigo del cliente: ", "\t\tError, codigo incorrecto\n", 200, 10000000, 10);

            indice = buscarCliente(clientes, tam, codigo);

            if(indice == -1){
                printf("\t\tNo existe un cliente con ese id %d\n\n", codigo);
            }
            else{
                mostrarCliente(clientes[indice], localidades, taml);

                pedirChar(&confirma, "\n\tConfirma baja?: ", "\t\tError ingrese un caracter valido\n", 10);

                if(confirma == 's' || confirma == 'S'){
                    clientes[indice].isEmpty = 1;
                    todoOk = 1;
                }
                else{
                    printf("\n\tBaja cancelada por el usuario\n");
                }
            }
        }
        return todoOk;
}

int buscarLibre(eCliente clientes[], int tam){
    int indice = -1;
    if(clientes != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(clientes[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int buscarCliente(eCliente clientes[], int tam, int codigo){
     int indice = -1;
        if(clientes != NULL && tam > 0)
        {
            for(int i=0; i<tam; i++)
            {
                if(!clientes[i].isEmpty &&  clientes[i].codigo == codigo)
                {
                    indice = i;
                    break;
                }
            }
        }
        return indice;
}

void mostrarCliente(eCliente cliente, eLocalidad localidades[], int taml){
    char nombreLocalidad[20];
    cargarNombreLocalidad(cliente.localidad.id, localidades, taml, nombreLocalidad);
    printf("\n\t|%10d|%20s|%20s|%10c|%15s|%20s|",
           cliente.codigo,
           cliente.nombre,
           cliente.apellido,
           cliente.sexo,
           cliente.telefono,
           nombreLocalidad);
}

int mostrarClientes(eCliente cliente[], int tam, eLocalidad localidades[], int taml){
    int flag = 0;
    printf("\n\n\t\t\t\t\t\tLista de clientes\n");
    printf("\t--------------------------------------------------------------------------------------------\n");
    printf("\t  Codigo\t\tNombre\t\tApellido\tSexo\t\tTelefono\tLocalidad\n");
    printf("\t----------------------------------------------------------------------------------------------");
    for(int i=0; i<tam; i++)
    {
        if( !cliente[i].isEmpty )
        {
            mostrarCliente(cliente[i], localidades, taml);
            flag = 1;
        }
    }
    if(!flag){
        printf(BOLDRED "\n\t\tNo hay clientes en la lista" RESET);
    }
    printf("\n\n");
    return flag;
}

int ordenarClientes(eCliente clientes[], int tam){
    int todoOk=0;
    eCliente auxCliente;
    char nombreI[51];
    char nombreJ[51];
    char apellidoI[51];
    char apellidoJ[51];
    if(clientes!=NULL && tam > 0)
    {
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                strcpy(nombreI, clientes[i].nombre);
                strcpy(nombreJ, clientes[j].nombre);
                strcpy(apellidoI, clientes[i].apellido);
                strcpy(apellidoJ, clientes[j].apellido);
                pasarStringAMinuscula(nombreI);
                pasarStringAMinuscula(nombreJ);
                pasarStringAMinuscula(apellidoI);
                pasarStringAMinuscula(apellidoJ);
                if (strcmp(apellidoI, apellidoJ) > 0 || (strcmp(apellidoI, apellidoJ) == 0 && strcmp(nombreI, nombreJ) > 0))
                {
                    auxCliente = clientes[i];
                    clientes[i] = clientes[j];
                    clientes[j] = auxCliente;
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int pasarStringAMinuscula(char vect[])
{
    int retorno = 0;
    if (vect != NULL)
    {
        for (int i = 0; i < strlen(vect); i++)
        {
            vect[i] = tolower(vect[i]);
            retorno = 1;
        }
    }
    return retorno;
}

int modificarUno(eCliente clientes[], int tam, eLocalidad localidades[], int taml) {
	eCliente auxiliar;
	int todoOk = 0;
	int opcion;
	int indice;
	int codigo;
	char seguir = 's';
    int flagNombre = 0;
	int flagApellido = 0;
	int flagSexo = 0;
	int flagTelefono = 0;
    int flagLocalidad = 0;
    system("cls");
    printf("\n\n\t\t\t\t\t\t2.Modificar cliente\n");
    printf("\t\t\t\t\t\t===================\n");
    if(mostrarClientes(clientes, tam, localidades, taml))
    {
        printf("\tIngrese codigo: ");
        scanf("%d", &codigo);

        if(clientes != NULL && tam >0)
        {
            indice = buscarCliente(clientes, tam, codigo);

            if(indice == -1){
                printf("\t\tNo se encontro el cliente ingresado");
            }
            else{
                printf("\n\t  codigo\t\tNombre\t\tApellido\tSexo\t\tTelefono\n");
                printf("\t---------------------------------------------------------------------------------");
                mostrarCliente(clientes[indice], localidades, taml);
                do{
                    opcion = menuModificar();
                    switch(opcion)
                        {
                        case 1:
                                pedirString(auxiliar.nombre, "\t\tIngrese el nuevo nombre:", 51);
                                flagNombre = 1;
                            break;
                        case 2:
                               pedirString(auxiliar.apellido, "\t\tIngrese el nuevo apellido:",51);
                                flagApellido = 1;
                            break;
                        case 3:
                               pedirSexo(&auxiliar.sexo, "\t\tIngrese sexo: ", "\t\tError, reingrese un sexo valido\n",  20);
                                flagSexo = 1;
                            break;
                        case 4:
                                pedirString(auxiliar.telefono, "\t\tIngrese el nuevo telefono:", 21);
                                flagTelefono = 1;
                            break;
                        case 5:
                                mostrarLocalidades(localidades, taml);
                                pedirNumero(&auxiliar.localidad.id, "\t\tIngrese id de la localidad:", "\t\tError, reingrese un numero valido\n", 1, 10, 21);
                                flagLocalidad = 1;
                            break;
                        case 6:
                                if(flagNombre)
                                {
                                    strcpy(clientes[indice].nombre, auxiliar.nombre);
                                }
                                if(flagApellido)
                                {
                                    strcpy(clientes[indice].apellido, auxiliar.apellido);
                                }

                                if(flagSexo)
                                {
                                    clientes[indice].sexo=auxiliar.sexo;
                                }
                                if(flagTelefono)
                                {
                                    strcpy(clientes[indice].telefono, auxiliar.telefono);
                                }
                                if(flagLocalidad)
                                {
                                    clientes[indice].localidad.id = auxiliar.localidad.id;
                                }
                                mostrarCliente(clientes[indice], localidades, taml);
                                todoOk = 1;
                                seguir = 'n';
                            break;
                        }
                    }while(seguir == 's');
            }

        }
    }
	return todoOk;
}


int menuModificar(){
    int opcion;
    printf("\n\n\t\t\tMENU DE MODIFICACIONES\n");
    printf("\t\t\t--------------------");
    printf("\n\t1. Nombre.\n");
    printf("\t2. Apellido.\n");
    printf("\t3. Sexo.\n");
    printf("\t4. Telefono.\n");
    printf("\t5. Localidad.\n");
    printf("\t6. Guardar cambios y salir.\n");
    pedirNumero(&opcion, "\tIngrese la opcion: ", "\t\tError, reingrese un numero valido\n", 1, 6, 100);
    return opcion;
}

int cargarNombreCliente(int codigoCliente, eCliente clientes[], int tamC, char* nombreCliente){
        int todoOk = 0;
        if(clientes != NULL && tamC  > 0 && nombreCliente != NULL){
            for(int i=0; i<tamC; i++){
                if(clientes[i].codigo == codigoCliente && clientes[i].isEmpty == 0){
                    strcpy(nombreCliente, clientes[i].nombre);
                    todoOk = 1;
                    break;
                }
            }
        }
        return todoOk;
}
