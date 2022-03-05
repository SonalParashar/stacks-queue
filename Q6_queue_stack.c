#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

#define MAX 10

struct queue
{
    int data[MAX];
    int front,rear;
};
typedef struct queue qu;

struct stack
{
    int items[MAX];
    int top;
};
typedef struct stack st;

//QUEUE FUNCTIONS
int CreateEmptyQueue(qu *q);
int isFull(qu *q);
int isEmpty(qu *q);
int enQueue(qu *q, int n);
int deQueue(qu *q);
int display(qu *q);

//STACK FUNCTIONS
int CreateEmptyStack(st *s);
int sEmpty(st *s);
int Push(st *s, int n);
int Pop(st *s);

//REVERSE FUNSTIONS
int renQueue(qu *q, st *s);
int rdeQueue(qu *q,st *s);
int reverse(qu *q, st *s);

int main()
{
    int n;
    qu *q = (qu *)malloc(sizeof(qu));
    CreateEmptyQueue(q);

    st *s = (st *)malloc(sizeof(st));
    CreateEmptyStack(s);

    while(n!=5)
    {
        printf("\nEnter 1 to enqueue an element\nEnter 2 to dequeue an element\nEnter 3 to reverse the queue\nEnter 4 to display the queue\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                printf("Enter the element you want to enqueue : ");
                scanf("%d",&n);
                enQueue(q, n);
                n=2;
                break;
            case 2:
                 deQueue(q);
                break;
            case 3:
                reverse(q,s);
                break;
            case 4:
                display(q);
                break;
            default:
                printf("Wrong input!");
        }
    }

    free(q);
    q=NULL;
    free(s);
    s=NULL;
    getch();
    return 0;

}

//REVERSE FUNCTIONS
int reverse(qu *q, st *s)
{
    while(!isEmpty(q))
        rdeQueue(q,s);
    while(!isEmpty(s))
        renQueue(q,s);

    printf("Queue reversed\n");
    return 0;
}

int rdeQueue(qu *q,st *s)
{
    Push(s,q->data[q->front]);
    if (q->front == q->rear)
        CreateEmptyQueue(q);
    else
        q->front = (q->front + 1) % MAX;
    return 0;
}

int renQueue(qu *q, st *s)
{
    if (q->front == -1)
        q->front = 0;
    q->rear = (q->rear + 1) % MAX;

    q->data[q->rear] = Pop(s);

    return 0;
}

//QUEUE FUNCTIONS
int CreateEmptyQueue(qu *q)
{
    q->front = -1;
    q->rear = -1;
    return 0;
}

int isFull(qu *q)
{
    if (q->front == (q->rear + 1)% MAX)
        return 1;

    return 0;
}

int isEmpty(qu *q)
{
    if (q->front == -1)
        return 1;
    return 0;
}

int enQueue(qu *q, int n)
{
    if (isFull(q))
        printf("Queue is full!\n");
    else
    {
        if (q->front == -1)
            q->front = 0;
        q->rear = (q->rear + 1) % MAX;
        q->data[q->rear] = n;
        printf("Inserted : %d\n", n);
    }

    return 0;
}

int deQueue(qu *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty!!\n");
        return -1;
    }
    else
    {
        int n = q->data[q->front];
        if (q->front == q->rear)
            CreateEmptyQueue(q);
        else
            q->front = (q->front + 1) % MAX;

        printf("Deleted element : %d\n", n);
        return n;
    }
}

int display(qu *q)
{
    if (isEmpty(q))
        printf("Empty Queue\n");
    else
    {
        printf("Front position : %d ", q->front);
        printf("\nItems : ");
        int i;
        for (i = q->front; i != q->rear; i = (i + 1) % MAX)
            printf("%d ", q->data[i]);

        printf("%d ", q->data[i]);
        printf("\nRear position: %d\n", q->rear);
    }

    return 0;
}

//STACK FUNCTIONS
int CreateEmptyStack(st *s)
{
  s->top = -1;

  return 0;
}

int sEmpty(st *s)
{
    if (s->top == -1)
        return 1;

    return 0;
}

int Push(st *s, int n)
{
    s->top++;
    s->items[s->top] = n;

    return 0;
}

int Pop(st *s)
{
    s->top--;
    return s->items[(s->top)+1];
}