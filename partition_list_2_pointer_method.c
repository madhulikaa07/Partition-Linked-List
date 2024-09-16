/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

Delete duplicates from a linked list
Tips: remember to check derefrencing a null pointer while deleting last node 

Cracking The Coding Interview
Partition: Write code to partition a linked list around a value x, such that all nodes less than x come 
before all nodes greater than or equal to x. If xis contained within the list, the values of x only need 
to be after the elements less than x (see below). The partition element x can appear anywhere in the 
"right partition"; it does not need to appear between the left and right partitions. 
EXAMPLE 
Input: 
Output: 
3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition= 5] 
3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* link;
};

int insert(int data);
//void insert_beg(int data);
struct Node* print();
void partition(int part);
struct Node* head = NULL;


int main()
{
    insert(3);
    insert(5);
    insert(8);
	insert(5);
	insert(10);
	insert(2);
	insert(1);
	
	int part = 5;
	print();
    partition(part);
	print();
	
    
}

/*void insert_beg(int data)
{
    //Insert a Node in the beginning of a Linkedlist
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->link = head;//this node now points to the previous 1st Node
    head = temp; //head now points to this node
    
    return;
}*/

int insert(int data)
{
   
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    temp1->data = data;
    temp1->link = NULL;
    
    if(head == NULL)
    {
        head = temp1;
    }
    else
    {
        struct Node* temp2 = head;
        
        while(temp2->link != NULL)
        {
            temp2 = temp2->link;
        }
        
        temp2->link = temp1;
    }
    
    return 0;
}

void partition(int part)
{
    
    struct Node* temp = head;
    struct Node* temp1;
    temp1=temp;
    struct Node* head_t = head;
    struct Node* tail_t = head;
    
    while(temp != NULL)
    {
        temp1 = temp->link;
        printf("Current Node is at %d\n",temp->data);
        if(temp->data >= part)
        {
            tail_t->link = temp;
            tail_t = temp;
            printf("Tail is now at %d\n",tail_t->data);
        }
        else
        {
            temp->link = head_t;
            head_t = temp;
            printf("Head is now at %d\n",head_t->data);
        }
        temp = temp1;
    }
    
    tail_t->link=NULL;
    head = head_t;

}


struct Node* print()
{
    printf("\n");
    struct Node* temp = head;
    struct Node* temp1;
    while(temp != NULL)
    {
        printf(" %d",temp->data);
        if(temp->data == 7)
        {
            temp1= temp;
        }
        temp = temp->link;
    }
    printf("\n");
    
    return temp1;
}