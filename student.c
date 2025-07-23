#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Student {
    char name[50];
    int age;
    float marks;
};

struct Student students[MAX];
int count = 0;

void addStudent();
void displayStudents();
void deleteStudent();
void searchStudent();
void sortStudents();
void updateStudent();
void exportToCSV();
void saveToFile();
void loadFromFile();

int main() {
    int choice;
    loadFromFile();

    while (1) {
        printf("\033[1;34m\n===== Student Management System =====\033[0m\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Delete Student\n");
        printf("4. Search Student\n");
        printf("5. Sort Students by Marks (Descending)\n");
        printf("6. Update Student\n");
        printf("7. Export to CSV\n");
        printf("8. Save & Exit\n");
        printf("\033[1;33mEnter your choice:\033[0m ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: deleteStudent(); break;
            case 4: searchStudent(); break;
            case 5: sortStudents(); break;
            case 6: updateStudent(); break;
            case 7: exportToCSV(); break;
            case 8: saveToFile(); printf("Data saved. Exiting...\n"); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

void addStudent() {
    if (count >= MAX) {
        printf("Student list is full!\n");
        return;
    }
    printf("Enter name: ");
    scanf("%s", students[count].name);
    printf("Enter age: ");
    scanf("%d", &students[count].age);
    printf("Enter marks: ");
    scanf("%f", &students[count].marks);
    count++;
    printf("\033[1;32mStudent added successfully!\033[0m\n");
}

void displayStudents() {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }
    printf("\n===== Student List =====\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Name: %s | Age: %d | Marks: %.2f\n", i+1, students[i].name, students[i].age, students[i].marks);
    }
}

void deleteStudent() {
    char name[50];
    printf("Enter name of student to delete: ");
    scanf("%s", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].name, name) == 0) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            printf("\033[1;31mStudent deleted successfully!\033[0m\n");
            return;
        }
    }
    printf("Student not found!\n");
}

void searchStudent() {
    char name[50];
    printf("Enter name to search: ");
    scanf("%s", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("Found: Name: %s | Age: %d | Marks: %.2f\n", students[i].name, students[i].age, students[i].marks);
            return;
        }
    }
    printf("Student not found!\n");
}

void sortStudents() {
    struct Student temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (students[i].marks < students[j].marks) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("Students sorted by marks in descending order!\n");
}

void updateStudent() {
    char name[50];
    printf("Enter name of student to update: ");
    scanf("%s", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("Enter new age: ");
            scanf("%d", &students[i].age);
            printf("Enter new marks: ");
            scanf("%f", &students[i].marks);
            printf("\033[1;32mStudent updated successfully!\033[0m\n");
            return;
        }
    }
    printf("Student not found!\n");
}

void exportToCSV() {
    FILE *file = fopen("students.csv", "w");
    if (file == NULL) {
        printf("Error exporting to CSV!\n");
        return;
    }
    fprintf(file, "Name,Age,Marks\n");
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s,%d,%.2f\n", students[i].name, students[i].age, students[i].marks);
    }
    fclose(file);
    printf("\033[1;32mData exported to students.csv!\033[0m\n");
}

void saveToFile() {
    FILE *file = fopen("students.dat", "wb");
    if (file == NULL) {
        printf("Error saving file!\n");
        return;
    }
    fwrite(&count, sizeof(int), 1, file);
    fwrite(students, sizeof(struct Student), count, file);
    fclose(file);
}

void loadFromFile() {
    FILE *file = fopen("students.dat", "rb");
    if (file == NULL) {
        return;
    }
    fread(&count, sizeof(int), 1, file);
    fread(students, sizeof(struct Student), count, file);
    fclose(file);
}
