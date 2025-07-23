#include <stdio.h>

int main(void) {
    int score[3]; // Use square brackets for arrays

    // Assign values
    score[0] = 73;
    score[1] = 74;
    score[2] = 33;

    // Calculate average
    float average = (score[0] + score[1] + score[2]) / 3.0;

    // Print average
    printf("Average score is %.2f\n", average);

    return 0;
}
