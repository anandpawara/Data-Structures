//This code is taken from https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

//Given a reference (pointer to pointer) to the head
//of a list and an int,appends a new node at the end
void append(struct node **head_ref,int new_data)
{
	//1. allocate a node
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	
	struct node *last = *head_ref;
	//2. Put in the data
	new_node->data = new_data;
	//3. The new_node is going to be last node 
	new_node->next = NULL;
	//4. If the linked List is empty ,then make new node as head
	if(*head_ref == NULL)
	{
		*head_ref == new_node;
		return;
	}
	//5. Else traverse till the last node
	while(last->next != NULL)
		last = last->next;
	
	//6. Change the next node of last node
	last->next = new_node;
	return;
}

/* Given reference (pointer to pointer ) to the head of a list and an
int inserts a new node on the front of the list*/
void push (struct node **head_ref,int new_data)
{
	//1. allocate new node
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	//2. Put in the data
	new_node->data = new_data;
	//3. Make next of next node as head
	new_node->next = (*head_ref);
	//4 mode the head to point to the new node
	(*head_ref) = new_node;
}
void insertAfter(struct node *prev_node,int new_data)
{
	//1. Check if the given prev_node is NULL
	if(prev_node == NULL)
	{
		printf("the given previous node cannot be NULL");
		return;
	}
	//2. allocate new node
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	
	//3. Put in the data
	new_node->data = new_data;
	
	//4. Make next of new node as next of prev node
	new_node->next = prev_node->next;
	
	//5. move the next of prev node as new node
	prev_node->next = new_node;
}
	
void printList(struct node *node)
{
	while(node != NULL)
	{
		printf("%d\t",node->data);
		node = node->next;
	}
}

//Drive program to test above function
int main()
{
	struct node* head = NULL;
	append(&head,6);
	push(&head,7);
	push(&head,8);
	push(&head,9);
	insertAfter(head->next,10);
	printf("\n Created Linked List is :");
	printList(head);
	return 0;
}


