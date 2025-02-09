#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generate_combinations(const char *new_str, int len, int index, char *current_comb, int len_comb, int *unique_numbers, int *count) {
    if (len_comb == 3) {
        if (current_comb[0] != '0') {
            int num = (current_comb[0] - '0') * 100 + (current_comb[1] - '0') * 10 + (current_comb[2] - '0');
            int found = 0;
            for (int i = 0; i < *count; i++) {
                if (unique_numbers[i] == num) {
                    found = 1;
                    break;
                }
            }
            if (found == 0) {
                unique_numbers[*count] = num;
                (*count)++;
            }
        }
        return;
    }

    for (int i = index; i < len; i++) {
        current_comb[len_comb] = new_str[i];
        generate_combinations(new_str, len, i + 1, current_comb, len_comb + 1, unique_numbers, count);
    }
}

int main(void) {
    char our_str[100];
    scanf("%s", our_str);
    int count = 0;
    int unique_three[1000] = {0};
    int len = strlen(our_str);
    if (len < 3) {
        count = 0;
    }
    else {
        char current_comb[4] = {0};
        generate_combinations(our_str, len, 0, current_comb, 0, unique_three, &count);
    }
    printf("%d\n", count);
//    for (int i = 0; i < count; i++) {
//        printf("%d\n", unique_three[i]);
//    }

    return 0;
}
