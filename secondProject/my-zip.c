#include <stdio.h>
#include <stdlib.h>

// I lost the original my-zip.c file and Deepseek helped me recover it //
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "my-zip: file1 [file2 ...]\n");
        return 1;
    }
    for (int i = 1; i < argc; i++) {
        FILE *input = fopen(argv[i], "r");
        if (input == NULL) {
            perror("Error occurred opening the file\n");
            return 1;
        }
        // Deepseek helped me to check EOF instead of making long if conditions //
        int current = fgetc(input);
        while (current != EOF) {
            int count = 1;
            int next;
            while ((next = fgetc(input)) == current) {
                count++;
            }
            fwrite(&count, sizeof(int), 1, stdout);
            fwrite(&current, sizeof(char), 1, stdout);

            current = next;
        }

        fclose(input);
    }
    return 0;
}
