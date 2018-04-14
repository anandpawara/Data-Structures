/*this code is taken from 
https://www.geeksforgeeks.org/swap-nodes-in-a-linked-list-without-swapping-data/
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

/*Function to swap nodes x and y in linked list by 
changing links*/
void swapNodes(struct node **head_ref,int x,int y)
{
	//Nothing to do if x and y are same
	if(x == y)
		return;
	
	//Search for x (keep track of prevX and CurrX
	struct node *prevX = NULL, *currX = *head_ref;
	while(currX && currX->data !=x)
	{
		prevX = currX;
		currX = currX->next;
	}
	
	//Search for y(keep track of prevY and currY
	struct node *prevY = NULL, *currY = *head_ref;
	while(currY && currY->data !=y)
	{
		prevY = currY;
		currY = currY->next;
	}
	//If either x or y is not present,do nothing
	if(currX == NULL || currY == NULL)
		return;
	//If x is not head of linked list
	if(prevX != NULL)
		prevX->next = currY;
	else //Else make y as new head
		*head_ref = currY;
		
	//If y is not head of linked list
	if(prevY !=NULL)
		prevY->next = currX;
	else //Else make x as new head
		*head_ref = currX;
	
	//Swap next pointers
	struct node *temp = currY->next;
	currY->next = currX->next;
	currX->next = temp;
}

	








/* ----------------------------end---------------------------------*/



//Main driver function
int main()
{
	//Start with empty list
	struct node *head = NULL;
	  push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
	push(&head, 2);
	push(&head, 1);
    puts("\nLinked list before calling swapNode()");
    printList(head);
    swapNodes(&head,1,7);
    puts("\nLinked List after calling swapNodes()");
    printList(head);	
    return 0;
}

