#ifndef FUNCIONES_H
#define FUNCIONES_H
#endif // FUNCIONES_H

#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

//funcion de pregunta
void implementacion(unsigned long int*,unsigned short int*,unsigned short int*);

//metodo1
char *lecturam1(unsigned long long int*);
char *binarim1(unsigned long long int, char* );
void metodo1(unsigned long long int, char*,unsigned int);
char *codificacionm1(unsigned long long int, char*);
void escribirm1( char, char, bool , unsigned long long int );


//metodo 2

bool lecturam2( unsigned short int,string *);
string *bin_m2(unsigned long long int , string &);
void metodo2(string&,unsigned long long,unsigned long int,unsigned long int);
void transcripcionm2(bool *,string*,fstream&);
string *codificaionm2(unsigned long long int tamano, string &bina);
void escribirm2 ( string &, unsigned short int  );





