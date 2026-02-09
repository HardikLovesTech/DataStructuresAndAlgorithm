#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define max 100
#define MAX_SIZE 1000000

// Function to check for duplicate parentheses in an expression
int top = -1;

bool isDuplicate(char s[]) {
    char Stack[MAX_SIZE];
    int n = strlen(s);

    for (int i = 0; i < n; i++) {
        if (s[i] == ')') {
            // Case 1: Empty brackets ()
            if (top != -1 && Stack[top] == '(') {
                return true; // Duplicate found
            }

            int elementsInside = 0;

            // Pop until '(' is found
            while (top != -1 && Stack[top] != '(') {
                elementsInside++;
                top--;
            }

            // Pop the '(' also
            if (top != -1) {
                top--;
            }

            // If no valid content inside ()
            if (elementsInside < 1) {
                return true;
            }
        } else {
            // Push character onto stack
            Stack[++top] = s[i];
        }
    }

    // If unmatched parentheses remain
    while (top != -1) {
        if (Stack[top] == '(') {
            return true;
        }
        top--;
    }

    return false;
}

// int main() {
//     char s[MAX_SIZE] = "(((a+(b))+(c+d)))";

//     if (isDuplicate(s)) {
//         printf("Expression contains duplicate parentheses.\n");
//     } else {int top = 3;

//         printf("Expression does not contain duplicate parentheses.\n");
//     }

//     return 0;
// }

// int stack[100];
// char infix[100];
// char postfix[100];


// void InToPost()
// {
//   int i, j=0,x;
//   char symbol, next;
//   for(i=0; i<strlen(infix); i++)
//   {
//     symbol = infix[i];
//     switch(symbol)
//     {
//       case ' ':
//       case '\t':
//           break;
//       case '(':
//           push(symbol);
//           break;
//       case ')':
//           while( (next = pop()) != '(')
//               postfix[j++] = next;
//           break;
//       case '^':
//       case '*':
//       case '/':
//       case '+':
//       case '-':
//           while(top!=-1 && precedence(symbol) <= precedence(stack[top]))
//               postfix[j++] = pop();
//           push(symbol);
//           break;
//       default:
//           while(infix[i+1] >= '0' && infix[i+1] <= '9')
//               {
//                 x = ((symbol-'0') * 10) + (infix[++i]-'0');
//                 symbol = (x+'0');
//               }                
//           postfix[j++] = symbol;
//           break;
//     }
//   }
//   while(top != -1)
//       postfix[j++] = pop();
//   postfix[j++] = '\0';
// }

// int precedence(char s)
// {
//   switch(s)
//   {
//     case '^':  return 3;
//                break;
//     case '*':
//     case '/':  return 2;
//                break;
//     case '+':
//     case '-':  return 1;
//                break;
//     default:   return 0;
//                break;
//   }
// }

// int post_evaluation()
// {
//   int i,a,b,n;
//   for(i=0; i<strlen(postfix); i++)
//   {
//     if(postfix[i]!='+' && postfix[i]!='-' && postfix[i]!='*'
//         && postfix[i]!='/' && postfix[i]!='^')  
//           push(postfix[i]-'0');
//     else
//     {
//       a = pop();
//       b = pop();
//       switch(postfix[i])
//       {
//         case '+':  push(b+a);
//                    break;
//         case '-':  push(b-a);
//                    break;
//         case '*':  push(b*a);
//                    break;
//         case '/':  push(b/a);
//                    break;
//         case '^':  push(pow(b,a));
//                    break;
//       }
//     }
//   }
//   return pop();
// }

// void print(char *s)
// {
//   int i=0;
//   printf("Postfix expression: ");
//   while(s[i])
//   {
//     if(postfix[i]!='+' && postfix[i]!='-' && postfix[i]!='*'
//         && postfix[i]!='/' && postfix[i]!='^')
//         printf("(%d)",(s[i]-'0'));
//     else
//         printf("%c",s[i]);
//     i++;
//   }
//   printf("\n");
// }


// Stack is a struct
// struct stack {
//     char stck[max];
//     int top;
// };

// typedef struct stack stack;

// void push(stack *s, char item) {
//     if (s->top != max - 1) {
//         s->stck[++s->top] = item;
//     }
// }

// void pop(stack *s) {
//     if (s->top != -1) {
//         --s->top;
//     }
// }

// bool CheckPair(char val1, char val2) {
//     return (
//         (val1 == '(' && val2 == ')') ||
//         (val1 == '[' && val2 == ']') ||
//         (val1 == '{' && val2 == '}')
//     );
// }

// bool CheckBalanced(stack *s, char exp[]) {
//     int i = 0;
//     while (exp[i] != '\0') {
//         char s1 = exp[i];
//         if (s1 == '(' || s1 == '[' || s1 == '{') {
//             push(s, s1);
//         } else if (s1 == ')' || s1 == ']' || s1 == '}') {
//             if (s->top == -1) return false;
//             else if (CheckPair(s->stck[s->top], s1)) {
//                 pop(s);
//             } else return false;
//         }
//         i++;
//     }
//     return (s->top == -1);
// }

// bool isEmpty(stack *s) {
//     return (s->top == -1);
// }

// bool DuplicateParanthesis(stack *s, char exp[]) {
//     for (int i = 0; exp[i] != '\0'; i++) {
//         char ch = exp[i];

//         if (ch == ')') {
//             if (isEmpty(s)) return false; // nothing to match

//             int count = 0;
//             // pop elements until '(' found
//             while (!isEmpty(s) && s->stck[s->top] != '(') {
//                 pop(s);
//                 count++;
//             }

//             // if '(' found immediately (count == 0), duplicate found
//             if (count == 0) return true;

//             if (!isEmpty(s)) pop(s); // pop the '('
//         }
//         else {
//             push(s, ch);
//         }
//     }
//     return false;
// }

// int main() {
//     stack s;
//     s.top = -1;
//     char exp[max];

//     printf("Enter the expression: ");
//     scanf("%s", exp);

//     if (CheckBalanced(&s, exp))
//         printf("Parentheses are balanced.\n");
//     else
//         printf("Not balanced.\n");

//     stack d;
//     d.top = -1;

//     if (DuplicateParanthesis(&d, exp))
//         printf("Duplicate parentheses found.\n");
//     else
//         printf("No duplicate parentheses.\n");

//     return 0;
// }