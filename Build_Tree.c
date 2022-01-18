// build tree
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int left;
    int right;
    int key;
    int parent;
};

struct node attrib[6];
int pre[6] = {7,5,2,6,8,9};
int in[6] ={2,5,6,7,8,9};
int search=0;

int Build_Tree(int, int, int);

int main()
{
    for(int i=0; i<6; i++)
    {
        attrib[i].left = 999;
        attrib[i].right = 999;
        attrib[i].key = 999;
        attrib[i].parent = 999;
    }

    search = Build_Tree(5,0,5);
    printf("%d",search);
}

int Build_Tree(int x, int left, int right)
{
    int mid = ((right-left)/2)+1;

    if(in[mid]==x)
    {
        return mid;
    }

    if(in[mid]>x)
    {
        return Build_Tree(x, left, mid-1);
    }

    if(in[mid]<x)
    {
        return Build_Tree(x, mid+1, right);
    }
}
