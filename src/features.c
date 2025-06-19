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

    int largeur = 0;
    int hauteur = 0;
    int compteur = 0;

    int result = read_image_data(source_path, &data, &largeur, &hauteur, &compteur);

    if (result > 0)
    {

        printf("dimension: %d, %d\n", largeur, hauteur);
    }
    return;
}

void first_pixel(char *source_path)
{
    int largeur, hauteur, compteur;
    unsigned char *data;

    read_image_data(source_path, &data, &largeur, &hauteur, &compteur);

    unsigned char R = data[0];
    unsigned char G = data[1];
    unsigned char B = data[2];
    printf("first_pixel: %d, %d, %d", R, G, B);
}

void tenth_pixel(char *source_path)
{
    int largeur, hauteur, compteur;
    unsigned char *data;

    read_image_data(source_path, &data, &largeur, &hauteur, &compteur);

    int pixel = 9;                
    int res = pixel * 3; 

    unsigned char R = data[res];
    unsigned char G = data[res + 1];
    unsigned char B = data[res + 2];

    printf("tenth_pixel: %d, %d, %d", R, G, B);
}

/* #22 */

void second_line(char *source_path)
{
    int largeur, hauteur, compteur;
    unsigned char *data;

    read_image_data(source_path, &data, &largeur, &hauteur, &compteur);

    int ligne = 1;                                    
    int colonne = 0;                                  
    int res = (ligne * largeur + colonne) * 3; 

    unsigned char R = data[res];
    unsigned char G = data[res + 1];
    unsigned char B = data[res + 2];

    printf("second_line : %d, %d, %d", R, G, B);
}


void print_pixel(char *source_path, int x, int y) {
    unsigned char *data = NULL;
    int largeur, hauteur, nb_canaux;
    pixelRGB *pixel = NULL;

    read_image_data(source_path, &data, &largeur, &hauteur, &nb_canaux);
    
    pixel = get_pixel(data, largeur, hauteur, nb_canaux, x, y);

    if (pixel != NULL) {
        printf("print_pixel (%d, %d): %d, %d, %d\n", x, y, pixel->R, pixel->G, pixel->B);
    }

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

    int somme_min = 256 * 3 + 1; 
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
    int largeur, hauteur, compteur;
    unsigned char *data;

    read_image_data(source_path, &data, &largeur, &hauteur, &compteur);

    if (compteur < 3) {
        printf("Image must have at least 3 channels (R, G, B)\n");
        return;
    }

    int max_value = -1;
    int max_x = 0;
    int max_y = 0;

    int index = 0;
    char c = component[0];
    int componentt = (c == 'R') ? 0 : (c == 'G') ? 1 : 2;

    for (int y = 0; y < hauteur; y++) {
        for (int x = 0; x < largeur; x++) {
            index = (y * largeur + x) * compteur;
            int value = data[index + componentt];

            if (value > max_value) {
                max_value = value;
                max_x = x;
                max_y = y;

                if (max_value == 255) { 
                    goto print_result;
                }
            }
        }
    }

print_result:
    printf("max_component %c (%d, %d): %d\n", c, max_x, max_y, max_value);

    free(data);
}

/*#17*/

void min_component(char *source_path, char *component)
{
    int largeur, hauteur, compteur;
    unsigned char *data;

    read_image_data(source_path, &data, &largeur, &hauteur, &compteur);

    if (compteur < 3) {
        printf("l'image doit comporter au moins 3 canaux (R, G, B)\n");
        return;
    }

    int min_value = 256;
    int min_x = 0;
    int min_y = 0;

    int index = 0;
    char c = component[0];
    int componentt = (c == 'R') ? 0 : (c == 'G') ? 1 : 2;

    for (int y = 0; y < hauteur; y++) {
        for (int x = 0; x < largeur; x++) {
            index = (y * largeur + x) * compteur;
            int value = data[index + componentt];

            if (value < min_value) {
                min_value = value;
                min_x = x;
                min_y = y;

                if (min_value == 0) { 
                    goto print_result;
                }
            }
        }
    }

print_result:
    printf("min_component %c (%d, %d): %d\n", c, min_x, min_y, min_value);

    free(data);
}



/*#16*/

