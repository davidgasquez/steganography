/**
  * @file codificar.h
  * @brief Fichero cabecera para la codificación de textos en imágenes
  *
  * Permite la codificación de cadenas de texto en archivos de tipo PGM,PPM
  *
  */

#ifndef _CODIFICAR_H_
#define _CODIFICAR_H_

#include <iostream>
#include "imagenES.h"
using namespace std;

#define Byte unsigned char

int size(Byte c[],int n);

bool getbit (Byte c, int pos);

void setbit (Byte &b, int pos, bool bit);

void codify(Byte c, Byte buffer[], int offset);

void decodify(Byte &c, Byte buffer[], int offset);

void Ocultar(Byte img[], Byte cad[]);

void Revelar(Byte img[], Byte cad[]);

#endif

/* Fin Fichero: codificar.h */

