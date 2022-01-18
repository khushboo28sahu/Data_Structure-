#include <stdio.h>

// void print_mat(int *, int, int);
int non_zero_r=0, non_zero_s=0;

int main()
{
    int a[3][3] = {{9,0,0},{0,7,0},{0,0,5}};
    int b[3][3] = {{0,1,0},{0,11,1},{2,0,0}};
    int mul[3][3];
    //int c_rep[3][3];

    int i=0, j=0, k=0, temp_max, temp_min;

    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            if(a[i][j]!=0)
                non_zero_r = non_zero_r+1;
            
            if(b[i][j]!=0)
                non_zero_s = non_zero_s+1;
        }
    }

    int a_rep[non_zero_r][3], b_rep[non_zero_s][3], row_a=0, row_b=0;

    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            if(a[i][j]!=0)
            {
                a_rep[row_a][0] = i;
                a_rep[row_a][1] = j;
                a_rep[row_a][2] = a[i][j];
                row_a = row_a+1;
            }
            if(b[i][j]!=0)
            {
                b_rep[row_b][0] = i;
                b_rep[row_b][1] = j;
                b_rep[row_b][2] = b[i][j];
                row_b = row_b+1;
            }
        }
    }
 
    for (i=0;i<3;i++) 
    { 
        for (j=0;j<3;j++) 
        { 
            mul[i][j]=0; 
            for (k=0;k<3;k++) 
                mul[i][j]+=a[i][k]*b[k][j];
        }
    } 

    // for(i=0;i<non_zero_s;i++)
    // {
    //     for(j=0;j<3;j++)
    //     {
    //         printf("%d ",b_rep[i][j]);
    //     }
    //     printf("\n");
    // }

    row_a=0; row_b=0; 
    int c_rep[non_zero_r+non_zero_s][3], row_c=0;
    i=0;
    while(row_a<non_zero_r && row_b<non_zero_s)
    {
        if(a_rep[row_a][0]==b_rep[row_b][0] && a_rep[row_a][1]==b_rep[row_b][1])
        {
            c_rep[row_a][0] = a_rep[row_a][0];
            c_rep[row_a][1] = a_rep[row_a][1];
            c_rep[row_a][2] = a_rep[row_a][2] + b_rep[row_b][2];

            row_a=row_a+1; row_b=row_b+1;
        }

        else if(a_rep[row_a][0] == b_rep[row_b][0])
        {
            if(a_rep[row_a][1] < b_rep[row_b][1])
            {
                c_rep[row_a][0] = a_rep[row_a][0];
                c_rep[row_a][1] = a_rep[row_a][1];
                c_rep[row_a][2] = a_rep[row_a][2];

                row_a=row_a+1;
            }

            if(a_rep[row_a][1] > b_rep[row_b][1])
            {
                c_rep[row_b][0] = b_rep[row_b][0];
                c_rep[row_b][1] = b_rep[row_b][1];
                c_rep[row_b][2] = b_rep[row_b][2];

                row_b=row_b+1;
            }
        }

        else
        {
            if(a_rep[row_a][0] < b_rep[row_b][0])
            {
                c_rep[row_a][0] = a_rep[row_a][0];
                c_rep[row_a][1] = a_rep[row_a][1];
                c_rep[row_a][2] = a_rep[row_a][2];

                row_a=row_a+1;
            }

            if(a_rep[row_a][0] > b_rep[row_b][0])
            {
                c_rep[row_b][0] = b_rep[row_b][0];
                c_rep[row_b][1] = b_rep[row_b][1];
                c_rep[row_b][2] = b_rep[row_b][2];

                row_b=row_b+1;
            }
        }  
    }

    if(row_a>non_zero_r)
    {
        for(i=row_b; i<non_zero_s; i++)
        {
            for(j=0; j<3; j++)
            {
                c_rep[i][j] = b_rep[i][j];
            }
        }
        row_c = i;
    }

    if(row_b>non_zero_s)
    {
        for(i=row_a; i<non_zero_r; i++)
        {
            for(j=0; j<3; j++)
            {
                c_rep[i][j] = a_rep[i][j];
            }
        }
        row_c = i;
    }

    printf("\n%d\n",row_c);

    for(i=0;i<6;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",c_rep[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",mul[i][j]);
        }
        printf("\n");
    }


    // print_mat(a_rep, non_zero_r, 3);
    // print_mat(b_rep, non_zero_s, 3);

    return 0;
}

// void print_mat(int a[rows][cols], int rows, int cols)
// {
//     for(int i=0; i<rows; i++)
//     {
//         for(int j=0; j<cols; j++)
//         {
//             printf("%d ",a[i][j]);
//         }
//         printf("\n");
//     }
// }

