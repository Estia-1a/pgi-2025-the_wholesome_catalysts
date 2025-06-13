#include <estia-image.h>

#include "utils.h"

pixelRGB * get_pixel(unsigned char* data, const unsigned int x, const unsigned int width, const unsigned int y, const unsigned int height, const unsigned int i) {

    unsigned int index = (y * width + x) * i;
    return (pixelRGB*) &data[index];
}