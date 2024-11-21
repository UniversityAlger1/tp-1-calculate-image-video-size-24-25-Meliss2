#include <string.h>
#include "config/video.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in second of movie (colored image)
//   durationCredits: duration in second of credit (image Black/White)
//   unit: Unit of the output value. It could be 'bt' byte, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored video size (based on the unit passed parametter)
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
 int colorFrameSize = w * h * 3; // 3 bytes per pixel for RGB
    int grayFrameSize = w * h;     // 1 byte per pixel for grayscale

    // Calculate the total number of frames
    int totalColorFrames = durationMovie * fps;
    int totalGrayFrames = durationCredits * fps;

    // Calculate the total size in bytes
    long long totalSizeBytes = 
        (long long)totalColorFrames * colorFrameSize + 
        (long long)totalGrayFrames * grayFrameSize;

    // Convert the size based on the unit
    float convertedSize = 0.0;
    if (unit == NULL || strcmp(unit, "bt") == 0){
        convertedSize = totalSizeBytes; // bytes
    } else if (strcmp(unit, "ko") == 0) {
        convertedSize = (totalSizeBytes * 8.0) / 1024.0; // kilobits
    } else if (strcmp(unit, "mo") == 0) {
        convertedSize = (totalSizeBytes * 8.0) / (1024.0 * 1024.0); // megabits
    } else if (strcmp(unit, "go") == 0) {
        convertedSize = (totalSizeBytes * 8.0) / (1024.0 * 1024.0 * 1024.0); // gigabits
    } else {
        return 0; // Invalid unit
    }

    return convertedSize;
}