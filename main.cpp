#include "funciones.h"

int main()
{


    unsigned short int metodo;
    unsigned int long semilla ;
    unsigned long long int tamano;
    unsigned short int prueba;
    implementacion(&semilla,&metodo,&prueba);

    if(metodo==1)
    {
        /*char *texto=new char;
        texto=lectura(&tamano);
        cout<<endl<<texto<<endl;
        texto=binari(tamano,texto);
        metodo1(tamano,texto,semilla);
        cout<<endl<<texto<<endl;
        codificacion(tamano,texto);
        cout<<endl<<texto<<endl;
        delete texto;*/
    }
    else
   {
    string *texto=new  string,nombre="prueba.txt";
    bool fallo=true;
    while(fallo)
    {
        fallo=lecturam2(prueba,texto);
    }
    tamano=texto->length();
    cout<<*texto<<endl;
    texto=bin_m2(tamano,*texto);
    cout<<*texto<<endl;
    metodo2(*texto,tamano,semilla,0);
    cout<<*texto<<endl;
    texto=codificaionm2(tamano,*texto);
    cout<<*texto<<endl;
    delete texto;
    }
    return 0;
}










