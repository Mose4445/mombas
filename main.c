#include <stdio.h>

int main(void) {
    int num1, num2, sum;

    // Ask for input
    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    // Calculate sum
    sum = num1 + num2;

    // Display result
    printf("The sum of %d and %d is %d\n", num1, num2, sum);

    return 0;
}
