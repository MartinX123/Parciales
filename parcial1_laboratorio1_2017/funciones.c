#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "f_biblio.h"
#include "asignarProyect.h"


/**
* brief Inicializa un array de tipo Epersona cargando un valor ingresado por parametro en el campo .estado
* param Epersona Contactos[] Array de tipo Epersona. Es el Array a inicializar
* param int cant_Contactos Es la cantidad de elementos del array de tipo Epersona
* param int valor Es el valor a cargar en el campo .estado del array de tipo Epersona
* return -
*/
void inicializarArrayProgramadores(Eprogramador Programadores[], int cant_Programadores, int valor)
{
    int i;
    for(i = 0; i < cant_Programadores; i++)
    {
        Programadores[i].estado = valor;
    }
}

/**
* brief Busca el primer lugar libre en un array de tipo Epersona
* param int cant_Contactos es la cantidad de elementos del array de tipo Epersona
* param int valor es valor del estado que debe tener elemento libre del array de tipo Epersona
* return si encuentra un lugar libre, devuelve la posicion del mismo, sino retorna -1
*/
int findEmptyPlace(Eprogramador Programadores[], int cant_Programadores, int valor)
{
    int i;
    for(i = 0; i < cant_Programadores; i++)
    {
        if(Programadores[i].estado == valor)
            return i;
    }
    return -1;
}

/**
* brief Carga los datos por teclado en una variable auxiliar de tipo Eprogramador
* param -
* return La variable de tipo Eprogramador con todos sus campos cargados
*/
Eprogramador getProgramador(void)
{
    Eprogramador auxProgramador;
    char auxId[5], auxNombre[20];
    char auxApellido[20], auxIdCategoria;
    int auxIdInt;

        do{
            fflush(stdin);
            printf("Ingrese el Id del Programador: ");
            scanf("%s", auxId);
            if(!soloNumeros(auxId))
                printf("El Id debe estar compuesto solamente por numeros");
            else{
                auxIdInt = atoi(auxId);
                fflush(stdin);
                break;
            }
        }while(1);
        do{
            printf("Ingrese Nombre: ");
            gets(auxNombre);

            if(!soloLetras(auxNombre))
                printf("El nombre debe contener solamente letras\n");
            else
                break;
        }while(1);
        do{
            printf("Ingrese Apellido: ");
            scanf("%s", auxApellido);
            if(!soloLetras(auxApellido))
                printf("El apellido debe contener solamente letras\n");
            else
                break;
        }while(1);
        do{
            fflush(stdin);
            printf("Ingrese Id Categoria del Programador:\n\t0- JUNIOR\n\t1- SEMISENIOR\n\t2- SENIOR\n");
            scanf("%c", &auxIdCategoria);
           while(1)
           {
            if((validIdCategoria(auxIdCategoria)) == -1)
            {
                printf("\n\t0- JUNIOR\n\t1- SEMISENIOR\n\t2- SENIOR\n");
                scanf("%c", &auxIdCategoria);
            }
            else
                break;
           }
           break;
        }while(1);

        auxProgramador.Id = auxIdInt;
        strcpy(auxProgramador.Nombre, auxNombre);
        strcpy(auxProgramador.Apellido, auxApellido);
        auxProgramador.IdCategoria = auxIdCategoria;
        auxProgramador.estado = 1;


    return (auxProgramador);
}

/**
* brief Busca un programador en un array de tipo Eprogramador a partir de su DNI
* param char msj[] es la cadena de caracteres a evaluar
* param char Emsj[] es la cadena de caracteres con el mensaje de error
* param Eprogramador Programadores[] Es el array donde buscar el contacto
* param int cant_Contactos Es la cantidad de elementos del array de tipo Epersona
* param char fail es la cadena de caracteres si no se encontro el contacto ingresado
* return la posicion en el array del contacto buscado
*        -1 si no encuentra el programador a buscar
*/
int buscarProgramador(char msj[], char Emsj[], Eprogramador Programadores[], int cant_Programadores, char fail[])
{
    int i, auxInt;
    char aux[5];
    do{
        printf("\n%s", msj);
        scanf("%s", aux);
        if(!soloNumeros(aux))
        {
            printf("%s", Emsj);
        }
        else
            auxInt = atoi(aux);
            break;
    }while(1);
    for(i = 0; i < cant_Programadores; i++)
    {
        if(auxInt == Programadores[i].Id)
            return i;

    }
    printf("%s", fail);

    return -1;
}

