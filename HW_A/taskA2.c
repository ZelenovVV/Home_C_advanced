#include <stdio.h>

unsigned int get_shift(unsigned int number, int N) {
    return (number >> N) | (number << (32 - N));
}

int main() {
    unsigned int num;
    int N;
    scanf("%u %d", &num, &N);
    unsigned int result = get_shift(num, N);
    printf("%u\n", result);
    return 0;
}

