// compile with:
// em++ grayscale.cpp -o grayscale.js -s EXPORTED_FUNCTIONS="['_malloc', '_free']" -O3

#include <emscripten/emscripten.h>


// C code for web assembly
extern "C" {
  void grayScale (unsigned char* data, int len);
}


void EMSCRIPTEN_KEEPALIVE grayScale(unsigned char* data, int len) {
  for (int i = 0; i < len; i += 4) {
    int r = data[i];
    int g = data[i+1];
    int b = data[i+2];
    int a = data[i+3];
    int w = (r*5 + g*9 + b*2)/16;
    data[i] = w;
    data[i+1] = w;
    data[i+2] = w;
    data[i+3] = a;
  }
}