/**
* brief muestra la lista de programadores
* param Un array de tipo Eprogramador con los programadores ingresados
* param int cant_Programadores la cantidad de elementos del array
* return -
**/
void mostrarProgramadores(Eprogramador Programadores[], int cant_Programadores)
{
    int i;
    for(i = 0; i < cant_Programadores; i++)
    {
       /* if(!(Programadores[i].estado == 0))
            printf("Nombre:\t\t%-s\nApellido:\t%-s\nEdad:\t\t%-s\nDNI:\t\t%-.f\n\n", Programadores[i].Nombre, Programadores[i].Apellido, Programadores[i]., Contactos[i].Dni);*/
    }
}

/**
* brief Pide ingresar por teclado la categoria del programador y devuelve
        el valor de la hora paga según la categoría del programador ingresada
* param char msj El mensaje solicitando el dato. En este caso pidiendo al usuario que ingrese
*                la categoría del programador
* return la variable aux con el valor de la hora
*/
int pago_por_hora(char msj[50])
{
    int aux;
    enum categorias_programador cat;
    scanf("%u", &cat);
    switch(cat)
    {
        case JUNIOR:
            aux = 500;
            break;
        case SEMISENIOR:
            aux = 750;
            break;
        case SENIOR:
            aux = 1500;
            break;
        default: { break; }
    }
    return(aux);
}

/**
* brief Valida que el dato ingresado corresponda con las categorias definidas en la enum categorias_programador
* param char c el caracter ingresado por teclado
* return JUNIOR  Si el dato ingresado es 0, SEMISENIOR Si el dato ingresado es 1,
*        SENIOR  Si el dato ingresado es 2,
*         -1 Si el dato no corresponde con ninguna de las categorias
*/
int validIdCategoria(char c)
{
      switch(c)
    {
        case '0':
            return JUNIOR;
        case '1':
            return SEMISENIOR;
        case '2':
            return SENIOR;
        default:
           return -1;
    }
}

/**
* brief Modifica los datos de un programador a eleccion del usuario del listado de programadores dados de ALTA
* param -
* return un elementoo de tipo Eprogramador con los nuevos datos
*/
Eprogramador modificarDatosProgramador(void)
{
    Eprogramador auxProgramador;
    printf("\t\tQue dato desea modificar?\n\n1- MODIFICAR ID DE PROGRAMADOR\n2- MODIFICAR NOMBRE y APELLIDO\n\
            3- MODIFICAR ID DE CATEGORIA\n");
    char o = ' ';
    char auxId[5], auxNombre[20], auxApellido[20], auxIdCategoria =' ';
    int auxIdInt;
    do{
        o = getchar();

    }while((o < '1') || (o > '3'));
    do{
    switch(o)
    {
        case '1':
        {
            do{
            printf("Ingrese el Id del programador: ");
            scanf("%s", auxId);
            if(!soloNumeros(auxId))
                printf("El Id debe estar compuesto solamente por numeros");
            else
                auxIdInt = atoi(auxId);
                auxProgramador.Id = auxIdInt;
                break;
            }while(1);
        }
        case '2':
        {
            do{
                fflush(stdin);
                printf("Ingrese Nombre: ");
                gets(auxNombre);

                if(!soloLetras(auxNombre))
                    printf("El nombre debe contener solamente letras\n");
                else
                    break;
            }while(1);
            do{
                printf("Ingrese Apellido: ");
                scanf("%s", auxApellido);
                if(!soloLetras(auxApellido))
                    printf("El apellido debe contener solamente letras\n");
                else
                    break;
            }while(1);
            strcpy(auxProgramador.Nombre, auxNombre);
            strcpy(auxProgramador.Apellido, auxApellido);
            break;
        }
        case '3':
        {
           do{
                printf("Ingrese Id Categoria del Programador:\n\t0- JUNIOR\n\t1- SEMISENIOR\n\t2- SENIOR\n");
                scanf("%c", &auxIdCategoria);
                while(1)
                {
                    if(!validIdCategoria(auxIdCategoria))
                    {
                        printf("\n\t0- JUNIOR\n\t1- SEMISENIOR\n\t2- SENIOR\n");
                        scanf("%c", &auxIdCategoria);
                    }
                    else
                        break;
                }
                //strcpy(auxProgramador.IdCategoria, auxIdCategoria);
                auxProgramador.Id = auxIdCategoria;
                break;
            }while(1);

            break;
        }
    }
    char seguir = ' ';
    printf("\n\nDesea modificar otro dato?s/n");
    seguir = getchar();
    if(seguir == 's')
    {
        printf("\n1- MODIFICAR ID DE PROGRAMADOR\n2- MODIFICAR NOMBRE y APELLIDO\n\
            3- MODIFICAR ID DE CATEGORIA\n");
        o = getchar();
    }
    else
    {
        auxProgramador.estado = 1;
        break;
    }

    }while(!(o < '1') || (o > '3'));
    return(auxProgramador);
}









