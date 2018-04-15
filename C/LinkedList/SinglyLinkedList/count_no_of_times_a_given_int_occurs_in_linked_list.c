/*this code is taken from 
https://www.geeksforgeeks.org/write-a-function-that-counts-the-number-of-times-a-given-int-occurs-in-a-linked-list/
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

//initializing global variable for recursion
int frequency = 0;
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
Method 1-Witout Recursion
Algorithm:
1.Initialize count as zero
2.Loop through each element of linked list
	a)if element data is equal to the passed number then
	  increment the count
3.Return count
*/

//Counts the no. of occurences of a node

/*int count(struct node *head,int data)
{
	struct node *current = head;
	int count = 0;
	while(current != NULL)
	{
		if(current->data == data)
			count++;
		current = current->next;
	}
	return count;
}
*/

/*Method 2:
Algorith:

1.Exit condition:
	a.First condition check if head is NULL
	b.return return frequency
2.if head->data == data
	increase frequency by one
	pass remaining linked list in count(head->next,key)
*/

//counts no of occurence of given node in linked list
int count(struct node *head,int data)
{
	//exit condition
	if(head == NULL)
		return frequency;
	
	//check for match
	if(head->data == data)
		frequency++;
	
	//Recursively call count and pass remaining linked list to function
	count(head->next,data);
}


/* ----------------------------end---------------------------------*/



//Main driver function
int main()
{
	//Start with empty list
	struct node *head = NULL;
	push(&head, 1);
	push(&head, 3);
	push(&head, 1);
	push(&head, 2);
	push(&head, 1);
	printList(head);
 	printf("\n");
 	printf("count of 1 is %d\n",count(head,1));
 	return 0;

}

