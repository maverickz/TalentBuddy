#include <stdio.h>

void count_words(char *s) {
    // Write your code here
    // To print results to the standard output you can use printf()
    // Example: printf("%s", "Hello world!");
    char *token;
    int num_words = 0;
    token = strtok(s,", ");
    while(token != NULL) {
        num_words++;
        token = strtok(NULL,", ");
    }
    printf("%d\n", num_words);
}