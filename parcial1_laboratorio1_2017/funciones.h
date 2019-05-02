#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

enum categorias_programador
{
  JUNIOR, SEMISENIOR, SENIOR
};

typedef struct{
    int Id;
    char Nombre[30];
    int IdCategoria;
    int cant_horas;
    int idProgramadores[5];
    int estado;
}eProyectos;

typedef struct{
    int Id;
    char Nombre[20];
    char Apellido[20];
    char IdCategoria;
    int IdProyectos[10];
    int estado;
}Eprogramador;

int findEmptyPlace(Eprogramador Programadores[], int cant_Programadores, int valor);
void inicializarArrayProgramadores(Eprogramador [], int cant_Programadores, int valor);
Eprogramador getProgramador(void);
int buscarProgramador(char msj[], char Emsj[], Eprogramador Programadores[], int cant_Programadores, char fail[]);
void mostrarProgramadores(Eprogramador [], int cant_Programadores);
int pago_por_hora();
int validIdCategoria(char c);
Eprogramador modificarDatosProgramador(void);


















#endif // FUNCIONES_H_INCLUDED
