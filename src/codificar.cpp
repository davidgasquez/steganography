/**
  * @file codificar.cpp
  * @brief Fichero con definiciones para la codificación de textos en imágenes
  *
  * Permite la codificación y decodificación de mensajes en archivos de tipo PGM,PPM
  *
  */

#include <iostream>
#include <string>
#include "imagenES.h"
#include "codificar.h"
using namespace std;

int size(Byte c[], int n)
{
    int l = 0;
    while (c[l] != '\0' && l < n)
    {
        l++;
    }
    return l;
}

bool getbit(Byte c, int pos)
{
    if ((c & (1 << pos)))
        return true;
    else
        return false;
}

void setbit(Byte &b, int pos, bool bit)
{
    if (bit)
        b = b | (1 << pos);
    else
        b = b & ~(1 << pos);
}

void codify(Byte c, Byte buffer[], int offset) //Sumar al offset 8 despues de usar esta funcion
{
    for (int i = 0; i < 8; ++i)
    {
        setbit(buffer[offset + i], 0, getbit(c, 7 - i));
    }

}

void decodify(Byte &c, Byte buffer[], int offset)
{
    for (int i = 0; i < 8; ++i)
    {
        setbit(c, 7 - i, getbit(buffer[offset + i], 0));
    }
}

void Ocultar(Byte img[], Byte cad[])
{
    int offset = 0;
    for (int i = 0; i < 125000; ++i)
    {
        codify(cad[i], img, offset);
        offset = offset + 8;
    }
}

void Revelar(Byte img[], Byte cad[])
{
    int offset = 0;
    for (int i = 0; i < 125000; ++i)
    {
        decodify(cad[i], img, offset);
        offset = offset + 8;
    }
}
/* Fin Fichero: codificar.cpp */