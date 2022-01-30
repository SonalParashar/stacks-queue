
#include<stdio.h>
#include<stdlib.h>
#define MAX_STACK 5

struct stack 
{
    int data[MAX_STACK];
    int top;
};
int pop(struct stack *);
void push(struct stack *,int);
int isempty(struct stack *);
int peek(struct stack *);
void display(struct stack );

void push(struct stack *pt,int x)
{
    if(pt->top== MAX_STACK-1)
    {
        printf("Stack overflow");
    }
   else 
       {    pt->top++;
            pt->data[pt->top]=x;
    }
    
}

int pop(struct stack *pt)
{
    
    int tmp;
    /*
    if(pt->top==-1)
    {
        printf("Stack underflow");
        return -1;
    }
    else
    {       tmp=pt->data[pt->top];
		    pt->top--;
		    return tmp;
    }*/
    tmp=pt->data[pt->top];
	pt->top--;
	return tmp;
}

int isempty(struct stack *pt)
{
	if (pt->top==-1)
		return -1; 
}

int peek(struct stack *pt)
{
	return (pt->data[pt->top]);
}

void display(struct stack s)
{
    int i;
    
    for(i=s.top;i>=0;i--)
    {
        printf("\t %d",s.data[i]);
    }
}


int main()
{
   int  c,ch, val,p;
   struct stack ptr;
   ptr.top=-1;
   
    while (1) 
    {
    	
    	printf("\n MENU: ");
    	printf("\n1.Push");
    	printf("\n2.pop");
    	printf("\n3.peek");
    	printf("\n4.Display");
    	printf("\n5.Exit");
    	printf("\n");
    	printf("\nEnter your choice : ");
    	scanf("%d", &ch);
    	switch (ch) 
    	{
    		case 1:
        		printf("\nEnter the element into stack:");
        		scanf("%d", &val);
        		push(&ptr, val);
        		break;
    		case 2:
        		if(isempty(&ptr)==-1)
        		{
         			printf("The Stack is EMPTY");
				}
		 		else
				{
		 			c=pop(&ptr);
         			printf("\nThe element popped from stack is : %d", c);
				}
		 		break;
	  		case 3: 
	  			p= peek(&ptr);
	  			printf("The value PEEKED: %d",p);
	  			break;
      		case 4:
         		printf("\nThe current stack elements are:");
         		display(ptr);
         		break;
      		case 5:
         		exit(0);
      		default:
         		printf("\nEnter correct option!Try again.");
      	}
   }
   return (0);
}
