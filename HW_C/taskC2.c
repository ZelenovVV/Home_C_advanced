#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXSTACK 100
#define BSIZE 1024

int stack[MAXSTACK];
int sp = 0;

void push(int n) {
    if (sp < MAXSTACK) {
        stack[sp++] = n;
    }
}

int out(void) {
    if (sp > 0) {
        return stack[--sp];
    } else {
        return 0;
    }
}

void operation(char op) {
    int num2 = out();
    int num1 = out();
    switch (op) {
        case '+':
            push(num1 + num2);
            break;
        case '-':
            push(num1 - num2);
            break;
        case '*':
            push(num1 * num2);
            break;
        case 'x':
            push(num1 * num2);
            break;
        case '\xD7':
            push(num1 * num2);
            break;
        case '/':
            if (num2 != 0) {
                push(num1 / num2);
            }
            break;
        default:
            break;
    }
}

int main() {
    char buffer[BSIZE];
    int n;
    char *token;

    fgets(buffer, BSIZE, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    token = strtok(buffer, " ");

    while (token != NULL && token[0] != '.') {
        if (isdigit(token[0])) {
            n = atoi(token);
            push(n);
        } else {
            operation(token[0]);
        }
        token = strtok(NULL, " ");
    }

    printf("%d\n", out());

    return 0;
}
