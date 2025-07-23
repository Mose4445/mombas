#include <stdio.h>

// Function prototypes
void calculator();
void factorial();
void evenOdd();

int main() {
    int choice;

    while (1) {
        // Display menu
        printf("\n==== MENU ====\n");
        printf("1. Calculator (Add, Sub, Mul, Div)\n");
        printf("2. Factorial of a number\n");
        printf("3. Even/Odd Checker\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                calculator();
                break;
            case 2:
                factorial();
                break;
            case 3:
                evenOdd();
                break;
            case 4:
                printf("Exiting... Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// Calculator Function
void calculator() {
    int a, b;
    char op;

    printf("\nEnter expression (e.g., 4 + 3): ");
    scanf("%d %c %d", &a, &op, &b);

    switch (op) {
        case '+':
            printf("Result: %d\n", a + b);
            break;
        case '-':
            printf("Result: %d\n", a - b);
            break;
        case '*':
            printf("Result: %d\n", a * b);
            break;
        case '/':
            if (b != 0)
                printf("Result: %.2f\n", (float)a / b);
            else
                printf("Error: Division by zero!\n");
            break;
        default:
            printf("Invalid operator!\n");
    }
}

// Factorial Function
void factorial() {
    int num;
    unsigned long long fact = 1;

    printf("\nEnter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factorial of negative number doesn't exist!\n");
        return;
    }

    for (int i = 1; i <= num; i++) {
        fact *= i;
    }
    printf("Factorial of %d = %llu\n", num, fact);
}

// Even/Odd Checker
void evenOdd() {
    int num;
    printf("\nEnter a number: ");
    scanf("%d", &num);

    if (num % 2 == 0)
        printf("%d is Even\n", num);
    else
        printf("%d is Odd\n", num);
}
