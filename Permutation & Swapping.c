#include <stdio.h>

void permute(int *, int, int);
void swap(int *, int *);

int main()
{
    int a[] = {1, 2, 3, 4};

    permute(a,0,3);

    return 0;
}

void permute(int a[], int l, int r)
{
    int i=0;
    if(l==r)
    {
        for(i=0; i<4; i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
    }
    else
    {
        i=l;
        while(i<=r)
        {
            swap((a+l), (a+i));
            permute(a, l+1, r);
            swap((a+l), (a+i));
            i=i+1;
        }
    }
    
        // permute(a, l+1, r);
        // swap(a+l,a+r);
        // //printf("%d ",a[l]);
        // permute(a, l+1, r);
        // printf("%d ",a[l]);   
}

void swap(int *x, int *y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

