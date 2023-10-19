#include <stdio.h>
#include <stdbool.h>
bool A(char *str, int *index) {
    if (str[*index] == '0') {
        (*index)++;
        if (A(str, index))
            return true;
    } else if (str[*index] == '1') {
        (*index)++;
        if (A(str, index))
            return true;
    }
    return true; 
}
bool S(char *str) {
    int index = 0;
    if (A(str, &index) && str[index] == '1' && A(str, &index))
        return true;
    return false;
}
int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);
    if (S(input)) {
        printf("Accepted: The string belongs to the CFG.\n");
    } else {
        printf("Rejected: The string does not belong to the CFG.\n");
    }
    return 0;
}

