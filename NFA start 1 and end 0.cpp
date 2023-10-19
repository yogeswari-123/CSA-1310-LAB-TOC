#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int nfa_transition(int state, char input) {
    if (state == 0 && input == 'o') return 1;
    if (state == 1 && input == '1') return 2;
    return -1; 
}
bool is_accepted_by_nfa(const char *input) {
    int current_state = 0;
    int input_length = strlen(input);
    for (int i = 0; i < input_length; i++) {
        int new_state = nfa_transition(current_state, input[i]);
        if (new_state == -1) {
            return false; 
        }
        current_state = new_state;
    }
    return current_state ==2;
}
int main() {
    char input_string[100];
    printf("Enter a string: ");
    scanf("%s", input_string);
    if (is_accepted_by_nfa(input_string)) {
        printf("Accepted: The string starts with 'o' and ends with '1'.\n");
    } else {
        printf("Rejected: The string does not satisfy the NFA condition.\n");
    }
    return 0;
}

