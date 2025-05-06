#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Movie {
    char title[100];
    char director[100];
    char genre[50];
    int release_year;
    struct Movie* next;
};
void addMovie(struct Movie** head);
void updateMovie(struct Movie* head);
void deleteMovie(struct Movie** head);
void searchMovie(struct Movie* head);
void displayMovies(struct Movie* head);
int main() {
    struct Movie* head = NULL;
    int choice;

    do {
        printf("\n=== Movie Database System ===\n");
        printf("1. Add Movie\n");
        printf("2. Update Movie\n");
        printf("3. Delete Movie\n");
        printf("4. Search Movie\n");
        printf("5. Display All Movies\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1: addMovie(&head); break;
            case 2: updateMovie(head); break;
            case 3: deleteMovie(&head); break;
            case 4: searchMovie(head); break;
            case 5: displayMovies(head); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}
void addMovie(struct Movie** head) {
    struct Movie* newMovie = (struct Movie*)malloc(sizeof(struct Movie));
    printf("Enter movie title: ");
    fgets(newMovie->title, 100, stdin);
    newMovie->title[strcspn(newMovie->title, "\n")] = '\0';

    printf("Enter director: ");
    fgets(newMovie->director, 100, stdin);
    newMovie->director[strcspn(newMovie->director, "\n")] = '\0';

    printf("Enter genre: ");
    fgets(newMovie->genre, 50, stdin);
    newMovie->genre[strcspn(newMovie->genre, "\n")] = '\0';

    printf("Enter release year: ");
    scanf("%d", &newMovie->release_year);
    getchar(); // consume newline

    newMovie->next = *head;
    *head = newMovie;

    printf("Movie added successfully!\n");
}
void updateMovie(struct Movie* head) {
    char title[100];
    printf("Enter the title of the movie to update: ");
    fgets(title, 100, stdin);
    title[strcspn(title, "\n")] = '\0';

    while (head != NULL) {
        if (strcmp(head->title, title) == 0) {
            printf("Enter new director: ");
            fgets(head->director, 100, stdin);
            head->director[strcspn(head->director, "\n")] = '\0';

            printf("Enter new genre: ");
            fgets(head->genre, 50, stdin);
            head->genre[strcspn(head->genre, "\n")] = '\0';

            printf("Movie updated successfully!\n");
            return;
        }
        head = head->next;
    }
    printf("Movie not found!\n");
}
void deleteMovie(struct Movie** head) {
    char title[100];
    printf("Enter the title of the movie to delete: ");
    fgets(title, 100, stdin);
    title[strcspn(title, "\n")] = '\0';

    struct Movie* temp = *head, *prev = NULL;

    while (temp != NULL && strcmp(temp->title, title) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Movie not found!\n");
        return;
    }

    if (prev == NULL)
        *head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("Movie deleted successfully!\n");
}
void searchMovie(struct Movie* head) {
    char keyword[100];
    int found = 0;
    printf("Enter title or genre to search: ");
    fgets(keyword, 100, stdin);
    keyword[strcspn(keyword, "\n")] = '\0';

    while (head != NULL) {
        if (strstr(head->title, keyword) || strstr(head->genre, keyword)) {
            printf("\nTitle: %s\nDirector: %s\nGenre: %s\nRelease Year: %d\n",
                   head->title, head->director, head->genre, head->release_year);
            found = 1;
        }
        head = head->next;
    }

    if (!found)
        printf("No matching movies found.\n");
}
void displayMovies(struct Movie* head) {
    if (head == NULL) {
        printf("No movies in the database.\n");
        return;
    }

    printf("\n=== Movie List ===\n");
    while (head != NULL) {
        printf("Title: %s\nDirector: %s\nGenre: %s\nRelease Year: %d\n\n",
               head->title, head->director, head->genre, head->release_year);
        head = head->next;
    }
}
