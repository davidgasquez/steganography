#include <iostream>
#include "imagenES.h"
#include "codificar.h"

using namespace std;

const int MAXIMG = 1000000;
const int MAXNAME = 100;
const int MAXMESSAGE = 125000;

int main(int argc, char *argv[])
{
     if (argc != 2)
    {
        cerr << "Error en la introducción de los parámetros:" << endl;
        cerr << "Uso: revela [path_imagen_salida]" << endl;
        return -1;
    }

    char * name = argv[1];
    Byte img[MAXIMG];
    int rows, cols;
    Byte message[MAXMESSAGE];

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