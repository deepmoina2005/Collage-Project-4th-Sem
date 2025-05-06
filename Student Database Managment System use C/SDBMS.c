#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Structure to represent a student
struct Student {
    int rollNumber;
    char name[50];
    float marks;
};

// Function to add a new student
void addStudent(struct Student* students, int* count) {
    printf("Enter roll number: ");
    scanf("%d", &students[*count].rollNumber);
    printf("Enter student name: ");
    getchar();  // Consume leftover newline character
    fgets(students[*count].name, 50, stdin);
    students[*count].name[strcspn(students[*count].name, "\n")] = '\0';  // Remove newline
    printf("Enter marks: ");
    scanf("%f", &students[*count].marks);
    (*count)++;
    printf("Student added successfully!\n");
}

// Function to display all students
void displayStudents(struct Student* students, int count) {
    printf("\nStudent List:\n");
    for (int i = 0; i < count; i++) {
        printf("Roll No: %d, Name: %s, Marks: %.2f\n", students[i].rollNumber, students[i].name, students[i].marks);
    }
}

// Function to update a student's information
void updateStudent(struct Student* students, int count) {
    int rollNumber;
    printf("Enter roll number of the student to update: ");
    scanf("%d", &rollNumber);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == rollNumber) {
            found = 1;
            printf("Student found. Enter new name: ");
            getchar();  // Consume leftover newline character
            fgets(students[i].name, 50, stdin);
            students[i].name[strcspn(students[i].name, "\n")] = '\0';  // Remove newline
            printf("Enter new marks: ");
            scanf("%f", &students[i].marks);
            printf("Student updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Student with roll number %d not found.\n", rollNumber);
    }
}

// Function to delete a student record
void deleteStudent(struct Student* students, int* count) {
    int rollNumber;
    printf("Enter roll number of the student to delete: ");
    scanf("%d", &rollNumber);

    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (students[i].rollNumber == rollNumber) {
            found = 1;
            // Shift remaining students left to delete the record
            for (int j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
            }
            (*count)--;  // Decrease the student count
            printf("Student deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Student with roll number %d not found.\n", rollNumber);
    }
}

// Function to search for a student by roll number
void searchStudent(struct Student* students, int count) {
    int rollNumber;
    printf("Enter roll number to search for: ");
    scanf("%d", &rollNumber);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == rollNumber) {
            found = 1;
            printf("Student found!\n");
            printf("Roll No: %d, Name: %s, Marks: %.2f\n", students[i].rollNumber, students[i].name, students[i].marks);
            break;
        }
    }

    if (!found) {
        printf("Student with roll number %d not found.\n", rollNumber);
    }
}

// Function to display the menu
void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Add Student\n");
    printf("2. Display Students\n");
    printf("3. Update Student\n");
    printf("4. Delete Student\n");
    printf("5. Search Student\n");
    printf("6. Exit\n");
}

int main() {
    struct Student students[MAX];
    int studentCount = 0;
    int choice;

    // Main loop
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addStudent(students, &studentCount);
                break;
            case 2:
                displayStudents(students, studentCount);
                break;
            case 3:
                updateStudent(students, studentCount);
                break;
            case 4:
                deleteStudent(students, &studentCount);
                break;
            case 5:
                searchStudent(students, studentCount);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 6);

    return 0;
}