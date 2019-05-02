#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "f_biblio.h"
#include "asignarProyect.h"

int main()
{

    Eprogramador Programadores[5];
    Eprogramador nuevoProgramador;
    eProyectos Proyectos[10];
    eProyectos nuevoProyecto;

    inicializarArrayProgramadores(Programadores, 5, 0);
    inicializarArrayProyectos(Proyectos, 10, 0);

    int opcion, indice;

    do{
        Menu();
        printf("\n\nOpcion: ");
        scanf("%d", &opcion);
    }while((opcion < 1) || (opcion > 9));

    printf("\n");

    while(opcion != 0)
    {
        do{
            switch(opcion)
            {
                case (1):
                    {
                        indice = findEmptyPlace(Programadores, 5, 0);
                        if(indice == -1)
                        {
                            printf("\tNO QUEDA ESPACIO PARA CARGAR UN NUEVO CONTACTO!!!\n\n");
                            break;
                        }
                        printf("\tALTA DE PROGRAMADOR\n\n");
                        nuevoProgramador = getProgramador();
                        Programadores[indice] = nuevoProgramador;
                        break;
                    }
                case (2):
                    {
                        int index;
                        printf("\tMODIFICAR DATOS DEL PROGRAMADOR\n\n");
                        index = buscarProgramador("Ingrese el Id del programador a buscar: ","El Id del programador debe ser numerico", Programadores, 5, "El Id no coincide con ninguno de la lista de programadores dados de ALTA");
                        Programadores[index] = modificarDatosProgramador();
                        break;

                    }
                case (3):
                    {
                        printf("\tBAJA DE PROGRAMADOR\n");
                        int index = buscarProgramador("Ingrese el Id del programador a buscar: ","El Id del programador debe ser numerico", Programadores, 5, "El Id no coincide con ninguno de la lista de programadores dados de ALTA");
                        Programadores[index].estado = 0;
                        break;
                    }
                case (4):
                    {
                        printf("ASIGNAR PROYECTOS\n");
                        int index = buscarLugarArrayProyecto(Proyectos, 5, 0);
                        if(index == -1)
                        {
                            printf("No queda espacio para ingresar otro proyecto\n");
                            break;
                        }
                        nuevoProyecto = getProyecto();
                        Proyectos[index] = nuevoProyecto;
                        break;
                    }
                case (5):
                      {
                        printf("\tMOSTRAR LISTADO DE PROGRAMADORES\n");
                        break;
                      }
                case (6):
                    {
                        printf("\tMOSTRAR LISTADO DE PROYECTOS\n");
                        break;
                    }
                case (7):
                    {
                        printf("\tLISTAR PROYECTO DE PROGRAMADOR\nIngrese el Id del programador: ");
                        mostrarProyectos_x_Programador(Programadores, Proyectos, 5, 10);
                        break;
                    }
                case (8):
                    {
                        printf("PROYECTO DEMANDANTE");
                        break;
                    }
                case (9):
                    {
                        fflush(stdin);
                        printf("Desea ver nuevamente el menu de opciones?s/n: ");
                        char respuesta = getchar();
                        if(respuesta == 's')
                        {
                            system("cls");
                            Menu();
                        }

                    }
                default: { break; }

            }
            Menu();
            printf("\n\nOpcion: ");
            scanf("%d", &opcion);

        }while(!((opcion < 1) || (opcion > 9)));
        break;
    }

    return 0;
}
