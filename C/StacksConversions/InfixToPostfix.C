#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define Maxi 1000

typedef struct {
    char Stck[Maxi];
    int Top;
} Stack;

char Pop(Stack *S) {
    if (S->Top != -1)
        return S->Stck[S->Top--];
    return '\0';
}

void Push(Stack *S, char Item) {
    if (S->Top != Maxi - 1)
        S->Stck[++S->Top] = Item;
}

int Precedence(char Op) {
    if (Op == '+' || Op == '-') return 1;
    if (Op == '*' || Op == '/') return 2;
    if (Op == '^') return 3;
    return 0;
}

bool IsOperand(char Ch) {
    return (Ch != '+' && Ch != '-' && Ch != '*' && Ch != '/' && Ch != '^' && Ch != '(' && Ch != ')');
}

void InfixToPostfix(Stack *S, char Exp[]) {
    for (int i = 0; Exp[i] != '\0'; i++) {
        char Ch = Exp[i];

        if (IsOperand(Ch)) {
            printf("%c", Ch);
        } 
        else if (Ch == '(') {
            Push(S, Ch);
        } 
        else if (Ch == ')') {
            while (S->Top != -1 && S->Stck[S->Top] != '(')
                printf("%c", Pop(S));
            Pop(S); // remove '('
        } 
        else { // operator
            while (S->Top != -1 && Precedence(S->Stck[S->Top]) >= Precedence(Ch)) {
                // for '^' (right-associative)
                if (Ch == '^' && Precedence(S->Stck[S->Top]) == Precedence(Ch))
                    break;
                printf("%c", Pop(S));
            }
            Push(S, Ch);
        }
    }

    while (S->Top != -1)
        printf("%c", Pop(S));
}

int main() {
    Stack S;
    S.Top = -1;
    char Exp[] = "A+B*(C^D-E)^(F+G*H)-I";
    printf("Postfix: ");
    InfixToPostfix(&S, Exp);
    return 0;
}
