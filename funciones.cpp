#include "funciones.h"

void implementacion(unsigned long int* semilla,unsigned short int* metodo)
{
    cout<<"ingresa la semilla de codificacion"<<endl;cin>>*semilla;

    while (true)
    {
        cout<<endl<<" selecciona metodo de codificacion \n 1.primer metodo \n 2.segundo metodo  "<<endl;cin>>*metodo;

        if(*metodo<=2 and *metodo>0)
        {
            break;
        }
        cout<<endl<<"porfavor precionar el numero correspondiente al metodo"<<endl;
    }
}

void transcripcion(unsigned long long tamano, bool *correct, fstream &archivo, char* datos)
{
    if (archivo.is_open())
    {
        for(unsigned long long int i=0 ; i<tamano ;i++) datos[i]=archivo.get();
        datos[tamano]='\n';
    }else
    {
        *correct=false;
        cout <<"Archivo no encontrado"<< endl;
    }
}

 bool lectura(unsigned long long tamano, bool *modo, char *nombre_tex,char *datos)
{
    bool correct= true;
    if (*modo==true)
    {
        fstream archivo(nombre_tex, fstream::in);
        transcripcion(tamano,&correct,archivo,datos);

    }else if(*modo== false)
    {
        fstream archivo(nombre_tex, fstream::in | fstream::binary);
        transcripcion(tamano,&correct,archivo,datos);
    }
  return correct;
}


void escribirm1 ( char *datos, char *nombre, bool modo, unsigned long long int tam)
{

    fstream text;
    if(modo)
    {
        text.open(nombre, fstream::out);
        text << datos;
    }
    else
    {
        text.open(nombre, fstream::out | fstream::binary);
        text.write(datos,tam);
    }
    text.close();
}



char *binarim1(unsigned long long int tamano, char *escrito)
{
    char bits[8], *codificado= new char [8*tamano];
    unsigned char prueba;
    int contador;
    for (unsigned int i=0, ascii; i < tamano;i++)
    {
        prueba=unsigned(escrito[i]);
        ascii= int ( prueba);
        contador=7;
        while (ascii > 0)
        {

            if (ascii % 2 == 0) bits[contador] = '0' ;

            else bits[contador]= '1';

            ascii = (int) ascii/2;
            contador--;
        }

         for (int e=0 ; e<8; e++ )
         {
            if (e <= contador)
            {
                    codificado[(8*i)+e]= '0';
            }
            else
            {
                    codificado[(8*i)+e]=bits[e];
            }

         }

    }
    delete[] escrito;
    return codificado; 
    delete [] codificado;
}


void metodo1(unsigned long long int tamano,char *binario,unsigned int semilla)
{   char *guardado= new char [semilla] ;
    bool primer=true; unsigned long long int ceros=0,unos=0;

    for(unsigned long int i=0; i<tamano*8;)
    {

        if(primer ==false)
        {
            ceros=0;
            unos=0;
            for(unsigned int e=0; e<semilla ;e++)
            {
                if(guardado[e]=='1') unos++;
                else ceros++;
            }
            if(ceros==unos)unos=0;
            else if(ceros>unos)unos=1;
            else unos=2;
            ceros=0;
            for(unsigned int e=0,a=i; e<semilla and a<=tamano*8 ;a++,e++)guardado[e]=binario[a];
            for(unsigned int e=0; e<semilla and i<=tamano*8 ;i++,e++)
            {
                if(unos==ceros)
                {
                    if(binario[i]=='1') binario[i]='0';
                    else binario[i]='1';
                    ceros=0;
                }
                else ceros++;
            }

        }
        else
        {
            for(unsigned int e=0,a=i; e<semilla;a++,e++)guardado[e]=binario[a];

            for(unsigned int e=0; e<semilla;i++,e++)
            {
                if(binario[i]=='0') binario[i]='1';
                else binario[i]='0';
            }
            primer=false;

        }
    }
    delete[] guardado;
}

char * codificacionm1(unsigned long long int tamano, char *bina)
{
    char *escribir= new char (tamano);
    int letra;

    for(unsigned int i=0,e=0;e<tamano;e++)
    {   letra=0;
        for(int a=7;0<=a;i++,a--)
        {
            letra=letra+(pow((int(bina[i])-48)*2,a));
        }
        if(bina[i]==0) escribir[e]= char(letra-1);
        else escribir[e]= char(letra);
    }
    return escribir;
    delete  escribir;
}



//metodo 2

bool lecturam2(bool *modo, string *nombre_tex,string *datos)
{

   bool correct= true;
   if (*modo==true)
   {
       fstream archivo(*nombre_tex, fstream::in);
       transcripcionm2(&correct,datos,archivo);
   }
   else
   {
       fstream archivo(*nombre_tex, fstream::in | fstream::binary);
       transcripcionm2(&correct,datos,archivo);
   }

   return correct;
}

void transcripcionm2(bool *correct, string *datos,fstream &archivo)
{
    if (!archivo.is_open())
    {
        *correct=false;
        cout <<"Archivo no encontrado"<< endl;
    }

    while (getline(archivo,*datos)) *datos= *datos+'\n';
    datos->pop_back();
}

string *bin_m2(unsigned long long int tamano, string &escrito)
{

    string bits= "", *codificado = new string ;
    string prueba;
    int ascii;
    for (unsigned int i=0; i<tamano;i++)
    {
        //prueba = ();
        ascii= unsigned( int (escrito[i]));
        bits="";
        while(ascii > 0)
        {
            if(ascii % 2 == 0)
            {
                bits = '0'+bits;
            }
            else
            {
                bits = '1'+bits;
            }
            ascii = (int) ascii/2;
        }

        while(bits.size()<8)
        {
            bits='0'+bits;
        }
        *codificado= *codificado+bits;
    }
    return codificado;
    delete codificado;
}

string* codificaionm2(unsigned long long int tamano, string &bina)
{

    string *escribir= new string ;
    int letra;

    for(unsigned int i=0,e=0;e<tamano;e++)
    {   letra=0;
        for(int a=7;0<=a;i++,a--)
        {
            letra=letra+(pow((int(bina[i])-48)*2,a));
        }
        if(bina[i]==0)
         *escribir= *escribir+ to_string(letra-1);
        else *escribir=*escribir + to_string(letra);
    }
    return escribir;
    delete  escribir;
}



void metodo2(string &text, unsigned long long tamano, unsigned long int  semilla,unsigned long int posicion)
{

    string nex,ultimo;

    for(unsigned int i=0;i<(tamano*8)/semilla ;i++)
    {
        ultimo=text[posicion+semilla-1];
        nex=text[posicion+1];
        if(2<=semilla)
        {
            text[posicion+1]=text[posicion];
            text[posicion]=ultimo[0];
            posicion=posicion+2;
        }

        for(unsigned int e=2;e<semilla;e++,posicion++)
        {
                ultimo=nex;
                nex=text[posicion];
                text[posicion]=ultimo[0];
        }
    }
    if((tamano*8)%semilla != 0)
    {   unsigned long int conteo=0;
        for (unsigned long int i=posicion;i<tamano*8 ;i++ ) conteo++;
        metodo2(text,tamano,conteo,posicion);
    }
}






