//this code is taken from https://www.geeksforgeeks.org/delete-a-linked-list-node-at-a-given-position/

#include<stdio.h>
#include<stdlib.h>

//A linked list node
struct node
{
	int data;
	struct node *next;
};

/* Given a reference to head of a list
and an int,inserts a new node on the front of the list*/

void push(struct node **head_ref,int data)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

/* Give a reference of the head of a list,deletes the
node at the given position*/
void deleteNode(struct node **head_ref,int position)
{
	if(*head_ref == NULL)
	return;
	
	struct node *temp = *head_ref;
	
	if(position == 0)
	{
		*head_ref = temp->next;
		free(temp);
		return;
	}
	
	//Find previous node of the node to be deleted
	for(int i = 0;temp!=NULL && i< position-1;i++)
		temp = temp->next;  		
		
	//If position is more than the number of nodes
	if(temp==NULL || temp->next == NULL)
		return;
	
	//Node temp->next is the node to be deleted
	//Store pointer to the next of node to be deleted
	struct node *next = temp->next->next;
	
	//Free the node fron the linked list
	free(temp->next);
	temp->next = next;
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

//Main driver function
int main()
{
	//Start with empty list
	struct node *head = NULL;
	  push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
    push(&head, 8);
 
    puts("Created Linked List: ");
    printList(head);
    deleteNode(&head, 4);
    puts("\nLinked List after Deletion at position 4: ");
    printList(head);
    return 0;
}

