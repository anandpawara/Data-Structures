/*this code is taken from
 https://www.geeksforgeeks.org/nth-node-from-the-end-of-a-linked-list/
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
	while(node != NULL)
	{
		printf("%d ",node->data);
		node = node->next;
	}
}

/* ----------------------Start code from here ------------------------*/

void printNthFromLast(struct node *head,int n)
{
	struct node *main_ptr =head;
	struct node *ref_ptr = head;
	
	int count = 0;
	if(head)
	{
		while(count < n)
		{
			if(ref_ptr == NULL)
			{
				printf("%d is greater than the no. of nodes in list",n);
				return;
			}
		ref_ptr = ref_ptr->next;
		count++;
		}
	
		while(ref_ptr != NULL)
		{
			main_ptr = main_ptr->next;
			ref_ptr = ref_ptr->next;
		}
		printf("Node no. %d from last is %d",n,main_ptr->data);
	}
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
	push(&head,35);
 	printf("\n");
 	printList(head);
 	printf("\n");
 	printNthFromLast(head,4);
	return 0;
}

