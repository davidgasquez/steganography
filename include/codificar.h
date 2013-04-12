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


/**
  * @brief Calcula el tamaño de una cadena char.
  *
  * @param c[] vector de unigned char a calcular el tamaño.
  * @param n tamaño máximo que puede tener esa cadena.
  * @return Devuelve el tamaño de la cadena c si es menos que n, si no, devuelve n.
  */
int size(Byte c[], int n);

/**
  * @brief Obtiene el bit especificado de un unsigned char en binario.
  *
  * @param c[] unigned char a obtener el bit.
  * @param pos número de bit a botener
  * @return Devuelve 1(true) o 0(false).
  */
bool getbit (Byte c, int pos);

/**
  * @brief Modifica el bit especificado en un unsigned char.
  *
  * @param b unsigned char a modificar
  * @param pos número de bit a modificar
  * @param bit bool que indica si modificar c con un 1 o un 0.
  */
void setbit (Byte &b, int pos, bool bit);

/**
  * @brief Codifica un unsigned char en un buffer de unsigned chars.
  *
  * @param c caracter a codificar
  * @param buffer[] buffer donde codificar segun lo pedido el caracter c.
  * @param offset desplazamiento interno dentro de buffer
  * @return Buffer ahora contiene el caracter c cifrado en los últimos bits de cada componente.
  */
void codify(Byte c, Byte buffer[], int offset);

/**
  * @brief Descodifica 8 componentes de buffer para obtener el caracter c.
  *
  * @param c caracter que tendrá lo decodificado
  * @param buffer vector de donde decodificar el carácter.
  * @param offset desplazamiento interno dentro de buffer
  * @return El Byte c ahora contiene un caracter obtenido de buffer[]
  */
void decodify(Byte &c, Byte buffer[], int offset);

/**
  * @brief Oculta un texto en una imagen.
  *
  * @param img[] Imagen donde codificar.
  * @param cad[] cadena a codificar.
  */
void Ocultar(Byte img[], Byte cad[]);

/**
  * @brief Revela el texto codificado de una imagen.
  *
  * @param img[] Imagen que contiene el texto.
  * @param cad[] Cadena de unsigned chars donde se almacenaran los caracteres que se decodifiquen.
  */
void Revelar(Byte img[], Byte cad[]);

#endif

/* Fin Fichero: codificar.h */

