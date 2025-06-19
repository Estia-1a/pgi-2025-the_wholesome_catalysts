#include <estia-image.h>

#include "utils.h"

pixelRGB * get_pixel(unsigned char* data, const unsigned int x, const unsigned int largeur, const unsigned int y, const unsigned int hauteur, const unsigned int i) {

    unsigned int index = (y * largeur + x) * i;
    return (pixelRGB*) &data[index];
}