#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ceasar(char *str, int shift) {
    int prov = 0;
    for (int i = 0; i < strlen(str); i++) {
        if ((str[i] >= 'A' && str[i] <= 'Z')) {
            prov = (int)str[i] + shift;
            if (prov > 'Z') {
                prov = (int)str[i] - (26 - shift);
                str[i] = (char)prov;
            }
            else
                str[i] = (char)prov;
            }
        else if ((str[i] >= 'a' && str[i] <= 'z')) {
            prov = (int)str[i] + shift;
            if (prov > 'z') {
                prov = (int)str[i] - (26 - shift);
                str[i] = (char)prov;
            }
            else
                str[i] = (char)prov;
        }
    }
}


int main() {
    int shift;
    char *letter = NULL;
    char ch;
    size_t len = 0;

    scanf("%d ", &shift);
    shift = shift % 26;
    letter = malloc(1);
    while ((ch = getchar()) != '\n') {
        letter = realloc(letter, len + 2);
        letter[len++] = ch;
    }
    letter[len] = '\0';

    ceasar(letter, shift);

    printf(letter);


    free(letter);

    return 0;
}
