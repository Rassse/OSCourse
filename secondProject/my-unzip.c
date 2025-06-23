#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "my-unzip: file1 [file2 ...]\n");
        return 1;
    }
    // checking arguments //
    for (int i = 1; i < argc; i++) {
       // better to use "rb" = read binary for reading this compressed file than regular "r" //
       FILE *input = fopen(argv[i], "rb");
       if (input == NULL) {
           perror("Error occured opening the file.");
           return 1;
       }

       int count;
       char ch;
       // Deepseek helped me to fread both of the int and char in the zip file, rather than making two functions for it //
       // Loop is running until the reading ends //
       while (fread(&count, sizeof(int), 1, input) == 1 && fread(&ch, sizeof(char), 1, input) == 1) {
            // write the result to standard output //
            for (int i = 0; i < count; i++) {
                fputc(ch, stdout);
            }
       }
       fclose(input);
    }
    return 0;
}
