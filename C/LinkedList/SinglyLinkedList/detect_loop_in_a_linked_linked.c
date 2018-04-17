/*this code is taken from 
*/

#include<stdio.h>
#include<stdlib.h>

//A linked list node
struct node
{
	int data;
	struct node *next;
};
//HELPER FUNCTIONS
/* Given a reference to head of a list
and an int,inserts a new node on the front of the list*/

void push(struct node **head_ref,int data)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

//Helper function for printing linked list
void printList(struct node *node)
{
	while(node->next != NULL)
	{
		printf("%d-> ",node->data);
		node = node->next;
	}
	printf("%d\n",node->data);
}

/* ----------------------Start code from here ------------------------*/

/*
Using Floyd's Cycle-Finding Aglorithm:
This is the fastest method.Traverse linked list using two pointers.
Move one pointer one and other pointer by two.If these pointers meet at some node then there is a loop.If pointer do not meet then linked list does'nt have loop
*/

int detectLoop(struct node *head)
{
	struct node *slow = head,*fast = head;
	
	while(slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast)
		{
			printf("Loop found\n");
			return 1;
		}
	}
	return 0;
}


/* ----------------------------end---------------------------------*/



//Main driver function
int main()
{
	//Start with empty list
	struct node *head = NULL;
	push(&head,20);
	push(&head,4);
	push(&head,15);
	push(&head,10);
 
	//Creating a loop
	head->next->next->next->next = head;
	detectLoop(head);
	return 0;
}

