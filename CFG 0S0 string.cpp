#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool A(char *str, int *index) {
    if (str[*index] == '1') {
        (*index)++;
        if (A(str, index))
            return true;
    }
    return true; 
}
bool S(char *str, int *index) {
    if (str[*index] == '0') {
        (*index)++;
        if (S(str, index)) {
            if (str[*index] == '0') {
                (*index)++;
                return true;
            }
        }
    }
    return A(str, index);
}
int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);
    int index = 0;
    if (S(input, &index) && input[index] == '\0') {
        printf("Accepted: The string belongs to the CFG.\n");
    } else {
        printf("Rejected: The string does not belong to the CFG.\n");
    }
    return 0;
}

