#include <stdio.h>


int main() {
    FILE *fp = fopen("main.c", "r");
    // I learned here to read file //
    // https://www.youtube.com/watch?v=MQIF-WMUOL8 //
    // https://www.youtube.com/watch?v=Hzg3kCHJcxI //
    char buffer[255];

    if(fp == NULL) {
        printf("my-cat: cannot open file");
        exit(1);
    }
    else {
        while (fgets(buffer, 255, fp) != NULL) {
            printf("%s", buffer);
        }

    }
    fclose(fp);

    return 0;
}


