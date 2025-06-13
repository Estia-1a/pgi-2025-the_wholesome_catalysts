#ifndef FEATURES_H
#define FEATURES_H


void helloWorld();
void dimension (char *source_path); /*25*/
void first_pixel (char *source_path); /*24*/
void tenth_pixel (char *source_path); /*23*/
void second_line(char *source_path); /*22*/
void print_pixel( char *filename, int x, int y ); /*21*/
void max_pixel (char *filename); /*20*/
void min_pixel (char *filename); /*19*/
void max_component (char *source_path, char *component); /*18*/
void min_component (char *source_path, char *component); /*17*/
void stat_report(char * filename);
void color_red(char * filename);
void color_green(char * filename);
void color_blue(char * filename);
void color_gray(char * filename);
void invert(char * filename);
void color_gray_luminance(char * filename);
void rotate_cw(char * filename);
void rotate_acw(char * filename);
void mirror_horizontal(char * filename);
void mirror_vertical(char * filename);
void mirror_total(char * filename);
void scale_crop(char * filename);
void scale_nearest(char * filename);
void scale_bilinear(char * filename);
void color_desaturate(char * filename);

#endif
