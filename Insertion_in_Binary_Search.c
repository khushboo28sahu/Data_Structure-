/*#include <stdio.h>

int binary_s(int *, int);
void insertion_s(int *);

int main()
{
    int a[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    insertion_s(a);

    for(int i=0; i<9; i++)
    {
        printf("%d ",a[i]);
    }

    return 0;
}

int binary_s(int a[], int key)
{
    int length = 9;//sizeof(a)/sizeof(a[0]);
    int left = 0, right = length-1, mid, i=0;

    while(left<=right)
        {
            mid = (right+left)/2;

            if(a[mid]==key)
            {
                return mid+1;
            }

            else if(key<a[mid])
            {
                right = mid-1;
            }

            else if(key>a[mid])
            {
                left = mid+1;
            }
        }
}

void insertion_s(int a[])
{
    int i, target, j, k, pickup;
    int n = 9;//sizeof(a)/sizeof(a[0]);
  
    for (i = 1; i < n; ++i) 
    { 
        j = i - 1; 
        pickup = a[i]; 
  
        target = binary_s(a, pickup); 
   
        while (j >= target) 
        { 
            a[j+1] = a[j]; 
            j--; 
        } 
        a[j+1] = pickup; 
    } 
}*/

#include <stdio.h> 
  
int binary_s(int *, int, int, int);
void insertion_s(int *, int);

int main() 
{ 
    int a[] = {90, 80, 70, 60, 50, 40, 30, 20, 10}; 
    int n = sizeof(a)/sizeof(a[0]), i; 
  
    insertion_s(a, n); 
  
    //printf("Sorted array: \n"); 
    for (i = 0; i < n; i++) 
        printf("%d ",a[i]); 
  
    return 0; 
}

int binary_s(int a[], int key, int l, int r) 
{ 
    if (r <= l) 
        return (key > a[l])?  (l + 1): l; 
  
    int mid = (l + r)/2; 
  
    if(key == a[mid]) 
        return mid+1; 
  
    if(key > a[mid]) 
        return binary_s(a, key, mid+1, r); 
    return binary_s(a, key, l, mid-1); 
}

void insertion_s(int a[], int n) 
{ 
    int i, target, j, k, pickup; 
  
    for (i = 1; i < n; ++i) 
    { 
        j = i - 1; 
        pickup = a[i]; 
  
        target = binary_s(a, pickup, 0, j); 
  
        while (j >= target) 
        { 
            a[j+1] = a[j]; 
            j--; 
        } 
        a[j+1] = pickup; 
    } 
}

