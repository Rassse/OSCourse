#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>


// Deepseek taught me to use global variable to allocate memory for the user input //
// Global variable is easy to change afterwards, when the code expands //
#define MAX 256

// I learned here to list file directories //
// https://www.youtube.com/watch?v=0pjtn6HGPVI //
int ls(char *path) {
    DIR *directory;
    struct dirent *entry;

    const char *dir_path = (path == NULL) ? "." : path;

    directory = opendir(dir_path);

    // Check if the directory is null, then raise error message //
    if (directory == NULL) {
        printf("Error opening the directory.\n");
        return 0;
    }
    // going through the entries and //
    while ((entry = readdir(directory)) != NULL) {
        // checking if the entry is a file //
        if (entry->d_type == DT_REG) {
            printf("File: %s\n", entry->d_name);
        }
        // or a directory //
        else if (entry->d_type == DT_DIR) {
            printf("dir: %s\n",  entry->d_name);
        }

    }
    if (closedir(directory) == -1) {
        printf("Error closing the directory.\n");
        return 1;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    char input[MAX];
    /* Deepseek helped me to run while command checking number 1 and changing it to exit 0, instead of
       comparing the string with strcmp to "exit"  */
    // printing the wish> to console interactively, until user types "exit" //
     if (argc < 2) {
        while (1) {
            printf("wish> ");
            // Deepseek taught me to check for Ctrl + D command exception //
            if (fgets(input, sizeof(input), stdin) == NULL) {
                break;
            }
            input[strcspn(input, "\n")] = '\0';
            if (strcmp(input, "exit") == 0) {
                break;
            }
            /* Deepseek helped me fix a bug where ls didn't work, Deepseek suggested me to add
             == 0 condition to the else if */
            else if (strcmp(input, "ls") == 0) {
                ls(NULL);
            }
        }
     }
     else {
        // error handling when file doesn't exist //
        FILE *fp = fopen(argv[1], "r");
        if (fp == NULL) {
            perror("There was an error opening the file");
            return 0;
        }
        // when user types exit, the system exits with 0 //
        while (fgets(input, sizeof(input), fp) != NULL) {
            input[strcspn(input, "\n")] = '\0';
            if (strcmp(input, "exit") == 0) {
                fclose(fp);
                return 0;
            }
        }
     }
}