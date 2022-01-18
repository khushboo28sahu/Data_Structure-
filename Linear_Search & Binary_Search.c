#include <stdio.h>

int main()
{
    int a[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int length = sizeof(a)/sizeof(a[0]);
    int i=0, j=0, key;

    //Linear search
    /*while(i<length)
    {
        key = a[i];

        j=0;
        while(j<length)
        {
            if(a[j]==key)
            {
                printf("\nComparisons: %d for %d", j+1, key);
                break;
            }
            j=j+1;
        }
        i=i+1;
    }*/

    //Binary Search
    int left = 0, right = length-1, mid;

    while(i<length)
    {
        key = a[i]; j=0; left=0; right=length-1;

        while(left<=right)
        {
            mid = (right+left)/2;

            if(a[mid]==key)
            {
                printf("\nComparisons: %d for %d", j+1, key);
                break;
            }

            else if(key<a[mid])
            {
                right = mid-1;
            }

            else if(key>a[mid])
            {
                left = mid+1;
            }
            
            j=j+1;
        }
        i=i+1;
    }

    //Ternary Search
    /*int mid1, mid2, left, right;

    while(i<length)
    {
        left=0; right=length-1; key=a[i]; j=0;

        while(left<=right)
        {
            mid1 = left+(right-left)/3;
            mid2 = right-(right-left)/3;

            if(a[mid1]==key)
            {
                printf("\nComparisons: %d for %d", j+1, key);
                break;
            }
            if(a[mid2]==key)
            {
                printf("\nComparisons: %d for %d", j+1, key);
                break;
            }
            if(key<a[mid1])
            {
                right = mid1-1;
            }
            else if(key>a[mid2])
            {
                left = mid2+1;
            }
            else
            {
                left = mid1+1;
                right = mid2-1;
            }
            j=j+1;
        }
        i=i+1;
    }*/

    return 0;
}

