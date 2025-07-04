#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Deepseek helped me to check for the arguments correctly, otherwise my other function was always false //
    // If there are no arguments, the code exits //
    if (argc < 2) {
        fprintf(stderr, "my-grep: searchterm [file ...]\n");
        exit(1);
    }
    char *search_term = argv[1];
    char *line = NULL;
    size_t len = 0;
    // Deepseek helped me to create a ssize_t C variable read to aid in my file reading or input reading //
    // So I can access one variable instead of complex structure //
    ssize_t read;
    if (argc == 2) {
        // reading the prompt from the user //
        while ((read = getline(&line, &len, stdin)) != -1) {
            // printing the line, if search term is found //
            if (strstr(line, search_term)) {
                printf("%s", line);
            }
        }
    }
    else {
        FILE *file = fopen(argv[2], "r");
        if(file == NULL) {
            fprintf(stderr, "my-grep: cannot open file\n");
            exit(1);
        }
        char *line = NULL;
        // I learned here to read file //
        // https://www.youtube.com/watch?v=TKKQERrrt5o //
        // And here to check the correct word //
        // https://www.youtube.com/watch?v=8A3Zycio0W4 //
        while((read = getline(&line, &len, file)) != -1) {
            // writing the line to stdout, if search term is found //
            if (strstr(line, search_term)) {
                fputs(line, stdout);
                // Deepseek helped me take an extra line away because getline already passes a newline //
            }
        }
        fclose(file);
        free(line);
    }
    return 0;
}