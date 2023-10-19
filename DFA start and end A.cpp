#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int dfa_transition(int state, char input) {
    if (state == 0 && input == 'a') {
        return 1;
    } else if (state == 1 && input == 'a') {
        return 1;
    }
    return -1; 
}
int main() {
    char input_string[100];
    printf("Enter a string: ");
    scanf("%s", input_string);
    int current_state = 0;
    int input_length = strlen(input_string);
    for (int i = 0; i < input_length; i++) {
        int new_state = dfa_transition(current_state, input_string[i]);
        if (new_state == -1) {
            printf("Rejected: The string does not belong to the language.\n");
            return 0;
        }
        current_state = new_state;
    }
    if (current_state == 1) {
        printf("Accepted: The string starts and ends with 'a'.\n");
    } else {
        printf("Rejected: The string does not belong to the language.\n");
    }
    return 0;
}

