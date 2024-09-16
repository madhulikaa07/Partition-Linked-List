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
	printf("Input:\n");
	print();
    partition(part);
    printf("Output:\n");
	print();
	
    
}

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

/*******************************************************************************
 * partition : This function takes the patition as the input. It rearranges the 
 * Linked List such that all nodes less than x come before all nodes greater than 
 * or equal to x
 * 
 * We initialize two local pointer to struct Node* head_t and tail_t to head.
 * We then traverse the linked list one node at a time.
 * If the value of the current node is greater than or equal to the partition, 
 * it is appended it to the tail.
 * If the current node is less than the partition it is appended before the head.
 * 
 * Finally we set the tail_t->next = NULL and head = head_t.
 * we then return head for the resultant linked list
 */
 
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
        if(temp->data >= part)
        {
            tail_t->link = temp;
            tail_t = temp;
        }
        else
        {
            temp->link = head_t;
            head_t = temp;
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