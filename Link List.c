#include <stdio.h> 
#include <stdlib.h> 
  
struct Node 
{ 
    int degree;
    int coeff; 
    struct Node* next; 
}; 
  
int main() 
{ 
    struct Node* head1 = NULL; 
    struct Node* second1 = NULL; 
    struct Node* third1 = NULL;

    struct Node* head2 = NULL; 
    struct Node* second2 = NULL; 
    struct Node* third2 = NULL;

    struct Node* head3 = NULL;  
  
    
    head1 = (struct Node*)malloc(sizeof(struct Node)); 
    second1 = (struct Node*)malloc(sizeof(struct Node)); 
    third1 = (struct Node*)malloc(sizeof(struct Node));

    head2 = (struct Node*)malloc(sizeof(struct Node)); 
    second2 = (struct Node*)malloc(sizeof(struct Node)); 
    third2 = (struct Node*)malloc(sizeof(struct Node));

    head3 = (struct Node*)malloc(sizeof(struct Node)); 
  
    head1->degree = 3;
    head1->coeff = 1;
    head1->next = second1;
    
    second1->degree = 1;
    second1->coeff = 2; 
    second1->next = third1; 
  
    third1->degree = 0;
    third1->coeff = 13;
    third1->next = NULL;

    head2->degree = 2;
    head2->coeff = 5;
    head2->next = second2;
    
    second2->degree = 1;
    second2->coeff = 7; 
    second2->next = third2; 
  
    third2->degree = 0;
    third2->coeff = 1;
    third2->next = NULL;

    head3->degree = 9999;
    head3->coeff = 9999;
    head3->next = NULL;

    struct Node* temp1;
    struct Node* temp2;
    struct Node* temp3;

    temp1 = head1; temp2 = head2; temp3 = head3;

    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->degree == temp2->degree)
        {
            struct Node* new_node = NULL;
            new_node = (struct Node*)malloc(sizeof(struct Node));

            temp3->next = new_node;

            new_node->degree = temp1->degree;
            new_node->coeff = temp1->coeff + temp2->coeff;
            new_node->next = NULL;

            temp1 = temp1->next; temp2 = temp2->next; temp3 = temp3->next;

        }

        else if(temp1->degree > temp2->degree)
        {
            struct Node* new_node = NULL;
            new_node = (struct Node*)malloc(sizeof(struct Node));

            temp3->next = new_node;

            new_node->degree = temp1->degree;
            new_node->coeff = temp1->coeff;
            new_node->next = NULL;

            temp1 = temp1->next; temp3 = temp3->next;
        }

        else
        {
            struct Node* new_node = NULL;
            new_node = (struct Node*)malloc(sizeof(struct Node));

            temp3->next = new_node;

            new_node->degree = temp2->degree;
            new_node->coeff = temp2->coeff;
            new_node->next = NULL;

            temp2 = temp2->next; temp3 = temp3->next;  
        }
    }

    temp1 = head3;

    while(temp1!=NULL)
    {
        printf("%dx^%d\n", temp1->coeff, temp1->degree);

        temp1 = temp1->next;
    }
  
    return 0; 
}

