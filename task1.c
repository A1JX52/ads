#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int* eratosthenes(int* primes, int limit) {
    // '0' is no prime number
    for (int i = 1; i <= limit; i++) {
        primes[i] = 1;
    }

    // multiples of deleted numbers can be ignored in loop
    for (int i = 2; i <= limit; i++) {
        if (primes[i]) {
            for (int j = i + i; j <= limit; j += i) {
                printf("setting %d to zero.\n", j);
                primes[j] = 0;
            }
        }
        printf("next\n");
    }
    return primes;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: task1 NUMBER\n");
        return 1;
    }
    int num = atoi(argv[1]);
    printf("number %i entered.\n", num);

    int limit = sqrt(num);
    int* primes = malloc(limit * sizeof(int) + sizeof(int));
    eratosthenes(primes, limit);
    printf("\n");

    for (int i = 0; i <= limit; i++) {
        if (primes[i]) {
            printf("%d is a prime number.\n", i);
        }
    }
    printf("\n");

    // limit rule only applies for composite numbers
    for (int i = 0; i <= limit; i++) {
        if (primes[i] && i == num) {
            printf("%d is a prime number itself.\n", num);
        }
    }

    while (num > 1) {
        for (int i = 2; i <= limit; i++) {
            if (primes[i] && !(num % i)) {
                printf("%d is a factor.\n", i);
                num /= i;
                break;
            }
        }
    }
    free(primes);
    return 0;
}