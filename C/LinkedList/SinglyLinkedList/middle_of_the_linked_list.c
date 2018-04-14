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
/* In first method mode the linked list using two pointer.Move one pointer 
by one and other pointer by two.When last pointer reaches end first pointer will
reach middle
*/
void printMiddle(struct node *head)
{
	struct node *slow_ptr = head;
	struct node *fast_ptr = head;
	
	if(head != NULL)
	{
		while(fast_ptr != NULL && fast_ptr->next != NULL)
		{
			fast_ptr = fast_ptr->next->next;
			slow_ptr = slow_ptr->next;
		}
		printf("The middle element is [%d]\n\n",slow_ptr->data);
	}
}



/* ----------------------------end---------------------------------*/



//Main driver function
int main()
{
	//Start with empty list
	struct node *head = NULL;
	int i;

 	   for (i=5; i>0; i--)
 	   {
 	       push(&head, i);
 	       printList(head);
 	       printMiddle(head);
 	   }
 	
 	printf("\n");
	return 0;
}

