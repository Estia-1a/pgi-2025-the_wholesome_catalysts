#include <estia-image.h>

#include "utils.h"

pixelRGB * get_pixel(unsigned char* data, const unsigned int width, const unsigned int height, const unsigned int n, const unsigned int x, const unsigned int y) {
    if (!data || x >= width || y >= height) {
        return NULL;
    }

    // Calcul de l'index dans le tableau de données
    // Chaque pixel contient n composantes (ex: 3 pour RGB)
    unsigned int index = (y * width + x) * n;

    // On retourne l'adresse de pixelRGB dans le tableau data
    return (pixelRGB*) &data[index];
}
