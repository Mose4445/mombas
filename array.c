#include <stdio.h>
#include <string.h>

// Function to sort integers
void sortIntegers(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to sort names alphabetically
void sortStrings(char arr[][50], int n) {
    char temp[50];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[i], arr[j]) > 0) {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}

// Function to display integers
void displayIntegers(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to display names
void displayNames(char arr[][50], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }
}

// Function to calculate sum and average
void sumAverage(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    float avg = (float)sum / n;
    printf("Sum = %d, Average = %.2f\n", sum, avg);
}

int main() {
    int n, m;
    printf("Enter number of integers: ");
    scanf("%d", &n);
    int numbers[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &numbers[i]);

    printf("Enter number of names: ");
    scanf("%d", &m);
    getchar(); // clear input buffer
    char names[m][50];
    printf("Enter %d names:\n", m);
    for (int i = 0; i < m; i++) {
        fgets(names[i], sizeof(names[i]), stdin);
        names[i][strcspn(names[i], "\n")] = '\0';
    }

    int choice;
    do {
        printf("\n==== MENU ====\n");
        printf("1. Display Integers\n");
        printf("2. Display Names\n");
        printf("3. Sort Integers\n");
        printf("4. Sort Names\n");
        printf("5. Show Sum and Average of Integers\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Integers: ");
                displayIntegers(numbers, n);
                break;
            case 2:
                printf("Names:\n");
                displayNames(names, m);
                break;
            case 3:
                sortIntegers(numbers, n);
                printf("Integers sorted in ascending order!\n");
                break;
            case 4:
                sortStrings(names, m);
                printf("Names sorted alphabetically!\n");
                break;
            case 5:
                sumAverage(numbers, n);
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}

