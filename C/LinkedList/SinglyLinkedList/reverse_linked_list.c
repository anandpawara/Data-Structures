/*this code is taken from 
https://www.geeksforgeeks.org/reverse-a-linked-list/
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
//Reverse the linked list
/*Input:Head of following linked list
	1->2->3->4->NULL
Output:	Linked list should be changed to,
	NULL<-1<-2<-3<-4
*/
/*Method 1:Iterative Method
1.Initialize three pointers prev as NULL,curr as head and next NULL
2.Iterate through the linked list,in loop,do following
	a.Before changing next of current,store next node
	//This is where actual reverse happens
	b.curr->next = prev
	//Move prev and curr one step forward
	prev = curr
	curr = next
*/
//Function to reverse the linked list
void reverse(struct node **head_ref)
{
	struct node *prev = NULL;
	struct node *curr = *head_ref;
	struct node *next = NULL;
	//check conditions
	//If empty list passed then return 
	if(curr == NULL || curr->next == NULL)//If linked list is null or is length of 1 node
		return;
	//If linked list is length more than two
	while(curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*head_ref = prev;
}

/*Method 2:Using recursion
Algorithm:
1.Divide the list in two parts -first node and rest of the linked list
2.Call reverse for rest of the linked list
3.Link rest to first
4.Fix head pointer
*/

void recursiveReverse(struct node **head_ref)
{
	struct node *first;
	struct node *rest;
	//Empty list
	if(*head_ref == NULL)
		return;
	//Suppose first = {1,2,3},rest = {2,3}
	first = *head_ref;
	rest = first->next;
	//If list has one node
	if(rest == NULL)
		return;
	//Reverse the rest list and put the first element at the end
	recursiveReverse(&rest);
	first->next->next = first;
	
	first->next = NULL;
	*head_ref = rest;
}
//Time Complexity:O(n)
//Space Complexity:O(1)

	


/* ----------------------------end---------------------------------*/



//Main driver function
int main()
{
	//Start with empty list
	struct node *head = NULL;
	push(&head,20);
	push(&head,4);
	push(&head,15);
	push(&head,85);
 	printf("\nGiven linked list\n");
 	printList(head);
//	reverse(&head);
	recursiveReverse(&head);
	printf("Reversed linked list\n");
	printList(head); 	
	return 0;
}