void stat_report(char *source_path)
{
    int largeur, hauteur, compteur;
    unsigned char *data;
    
    read_image_data(source_path, &data, &largeur, &hauteur, &compteur);
    
    
    unsigned char max_pixel = 0;
    unsigned char min_pixel = 255;
    unsigned char max_r = 0, max_g = 0, max_b = 0;
    unsigned char min_r = 255, min_g = 255, min_b = 255;
    
    
    for (int i = 0; i < largeur * hauteur; i++) {
        int pixel = i * 3; 
        
        unsigned char r = data[pixel];
        unsigned char g = data[pixel + 1];
        unsigned char b = data[pixel + 2];
        
        
        unsigned char luminance = (unsigned char)(0.299 * r + 0.587 * g + 0.114 * b);
        
        
        if (luminance > max_pixel) max_pixel = luminance;
        if (luminance < min_pixel) min_pixel = luminance;
        
        
        if (r > max_r) max_r = r;
        if (r < min_r) min_r = r;
        
        if (g > max_g) max_g = g;
        if (g < min_g) min_g = g;
        
        if (b > max_b) max_b = b;
        if (b < min_b) min_b = b;
    }
    
    
    char output_filename[256];
    snprintf(output_filename, sizeof(output_filename), "%s_stats.txt", source_path);
    
    
    FILE *output_file = fopen(output_filename, "w");
    
    fprintf(output_file, "Rapport de statistiques de l'image\n");
    fprintf(output_file, "==================================\n");
    fprintf(output_file, "Image: %s\n", source_path);
    fprintf(output_file, "Dimensions: %d x %d pixels\n", largeur, hauteur);
    fprintf(output_file, "Total pixels: %d\n\n", largeur * hauteur);
    
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
    
    printf("Le rapport des statistiques est dans: %s\n", output_filename) ;

}

/*#15*/

void color_red(char *source_path)
{
    int largeur, hauteur, nb_canaux;
    unsigned char *donnee;
    
    read_image_data(source_path, &donnee, &largeur, &hauteur, &nb_canaux);
    
    for (int i = 0; i < largeur * hauteur; i++) {
        int compteur = i * 3;
        
        donnee[compteur + 1] = 0;  
        donnee[compteur + 2] = 0;  
    }
    
    
    write_image_data("image_out.bmp", donnee, largeur, hauteur);
}

/*#14*/

void color_green(char *source_path)
{
    int largeur, hauteur, nb_canaux;
    unsigned char *donnee;
    
    read_image_data(source_path, &donnee, &largeur, &hauteur, &nb_canaux)  ;
    
    for (int i = 0; i < largeur * hauteur; i++) {
        int compteur = i * 3;
        
        donnee[compteur] = 0;  
        donnee[compteur + 2] = 0;  
    }
    
    
    write_image_data("image_out.bmp", donnee, largeur, hauteur);
}

/*#13*/

void color_blue(char *source_path)
{
    int largeur, hauteur, nb_canaux;
    unsigned char *donnee;
    
    read_image_data(source_path, &donnee, &largeur, &hauteur, &nb_canaux)  ;
    
    for (int i = 0; i < largeur * hauteur; i++) {
        int compteur = i * 3;
        
        donnee[compteur] = 0;  
        donnee[compteur + 1] = 0;  
    }
    
    
    write_image_data("image_out.bmp", donnee, largeur, hauteur);
}

/*#12*/

void color_gray(char *source_path) {    
    int largeur, hauteur, nb_canaux;    
    unsigned char *donnee;    
    read_image_data(source_path, &donnee, &largeur, &hauteur, &nb_canaux);      
    for (int i = 0; i < largeur * hauteur; i++) {        
        int res = i * 3;        
        unsigned char r = donnee[res];        
        unsigned char g = donnee[res + 1];        
        unsigned char b = donnee[res + 2];          
        unsigned char gray = (r + g + b) / 3;        
        donnee[res] = gray;            
        donnee[res + 1] = gray;        
        donnee[res + 2] = gray;  
    }
 
    write_image_data("image_out.bmp", donnee, largeur, hauteur);
}

/*#11*/

void invert(char *source_path)
{
    int largeur, hauteur, nb_canaux;
    unsigned char *donnee;
    read_image_data(source_path, &donnee, &largeur, &hauteur, &nb_canaux);

    for (int i = 0; i < largeur * hauteur; i++) {
        int res = i * 3;

        donnee[res] = 255 - donnee[res];         // R inversé
        donnee[res + 1] = 255 - donnee[res + 1]; // G inversé
        donnee[res + 2] = 255 - donnee[res + 2]; // B inversé
    }

    write_image_data("image_out.bmp", donnee, largeur, hauteur);
}

/*#10*/

