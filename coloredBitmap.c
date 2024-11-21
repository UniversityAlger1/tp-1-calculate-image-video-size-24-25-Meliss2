#include <string.h>
#include "config/coloredBitmap.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   u: Unit of the output value. It could be 'bt' bits, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored image size Bitmap (based on the unit passed parametter)
float coloredBitmap(int w, int h, char* unit) {
   float tailleOctect=w*h*3;
    if (unit == NULL || strcmp(unit, "bt") == 0) {
        return tailleOctect;
    } else if (strcmp(unit, "ko") == 0) {
        return tailleOctect / 1024;
    } else if (strcmp(unit, "mo") == 0) {
        return tailleOctect / (1024 * 1024);
    } else if (strcmp(unit, "go") == 0) {
        return tailleOctect / (1024*1024*1024);
    } else {
        printf("Invalid unit. Supported units: bytes,KB,MB,GB.\n");
        return -1; 
    }
}

//int main(){
// printf("the size is :%f",coloredBitmap(200, 300,"go"));
//}