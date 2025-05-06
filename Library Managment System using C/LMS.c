#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

// Book structure
struct Book {
    int id;
    char title[100];
    char author[100];
    int isIssued; // 0 = available, 1 = issued
};

struct Book library[MAX];
int count = 0;

// Add a new book
void addBook() {
    printf("Enter Book ID: ");
    scanf("%d", &library[count].id);
    getchar();
    printf("Enter Book Title: ");
    fgets(library[count].title, 100, stdin);
    library[count].title[strcspn(library[count].title, "\n")] = '\0';

    printf("Enter Author Name: ");
    fgets(library[count].author, 100, stdin);
    library[count].author[strcspn(library[count].author, "\n")] = '\0';

    library[count].isIssued = 0;
    count++;

    printf("Book added successfully!\n");
}

// Display all books
void displayBooks() {
    printf("\nLibrary Books:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Title: %s | Author: %s | Status: %s\n",
               library[i].id,
               library[i].title,
               library[i].author,
               library[i].isIssued ? "Issued" : "Available");
    }
}

// Search for a book
void searchBook() {
    int id;
    printf("Enter Book ID to search: ");
    scanf("%d", &id);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (library[i].id == id) {
            found = 1;
            printf("Book Found:\n");
            printf("Title: %s\nAuthor: %s\nStatus: %s\n",
                   library[i].title,
                   library[i].author,
                   library[i].isIssued ? "Issued" : "Available");
            break;
        }
    }
    if (!found)
        printf("Book with ID %d not found.\n", id);
}

// Issue a book
void issueBook() {
    int id;
    printf("Enter Book ID to issue: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (library[i].id == id) {
            if (library[i].isIssued) {
                printf("Book already issued.\n");
                return;
            }
            library[i].isIssued = 1;
            printf("Book issued successfully!\n");
            return;
        }
    }
    printf("Book with ID %d not found.\n", id);
}

// Return a book
void returnBook() {
    int id;
    printf("Enter Book ID to return: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (library[i].id == id) {
            if (!library[i].isIssued) {
                printf("Book was not issued.\n");
                return;
            }
            library[i].isIssued = 0;
            printf("Book returned successfully!\n");
            return;
        }
    }
    printf("Book with ID %d not found.\n", id);
}

// Delete a book
void deleteBook() {
    int id;
    printf("Enter Book ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (library[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                library[j] = library[j + 1];
            }
            count--;
            printf("Book deleted successfully!\n");
            return;
        }
    }
    printf("Book with ID %d not found.\n", id);
}

// Menu
void menu() {
    printf("\nLibrary Management System\n");
    printf("1. Add Book\n");
    printf("2. View All Books\n");
    printf("3. Search Book\n");
    printf("4. Issue Book\n");
    printf("5. Return Book\n");
    printf("6. Delete Book\n");
    printf("7. Exit\n");
}

int main() {
    int choice;
    do {
        menu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: deleteBook(); break;
            case 7: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 7);
    return 0;
}