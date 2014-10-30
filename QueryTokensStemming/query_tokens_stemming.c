#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <stdbool.h>

char *strrstr(char *s1, char *s2)
{
  size_t  s1len = strlen(s1);
  size_t  s2len = strlen(s2);
  char *s;

  if (s2len > s1len)
    return NULL;
  for (s = s1 + s1len - s2len; s >= s1; --s)
    if (strncmp(s, s2, s2len) == 0)
      return s;
  return NULL;
}

int strlen_cmp(const void *s1, const void *s2)
{
    const char *str1 = *(const char **)s1;
    const char *str2 = *(const char **)s2;
    size_t l1 = strlen(str1);
    size_t l2 = strlen(str2);
 
    if (l1 > l2) return -1;
    if (l1 < l2) return 1;
    return strcasecmp(str1, str2);
}

void sort_suffixes(char **suffixes, int suffixes_length) {
    qsort(suffixes, suffixes_length, sizeof(*suffixes), strlen_cmp);
}

void token_stemming(char **tokens, int tokens_length, char **suffixes, int suffixes_length) {
    // Write your code here
    // To print results to the standard output you can use printf()
    // Example: printf("%s", "Hello world!");
        
    int token_index;
    int suffix_index;
    char **sorted_suffixes = calloc(suffixes_length, sizeof(char *));
    for(suffix_index=0; suffix_index<suffixes_length; suffix_index++) {
        sorted_suffixes[suffix_index] = strdup(suffixes[suffix_index]);
    }
    /*
     * Sort the suffixes and traverse the suffixes array in decreasing order of length to match the suffix with the max length
    */
    sort_suffixes(sorted_suffixes, suffixes_length);
    for(token_index=0; token_index<tokens_length; token_index++) {
        char *word = tokens[token_index];
        for(suffix_index=0; suffix_index<suffixes_length; suffix_index++) {
            char *token;
            if((token = strrstr(word, sorted_suffixes[suffix_index])) != NULL) {
                //Check if the token is a suffix
                if(*(token+strlen(sorted_suffixes[suffix_index])) == '\0') {   
                    *token = '\0';
                    break;
                }
            }
        }
        printf("%s\n", word);
    }
}