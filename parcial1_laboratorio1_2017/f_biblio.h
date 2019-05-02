#ifndef F_BIBLIO_H_INCLUDED
#define F_BIBLIO_H_INCLUDED


void Menu();
void getString(char* str[], char msj[]);
int soloLetras(char str[20]);
int validEdad(char str[5]);
int validRangoEtario(char str[5], int lowLimit, int hiLimit);
int validDni(char str[10]);
int soloNumeros(char str[]);
int alphaNum(char str[8]);
//void getDni(char msj[], char Emsj[], char* input);


#endif // F_BIBLIO_H_INCLUDED

