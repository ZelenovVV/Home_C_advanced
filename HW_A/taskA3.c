#include <stdio.h>

unsigned int get_mask(unsigned int number, int N) {
    unsigned int mask = (1 << N) - 1;
    return number & mask;
}

int main() {
    unsigned int num;
    int N;
    scanf("%u %d", &num, &N);
    unsigned int result = get_mask(num, N);
    printf("%u\n", result);
    return 0;
}
