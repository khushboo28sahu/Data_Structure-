#include <stdio.h>
#include <stdlib.h>

void enqueue(int *, int *, int);
void dequeue(int *, int *);
void print(int *);
int top1=0, top2=0, capacity;

int main()
{
    printf("Enter capacity of queue: ");
    scanf("%d",&capacity);

    int s1[capacity], s2[capacity];

    enqueue(s1,s2,1);
    print(s1);
    enqueue(s1,s2,2);
    print(s1);
    enqueue(s1,s2,3);
    print(s1);
    dequeue(s1,s2);
    print(s1);
    enqueue(s1,s2,1);
    print(s1);

    return 0;
}

void enqueue(int s1[], int s2[], int item)
{
    if(top1+1>capacity)
    {
        printf("\nQueue is full");
        exit(0);
    }

    s1[top1]=item; top1=top1+1;
}

void dequeue(int s1[], int s2[])
{
    int i;
    if(top1==0)
    {
        printf("\nQueue is empty");
        exit(0);
    }

    int top2=0;
    for(i=top1; i>0; i--)
    {
        s2[top2] = s1[i];
        top2=top2+1;
    }
    //print(s2);
    top2=top2-1;

    top1=0;
    for(i=top2; i>=0; i--)
    {
        s1[top1] = s2[i];
        top1=top1+1;
    }
    top1=top1-1;
}

void print(int a[])
{
    printf("\n");
    for(int i=0; i<top1; i++)
    {
        printf("%d ",a[i]);
    }
}

