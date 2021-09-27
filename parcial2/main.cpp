#include <iostream>
#include <QImage>
#include "imagen.h"

using namespace std;

int main()
{
    string nom_img;
    cout<<"Ingrese el nombre de su archivo(con extension): ";cin>>nom_img;
    nom_img=PATH_IM+nom_img;
    imagen im=imagen();
    int datos_r[16][16];//valores de R por pixel
    int datos_g[16][16];//valores de G por pixel
    int datos_b[16][16];//valores de B por pixel
    int comparador=16*16;
    int ancho=im.getwidth(nom_img),alto=im.getheight(nom_img);
    if(ancho*alto>comparador)//Algoritmo de submuestreo
    {
        im.submuestreo(datos_r,datos_g,datos_b,nom_img);
    }
    else if(ancho*alto<comparador)//Algoritmo de sobremuestreo
    {
        im.sobremuestreo(datos_r,datos_g,datos_b,nom_img);
    }
    else //simplemente enviar informacion cruda
    {
        im.no_muestreo(datos_r,datos_g,datos_b,nom_img);
    }
    im.guardar(datos_r,datos_g,datos_b);
    return 0;
}
