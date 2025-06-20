#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// I learned here to create node structure, linked list //
// https://www.youtube.com/watch?v=6wXZ_m3SbEs //
// I learned here also about struct and typedef //
// https://www.youtube.com/watch?v=e9OXqEPF-5M //
typedef struct node{
    char *line;
    struct node *next;
} Node;

Node* readFile(FILE *input);
void reversePrint(Node *head, FILE *output);
void freeList(Node *head);
// I learned here to create pointers, size_t... //
// https://www.youtube.com/watch?v=y4EzSnHJj-Q //

int main(int argc, char *argv[]) {
    // I learned here about creating linked lists //
    // https://www.youtube.com/watch?v=K7J3nCeRC80 //
    FILE *output = stdout;
    Node *head = NULL;
    FILE *text_input = NULL;
    // Here I learned the difference between argc, argv and their usages, also from lectures in the course //
    // https://www.tutorialspoint.com/cprogramming/c_command_line_arguments.htm //
    if(argc == 1) {
        head = readFile(stdin);
        reversePrint(head, stdout);
    } else if (argc == 2) {
        text_input = fopen(argv[1], "r");
        if (text_input == NULL) {
            fprintf(stderr, "There was an error opening the file!\n");
            exit(1);
        }
        head = readFile(text_input);
        reversePrint(head, stdout);
        fclose(text_input);
    }

    else if(argc == 2) {
        text_input = fopen(argv[1], "r");
        if (text_input == NULL) {
            fprintf(stderr, "There was an error opening the file!\n");
            exit(1);
        }
        head = readFile(text_input);
        reversePrint(head, stdout);
        fclose(text_input);
    }

    else if(argc == 3) {
        // I learned here to compare the user parameter in the kernel and the argument //
        // https://www.programiz.com/c-programming/library-function/string.h/strcmp //
        if (strcmp(argv[1], argv[2]) == 0)  {
            fprintf(stderr, "Given input and output files are same, they must differ.\n");
            exit(1);
        }
        text_input = fopen(argv[1], "r");
        if (text_input == NULL) {
            fprintf(stderr, "There was an error opening the file!\n");
            exit(1);
        }
        output = fopen(argv[2], "w");
        if (output == NULL) {
            fprintf(stderr, "There was an error creating the file!\n");
            exit(1);
        }
        head = readFile(text_input);
        reversePrint(head, output);
        fclose(text_input);
        fclose(output);
    }
    freeList(head);
    return 0;

}
// I learned here to free the list //
// https://stackoverflow.com/questions/6417158/c-how-to-free-nodes-in-the-linked-list //
void freeList(Node *head) {

    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp->line);
        free(temp);
    }
}

void reversePrint(Node *head, FILE *output) {
    if(head == NULL) {
        return;
    }
    reversePrint(head->next, output);
    /* Deepseek helped me to fix a bug where extra lines where created //
    and here it recommended me to add a newline \n to compensate the changes in readFile */
    fprintf(output, "%s\n", head->line);

}

Node* readFile(FILE *input) {
    Node *head = NULL;
    Node *tail = NULL;
    char *line = NULL;
    size_t l = 0;
    ssize_t read;

    while ((read = getline(&line, &l, input)) != -1) {
        /* Deepseek helped me fix a problem where newlines where added and I needed to
        add a check for the newlines in nodes */
        if (read > 0 && line[read-1] == '\n') {
            line[read-1] = '\0';
        }
        // Here I got inspiration for the reverse linked list //
        // https://www.youtube.com/watch?v=sYcOK51hl-A //
        Node *node = malloc(sizeof(Node));
        if (!node) {
            fprintf(stderr, "Memory allocation failed, try again\n");
            exit(1);
        }
        node->line = strdup(line);
        node->next = NULL;
        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    free(line);
    return head;
    // https://www.geeksforgeeks.org/read-a-file-line-by-line-in-c/ //
}
