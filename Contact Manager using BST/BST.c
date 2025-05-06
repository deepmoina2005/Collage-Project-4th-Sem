#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the contact node
typedef struct Contact {
    char name[50];
    char number[15];
    struct Contact* left;
    struct Contact* right;
} Contact;

// Function to create a new contact node
Contact* createContact(char name[], char number[]) {
    Contact* newContact = (Contact*)malloc(sizeof(Contact));
    if (!newContact) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(newContact->name, name);
    strcpy(newContact->number, number);
    newContact->left = newContact->right = NULL;
    return newContact;
}

// Insert contact into BST
Contact* insert(Contact* root, char name[], char number[]) {
    if (root == NULL) {
        return createContact(name, number);
    }

    int cmp = strcmp(name, root->name);
    if (cmp < 0) {
        root->left = insert(root->left, name, number);
    } else if (cmp > 0) {
        root->right = insert(root->right, name, number);
    } else {
        printf("Contact with this name already exists!\n");
    }
    return root;
}

// In-order traversal to display contacts alphabetically
void displayInOrder(Contact* root) {
    if (root != NULL) {
        displayInOrder(root->left);
        printf("Name: %s, Number: %s\n", root->name, root->number);
        displayInOrder(root->right);
    }
}

// Search for a contact
Contact* search(Contact* root, char name[]) {
    if (root == NULL || strcmp(name, root->name) == 0) {
        return root;
    }

    if (strcmp(name, root->name) < 0) {
        return search(root->left, name);
    } else {
        return search(root->right, name);
    }
}

// Find minimum value node (used in delete)
Contact* findMin(Contact* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Delete a contact
Contact* deleteContact(Contact* root, char name[]) {
    if (root == NULL) return NULL;

    int cmp = strcmp(name, root->name);
    if (cmp < 0) {
        root->left = deleteContact(root->left, name);
    } else if (cmp > 0) {
        root->right = deleteContact(root->right, name);
    } else {
        if (root->left == NULL) {
            Contact* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Contact* temp = root->left;
            free(root);
            return temp;
        }

        Contact* temp = findMin(root->right);
        strcpy(root->name, temp->name);
        strcpy(root->number, temp->number);
        root->right = deleteContact(root->right, temp->name);
    }
    return root;
}

// Clear memory
void freeTree(Contact* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main program
int main() {
    Contact* root = NULL;
    int choice;
    char name[50], number[15];

    while (1) {
        printf("\n--- Contact Manager ---\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Delete Contact\n");
        printf("4. Display All Contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline

                printf("Enter number: ");
                fgets(number, sizeof(number), stdin);
                number[strcspn(number, "\n")] = '\0';

                root = insert(root, name, number);
                break;

            case 2:
                printf("Enter name to search: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';

                Contact* found = search(root, name);
                if (found) {
                    printf("Found - Name: %s, Number: %s\n", found->name, found->number);
                } else {
                    printf("Contact not found.\n");
                }
                break;

            case 3:
                printf("Enter name to delete: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';

                root = deleteContact(root, name);
                printf("Contact deleted if it existed.\n");
                break;

            case 4:
                printf("All Contacts (Alphabetical Order):\n");
                displayInOrder(root);
                break;

            case 5:
                printf("Exiting...\n");
                freeTree(root); // Free allocated memory
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
