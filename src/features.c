#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>

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

        printf("dimension de l'image est : %d, %d\n", width, height);
    }
    return ;
}

