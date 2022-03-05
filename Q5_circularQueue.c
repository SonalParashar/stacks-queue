#include <stdio.h>
#define Max 10

struct queue
{
    int data[Max];
    int rear, front;
};
int dequeue(struct queue *pt);
void enqueue(struct queue *pt, int x);
void display(struct queue q);
int isEmpty(struct queue *pt);

int main()
{
    struct queue Q;
    Q.front= -1;
    Q.rear= -1;
    int val, ch, t, m, n;
    do
    {
        printf("\nMENU \n\t1. Enqueue\n\t2. Dequeue\n\t3. Dispaly\n\t4. Empty\n\t5. EXIT\n\tEnter Your CHOICE: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("\n\tEnter element: ");
            scanf("%d",&val);
            enqueue(&Q,val);
            break;
            
            case 2:
            t=dequeue(&Q);
            if(t!=-1)
            printf("\n\t%d is dequeue\n", t);
            break;

            case 3:
            display(Q);
            break;

            case 4: 
            m = isEmpty(&Q);
            if(m==1)
            {
                printf("\n\t\tQUEUE is EMPTY!\n");
            }
            else 
            {
                printf("\n\t\tQUEUE is not EMPTY\n");
            }
            break;
        }
    } 
    while(ch!=0);
    return 0;
}

void enqueue(struct queue *pt, int x)
{
    if(pt->front==((pt-> rear +1)% Max))
    {
        printf("\nQueue overflow");
        return;
    }
    if(pt-> front==-1)
    {
        pt-> front =0;
    }
    pt-> rear = (pt-> rear +1)% Max;
    pt-> data [pt-> rear]= x;
}

void display(struct queue q)
{
    int i;
    if(q.front == q.rear)
    {
        printf("%d\t", q.data[q.front]);
    }
    else
    {
        if(q.rear < q.front)
        {
            i=q.front;
            while(1)
            {
                printf("%d\t", q.data[i]);
                i=((i+1)% Max);
                if(i==q.rear+1)
                {
                    break;
                }
            }
        }
        else
        {
            for(i=q.front;i<=q.rear;i=i+1)
            {
                printf("%d\t", q.data[i]);
            }
        }
    }
}

int dequeue(struct queue *pt)
{
    int x;
    if(pt-> front == -1)
    {
        printf("\nQueue underflow\n");
        return -1;
    }
    x=pt->data [pt-> front];
    if(pt-> front == pt-> rear)
    {
        pt-> front = -1;
        pt->rear = -1;
    }
    else 
    {
        pt->front =(pt-> front +1)% Max;
    }
    return x;
}

int isEmpty(struct queue *pt)
{
    if(pt-> front == -1)
    return 1;
    return 0;
}