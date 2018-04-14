/*this code is taken from 
https://www.geeksforgeeks.org/search-an-element-in-a-linked-list-iterative-and-recursive/
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

//Check whether the value x is present in linked list 
//Iterative code for searching
/*bool search(struct node *head,int x)
{
	struct node *current = head;
	while(current)
	{
		if(current->data == x)
			return true;
		current = current->next;
	}
	return false;
}
*/

//Recursive code for searching
bool search(struct node *head,int x)
{
	//Base case
	if(head == NULL)
		return false;
	//If key is present in current node, return true
	if(head->data == x)
		return true;
	//Recur for remaining list
	return search(head->next,x);
}







/* ----------------------------end---------------------------------*/



//Main driver function
int main()
{
	//Start with empty list
	struct node *head = NULL;
	push(&head, 10);
	push(&head, 30);
	push(&head, 11);
	push(&head, 21);
	push(&head, 14);
   	search(head,21)?printf("Yes\n") : printf("No\n");
   	return 0;
}

