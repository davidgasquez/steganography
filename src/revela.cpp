#include <iostream>
#include "imagenES.h"
#include "codificar.h"

using namespace std;

const int MAXIMG = 1000000;
const int MAXNAME = 100;
const int MAXMESSAGE = 125000;

int main()
{
    char name[MAXNAME];
    Byte img[MAXIMG];
    int rows, cols;
    Byte message[MAXMESSAGE];

    cout << "Introduzca la imagen de entrada: ";
    cin >> name;

    TipoImagen type = LeerTipoImagen(name, rows, cols);

    if (type == IMG_PGM)
    {
        if (!LeerImagenPGM(name, rows, cols, img))
        {
            cerr << "Error en la lectura de la imagen PGM." << endl;
            return 1;
        }
    }
    else if (type == IMG_PPM)
    {
        if (!LeerImagenPPM(name, rows, cols, img))
        {
            cerr << "Error en la lectura de la imagen PPM." << endl;
            return 1;
        }
    }
    else
        cerr << "Error en la lectura de la imagen. Tipo de archivo desconocido." << endl;

    cout << "Revelando....." << endl;
    
    Revelar(img, message);

    if(size(message,MAXMESSAGE)==MAXMESSAGE){
        cerr << "Esta imagen no contiene ningún mensaje cifrado.";
        return 1;
    }

    cout << "El mensaje es: " << message << endl;

    return 0;
}