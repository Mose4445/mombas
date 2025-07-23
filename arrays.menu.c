#include <stdio.h>
#include <string.h>

// Function to sort integers
void sortIntegers(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
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

// Function to search for an integer
int searchInteger(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// Function to search for a name
int searchString(char arr[][50], int n, char key[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i], key) == 0)
            return i;
    }
    return -1;
}

int main() {
    int n, m, choice;
    printf("Enter number of integers: ");
    scanf("%d", &n);

    int numbers[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    printf("\nEnter number of names: ");
    scanf("%d", &m);
    getchar(); // clear input buffer
    char names[m][50];

    printf("Enter %d names:\n", m);
    for (int i = 0; i < m; i++) {
        fgets(names[i], sizeof(names[i]), stdin);
        names[i][strcspn(names[i], "\n")] = '\0';
    }

    do {
        printf("\n===== MENU =====\n");
        printf("1. Display Integers\n");
        printf("2. Display Names\n");
        printf("3. Sort Integers\n");
        printf("4. Sort Names\n");
        printf("5. Search Integer\n");
        printf("6. Search Name\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Integers: ");
                for (int i = 0; i < n; i++) printf("%d ", numbers[i]);
                printf("\n");
                break;
            case 2:
                printf("Names:\n");
                for (int i = 0; i < m; i++) printf("%s\n", names[i]);
                break;
            case 3:
                sortIntegers(numbers, n);
                printf("Integers sorted!\n");
                break;
            case 4:
                sortStrings(names, m);
                printf("Names sorted alphabetically!\n");
                break;
            case 5: {
                int key;
                printf("Enter integer to search: ");
                scanf("%d", &key);
                int pos = searchInteger(numbers, n, key);
                if (pos != -1) printf("%d found at position %d\n", key, pos + 1);
                else printf("Integer not found.\n");
                break;
            }
            case 6: {
                char key[50];
                printf("Enter name to search: ");
                fgets(key, sizeof(key), stdin);
                key[strcspn(key, "\n")] = '\0';
                int pos = searchString(names, m, key);
                if (pos != -1) printf("%s found at position %d\n", key, pos + 1);
                else printf("Name not found.\n");
                break;
            }
            case 7:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 7);

    return 0;
}
