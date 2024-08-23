#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_LEN 1024
int isKeyword(const char *word) {
    const char *keywords[] = {
        "auto", "break", "case", "char", "const", "continue", "default",
        "do", "double", "else", "enum", "extern", "float", "for", "goto",
        "if", "int", "long", "register", "return", "short", "signed",
        "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned",
        "void", "volatile", "while"
    };
    for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); ++i) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}
void identifyTokens(const char *code) {
    char token[MAX_LEN];
    int i = 0;
    int j = 0;    
    while (code[i] != '\0') {
        if (isspace(code[i])) {
            
            ++i;
            continue;
        }    
        if (isalpha(code[i]) || code[i] == '_') {
            j = 0;
            while (isalnum(code[i]) || code[i] == '_') {
                token[j++] = code[i++];
            }
            token[j] = '\0';
            if (isKeyword(token)) {
                printf("Keyword: %s\n", token);
            } else {
                printf("Identifier: %s\n", token);
            }
            continue;
        }        
        if (isdigit(code[i])) {
            j = 0;
            while (isdigit(code[i])) {
                token[j++] = code[i++];
            }
            token[j] = '\0';
            printf("Numeric Literal: %s\n", token);
            continue;
        }      
        if (strchr("+-*/%=&|!<>;,.(){}[]", code[i]) != NULL) {
            token[0] = code[i++];
            token[1] = '\0';
            printf("Operator/Punctuation: %s\n", token);
            continue;
        } 
        ++i;
    }
}
int main() {
    char code[MAX_LEN];
    printf("Enter the source code (end input with a newline):\n");
    fgets(code, MAX_LEN, stdin);
    size_t len = strlen(code);
    if (len > 0 && code[len - 1] == '\n') {
        code[len - 1] = '\0';
    }
    identifyTokens(code);
    return 0;
}
