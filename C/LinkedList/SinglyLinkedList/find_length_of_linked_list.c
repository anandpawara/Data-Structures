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
	while(node != NULL)
	{
		printf("%d ",node->data);
		node = node->next;
	}
}

/* ----------------------Start code from here ------------------------*/
//Counts no. of nodes iteratively

/*int getCount(struct node *head)
{
	int count = 0;
	struct node *current = head;
	//If empty list is passed the return count = 0
	if(head == NULL)
		return 0;
	//Traverse node till last node
	while(current != NULL)
	{
		count++;
		current = current->next;
	}
	return count;
}*/

//Count no of nodes recursively

int getCount(struct node *head)
{
	if(head == NULL)
		return 0;
	return 1 + getCount(head->next);
}
		








/* ----------------------------end---------------------------------*/



//Main driver function
int main()
{
	//Start with empty list
	struct node *head = NULL;
	
	push(&head,1);
	push(&head,3);
	push(&head,1);
	push(&head,2);
	push(&head,1);
	
	//Count the no. of nodes
	printf("Node count is %d\n",getCount(head));
	return 0;
}

