#include <stdio.h>

void find_missing_number(int *v, int v_length) {
    // Write your code here
    // To print results to the standard output you can use printf()
    // Example: printf("%s", "Hello world!");
    int sum = 0;
    int expected_sum = 0;
    int max = v_length+1;
    int i;
    for(i=0;i<v_length;i++) {
        sum += v[i];
    }
     
    expected_sum = (max*(max+1))/2;
    printf("%d\n", expected_sum - sum);
}