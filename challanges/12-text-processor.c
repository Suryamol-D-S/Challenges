/*(text processor). For a text processor, can you use a doubly linked list
to store text? The idea is to represent a “blob” of text through a struct that contains a
string (for the text) and pointers to preceding and following blobs.
Can you build a function that splits a text blob in two at a given point?
One that joins two consecutive text blobs?
================================================================
OUTPUT :
================================================================

*********Main Menu*********
Choose one option from the following list ...
===============================================
1. Insert at beginning
2. Insert at end
3. Split text blob at specific index
4. Join with next text blob
5. Display
6. Exit
Enter your choice?
1
Enter text to insert at beginning: Hello, 
Node inserted at the beginning

*********Main Menu*********
Choose one option from the following list ...
===============================================
1. Insert at beginning
2. Insert at end
3. Split text blob at specific index
4. Join with next text blob
5. Display
6. Exit
Enter your choice?
2
Enter text to insert at end: World!
Node inserted at the end

*********Main Menu*********
Choose one option from the following list ...
===============================================
1. Insert at beginning
2. Insert at end
3. Split text blob at specific index
4. Join with next text blob
5. Display
6. Exit
Enter your choice?
5

Printing values...
Hello, 
World!

*********Main Menu*********
Choose one option from the following list ...
===============================================
1. Insert at beginning
2. Insert at end
3. Split text blob at specific index
4. Join with next text blob
5. Display
6. Exit
Enter your choice?
4
Nodes joined successfully

*********Main Menu*********
Choose one option from the following list ...
===============================================
1. Insert at beginning
2. Insert at end
3. Split text blob at specific index
4. Join with next text blob
5. Display
6. Exit
Enter your choice?
5

Printing values...
Hello, World!

*********Main Menu*********
Choose one option from the following list ...
===============================================
1. Insert at beginning
2. Insert at end
3. Split text blob at specific index
4. Join with next text blob
5. Display
6. Exit
Enter your choice?
3
Enter index to split text: 6
Text split at position 6

*********Main Menu*********
Choose one option from the following list ...
===============================================
1. Insert at beginning
2. Insert at end
3. Split text blob at specific index
4. Join with next text blob
5. Display
6. Exit
Enter your choice?
5

Printing values...
Hello,
 World!

*********Main Menu*********
Choose one option from the following list ...
===============================================
1. Insert at beginning
2. Insert at end
3. Split text blob at specific index
4. Join with next text blob
5. Display
6. Exit
Enter your choice?
6
=================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for doubly linked list
struct node {
    struct node *prev;
    struct node *next;
    char *text;
    void (*split_text)(struct node *, int); // Function pointer for splitting text
    void (*join_next)(struct node *); // Function pointer for joining with next node
};

// Global variable for the head of the doubly linked list
struct node *head = NULL;

// Function prototypes
void insert_beginning(char *text);
void insert_last(char *text);
void display();
void free_list();
void split_text(struct node *current, int index);
void join_next_node(struct node *current);

int main() {
    int choice = 0;
    char text[100];

    while (1) {
        printf("\n*********Main Menu*********\n");
        printf("Choose one option from the following list ...\n");
        printf("===============================================\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Split text blob at specific index\n");
        printf("4. Join with next text blob\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice?\n");

        scanf("%d", &choice);
        getchar(); // Consume newline left by scanf

        switch (choice) {
            case 1:
                printf("Enter text to insert at beginning: ");
                fgets(text, sizeof(text), stdin);
                text[strcspn(text, "\n")] = '\0'; // Remove newline character from input
                insert_beginning(text);
                break;
            case 2:
                printf("Enter text to insert at end: ");
                fgets(text, sizeof(text), stdin);
                text[strcspn(text, "\n")] = '\0'; // Remove newline character from input
                insert_last(text);
                break;
            case 3: {
                int index;
                printf("Enter index to split text: ");
                scanf("%d", &index);
                getchar(); // Consume newline left by scanf
                if (head != NULL) {
                    split_text(head, index);
                } else {
                    printf("List is empty. Insert nodes first.\n");
                }
                break;
            }
            case 4: {
                if (head != NULL && head->next != NULL) {
                    join_next_node(head);
                } else {
                    printf("Cannot join. List either empty or has only one node.\n");
                }
                break;
            }
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Please enter valid choice..\n");
        }
    }

    return 0;
}

// Function to insert a new node at the beginning of the list
void insert_beginning(char *text) {
    struct node *ptr = (struct node *) malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    ptr->text = strdup(text); // Duplicate the input text

    ptr->prev = NULL;
    ptr->next = head;
    ptr->split_text = split_text; // Assign split_text function pointer
    ptr->join_next = join_next_node; // Assign join_next function pointer

    if (head != NULL) {
        head->prev = ptr;
    }

    head = ptr;

    printf("Node inserted at the beginning\n");
}

// Function to insert a new node at the end of the list
void insert_last(char *text) {
    struct node *ptr = (struct node *) malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    ptr->text = strdup(text); // Duplicate the input text

    ptr->next = NULL;
    ptr->split_text = split_text; // Assign split_text function pointer
    ptr->join_next = join_next_node; // Assign join_next function pointer

    if (head == NULL) {
        ptr->prev = NULL;
        head = ptr;
        printf("Node inserted at the end\n");
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = ptr;
    ptr->prev = temp;

    printf("Node inserted at the end\n");
}

// Function to split the text blob in a node at a given index
void split_text(struct node *current, int index) {
    if (current == NULL || current->text == NULL) {
        printf("Cannot split empty or NULL node\n");
        return;
    }

    int len = strlen(current->text);

    if (index < 0 || index >= len) {
        printf("Invalid split index\n");
        return;
    }

    // Create a new node for the split text
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // Allocate memory for text in new node
    new_node->text = strdup(current->text + index);

    // Modify current node text to end at index
    current->text[index] = '\0';

    // Insert new node after current node
    new_node->prev = current;
    new_node->next = current->next;
    if (current->next != NULL) {
        current->next->prev = new_node;
    }
    current->next = new_node;

    printf("Text split at position %d\n", index);
}

// Function to join current node with its next node
void join_next_node(struct node *current) {
    if (current == NULL || current->next == NULL || current->text == NULL || current->next->text == NULL) {
        printf("Cannot join. Current node or next node is NULL or empty.\n");
        return;
    }

    // Calculate new length for combined text
    int len1 = strlen(current->text);
    int len2 = strlen(current->next->text);
    int new_len = len1 + len2;

    // Allocate memory for combined text
    char *combined_text = (char *) malloc((new_len + 1) * sizeof(char));
    if (combined_text == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // Copy text from current and next nodes to combined_text
    strcpy(combined_text, current->text);
    strcat(combined_text, current->next->text);

    // Update current node's text
    free(current->text); // Free current text
    current->text = combined_text;

    // Remove the next node
    struct node *temp = current->next;
    current->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = current;
    }
    free(temp->text); // Free next node's text
    free(temp); // Free next node itself

    printf("Nodes joined successfully\n");
}

// Function to display all nodes in the list
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *ptr = head;
    printf("\nPrinting values...\n");
    while (ptr != NULL) {
        printf("%s\n", ptr->text);
        ptr = ptr->next;
    }
}


