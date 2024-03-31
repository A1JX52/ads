#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void eratosthenes(char* primes, unsigned long n) {
    for (unsigned long i = 2; i < n; i++) {
        primes[i] = 1;
    }
    // sqrt reduces the number of required bits by a factor of 2
    unsigned int limit = ceil(sqrt(n));

    for (unsigned long i = 2; i <= limit; i++) {
        if (primes[i]) {
            // multiples of prime numbers can be ignored
            for (unsigned long j = i + i; j < n; j += i) {
                primes[j] = 0;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("usage: ./task1 NUMBER\n");
        return 1;
    }
    char* endptr;
    errno = 0;
    unsigned long num = strtoul(argv[1], &endptr, 10);

    if (errno == ERANGE) {
        printf("too large number entered.\n");
        return 1;
    } else if (*endptr != '\0') {
        printf("invalid number entered.\n");
        return 1;
    }
    printf("number %lu entered.\n", num);
    // make index equal to numeric value by including zero
    unsigned long n = num + 1;

    char* primes = malloc(n * sizeof(char));
    
    if (primes == NULL) {
        printf("memory allocation failed.\n");
        return 1;
    }
    eratosthenes(primes, n);

    unsigned long rem = num;

    while (rem > 1) {
        for (unsigned long i = 2; i < n; i++) {
            if (primes[i] && !(rem % i)) {
                printf("%lu is a factor.\n", i);
                rem /= i;
                break;
            }
        }
    }
    free(primes);
    return 0;
}