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

//Function to delete the entire linked list

void deleteList(struct node **head_ref)
{
	struct node *current = *head_ref;
	struct node *next;
	while(current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head_ref = NULL;
}



/* ----------------------------end---------------------------------*/



//Main driver function
int main()
{
	//Start with empty list
	struct node *head = NULL;
	push(&head, 1);
	push(&head, 4);
	push(&head, 1);
	push(&head, 12);
	push(&head, 1);
 	printf("\nDeleting linked list");
 	deleteList(&head);
 	printf("\nLinked list is deleted");
	return 0;
}

