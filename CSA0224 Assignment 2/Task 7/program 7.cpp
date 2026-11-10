
#include <stdio.h>

unsigned long original_checks;
unsigned long optimized_checks;

int original_prime(unsigned long n) {
    original_checks = 0;

    if (n < 2)
        return 0;

    for (unsigned long i = 2; i <= n / i; i++) {
        original_checks++;

        if (n % i == 0)
            return 0;
    }

    return 1;
}

int optimized_prime(unsigned long n) {
    optimized_checks = 0;

    if (n < 2)
        return 0;

    if (n == 2)
        return 1;

    if (n % 2 == 0)
        return 0;

    for (unsigned long i = 3; i <= n / i; i += 2) {
        optimized_checks++;

        if (n % i == 0)
            return 0;
    }

    return 1;
}

int main(void) {
    unsigned long numbers[] = {97, 100, 7919, 1000003};

    for (int i = 0; i < 4; i++) {
        unsigned long n = numbers[i];

        int p1 = original_prime(n);
        unsigned long c1 = original_checks;

        int p2 = optimized_prime(n);
        unsigned long c2 = optimized_checks;

        printf("Number = %lu\n", n);
        printf("Original: %s, checks = %lu\n",
               p1 ? "Prime" : "Not Prime", c1);
        printf("Optimized: %s, checks = %lu\n",
               p2 ? "Prime" : "Not Prime", c2);
        printf("------------------------\n");
    }

    return 0;
}
