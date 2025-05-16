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

typedef struct TSimage
{
  int h, w;
  unsigned char * data;
  /* pixels are stored as 3 bytes, in Red Green Blue order */
} TSimage;
typedef struct TSimage * Timage;

typedef struct TSimage
{
  int h, w;
  unsigned char * data;
  /* pixels are stored as 3 bytes, in Red Green Blue order */
} TSimage;
typedef struct TSimage * Timage;
