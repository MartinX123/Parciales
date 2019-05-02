#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "f_biblio.h"


/**
* brief Imprime por pantalla el Menu del programa
* param -
* return -
*/
void Menu()
{
    char msj[400] = "**************************************************************\
\n\n\t\t\tMENU\n\n\
**************************************************************\n\n";
    printf("%-s", msj);
    printf("\tSeleccione opcion: \n\n\r\t1- ALTA DE PROGRAMADOR\n\r\t2- MODIFICAR DATOS DEL PROGRAMADOR\
           \n\r\t3- BAJA DEL PROGRAMADOR\n\r\t4- ASIGNAR PROGRAMADOR A PROYECTO\n\r\
        5- LISTADO DE PROGRAMADORES\n\r\t6- LISTADO DE PROYECTOS\n\r\t7- PROYECTOS DE PROGRAMADOR SELECCIONADO\
DE LA LISTA DE PROGRAMADORES\n\r\t8- PROYECTO DEMANDANTE\n\r\t9- AYUDA\n\r\t10- SALIR");
}



/**
* brief Valida que una cadena de caracteres este compuesta solamente por letras
* param char str Array de tipo char a evaluar
* return Un 0 si la cadena de caracteres no contiene letras o espacio en blanco
*        un 1 si la verificacion dio fue exitosa
*/
int soloLetras(char str[20])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        {
            return 0;
        }
       i++;
    }
   return 1;
}

/**
* brief valida que la cadena de caracteres ingresada sea un numero
* param char str La cadena de caracteres a ser evaluada
* return Un 0 si detecta un error, un 1 si la verificacion fue exitosa
*/
int validEdad(char str[5])
{
    int i = 0;

    while(str[i] != '\0')
    {
       if((str[i] < '0') || (str[i] > '9'))
            return 0;
       i++;
    }
   return 1;
}

/**
* brief Valida una edad en un rango minimo y maximo
* param char str[] Cadena de caracteres que contiene la edad a evaluar
* int lowLimit Limite inferior a evaluar
* int hiLimit Limite superior a evaluar
* return Un 0 si el dato ingresado esta fuera del rango solicitado
*        Un 1 si la verificacion fue correcta
*/
int validRangoEtario(char str[5], int lowLimit, int hiLimit)
{
    int aux = atoi(str);
    if((aux < lowLimit) || (aux > hiLimit))
        {
            return 0;
        }

    return 1;
}

/**
* brief Valida que la cadena de caracteres ingresada sea numerica y tenga una extension de entre 7 a 9 digitos.
* param char str[] array de tipo char que contiene la cadena de caracteres a ser evaluada
* return Un 0 si el dato ingresado no es un numero de 7 a 9 digitos
*        Un 1 si la verificacion es exitosa
*/
int validDni(char str[])
{
    int n;
    n = strlen(str);
    if((n < 7) || (n > 9))
        if(!(soloNumeros(str)))
            return 0;
    return 1;
}

/**
* brief Valida que la cadena de caracteres ingresada sea numerica
* param char str[] Array de tipo char. Contiene la cadena de caracteres a ser evaluada
* return Un 0 si el dato ingresado no es numerico
*        Un 1 si la verificacion fue exitosa
*/
int soloNumeros(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if((str[i] < '0') || (str[i] > '9'))
            return 0;
        i++;
    }
    return 1;
}
/**
* brief Valida que la cadena de caracteres ingresada conteng letras y numeros sin espacios.
* param str[] Cadena de caracteres a evaluar
* return 0 si da error
*         1 si la verificacion fue exitosa
*/
int alphaNum(char str[8])
{
    int i;
    while(str[i] != '\0')
    {
        if(((str[i] < '0') || (str[i] > '9')) && ((str[i] < 'a') || (str[i] > 'z')) && ((str[i] < 'A') || (str[i] > 'Z')))
            return 0;
        i++;
    }
    return 1;
}

void getString(char* str[], char msj[])
{
    fflush(stdin);
    printf(msj);
    scanf("%s", *str);
}

/*void getDni(char msj[], char Emsj[], char* input[20])
{
    char aux[20];
    do{
        fflush(stdin);
        printf("\n%s", msj);
        scanf("%s", aux);
        if(!validDni(aux))
        {
            if(!soloNumeros(aux))
                printf("\n%s", Emsj);
        }
        else
            break;
    }while(1);

    input = &aux;
}*/



/*int getInt(menu opcion;)
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}*/
