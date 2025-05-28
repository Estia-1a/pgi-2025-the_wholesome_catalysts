#include <estia-image.h>
#include <stdio.h>
#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld()
{
    printf("Hello World !");
}

void dimension(char *source_path)
{

    unsigned char *data;

    int width = 0;
    int height = 0;
    int channel_count = 0;

    int result = read_image_data(source_path, &data, &width, &height, &channel_count);

    if (result > 0)
    {

        printf("dimension: %d, %d\n", width, height);
    }
    return;
}

void first_pixel(char *source_path)
{
    int width, height, channel_count;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    unsigned char R = data[0];
    unsigned char G = data[1];
    unsigned char B = data[2];
    printf("first_pixel: %d, %d, %d", R, G, B);
}

void tenth_pixel(char *source_path)
{
    int width, height, channel_count;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    int ligne_pixel = 9;                /*pixel de la 10eme ligne */
    int indice_pixel = ligne_pixel * 3; /*Chaque pixel est composé de 3 bytes*/

    unsigned char R = data[indice_pixel];
    unsigned char G = data[indice_pixel + 1];
    unsigned char B = data[indice_pixel + 2];

    printf("tenth_pixel: %d, %d, %d", R, G, B);
}

/* #22 */

void second_line(char *source_path)
{
    int width, height, channel_count;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    int ligne = 1;                                    /* seconde ligne (index 1) */
    int colonne = 0;                                  /* premier pixel de la ligne */
    int indice_pixel = (ligne * width + colonne) * 3; /* Calcul correct de l'indice */

    unsigned char R = data[indice_pixel];
    unsigned char G = data[indice_pixel + 1];
    unsigned char B = data[indice_pixel + 2];

    printf("tenth_pixel: %d, %d, %d", R, G, B);
}

/* #21 */

void print_pixel(char *filename, int x, int y)
{
}

/* #20 */
void max_pixel(char *filename)
{
}

/* 19 */

void min_pixel(char *filename)
{
}

/* 18 */

void max_component(char *filename)
{
}

void min_component(char *filename)
{
}

void stat_report(char *filename)
{
}
void color_red(char *filename)
{
}
void color_green(char *filename)
{
}
void color_blue(char *filename)
{
}
void color_gray(char *filename)
{
}
void invert(char *filename)
{
}
void color_gray_luminance(char *filename)
{
}
void rotate_cw(char *filename)
{
}
void rotate_acw(char *filename)
{
}
void mirror_horizontal(char *filename)
{
}
void mirror_vertical(char *filename)
{
}
void mirror_total(char *filename)
{
}
void scale_crop(char *filename)
{
}
void scale_nearest(char *filename)
{
}
void scale_bilinear(char *filename)
{
}
void color_desaturate(char *filename)
{
}