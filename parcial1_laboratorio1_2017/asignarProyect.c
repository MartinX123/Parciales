#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "f_biblio.h"
#include "asignarProyect.h"


/**
* brief Inicializa todos los elementos del array de tipo estructura Proyectos pasando le un valor al campo estado
* param eProyectos Proyectos[] Array de tipo de datos eProyectos
* param int cant_Proyectos es la cantidad de elementos del array
* param int valor El valor a cargar en el campo estado del arrayr
* return -
*/
void inicializarArrayProyectos(eProyectos Proyectos[], int cant_Proyectos, int valor)
{
    int i;
    for(i = 0; i < cant_Proyectos; i++)
    {
        Proyectos[i].estado = valor;
    }
}

/**
* brief Busca en el array de tipo estructura Proyectos el primer elemento vacio
* param eProyectos Proyectos[] Array de tipo eProyectos
* param int cant_Proyectos Cantidad de elementos del Array Proyectos
* param int valor Es el valor a buscar en el campo estado de cada elemento del array Proyectos
* return la posicion del ellemento libre dentro del array, -1 si no encontro ningun elemento disponible
*/
int buscarLugarArrayProyecto(eProyectos Proyectos[], int cant_Proyectos, int valor)
{
    int i;
    for(i = 0; i < cant_Proyectos; i++)
    {
        if(Proyectos[i].estado == valor)
            return i;
    }
    return -1;
}
/**
* brief Carga los datos en un elemento del array de tipo estructura eProyectos y asigna el/los
*       programador/es al proyecto
* param -
* return Un elemento de tipo estructura eProyecto con todos sus campos validados y cargados
*/
eProyectos getProyecto()
{
    char auxIdProyect[5], auxNameProyect[30], auxCant_Horas[3], auxIdProgramadorChar[5];
    int auxIdProgramador[5], auxIdCatProg, r, cont = 0, auxIdProyectInt;
    eProyectos auxProyecto;
        do{
            printf("Ingrese el Id del Proyecto: ");
            scanf("%s", auxIdProyect);
            if(!soloNumeros(auxIdProyect))
                printf("El Id debe estar compuesto solamente por numeros");
            else
            {
                auxIdProyectInt = atoi(auxIdProyect);
                fflush(stdin);
                break;
            }
        }while(1);
         do{
            fflush(stdin);
            printf("Ingrese el Nombre del Proyecto: ");
            gets(auxNameProyect);

            if(!soloLetras(auxNameProyect))
                printf("El nombre debe contener solamente letras\n");
            else
                break;
        }while(1);
         do{
            char c = ' ';
            printf("Ingrese Id de la Categoria:\n\t0- JUNIOR\n\t1-SEMISENIOR\n\t2- SENIOR ");
            c = getchar();
            r = validIdCategoria(c);
            if(r == -1)
                printf("No ha ingresado la opcion correcta \n\t0- JUNIOR\n\t1-SEMISENIOR\n\t2- SENIOR ");
            else
            {
                auxIdCatProg = r;
                break;
            }
        }while(1);
        do{
            printf("Ingrese la cantidad de horas que demandará la realizacion del Proyecto: ");
            scanf("%s", auxCant_Horas);
            if(!soloNumeros(auxCant_Horas))
                printf("No ha ingresado una opcion valida");
            else
            {
                atoi(auxCant_Horas);
                break;
            }
        }while(1);
         do{
                char c = ' ';
                do{
                    int i = 0;
                    fflush(stdin);
                    printf("Ingrese el Id del/los Programador/es asignado/s al proyecto: ");
                    scanf("%s", auxIdProgramadorChar);
                    if(!soloNumeros(auxIdProgramadorChar))
                        printf("El Id debe estar compuesto solamente por numeros");
                    else
                    {
                        auxIdProgramador[i] = atoi(auxIdProgramadorChar);
                    }
                    printf("Desea asignar otro programador al proyecto? s/n");
                    fflush(stdin);
                    scanf("%c", &c);
                    if(c == 's')
                        i++;
                    else
                        cont = i + 1;
                        break;
                }while(c == 's');
            break;
        }while(1);

        auxProyecto.Id = auxIdProyectInt;
        strcpy(auxProyecto.Nombre, auxNameProyect);
        auxProyecto.IdCategoria = auxIdCatProg;
        auxProyecto.cant_horas = auxCant_Horas;
        int i;
        for(i = 0; i < cont; i++)
        {
            auxProyecto.idProgramadores[i] = auxIdProgramador[i];
        }
        auxProyecto.estado = 1;
}

/**
* brief Pide el id por pantalla del programador a consultar. Recorre el array de Programadores. Recorre el array de Proyectos
*       e imprime por pantalla el nombre del programador y los proyectos a los que fue asignado
* param Eprogramador Programadores[] array de tipo de datos Eprogramador
* param eProyectos Proyectos[]array de tipo de datos eProyectos
* param int cant_progs Cantidad de elementos del array de Programadores
* param int cant_proys Cantidad de elementos del array de Proyectos
* return -
*/
void mostrarProyectos_x_Programador(Eprogramador Programadores[5], eProyectos Proyectos[10], int cant_progs, int cant_proys)
{
    char auxIdProgramadorChar[5];
    int auxIdProgramador, index, i, j, flag = 1;
    do{
        do{
            printf("Ingrese el Id del programador del que desea consultar sus proyectos asignados: ");
            fflush(stdin);
            scanf("%s", auxIdProgramadorChar);
            if(!soloNumeros(auxIdProgramadorChar))
                printf("El Id debe ser un dato numerico!!!");
            else
                break;
        }while(1);
        auxIdProgramador = atoi(auxIdProgramadorChar);


        do{
            if(Programadores[i].Id == auxIdProgramador)
            {
                index = i;
                break;
            }
            else
                i++;
            if(i == cant_progs)
                flag = 0;
        }while(flag == 1);

        if(flag == 0)
            printf("El Id ingresado no coincide con ninguno de los programadores dados de alta");
        else
        {
            printf("\rLos proyectos asignados al programador %s %s son: ", Programadores[index].Nombre, Programadores[index].Apellido);
            break;
        }
    }while(1);

    for(i = 0; i < cant_proys; i++)
    {
        for(j = 0; j < 5; j++)
        {
            if(Proyectos[i].idProgramadores[j] == auxIdProgramador)
                printf("\n\t%s", Proyectos[i].Nombre);
        }
    }


}
