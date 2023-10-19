#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_STATES 100
int n, m;
int transitions[MAX_STATES][MAX_STATES]; 
int epsilonTransitions[MAX_STATES][MAX_STATES]; 
int epsilonClosure[MAX_STATES][MAX_STATES]; 
void dfs(int state, int current, bool visited[MAX_STATES]) {
    visited[current] = true;
    epsilonClosure[state][current] = 1;
    for (int i = 0; i < n; i++) {
        if (epsilonTransitions[current][i] && !visited[i]) {
            dfs(state, i, visited);
        }
    }
}
void findEpsilonClosures() {
    for (int state = 0; state < n; state++) {
        bool visited[MAX_STATES] = {false};
        dfs(state, state, visited);
    }
}
int main() {
    printf("Enter the number of states: ");
    scanf("%d", &n);
    printf("Enter the number of transitions: ");
    scanf("%d", &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            transitions[i][j] = -1;
            epsilonTransitions[i][j] = 0;
            epsilonClosure[i][j] = 0;
        }
    }
    printf("Enter the transitions (state1 input state2):\n");
    for (int i = 0; i < m; i++) {
        int state1, state2;
        char input;
        scanf("%d %c %d", &state1, &input, &state2);
        if (input == 'e') {
            epsilonTransitions[state1][state2] = 1;
        } else {
            transitions[state1][state2] = input - 'a'; 
        }
    }
    findEpsilonClosures();
    printf("Epsilon-closures for each state:\n");
    for (int state = 0; state < n; state++) {
        printf("e-Closure(%d): { ", state);
        for (int i = 0; i < n; i++) {
            if (epsilonClosure[state][i] == 1) {
                printf("%d ", i);
            }
        }
        printf("}\n");
    }
    return 0;
}

