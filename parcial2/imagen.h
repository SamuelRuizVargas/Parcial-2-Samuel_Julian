#ifndef IMAGEN_H
#define IMAGEN_H

#include <iostream>
#include <fstream>
#include <QImage>

#define PATH_IM "../parcial2/imagenes/"
#define PATH_SAVE "../parcial2/saves/resultado.txt"

using namespace std;

class imagen
{
    int width;
    int height;

public:
    imagen();
    void sobremuestreo(int[16][16], int[16][16], int[16][16]);
    void submuestreo(int[16][16], int[16][16], int[16][16]);
    void guardar(int[16][16], int[16][16], int[16][16]);
    ~imagen();
};

#endif // IMAGEN_H
