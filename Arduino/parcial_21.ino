#include <Adafruit_NeoPixel.h>

#define LED_PIN 2

#define LED_COUNT 256

Adafruit_NeoPixel N1(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

//Copiado del TXT
//----------------------
byte arr[3][16][16]=
{
   {
       {186,188,202,203,212,209,216,199,30,34,69,129,166,185,181,180},{199,201,215,216,225,222,228,212,35,41,76,137,172,190,186,187},{204,204,218,219,227,226,233,217,39,45,81,141,177,193,192,193},{206,206,219,220,229,227,235,220,40,45,82,143,178,195,194,197},{209,211,223,222,231,229,238,223,41,46,83,146,182,199,199,201},{209,208,221,221,230,228,237,221,40,46,84,146,184,202,201,202},{211,212,224,223,231,229,237,220,40,45,83,147,185,203,202,205},{212,212,224,224,232,230,237,221,43,47,84,150,188,205,203,206},{212,213,223,222,232,230,237,221,42,48,85,146,186,199,202,202},{211,211,223,223,232,229,237,221,40,47,86,148,187,197,197,195},{210,213,224,223,232,230,238,222,36,44,83,145,185,196,195,192},{210,211,223,223,233,230,238,222,43,47,81,140,181,192,190,185},{210,212,222,222,233,231,239,221,44,47,81,139,176,188,188,182},{208,208,219,220,231,230,237,219,39,44,80,138,175,186,186,180},{205,207,219,219,231,227,235,219,41,46,81,136,172,182,179,173},{203,204,217,217,227,225,233,216,39,46,80,134,169,178,177,173}
   },
  {
       {168,169,181,181,188,187,197,191,40,30,18,31,19,13,12,13},{181,182,194,194,201,200,212,205,48,37,25,37,25,18,17,18},{185,185,197,197,205,204,217,211,52,41,29,41,27,20,19,21},{187,188,198,198,207,208,219,214,53,41,30,41,26,20,19,22},{190,190,201,200,210,210,222,217,54,42,31,42,28,19,19,23},{191,190,201,200,209,209,221,215,53,41,29,42,28,20,19,22},{193,191,202,202,210,210,223,217,53,40,28,41,28,19,18,21},{194,194,205,203,211,212,223,218,56,42,30,44,31,21,19,22},{194,192,202,201,211,212,222,216,56,43,31,40,29,15,18,18},{193,193,204,202,211,211,222,216,54,42,32,42,30,15,15,13},{192,192,203,202,210,210,220,217,50,39,29,41,29,16,17,14},{192,193,203,202,211,210,220,215,54,42,29,39,27,14,14,11},{191,191,200,201,211,209,219,214,55,42,29,37,26,15,16,13},{189,190,199,199,208,208,217,212,50,39,28,38,28,17,18,15},{186,186,197,196,206,205,215,209,50,41,31,39,26,15,14,10},{184,186,197,196,204,203,213,209,50,41,30,37,25,13,14,11}
   },
  {
       {6,5,12,10,17,13,19,84,76,125,84,69,29,9,7,7},{19,17,25,22,30,26,31,98,83,132,91,75,35,14,12,13},{21,20,28,25,33,30,36,101,87,136,95,77,38,16,15,17},{23,20,27,24,33,30,36,104,88,135,94,78,38,17,16,19},{25,23,30,26,33,30,39,105,88,136,95,79,40,18,18,21},{23,20,28,23,30,27,37,103,87,133,94,79,39,19,18,21},{25,20,28,23,31,28,36,102,85,132,93,79,39,17,18,21},{24,22,27,24,30,28,36,101,88,134,92,80,42,19,19,22},{24,21,25,22,30,28,35,99,85,133,93,76,40,13,18,18},{23,21,26,23,30,27,35,99,83,132,94,78,41,12,14,12},{24,21,26,23,29,27,34,100,79,129,91,76,40,15,17,14},{24,23,28,23,30,27,34,99,84,132,91,73,37,12,14,10},{26,22,26,22,30,27,34,98,87,134,91,74,37,11,14,10},{24,22,26,22,30,26,32,96,82,131,90,74,38,12,15,11},{22,19,25,20,28,24,32,96,83,133,94,74,36,9,10,5},{20,18,24,19,26,22,30,95,82,133,93,72,34,7,9,6}
   }
};
//----------------------

void setup()
{
  N1.begin();
  int contador=0;
  for(int j=0;j<16;j++)
  {
    for(int i=0;i<16;i++)
    {
        N1.setPixelColor(contador,arr[0][i][j],arr[1][i][j],arr[2][i][j]);
      	contador++;
    }
  }
  N1.show();// Initialize all pixels to 'off'
}

void loop()
{
  
}