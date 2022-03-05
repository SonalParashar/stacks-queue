#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 100

struct stack
{
    int top;
    char array[MAXLEN];
};

int palindrome(char*);
int isEmpty(struct stack* stack);
char pop(struct stack*);
void push(struct stack*, char);
int main()
{
    char exp[MAXLEN];
    printf("Enter String\n");
    fgets(exp,MAXLEN,stdin);
    exp[strcspn(exp, "\n")] = 0;
    if(palindrome(exp))
        printf("\tIt is a palindrome");
    else
        printf("\tIt is not a palindrome");
    return 0;
}

int palindrome(char* exp)
{
    struct stack st;
    st.top = -1;
    int l = strlen(exp);
    int i, mid = l / 2;
 
    for (i = 0; i < mid; i++) 
        push(&st,exp[i]);
    if (l % 2 != 0)
        i++;
    while (exp[i] != '\0') 
    {
        char c = pop(&st);
        if (c != exp[i])
            return 0;
        i++;
    }
    return 1;
}
int isEmpty(struct stack* stack)
{
    return stack->top == -1 ;
}
char pop(struct stack* stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--] ;
    return '$';
}
void push(struct stack* stack, char op)
{
    stack->array[++stack->top] = op;
}