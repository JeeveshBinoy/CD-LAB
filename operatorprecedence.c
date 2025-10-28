#include <stdio.h>
#include <string.h>

#define MAX_TERMS 10
#define MAX_STACK 20
#define MAX_INPUT 50

char stack[MAX_STACK];
char input[MAX_INPUT];
char optable[MAX_TERMS][MAX_TERMS];
char terminals[MAX_TERMS];
int n_terminals;
int top = 0;

void print_status(int input_ptr) {
    for (int i = 0; i <= top; i++) printf("%c", stack[i]);
    printf("\t\t");
    for (int i = input_ptr; i < strlen(input); i++) printf("%c", input[i]);
    printf("\t\t");
}

int get_index(char c) {
    for (int i = 0; i < n_terminals; i++) {
        if (terminals[i] == c) return i;
    }
    return -1;
}

void print_table() {
    printf("\nOperator Precedence Table:\n\t");
    for (int i = 0; i < n_terminals; i++) printf("%c\t", terminals[i]);
    printf("\n");
    for (int i = 0; i < n_terminals; i++) {
        printf("%c\t", terminals[i]);
        for (int j = 0; j < n_terminals; j++) {
            printf("%c\t", optable[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter number of terminals: ");
    scanf("%d", &n_terminals);
    printf("Enter terminals: ");
    scanf("%s", terminals);

    printf("Enter precedence table values (<,=,>):\n");
    for (int i = 0; i < n_terminals; i++) {
        for (int j = 0; j < n_terminals; j++) {
            printf("precedence[%c,%c]: ", terminals[i], terminals[j]);
            scanf(" %c", &optable[i][j]);
        }
    }

    print_table();

    stack[top] = '$';
    printf("\nEnter input string (end with $): ");
    scanf("%s", input);

    printf("\nSTACK\t\tINPUT\t\tACTION\n");
    print_status(0);

    int ptr = 0;

    while (1) {
        int col = get_index(stack[top]);
        int row = get_index(input[ptr]);

        if (stack[top] == '$' && input[ptr] == '$') {
            printf("Accept\n");
            break;
        }

        // Invalid symbol check
        if (col == -1 || row == -1) {
            printf("Error: Unknown symbol\n");
            printf("Not Accepted\n");
            break;
        }

        char prec = optable[col][row];

        if (prec == '<' || prec == '=') {
            // Shift
            stack[++top] = input[ptr];
            printf("Shift %c\n", input[ptr]);
            ptr++;
        } else if (prec == '>') {
            // Reduce
            printf("Reduce\n");
            top--; // just pop one symbol to simulate reduction
        } else {
            printf("Error: No precedence between %c and %c\n", stack[top], input[ptr]);
            printf("Not Accepted\n");
            break;
        }

        print_status(ptr);
        printf("\n");

        // Safety break if infinite
        if (ptr > strlen(input) + 5 || top < 0) {
            printf("Not Accepted\n");
            break;
        }
    }

    return 0;
}

