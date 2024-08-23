#include <stdio.h>
#include <string.h>
int main() {
    char arithmetic[5] = {'+', '-', '*', '/', '%'};
    char relational[4] = {'<', '>', '!', '='};
    char bitwise[4] = {'&', '^', '~', '|'};
    char str[3]; 
    printf("Enter value to be identified: ");
    scanf("%2s", str);
    if (((str[0] == '&' || str[0] == '|') && str[0] == str[1]) || (str[0] == '!' && str[1] == '\0')) {
        printf("\nIt is a Logical operator\n");
    }
    for (int i = 0; i < 4; i++) {
        if (str[0] == relational[i] && (str[1] == '=' || str[1] == '\0')) {
            printf("\nIt is a Relational Operator\n");
            break;
        }
    }
   for (int i = 0; i < 4; i++) {
        if ((str[0] == bitwise[i] && str[1] == '\0') || ((str[0] == '<' || str[0] == '>') && str[1] == str[0])) {
            printf("\nIt is a Bitwise Operator\n");
            break;
        }
    }
    if (str[0] == '?' && str[1] == ':') {
        printf("\nIt is a Ternary Operator");
    }
    for (int i = 0; i < 5; i++) {
        if ((str[0] == '+' || str[0] == '-') && str[0] == str[1]) {
            printf("\nIt is a Unary Operator\n");
            break;
        } else if ((str[0] == arithmetic[i] && str[1] == '=') || (str[0] == '=' && str[1] == ' ')) {
            printf("\nIt is an Assignment Operator\n");
            break;
        } else if (str[0] == arithmetic[i] && str[1] == '\0') {
            printf("\nIt is an Arithmetic Operator\n");
            break;
        }
    }
    return 0;
}
