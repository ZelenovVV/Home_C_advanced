#include <stdio.h>

unsigned int countBinary(unsigned int N) {
    unsigned int count = 0;
    while (N) {
        if (N & 1){
            count++;
        }
        N >>= 1;
    }
    return count;
}

int main() {
    unsigned int N;
    scanf("%u", &N);
    int result = countBinary(N);
    printf("%u\n", result);
    return 0;
}

