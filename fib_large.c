#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fibonacci(int n) {
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("invalid: %s\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);

    unsigned long long fib = 1, fib_ = 0, temp;  // fib_ is 0 to match fibonacci(1) == 0

    // Recursive approach
    if (strcmp(argv[2], "r") == 0) {
        fib = fibonacci(n);
    }
    // Iterative approach
    else {
        if (n == 1) {
            fib = 0;
        } else if (n == 2) {
            fib = 1;
        } else {
            for (int i = 3; i <= n; i++) {
                temp = fib;
                fib += fib_;
                fib_ = temp;
            }
        }
    }

    printf("%llu\n", fib);

    return 0;
}
