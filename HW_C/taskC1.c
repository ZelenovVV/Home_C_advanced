#include <stdio.h>
#include <string.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
#define MAX_LEN 1024

void zFunction(char *s, int z[]) {
    int n = strlen(s);
    z[0] = n;
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[i + z[i]] == s[z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
}


int findMaxPrefSuf(char *s1, char *s2) {
    int len1 = strlen(s1);
    char s_comb[2*MAX_LEN];

    strcpy(s_comb, s1);
    strcat(s_comb, s2);

    int n_comb = strlen(s_comb);
    int z_comb[n_comb];

    for (int i = 0; i < n_comb; ++i) {
        z_comb[i] = 0;
    }

    zFunction(s_comb, z_comb);

    int max = 0;

    for (int i = len1; i < n_comb; ++i) {
        if (z_comb[i] > max && i + z_comb[i] == n_comb) {
            max = z_comb[i];
        }
    }

    return max;
}


void firstAndLast(char *buffer, char *s, char *s_r, int n){
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
        len--;
    }
    if (len > 0 && len >= n) {
        strncpy(s, buffer, n);
        s[n] = '\0';
    } else if (len > 0 && len < n){
        strcpy(s, buffer);
    }
    if (len >= n) {
        strncpy(s_r, buffer + len - n, n);
        s_r[n] = '\0';
    } else {
        strcpy(s_r, buffer);
    }
}


int main() {
    int n = MAX_LEN, max1 = 0, max2 = 0;
    char s1[n+1], s1_r[n+1], s2[n+1], s2_r[n+1];
    char buffer1[4096];
    char buffer2[4096];
    fgets(buffer1, sizeof(buffer1), stdin);
    fgets(buffer2, sizeof(buffer2), stdin);

    if (strlen(buffer1) == 0 || strlen(buffer2) == 0) {
        printf("%d %d\n", max1, max2);
        return 0;
    }

    else {
        firstAndLast(buffer1, s1, s1_r, n);
        firstAndLast(buffer2, s2, s2_r, n);

        max1 = findMaxPrefSuf(s1, s2_r);
        max2 = findMaxPrefSuf(s2, s1_r);
    }
        printf("%d %d\n", max1, max2);

    return 0;
}
