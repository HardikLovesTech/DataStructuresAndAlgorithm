#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Function to check for duplicate parentheses in an expression
int top = -1;

// bool isDuplicate(char s[]) {
//     char Stack[MAX_SIZE];
//     int n = strlen(s);

//     for (int i = 0; i < n; i++) {
//         if (s[i] == ')') {
//             // Case 1: Empty brackets ()
//             if (top != -1 && Stack[top] == '(') {
//                 return true; // Duplicate found
//             }

//             int elementsInside = 0;

//             // Pop until '(' is found
//             while (top != -1 && Stack[top] != '(') {
//                 elementsInside++;
//                 top--;
//             }

//             // Pop the '(' also
//             if (top != -1) {
//                 top--;
//             }

//             // If no valid content inside ()
//             if (elementsInside < 1) {
//                 return true;
//             }
//         } else {
//             // Push character onto stack
//             Stack[++top] = s[i];
//         }
//     }

//     // If unmatched parentheses remain
//     while (top != -1) {
//         if (Stack[top] == '(') {
//             return true;
//         }
//         top--;
//     }

//     return false;
// }

// int main() {
//     char s[MAX_SIZE] = "(((a+(b))+(c+d)))";

//     if (isDuplicate(s)) {
//         printf("Expression contains duplicate parentheses.\n");
//     } else {
//         printf("Expression does not contain duplicate parentheses.\n");
//     }

//     return 0;
// }

int stack[100];
char infix[100];
char postfix[100];


void InToPost()
{
  int i, j=0,x;
  char symbol, next;
  for(i=0; i<strlen(infix); i++)
  {
    symbol = infix[i];
    switch(symbol)
    {
      case ' ':
      case '\t':
          break;
      case '(':
          push(symbol);
          break;
      case ')':
          while( (next = pop()) != '(')
              postfix[j++] = next;
          break;
      case '^':
      case '*':
      case '/':
      case '+':
      case '-':
          while(top!=-1 && precedence(symbol) <= precedence(stack[top]))
              postfix[j++] = pop();
          push(symbol);
          break;
      default:
          while(infix[i+1] >= '0' && infix[i+1] <= '9')
              {
                x = ((symbol-'0') * 10) + (infix[++i]-'0');
                symbol = (x+'0');
              }                
          postfix[j++] = symbol;
          break;
    }
  }
  while(top != -1)
      postfix[j++] = pop();
  postfix[j++] = '\0';
}

int precedence(char s)
{
  switch(s)
  {
    case '^':  return 3;
               break;
    case '*':
    case '/':  return 2;
               break;
    case '+':
    case '-':  return 1;
               break;
    default:   return 0;
               break;
  }
}

int post_evaluation()
{
  int i,a,b,n;
  for(i=0; i<strlen(postfix); i++)
  {
    if(postfix[i]!='+' && postfix[i]!='-' && postfix[i]!='*'
        && postfix[i]!='/' && postfix[i]!='^')  
          push(postfix[i]-'0');
    else
    {
      a = pop();
      b = pop();
      switch(postfix[i])
      {
        case '+':  push(b+a);
                   break;
        case '-':  push(b-a);
                   break;
        case '*':  push(b*a);
                   break;
        case '/':  push(b/a);
                   break;
        case '^':  push(pow(b,a));
                   break;
      }
    }
  }
  return pop();
}

void print(char *s)
{
  int i=0;
  printf("Postfix expression: ");
  while(s[i])
  {
    if(postfix[i]!='+' && postfix[i]!='-' && postfix[i]!='*'
        && postfix[i]!='/' && postfix[i]!='^')
        printf("(%d)",(s[i]-'0'));
    else
        printf("%c",s[i]);
    i++;
  }
  printf("\n");
}
