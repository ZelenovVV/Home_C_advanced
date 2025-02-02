#include <stdio.h>

int main() {
    int N, number, max, count = 0;

    scanf("%d", &N);

    if (N > 0) {

        scanf("%d", &number);
        max = number;
        count = 1;

        for (int i = 1; i < N; ++i) {
            scanf("%d", &number);

            if (number > max) {
                max = number;
                count = 1;
            }
            else if (number == max) {
                count++;
            }
        }
    }


    printf("%d\n", count);

    return 0;
}
