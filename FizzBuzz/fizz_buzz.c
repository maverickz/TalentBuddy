#include <stdio.h>
#include <stdbool.h>

static inline bool divisible_by_three(int n) {
    return (n%3 == 0)?true:false;
}

static inline bool divisible_by_five(int n) {
    return (n%5 == 0)?true:false;
}
void fizzbuzz(int n) {
    // Write your code here
    // To print results to the standard output you can use printf()
    // Example: printf("%s", "Hello world!");
    if(n<0) {
        return;
    }
    int num;
    
    for(num=1; num<=n; num++) {
        if(divisible_by_three(num) && divisible_by_five(num)) {
            printf("FizzBuzz\n");
        } else if(divisible_by_three(num)) {
            printf("Fizz\n");
        } else if(divisible_by_five(num)) {
            printf("Buzz\n");
        } else {
            printf("%d\n", num);
        }
    }
}