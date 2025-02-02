#include <stdio.h>

unsigned int findUnique() {
    unsigned int N, num, result = 0;
    scanf("%u", &N);

    for (unsigned int i = 0; i < N; i++) {
        scanf("%u", &num);
        result ^= num;
    }

    return result;
}

int main() {
    printf("%u\n", findUnique());
    return 0;
}
