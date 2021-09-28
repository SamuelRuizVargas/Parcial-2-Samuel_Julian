#include "imagen.h"

imagen::imagen()//constructor
{
    width=0;
    height=0;
}

int imagen::getwidth(string nombre)//retorna el ancho
{
    QImage img(nombre.c_str());
    if (img.load(nombre.c_str())==false)//si la imagen no carga
    {
        cout<<"La imagen no pudo ser cargada"<<endl;
    }
    else
    {
        width=img.width();//ancho
        height=img.height();//alto
    }
    return width;
}

int imagen::getheight(string nombre)//retorna el alto
{
    QImage img(nombre.c_str());
    if (img.load(nombre.c_str())==false)//si la imagen no carga
    {
        cout<<"La imagen no pudo ser cargada"<<endl;
    }
    else
    {
        width=img.width();//ancho
        height=img.height();//alto
    }
    return height;
}

void imagen::no_muestreo(int r[16][16], int g[16][16], int b[16][16],string nombre)//si la imagen tiene la misma dimension de la matriz de leds
{
    //DATOS DE LA IMAGEN
    QImage img(nombre.c_str());
    if (img.load(nombre.c_str())==false)//si la imagen no carga
    {
        cout<<"La imagen no pudo ser cargada"<<endl;
    }
    else
    {
        width=img.width();//ancho
        height=img.height();//alto
        vector<vector<int>> datos_originales_r(width,vector<int>(height));;//valores de R por pixel
        vector<vector<int>> datos_originales_g(width,vector<int>(height));//valores de G por pixel
        vector<vector<int>> datos_originales_b(width,vector<int>(height));//valores de B por pixel
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
        //FIN DATOS DE LA IMAGEN
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<16;j++)
            {
                for(int k=0;k<16;k++)
                {
                    if(i==0)
                    {
                        r[j][k]=img.pixelColor(j,k).red();
                    }
                    else if(i==1)
                    {
                        g[j][k]=img.pixelColor(j,k).green();
                    }
                    else
                    {
                        b[j][k]=img.pixelColor(j,k).blue();
                    }
                }
            }
        }
    }
}

void imagen::sobremuestreo(int r[16][16], int g[16][16], int b[16][16],string nombre)
{
    //DATOS DE LA IMAGEN
    QImage img(nombre.c_str());
    if (img.load(nombre.c_str())==false)//si la imagen no carga
    {
        cout<<"La imagen no pudo ser cargada"<<endl;
    }
    else
    {
        width=img.width();//ancho
        height=img.height();//alto
        vector<vector<int>> datos_originales_r(width,vector<int>(height));;//valores de R por pixel
        vector<vector<int>> datos_originales_g(width,vector<int>(height));//valores de G por pixel
        vector<vector<int>> datos_originales_b(width,vector<int>(height));//valores de B por pixel
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
        //FIN DATOS DE LA IMAGEN
        int width_multi,height_multi;
        if(width>=8)
        {
            width_multi=2;
        }
        else
        {
            width_multi=3;
        }
        if(height>=8)
        {
            height_multi=2;
        }
        else
        {
            height_multi=3;
        }
        int rojo,verde,azul;
        for(int i=0;i<width;i++)
        {
            for(int j=0;j<height;j++)
            {
                rojo=datos_originales_r[i][j];
                if(rojo==255)
                {
                    rojo=250;
                }
                else if(rojo==0)
                {
                    rojo=5;
                }
                verde=datos_originales_g[i][j];
                if(verde==255)
                {
                    verde=250;
                }
                else if(verde==0)
                {
                    verde=5;
                }
                azul=datos_originales_b[i][j];
                if(azul==255)
                {
                    azul=250;
                }
                else if(azul==0)
                {
                    azul=5;
                }
                for(int k=0;k<width_multi;k++)
                {
                    for(int l=0;l<height_multi;l++)
                    {
                        int pos_fila=k+(width_multi*i),pos_columna=l+(height_multi*j);
                        if(pos_fila>=16 or pos_columna>=16)
                        {
                            break;
                        }
                        r[pos_fila][pos_columna]=rojo;
                        g[pos_fila][pos_columna]=verde;
                        b[pos_fila][pos_columna]=azul;
                    }
                }
            }
        }
    }
}

void imagen::submuestreo(int r[16][16], int g[16][16], int b[16][16],string nombre)//si la imagen tiene mas pixeles que la matriz de leds
{
    //DATOS DE LA IMAGEN
    QImage img(nombre.c_str());
    if (img.load(nombre.c_str())==false)//si la imagen no carga
    {
        cout<<"La imagen no pudo ser cargada"<<endl;
    }
    else
    {
        width=img.width();//ancho
        height=img.height();//alto
        vector<vector<int>> datos_originales_r(width,vector<int>(height));;//valores de R por pixel
        vector<vector<int>> datos_originales_g(width,vector<int>(height));//valores de G por pixel
        vector<vector<int>> datos_originales_b(width,vector<int>(height));//valores de B por pixel
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
        //FIN DATOS DE LA IMAGEN
        int width_divi=width/16,height_divi=height/16;
        if(height<16)
        {
            height_divi=1;
        }
        if(width<16)
        {
            width_divi=1;
        }
        int cubo_actu_r[width_divi][height_divi];
        int cubo_actu_g[width_divi][height_divi];
        int cubo_actu_b[width_divi][height_divi];
        int rojo,verde,azul,suma_r,suma_v,suma_a,prom,a_dividir=width_divi*height_divi;
        for(int i=0;i<16;i++)//itera las filas de la imagen
        {
            for(int j=0;j<16;j++)//itera las columnas de la imagen
            {
                for(int k=0;k<width_divi;k++)//itera las filas de la subseccion de la imagen
                {
                    for(int l=0;l<height_divi;l++)//itera las columnas de la subseccion de la imagen
                    {
                        int pos_fila=k+(width_divi*j),pos_columna=l+(height_divi*i);
                        rojo=datos_originales_r[pos_fila][pos_columna];
                        cubo_actu_r[k][l]=rojo;
                        verde=datos_originales_g[pos_fila][pos_columna];
                        cubo_actu_g[k][l]=verde;
                        azul=datos_originales_b[pos_fila][pos_columna];
                        cubo_actu_b[k][l]=azul;
                    }
                }
                //Matrices cubo llenas
                suma_r=0;
                suma_v=0;
                suma_a=0;
                for(int m=0;m<width_divi;m++)//itera sobre el cubo actual
                {
                    for(int z=0;z<height_divi;z++)
                    {
                        rojo=cubo_actu_r[m][z];
                        if(rojo==255)
                        {
                            rojo=250;
                        }
                        else if(rojo==0)
                        {
                            rojo=5;
                        }
                        suma_r+=rojo;
                        verde=cubo_actu_g[m][z];
                        if(verde==255)
                        {
                            verde=250;
                        }
                        else if(verde==0)
                        {
                            verde=5;
                        }
                        suma_v+=verde;
                        azul=cubo_actu_b[m][z];
                        if(azul==255)
                        {
                            azul=250;
                        }
                        else if(azul==0)
                        {
                            azul=5;
                        }
                        suma_a+=azul;
                    }
                }
                prom=suma_r/a_dividir;
                r[j][i]=prom;
                prom=suma_v/a_dividir;
                g[j][i]=prom;
                prom=suma_a/a_dividir;
                b[j][i]=prom;
            }
        }
    }
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
