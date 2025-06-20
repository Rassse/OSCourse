#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "my-cat: no file given.\n");
        exit(1);
    }
    int j = 0;
    for (int i = 1; i < argc; i++) {
        // I learned here in these videos to read file //
        // https://www.youtube.com/watch?v=MQIF-WMUOL8 //
        // https://www.youtube.com/watch?v=Hzg3kCHJcxI //
        FILE *fp = fopen(argv[i], "r");
        if(fp == NULL) {
            fprintf(stderr, "my-cat: cannot open file\n");
            exit(1);
        }
        /* Deepseek helped me to add a newline by helping me
        create a new variable */
        if (j > 0) {
            printf("\n");
        }
        // Deepseek helped me to add considerably more buffer, before I had 255 //
        char buffer[4096];
        while (fgets(buffer, sizeof(buffer), fp) != NULL) {
            printf("%s", buffer);
        }
        fclose(fp);
        j++;
    }
    return 0;
}