void color_gray_luminance(char *source_path)
{
    int largeur, hauteur, nb_canaux;
    unsigned char *donnee;
    
    read_image_data(source_path, &donnee, &largeur, &hauteur, &nb_canaux);
    
    
    for (int i = 0; i < largeur * hauteur; i++) {
        int compteur = i * 3;
        
        unsigned char r = donnee[compteur];
        unsigned char g = donnee[compteur + 1];
        unsigned char b = donnee[compteur + 2];
        
        
        unsigned char luminance = 0.21 * r + 0.72 * g + 0.07 * b;
        
        donnee[compteur] = luminance;    
        donnee[compteur + 1] = luminance; 
        donnee[compteur + 2] = luminance; 
    }
     write_image_data("image_out.bmp", donnee, largeur, hauteur);
}

void rotate_cw(char *source_path)
{
    int largeur, hauteur, nb_canaux;
    unsigned char *data;

    read_image_data(source_path, &data, &largeur, &hauteur, &nb_canaux);


    int new_largeur = hauteur;
    int new_hauteur = largeur;

    unsigned char *rotated_data = malloc(new_largeur * new_hauteur * nb_canaux);
    if (!rotated_data) {
        printf("Memory allocation failed\n");
        free(data);
        return;
    }

    for (int y = 0; y < hauteur; y++) {
        for (int x = 0; x < largeur; x++) {
            int src_index = (y * largeur + x) * nb_canaux;
            int dst_x = hauteur - 1 - y;
            int dst_y = x;
            int dst_index = (dst_y * new_largeur + dst_x) * nb_canaux;



            for (int c = 0; c < nb_canaux; c++) {
                rotated_data[dst_index + c] = data[src_index + c];
            }
        }
    }


    write_image_data("image_out.bmp", rotated_data, new_largeur, new_hauteur);

    free(data);
    free(rotated_data);

    printf("Image rotated 90° clockwise and saved as image_out.bmp\n");
}

void rotate_acw(char *source_path)
{
    int largeur, hauteur, nb_canaux;
    unsigned char *data;

    read_image_data(source_path, &data, &largeur, &hauteur, &nb_canaux);

    if (nb_canaux < 3) {
        printf("Image must have at least 3 channels\n");
        free(data);
        return;
    }

    int new_largeur = hauteur;
    int new_hauteur = largeur;

    unsigned char *rotated_data = malloc(new_largeur * new_hauteur * nb_canaux);
    if (!rotated_data) {
        printf("Memory allocation failed\n");
        free(data);
        return;
    }

    for (int y = 0; y < hauteur; y++) {
        for (int x = 0; x < largeur; x++) {
            int src_index = (y * largeur + x) * nb_canaux;
            int dst_x = y;
            int dst_y = largeur - 1 - x;
            int dst_index = (dst_y * new_largeur + dst_x) * nb_canaux;

            for (int c = 0; c < nb_canaux; c++) {
                rotated_data[dst_index + c] = data[src_index + c];
            }
        }
    }
    
    write_image_data("image_out.bmp", rotated_data, new_largeur, new_hauteur);

    free(data);
    free(rotated_data);

    printf("Image rotated 90° anti-clockwise and saved as image_out.bmp\n");
}  


void mirror_horizontal(char *source_path)
{
    int largeur, hauteur, nb_canaux;
    unsigned char *data;
 
    read_image_data(source_path, &data, &largeur, &hauteur, &nb_canaux);
 
    
    for (int y = 0; y < hauteur; y++) {
        for (int x = 0; x < largeur / 2; x++) {
            int left_index = (y * largeur + x) * nb_canaux;
            int right_index = (y * largeur + (largeur - 1 - x)) * nb_canaux;
 
            
            for (int c = 0; c < nb_canaux; c++) {
                unsigned char temp = data[left_index + c];
                data[left_index + c] = data[right_index + c];
                data[right_index + c] = temp;
            }
        }
    }
 
    write_image_data("image_out.bmp", data, largeur, hauteur);
 
}

void mirror_vertical(char *source_path)
{
    int largeur, hauteur, nb_canaux;
    unsigned char *data;
    
    read_image_data(source_path, &data, &largeur, &hauteur, &nb_canaux);
    
    for (int y = 0; y < hauteur / 2; y++) {
        for (int x = 0; x < largeur; x++) {
    
            int top_index = (y * largeur + x) * 3;
            int bottom_index = ((hauteur - 1 - y) * largeur + (largeur - 1 - x)) * 3;
            
            for (int c = 0; c < 3; c++) {
                unsigned char temp = data[top_index + c];
                data[top_index + c] = data[bottom_index + c];
                data[bottom_index + c] = temp;
            }
        }
    }

    
    write_image_data("image_out.bmp", data, largeur, hauteur);
}


