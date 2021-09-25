#include "imagen.h"

imagen::imagen()//constructor
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
        width=img.width();//ancho
        height=img.height();//alto
        int datos_originales_r[width][height];//valores de R por pixel
        int datos_originales_g[width][height];//valores de G por pixel
        int datos_originales_b[width][height];//valores de B por pixel
        for(int i=0;i<3;i++)//iterador para sacar todos los datos de la imagen
        {
            for(int j=0;j<width;j++)
            {
                for(int k=0;k<height;k++)
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
        int datos_r[16][16];//valores de R por pixel
        int datos_g[16][16];//valores de G por pixel
        int datos_b[16][16];//valores de B por pixel
        int comparador=16*16;
        if(width*height>comparador)//Algoritmo de submuestreo
        {
            submuestreo(datos_r,datos_g,datos_b);
        }
        else if(width*height<comparador)//Algoritmo de sobremuestreo
        {
            sobremuestreo(datos_r,datos_g,datos_b);
        }
        else //simplemente enviar informacion cruda
        {
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<16;j++)
                {
                    for(int k=0;k<16;k++)
                    {
                        if(i==0)
                        {
                            datos_r[j][k]=img.pixelColor(j,k).red();
                        }
                        else if(i==1)
                        {
                            datos_g[j][k]=img.pixelColor(j,k).green();
                        }
                        else
                        {
                            datos_b[j][k]=img.pixelColor(j,k).blue();
                        }
                    }
                }
            }
        }
        guardar(datos_r,datos_g,datos_b);
    }
}

void imagen::sobremuestreo(int r[16][16], int g[16][16], int b[16][16])
{

}

void imagen::submuestreo(int r[16][16], int g[16][16], int b[16][16])
{

}

void imagen::guardar(int r[16][16], int g[16][16], int b[16][16])//guarda la informacion en el txt lista para copiar y pegar
{
    //guardar en un txt;
    ofstream escritura;
    string texto;
    char c=10;
    string new_line=string(1,c);
    texto+="byte arr[3][16][16]="+new_line+"{"+new_line+"   {"+new_line+"       ";
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<16;j++)
        {
            texto+="{";
            for(int k=0;k<16;k++)
            {
                if(i==0)
                {
                    texto+=to_string(r[j][k]);
                }
                else if(i==1)
                {
                    texto+=to_string(g[j][k]);
                }
                else
                {
                    texto+=to_string(b[j][k]);
                }
                if(k!=15)
                {
                   texto+=",";
                }
            }
            texto+="}";
            if(j!=15)
            {
                texto+=",";
            }
        }
        if(i==2)
        {
            texto+=new_line+"   }"+new_line+"};";
        }
        else
        {
            texto+=new_line+"   },"+new_line+"  {"+new_line+"       ";
        }
    }
    escritura.open(PATH_SAVE);// Crear o abrir un archivo para escritura
    escritura<<texto;
    escritura.close();
}

imagen::~imagen()//destructor
{

}
