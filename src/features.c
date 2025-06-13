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

    printf("second_line : %d, %d, %d", R, G, B);
}






/* #20 */
void max_pixel(char *source_path)
{
    int width, height, channels;
    unsigned char *data;

    if (read_image_data(source_path, &data, &width, &height, &channels) <= 0)
    {
        printf("Erreur lors de la lecture de l'image.\n");
        return;
    }

    int max_total = -1;
    int best_x = 0, best_y = 0;
    unsigned char best_r = 0, best_g = 0, best_b = 0;

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int pixel_index = (y * width + x) * channels;

            unsigned char r = data[pixel_index];
            unsigned char g = data[pixel_index + 1];
            unsigned char b = data[pixel_index + 2];

            int rgb_sum = r + g + b;

            if (rgb_sum > max_total)
            {
                max_total = rgb_sum;
                best_x = x;
                best_y = y;
                best_r = r;
                best_g = g;
                best_b = b;
            }
        }
    }

    printf("max_pixel (%d, %d): %d, %d, %d\n", best_x, best_y, best_r, best_g, best_b);
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
    int width, height, channel_count;
    unsigned char *data;
    
    // Lire les données de l'image
    int result = read_image_data(filename, &data, &width, &height, &channel_count);
    
    if (result <= 0) {
        printf("Erreur lors de la lecture de l'image\n");
        return;
    }
    
    // Initialiser les variables de statistiques
    unsigned char max_pixel = 0;
    unsigned char min_pixel = 255;
    unsigned char max_r = 0, max_g = 0, max_b = 0;
    unsigned char min_r = 255, min_g = 255, min_b = 255;
    
    // Parcourir tous les pixels
    for (int i = 0; i < width * height; i++) {
        int pixel_index = i * 3;  // Chaque pixel = 3 bytes (RGB)
        
        unsigned char r = data[pixel_index];
        unsigned char g = data[pixel_index + 1];
        unsigned char b = data[pixel_index + 2];
        
        // Calculer l'intensité du pixel (luminance)
        unsigned char intensity = (unsigned char)(0.299 * r + 0.587 * g + 0.114 * b);
        
        // Mettre à jour les statistiques globales
        if (intensity > max_pixel) max_pixel = intensity;
        if (intensity < min_pixel) min_pixel = intensity;
        
        // Mettre à jour les statistiques par composante
        if (r > max_r) max_r = r;
        if (r < min_r) min_r = r;
        
        if (g > max_g) max_g = g;
        if (g < min_g) min_g = g;
        
        if (b > max_b) max_b = b;
        if (b < min_b) min_b = b;
    }
    
    // Créer le nom du fichier de sortie
    char output_filename[256];
    snprintf(output_filename, sizeof(output_filename), "%s_stats.txt", filename);
    
    // Écrire les statistiques dans le fichier
    FILE *output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Erreur lors de la création du fichier de sortie\n");
        return;
    }
    
    fprintf(output_file, "Rapport de statistiques de l'image\n");
    fprintf(output_file, "==================================\n");
    fprintf(output_file, "Image: %s\n", filename);
    fprintf(output_file, "Dimensions: %d x %d pixels\n", width, height);
    fprintf(output_file, "Total pixels: %d\n\n", width * height);
    
    fprintf(output_file, "Statistiques des pixels:\n");
    fprintf(output_file, "max_pixel: %d\n", max_pixel);
    fprintf(output_file, "min_pixel: %d\n\n", min_pixel);
    
    fprintf(output_file, "Statistiques des composantes RGB:\n");
    fprintf(output_file, "max_component_R: %d\n", max_r);
    fprintf(output_file, "max_component_G: %d\n", max_g);
    fprintf(output_file, "max_component_B: %d\n", max_b);
    fprintf(output_file, "min_component_R: %d\n", min_r);
    fprintf(output_file, "min_component_G: %d\n", min_g);
    fprintf(output_file, "min_component_B: %d\n", min_b);
    
    fclose(output_file);
    
    printf("Rapport de statistiques écrit dans: %s\n", output_filename);

}
void color_red(char *source_path)
{
    int width, height, channel_count;
    unsigned char *data;
    
    read_image_data(source_path, &data, &width, &height, &channel_count);
    
    for (int i = 0; i < width * height; i++) {
        int pixel_index = i * 3;
        
        data[pixel_index + 1] = 0;  // vert = 0
        data[pixel_index + 2] = 0;  // Bleu = 0
    }
    
    // Enregistrement de l'image
    write_image_data("image_out.bmp", data, width, height);
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