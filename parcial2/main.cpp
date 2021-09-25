#include <iostream>
#include <QImage>

//Codigo inicial, luego definir la clase imagen
#define PATH_IM "../parcial2/imagenes/"

using namespace std;

int main()
{
    string nom_img;
    cout<<"Ingrese el nombre de su archivo(con extension): ";cin>>nom_img;
    nom_img=PATH_IM+nom_img;
    QImage img(nom_img.c_str());
    if (img.load(nom_img.c_str())==false)
    {
        cout<<"La imagen no pudo ser cargada"<<endl;
    }
    else
    {
        int ancho_im=img.width();
        int alto_im=img.height();
        int datos_originales_r[ancho_im][alto_im];//valores de R por pixel
        int datos_originales_g[ancho_im][alto_im];//valores de G por pixel
        int datos_originales_b[ancho_im][alto_im];//valores de B por pixel
        for(int i=0;i<3;i++)//iterador para sacar todos los datos de la imagen
        {
            for(int j=0;j<ancho_im;j++)
            {
                for(int k=0;k<alto_im;k++)
                {
                    if(i==0)
                    {
                        datos_originales_r[j][k]=img.pixelColor(j,k).red();
                    }
                    else if(i==1)
                    {
                        datos_originales_g[j][k]=img.pixelColor(j,k).green();
                    }
                    else
                    {
                        datos_originales_b[j][k]=img.pixelColor(j,k).blue();
                    }
                }
            }
        }
    }

    return 0;
}
