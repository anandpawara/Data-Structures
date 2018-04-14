/*this code is taken from 
*/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

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
/*
1.Initialize count = 0
2.Loop through the link list
	a.if count equal to the passed index return current
	b.Increment count
	c.change current to point to next of the current
*/
int getNth(struct node *head,int index)
{
	int count = 0;
	struct node *current = head;
	while(current)
	{
		if(count == index)
			return(current->data);
		count++;
		current = current->next;
	}
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
	
	printf("Element at index 3 is %d\n",getNth(head,3)); 
	return 0;
}

