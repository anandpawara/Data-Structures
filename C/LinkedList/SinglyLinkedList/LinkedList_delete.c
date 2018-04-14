//A working C code to delete a node from linked list

#include<stdio.h>
#include<stdlib.h>

//A linked list node
struct node
{
	int data;
	struct node *next;
};

/*Given a reference (pointer to pointer ) to the head of a list 
and an int, inserts a new node on the front of the list*/

void push(struct node **head_ref,int data)
{
	struct node* new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}
/*Given reference (pointer to pointer)to the head of a list 
and a key, deletes the first occurence of key in linked list*/

void delete_node(struct node **head_ref,int key)
{
	struct node *temp = *head_ref,*prev;
	
	if(temp != NULL && temp->data==key)
	{
		*head_ref = temp->next;
		free(temp);
		return;
	}
	while(temp !=NULL && temp->data !=key)
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL)
		return;
	
	prev->next = temp->next;
	
	free(temp);
}

//This function prints contents of linked list starting from given linked list
void printList(struct node *node)
{
	while(node != NULL)
	{
		printf("%d\t",node->data);
		node = node->next;
	}
}

int main()
{
	struct node *head = NULL;
	push(&head,7);
	push(&head,1);
	push(&head,3);
	push(&head,2);
	
	printf("\nCreated Linked list:\n");
	printList(head);
	
	delete_node(&head,1);
	printf("\nLinked List after deletion\n");
	printList(head);
	printf("\n");
	return 0;
}






