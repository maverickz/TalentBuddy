#include <stdio.h>
#include <stdbool.h>

static inline is_stop_word(char *word, char **stopwords, int stopwords_length) {
    int i;
    for(i=0; i<stopwords_length; i++) {
        if(strcmp(word,stopwords[i]) == 0) {
            return true;
        }
    }
    return false;
}

void remove_stopwords(char **query, int query_length, char **stopwords, int stopwords_length) {
    // Write your code here
    // To print results to the standard output you can use printf()
    // Example: printf("%s", "Hello world!");
    int i;
    for(i=0;i<query_length;i++) {
        if(!is_stop_word(query[i], stopwords, stopwords_length)) {
            printf("%s\n", query[i]);
        }
    }
}