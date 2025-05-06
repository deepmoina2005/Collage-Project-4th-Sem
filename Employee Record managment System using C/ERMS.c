#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

void addEmployee() {
    struct Employee emp;
    FILE *fp = fopen("employees.dat", "ab");
    if (!fp) {
        printf("File error.\n");
        return;
    }

    printf("Enter ID: ");
    scanf("%d", &emp.id);
    getchar();

    printf("Enter Name: ");
    fgets(emp.name, 50, stdin);
    emp.name[strcspn(emp.name, "\n")] = '\0';

    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    fwrite(&emp, sizeof(emp), 1, fp);
    fclose(fp);
    printf("Employee added.\n");
}

void viewEmployees() {
    struct Employee emp;
    FILE *fp = fopen("employees.dat", "rb");
    if (!fp) {
        printf("No data found.\n");
        return;
    }

    printf("\nEmployee Records:\n");
    while (fread(&emp, sizeof(emp), 1, fp)) {
        printf("ID: %d | Name: %s | Salary: %.2f\n", emp.id, emp.name, emp.salary);
    }
    fclose(fp);
}

void searchEmployee() {
    struct Employee emp;
    int id, found = 0;
    FILE *fp = fopen("employees.dat", "rb");
    if (!fp) {
        printf("No data found.\n");
        return;
    }

    printf("Enter ID to search: ");
    scanf("%d", &id);

    while (fread(&emp, sizeof(emp), 1, fp)) {
        if (emp.id == id) {
            printf("Found: ID: %d | Name: %s | Salary: %.2f\n", emp.id, emp.name, emp.salary);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Employee not found.\n");
    fclose(fp);
}

void deleteEmployee() {
    struct Employee emp;
    int id, found = 0;
    FILE *fp = fopen("employees.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (!fp || !temp) {
        printf("File error.\n");
        return;
    }

    printf("Enter ID to delete: ");
    scanf("%d", &id);

    while (fread(&emp, sizeof(emp), 1, fp)) {
        if (emp.id != id) {
            fwrite(&emp, sizeof(emp), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("employees.dat");
    rename("temp.dat", "employees.dat");

    if (found)
        printf("Employee deleted.\n");
    else
        printf("Employee not found.\n");
}

void updateEmployee() {
    struct Employee emp;
    int id, found = 0;
    FILE *fp = fopen("employees.dat", "rb+");

    if (!fp) {
        printf("File error.\n");
        return;
    }

    printf("Enter ID to update: ");
    scanf("%d", &id);

    while (fread(&emp, sizeof(emp), 1, fp)) {
        if (emp.id == id) {
            printf("Enter new name: ");
            getchar();
            fgets(emp.name, 50, stdin);
            emp.name[strcspn(emp.name, "\n")] = '\0';

            printf("Enter new salary: ");
            scanf("%f", &emp.salary);

            fseek(fp, -sizeof(emp), SEEK_CUR);
            fwrite(&emp, sizeof(emp), 1, fp);
            found = 1;
            printf("Employee updated.\n");
            break;
        }
    }

    if (!found)
        printf("Employee not found.\n");
    fclose(fp);
}

void menu() {
    printf("\n--- Employee Management System ---\n");
    printf("1. Add Employee\n");
    printf("2. View Employees\n");
    printf("3. Search Employee\n");
    printf("4. Update Employee\n");
    printf("5. Delete Employee\n");
    printf("6. Exit\n");
}

int main() {
    int choice;
    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addEmployee(); break;
            case 2: viewEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: updateEmployee(); break;
            case 5: deleteEmployee(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}