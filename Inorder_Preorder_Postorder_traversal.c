//in-order, pre-order, post-order tree taversal
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int left;
    int right;
    int key;
};

struct node attrib[6];
void inorder(int);
void preorder(int);
void postorder(int);

int main()
{
    for(int i=0; i<6; i++)
    {
        attrib[i].left = 999;
        attrib[i].right = 999;
        attrib[i].key = 999;
    }

    attrib[0].left = 1; attrib[0].right = 2; attrib[0].key = 7;
    attrib[1].left = 3; attrib[1].right = 4; attrib[1].key = 5;
    attrib[2].right = 5; attrib[2].key = 8;
    attrib[3].key = 2;
    attrib[4].key = 6;
    attrib[5].key = 9;

    inorder(0); printf("\n");
    preorder(0); printf("\n");
    postorder(0);
}

// Inorder
void inorder(int r)
{
    if(r != 999)
    {
        inorder(attrib[r].left);
        
        printf("%d ",attrib[r].key);

        inorder(attrib[r].right);
    }
}

//PreOrder
void preorder(int r)
{
    if(r != 999)
    {
            printf("%d ",attrib[r].key);
        
            preorder(attrib[r].left);
        
            preorder(attrib[r].right);
    }
}
// Postorder
void postorder(int r)
{
    if(r != 999)
    {   
        postorder(attrib[r].left);
        
        postorder(attrib[r].right);

        printf("%d ",attrib[r].key);
    }
}
