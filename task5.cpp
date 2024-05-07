#include <iostream>

int fac1(int n) {
    if (n < 1) {
        return 1;
    }
    return n * fac1(n - 1);
}

unsigned long long int fac2(int n) {
    unsigned long long int r = 1;

    while (n > 1) {
        r = r * n;
        n--;
    }
    return r;
}

int sum1(int n) {
    if (n < 1) {
        return 0;
    }
    return n + sum1(n - 1);
}

int sum2(int n) {
    int r = 0;

    while (n > 0) {
        r = r + n;
        n--;
    }
    return r;
}

int main() {
    // fails because of integer overflow
    // may also fail because too many stack frames are placed on the stack (not tail recursive)
    std::cout << fac1(50) << std::endl;

    std::cout << sum2(10) << std::endl;
    return 0;
}