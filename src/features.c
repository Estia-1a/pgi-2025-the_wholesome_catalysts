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

void helloWorld() {
    printf("Hello World !");
}

void dimension (char *source_path){

    unsigned char* data;

    int width =0;
    int height = 0;
    int channel_count = 0;
    
    int result = read_image_data(source_path, &data, &width, &height, &channel_count);
    
    if (result > 0){

        printf("dimension: %d, %d\n", width, height);
    }
    return ;

}

void first_pixel (char *source_path){
    int width, height, channel_count;
    unsigned char* data;

    read_image_data(source_path, &data, &width, &height, &channel_count);
    
    unsigned char R = data[0];
    unsigned char G = data[1];
    unsigned char B = data[2];
    printf("first_pixel: %d, %d, %d",R,G,B);
}

void second_line(char *source_path) {
    int width, height, channels;
    unsigned char *data;
    

    int result = read_image_data(source_path, &data, &width, &height, &channels);
    
    if (result != 0) {
        printf("Error: Failed to read image data from %s (error code: %d)\n", source_path, result);
        return;
    }
    
    if (height < 2) {
        printf("Error: Image must have at least 2 pixels height\n");

        return;
    }
    
    int pixel_index = 3 * width;
    
    unsigned char R = data[pixel_index];     
    unsigned char G = data[pixel_index + 1]; 
    unsigned char B = data[pixel_index + 2]; 
    
    printf("second_line: %d, %d, %d\n", R, G, B);
    
}