#include<stdio.h>
#include<string.h>
#define MAX 5

struct stack
{
    int elements[MAX];
    int top;
};

int pop(struct stack *);
void push(struct stack *, int);
int isEmpty(struct stack *);
int Balanced(char *st, int l, struct stack S);

int main()
{
    struct stack S1;
    S1.top = -1;
   char str[100];
   int n,i;
   printf("\nEnter number of inputs : ");
   scanf("%d\n", &n);

    for( i=0; i<n; i++)
    {
         gets(str);
    	//}
    	int l = strlen(str);

    	if(Balanced(str, l,  S1))
    	{
        	printf("Balanced\n\n");
    	}
    	else
    	{
        	printf("Not Balanced\n\n");
    	}
    }
    return 0;
}

void push(struct stack *S, int val)
{
    if(S -> top == MAX-1)
    {
        printf("\nStack Overflow\n");
        return;
    }
    S -> top = S->top + 1;
    S->elements[S->top] = val;
}


int pop(struct stack *S)
{
    int tmp;
    if(S->top < 0)
    {
        printf("\nUnderflow\n");
        return -1;
    }
    tmp = S->elements[S->top];
    S->top = S->top - 1;
    return tmp;
}

int isEmpty(struct stack *S)
{
  if(S->top==-1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
int Balanced(char *st, int l, struct stack S)
{
    char x,i;

    if(st[0] == '(')
    {
        for(i=1; i<l; i++)
        {
            if(st[i] == '{' || st[i] == '}' || st[i] == '[' || st[i] == ']')
                return 0;
        }
    }
    else if(st[0] == '{')
    {
        for( i=1; i<l; i++)
        {
            if(st[i] == '[' || st[i] == ']')
                return 0;
        }
    }
    for ( i = 0; i < l; i++)
    {
        if (st[i] == '(' || st[i] == '[' || st[i] == '{')
        {
            push(&S, st[i]);
            continue;
        }

        if (isEmpty(&S))
        {
            return 0;
        }

        switch (st[i]) {
        case ')':
            x = S.elements[S.top];
            pop(&S);
            if (x == '{' || x == '[' )
            {
                 return 0;
            }
            break;
        case '}':
            x = S.elements[S.top];
            pop(&S);
            if (x == '(' || x == '[' )
            {
                return 0;
            }
            break;
        case ']':
            x = S.elements[S.top];
            pop(&S);
            if (x == '(' || x == '{')
            {
                return 0;
            }
            break;
        }
    }
    return (isEmpty(&S));
}