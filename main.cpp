#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <stdalign.h>
#include <stdio.h>

using namespace std;


void codificar(int numero,string numeroS, string aux){
    while(numero >0){
        if (numero%2 == 0){
            numeroS = numeroS + "0";
        }else{
            numeroS = numeroS + "1";
        }
        numero = numero/2;
    }

    for(int i=numeroS.length()-1;i>=0;i--){
        aux = aux +numeroS.at(i);

    }
    numeroS = aux;
}
int main () {
    char data[100];
    string nombre_archivo;


 //El nombre dle archivo debe ser ingresado en .txt
 cout <<"Ingrese nombre del archivo: ";
 cin >> nombre_archivo;

    // abrir un archivo en modo escritura
    ofstream outfile;

    // Se pone de manera explicita la ruta relativa donde se encuentra el archivo
    outfile.open("../Guia3/BD/"+nombre_archivo);

    // Se comprueba si el archivo fue abierto exitosamente
    if (!outfile.is_open())
    {
      cout << "Error abriendo el archivo" << endl;
      exit(1);
    }

    cout << "Escribiendo en el archivo" << endl;


    // Escribir el dato ingresado en el archivo


   int numero;
   string numeroS =" ",aux;
   cout <<"ingrese el numero: ";
   cin >> numero;

   codificar(numero,numeroS, aux);
   istringstream(numeroS)>> numero;
   printf("numero binario %i \n",numero);
   outfile << numero << endl;
   // Se cierra el archivo
   outfile.close();
//--------------lectura----------------------------------
/*string data;

   // Abre el archivo en modo lectura
   ifstream infile;
string nombre_archivo;
cout <<"Ingrese nombre del archivo";
cin >> nombre_archivo;

   // Se pone de manera explicita la ruta relativa donde se encuentra el archivo
   infile.open("../Guia3/BD/"+nombre_archivo);

   // Se comprueba si el archivo fue abierto exitosamente
   if (!infile.is_open())
   {
     cout << "Error abriendo el archivo" << endl;
     exit(1);
   }

   cout << "Leyendo el archivo" << endl;
   infile >> data;

   // Se escribe el dato en la pantalla
   cout << data << endl;
   cout << "longitud: " << data.length() << endl;

   cout << "Impresion caracter a caracter" << endl;
   for (unsigned int i = 0; i < data.length(); i++) {
       cout << data.at(i) << endl;
   }

   // Se cierra el archivo abierto
   infile.close();*/


   return 0;
}
