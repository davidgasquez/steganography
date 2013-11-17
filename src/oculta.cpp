#include <iostream>
#include <string.h>
#include "imagenES.h"
#include "codificar.h"

using namespace std;

const int MAXIMG = 1000000;
const int MAXNAME = 100;
const int MAXMESSAGE = 125000;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cerr << "Error en la introducción de los parámetros:" << endl;
        cerr << "Uso: oculta [path_imagen_entrada] [nombre_imagen_salida]" << endl;
        return -1;
    }

    char* name;
    char* out;
    Byte img[MAXIMG];
    int rows, cols;
    Byte message[MAXMESSAGE];

    name = argv[1];
    out = argv[2];

    cout << "Introduzca mensaje: ";
    cin.getline((char *) message, 125000);

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

    if (rows * cols < size(message, MAXMESSAGE))
    {
        cerr << "Mensaje demasiado grande para la imagen.";
        return 1;
    }

    cout << "Ocultando..." << endl;
    Ocultar(img, message);
    cout << "Mensaje ocultado con exito" << endl;

    if (type == IMG_PGM)
    {
        strcat(out, ".pgm");
        if (!EscribirImagenPGM(out, img, rows, cols))
        {
            cerr << "Error en la escritura de la imagen PGM." << endl;
            return 1;
        }
    }
    else if (type == IMG_PPM)
    {
        strcat(out, ".ppm");
        if (!EscribirImagenPPM(out, img, rows, cols))
        {
            cerr << "Error en la escritura de la imagen PPM." << endl;
            return 1;
        }
    }
    else
    {
        cerr << "Error en la escritura de la imagen." << endl;
        return 1;
    }
    return 0;
}