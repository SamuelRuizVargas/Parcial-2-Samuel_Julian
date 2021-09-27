#ifndef IMAGEN_H
#define IMAGEN_H

#include <iostream>
#include <fstream>
#include <QImage>
#include <vector>

#define PATH_IM "../parcial2/imagenes/"
#define PATH_SAVE "../parcial2/saves/resultado.txt"

using namespace std;

class imagen
{
    int width;
    int height;

public:
    imagen();
    int getwidth(string);
    int getheight(string);
    void no_muestreo(int[16][16], int[16][16], int[16][16],string);
    void sobremuestreo(int[16][16], int[16][16], int[16][16],string);
    void submuestreo(int[16][16], int[16][16], int[16][16],string);
    void guardar(int[16][16], int[16][16], int[16][16]);
    ~imagen();
};

#endif // IMAGEN_H
