#include <string.h>
#include "config/coloredBitmap.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   u: Unit of the output value. It could be 'bt' bits, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored image size Bitmap (based on the unit passed parametter)
float coloredBitmap(int w, int h, char* unit) {
   float sizeInBits = w * h * 24; // 24 bits pour une image couleur

    // Conversion selon l'unité demandée
    if (strcmp(unit, "bt") == 0) {
        return sizeInBits; // En bits
    } else if (strcmp(unit, "ko") == 0) {
        return sizeInBits / 1024; // En kilobits
    } else if (strcmp(unit, "mo") == 0) {
        return sizeInBits / (1024 * 1024); // En megabits
    } else if (strcmp(unit, "go") == 0) {
        return sizeInBits / (1024 * 1024 * 1024); // En gigabits
    } else {
        // Unité non reconnue, on retourne 0 ou on pourrait gérer une erreur
        return 0;
    }
}