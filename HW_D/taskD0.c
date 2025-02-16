#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct list {
    char word[20];
    struct list *next;
} list;


struct list* createNote(char* word) {
    list* newNote = (list*)calloc(1, sizeof(list));
    strcpy(newNote->word, word);
    return newNote;
}

void printList(list* head) {
    list* temp = head;
    while (temp != NULL) {
        printf("%s ", temp->word);
        temp = temp->next;
    }
    printf("\n");
}

void deleteList(list** head) {
    list* current = *head;
    list* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

void insertSorted(struct list** head, struct list* newNote) {
    list* current;

    if (*head == NULL || strcmp((*head)->word, newNote->word) > 0) {
        newNote->next = *head;
        *head = newNote;
    } else {
        current = *head;

        while (current->next != NULL && strcmp(current->next->word, newNote->word) <= 0) {
            current = current->next;
        }
        newNote->next = current->next;
        current->next = newNote;
    }
}


int main() {
    char str[1024];
    fgets(str, sizeof(str), stdin);
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
    char* token;
    list* head = NULL;

    token = strtok(str, " .");
    while (token != NULL) {
        list* newNote = createNote(token);
        insertSorted(&head, newNote);
        token = strtok(NULL, " .");
    }

    printList(head);

    deleteList(&head);

    return 0;
}



