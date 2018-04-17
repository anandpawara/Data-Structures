/*This code is taken from
https://www.geeksforgeeks.org/generic-linked-list-in-c-2/
*/
#include<stdio.h>
#include<stdlib.h>

//A linked list node
struct node
{
	void *data;
	struct node *next;
};

/*Function to add a node at the beginning of linked list.
This function expects a pointer to the data to be added 
and size of the data type
*/

void push(struct node** head_ref,void *new_data,size_t data_size)
{
	struct node* new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = malloc(data_size);
	new_node->next = (*head_ref);
	
	//Copy contents of new_data to newly allocated memory
	//Assumption char takes 1 byte
	int i;
	for(i = 0;i<data_size;i++)
		*(char *)(new_node->data + i) = *(char *)(new_data +i);
		
	(*head_ref) = new_node;
}
/*Funtion to print nodes in a given linked list.
fpitr is used to accesss the function to be used for printing current node data
Note that different data types need different specifier in printf()
*/

void printList(struct node* node, void (*fptr)(void *))
{
	while(node != NULL)
	{
		(*fptr)(node->data);
		node = node->next;
	}
}

//Function to print an integer
void printInt(void *n)
{
	printf(" %d",*(int *)n);
}

//Function to print a float
void printFloat(void *f)
{
	printf(" %f",*(float *)f);
}

//Driver program to test above function
int main()
{
	struct node *start = NULL;
	//Create and print an int linked list 
	unsigned int_size = sizeof(int);
	int arr[] = {10,20,30,40,50},i;
	for(i = 4;i >=0;i--)
		push(&start,&arr[i],int_size);
	printf("Created integer linked list is\n");
	printList(start,printInt);
	
	//Create and print a float linked list
	unsigned float_size = sizeof(float);
	start = NULL;
	float arr2[] = {10.1,20.2,30.3,40.4,50.5};
	for(i = 4;i >= 0;i--)
		push(&start ,&arr2[i],float_size);
	printf("\n\nCreated float linked list is\n");
	printList(start,printFloat);
	
	return 0;
}
