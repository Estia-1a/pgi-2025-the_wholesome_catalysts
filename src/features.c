#include <estia-image.h>
#include <stdio.h>
#include "features.h"
#include "utils.h"
#include <stdlib.h>

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


void print_pixel(char *source_path, int x, int y) {
    unsigned char *data;
    int width, height, channel_count;
    pixelRGB *pixel = NULL;  

    if (read_image_data(source_path, &data, &width, &height, &channel_count)){
        pixel = get_pixel(data, width, height, channel_count, x, y);
    }

    if (pixel != NULL){
        printf("print_pixel (%d, %d): %d, %d, %d\n", x, y, pixel->R, pixel->G, pixel->B);
    }
    return;
    free(data);
}



/* #20 */


void max_pixel(char *source_path)
{
    int largeur, hauteur, canaux;
    unsigned char *donnees;

    if (read_image_data(source_path, &donnees, &largeur, &hauteur, &canaux) <= 0)
    {
        printf("Erreur : impossible de charger l'image %s\n", source_path);
        return;
    }

    int somme_max = -1;
    int coord_x_max = 0, coord_y_max = 0;
    unsigned char r_max = 0, g_max = 0, b_max = 0;

    for (int ligne = 0; ligne < hauteur; ligne++)
    {
        for (int col = 0; col < largeur; col++)
        {
            int index = (ligne * largeur + col) * canaux;

            unsigned char r = donnees[index];
            unsigned char g = donnees[index + 1];
            unsigned char b = donnees[index + 2];

            int total_rgb = r + g + b;

            if (total_rgb > somme_max)
            {
                somme_max = total_rgb;
                coord_x_max = col;
                coord_y_max = ligne;
                r_max = r;
                g_max = g;
                b_max = b;
            }
        }
    }

    printf("max_pixel (%d, %d): %d, %d, %d\n", coord_x_max, coord_y_max, r_max, g_max, b_max);
}


/* 19 */

void min_pixel(char *source_path)
{
    int largeur, hauteur, canaux;
    unsigned char *donnees;

    if (read_image_data(source_path, &donnees, &largeur, &hauteur, &canaux) <= 0)
    {
        printf("Erreur : impossible de charger l'image %s\n", source_path);
        return;
    }

    int somme_min = 256 * 3 + 1; // valeur plus haute que toute somme RGB possible
    int coord_x_min = 0, coord_y_min = 0;
    unsigned char r_min = 0, g_min = 0, b_min = 0;

    for (int ligne = 0; ligne < hauteur; ligne++)
    {
        for (int col = 0; col < largeur; col++)
        {
            int index = (ligne * largeur + col) * canaux;

            unsigned char r = donnees[index];
            unsigned char g = donnees[index + 1];
            unsigned char b = donnees[index + 2];

            int somme_rgb = r + g + b;

            if (somme_rgb < somme_min)
            {
                somme_min = somme_rgb;
                coord_x_min = col;
                coord_y_min = ligne;
                r_min = r;
                g_min = g;
                b_min = b;
            }
        }
    }

    printf("min_pixel (%d, %d): %d, %d, %d\n", coord_x_min, coord_y_min, r_min, g_min, b_min)  ;
}


/* 18 */
void max_component(char *source_path, char *component)
{
    int width, height, channel_count;
    unsigned char *data;

    read_image_data(source_path, &data, &width, &height, &channel_count);

    if (channel_count < 3) {
        printf("Image must have at least 3 channels (R, G, B)\n");
        return;
    }

    int max_value = -1;
    int max_x = 0;
    int max_y = 0;

    int index = 0;
    char c = component[0];
    int component_offset = (c == 'R') ? 0 : (c == 'G') ? 1 : 2;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            index = (y * width + x) * channel_count;
            int value = data[index + component_offset];

            if (value > max_value) {
                max_value = value;
                max_x = x;
                max_y = y;

                if (max_value == 255) { // valeur max possible
                    goto print_result;
                }
            }
        }
    }

print_result:
    printf("max_component %c (%d, %d): %d\n", c, max_x, max_y, max_value);

    free(data);
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