void mirror_total(char *source_path)
{
    int largeur, hauteur, nb_canaux;
    unsigned char *data;
    
    read_image_data(source_path, &data, &largeur, &hauteur, &nb_canaux);
    
    for (int y = 0; y < hauteur / 2; y++) {
        for (int x = 0; x < largeur; x++) {
            
            int top_index = (y * largeur + x) * 3;
            int bottom_index = ((hauteur - 1 - y) * largeur + (largeur - 1 - x)) * 3;
            
            
            for (int c = 0; c < 3; c++) {
                unsigned char temp = data[top_index + c];
                data[top_index + c] = data[bottom_index + c];
                data[bottom_index + c] = temp;
            }
        }
    }
    
    
    if (hauteur % 2 == 1) {
        int middle_y = hauteur / 2;
        for (int x = 0; x < largeur / 2; x++) {
            int left_index = (middle_y * largeur + x) * 3;
            int right_index = (middle_y * largeur + (largeur - 1 - x)) * 3;
            
            
            for (int c = 0; c < 3; c++) {
                unsigned char temp = data[left_index + c];
                data[left_index + c] = data[right_index + c];
                data[right_index + c] = temp;
            }
        }
    }
    
    write_image_data("image_out.bmp", data, largeur, hauteur);
    
}

void scale_crop_internal(char *source_path, int center_x, int center_y, int crop_largeur, int crop_hauteur)
{
    int largeur, hauteur, nb_canaux;
    unsigned char *data;

    read_image_data(source_path, &data, &largeur, &hauteur, &nb_canaux);

    if (nb_canaux < 3) {
        printf("Image must have at least 3 channels\n");
        free(data);
        return;
    }

    unsigned char *cropped_data = calloc(crop_largeur * crop_hauteur * nb_canaux, sizeof(unsigned char));
    if (!cropped_data) {
        printf("Memory allocation failed\n");
        free(data);
        return;
    }

    int start_x = center_x - crop_largeur / 2;
    int start_y = center_y - crop_hauteur / 2;

    for (int y = 0; y < crop_hauteur; y++) {
        for (int x = 0; x < crop_largeur; x++) {
            int src_x = start_x + x;
            int src_y = start_y + y;

            int dst_index = (y * crop_largeur + x) * nb_canaux;

            if (src_x >= 0 && src_x < largeur && src_y >= 0 && src_y < hauteur) {
                int src_index = (src_y * largeur + src_x) * nb_canaux;

                for (int c = 0; c < nb_canaux; c++) {
                    cropped_data[dst_index + c] = data[src_index + c];
                }
            }
        }
    }

    write_image_data("image_out.bmp", cropped_data, crop_largeur, crop_hauteur);

    free(data);
    free(cropped_data);

    printf("Image cropped around (%d, %d) to %dx%d and saved as image_out.bmp\n", center_x, center_y, crop_largeur, crop_hauteur);
}


void scale_nearest(char *source_path)
{
}
void scale_bilinear(char *source_path)
{
}
void color_desaturate(char *source_path)
{
    int largeur, hauteur, nb_canaux;
    unsigned char *donnee;
    

    read_image_data(source_path, &donnee, &largeur, &hauteur, &nb_canaux);
    

    for (int i = 0; i < largeur * hauteur; i++) {
        int index = i * 3;
        
        unsigned char r = donnee[index];
        unsigned char g = donnee[index + 1];
        unsigned char b = donnee[index + 2];
        

        unsigned char max_val = r;
        if (g > max_val) max_val = g;
        if (b > max_val) max_val = b;
        
        unsigned char min_val = r;
        if (g < min_val) min_val = g;
        if (b < min_val) min_val = b;
        

        if (max_val == 0) {

            continue;
        }
        
   
        unsigned char luminance = (r + g + b) / 3;
        
        float desaturation_factor = 0.5f; 
        
        donnee[index] = (unsigned char)(r * (1.0f - desaturation_factor) + luminance * desaturation_factor);
        donnee[index + 1] = (unsigned char)(g * (1.0f - desaturation_factor) + luminance * desaturation_factor);
        donnee[index + 2] = (unsigned char)(b * (1.0f - desaturation_factor) + luminance * desaturation_factor);
    }
    
    write_image_data("image_out.bmp", donnee, largeur, hauteur);
}