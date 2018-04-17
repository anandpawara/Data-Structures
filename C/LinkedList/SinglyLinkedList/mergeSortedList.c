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
	while(node->next != NULL)
	{
		printf("%d-> ",node->data);
		node = node->next;
	}
	printf("%d\n",node->data);
}

/* ----------------------Start code from here ------------------------*/

/*
Method 1:Using Dummy Nodes)
The strategy here uses a temporary dummy node as the start of the result list.
Tail always points to last node in the result list, so appending new nodes is easy .
The dummy node gives tail something to point initially when the result is empty.
This dummy node is efficient,since it is only temporary, and it is allocated in the stact .The loop  proceeds ,removing one node either from 'a' or 'b', and adding it to tail.When we are done, the result is dummy.next

*/
//pull off the front node of the source and put it in destination	
void moveNode(struct node **destRef,struct node **sourceRef);

/*Takes two list sorted in increasing order, and splices their nodes together to make one big sorted list which is returned*/

/*struct node *sortedMerge(struct node *a,struct node *b)
{
	//A dummy first node to hang the result
	struct node dummy;
	
	struct node *tail = &dummy;
	//so tail->next is the place to add new nodes to the result
	dummy.next = NULL;
	while(1)
	{
		if(a == NULL)
		{
			//if either list run out ,use the other list
			tail->next = b;
			break;
		}
		else if(b == NULL)
		{
			tail->next = a;
			break;
		}
		if(a->data <= b->data)
			moveNode(&(tail->next),&a);
		else
			moveNode(&(tail->next),&b);
		tail = tail->next;
	}
	return dummy.next;
}
*/

//Method 2:Using local reference
/*
This solution is structurally very similar to the above, but it avoids using dummy node .Instead it uses struct node** pointer ,lastPtrRef that always points to the last pointer of the result list.This solve the same case that the dummy node did-dealing with the result when it is empty.If you are trying to build up a list at its tail,either the dummy node or the struct node** reference strategy can be used
*/

/*struct node *sortedMerge(struct node* a,struct node* b)
{
	struct node* result = NULL;
	//pointer to the result pointer
	struct node** lastPtrRef = &result;
	
	while(1)
	{
		if(a == NULL)
		{
			*lastPtrRef = b;
			break;
		}
		else if(b == NULL)
		{
			*lastPtrRef = a;
			break;
		}
		if(a->data <= b->data)
			moveNode(lastPtrRef,&a);
		else
			moveNode(lastPtrRef,&b);
			
		lastPtrRef = &((*lastPtrRef)->next);
	}
	return result;
}
*/

//Method 3:Using Recursion
/*Merge is one of those nice recursive problems where the recursive code is much cleaner that iterative code.You probably would'nt want to use the recursive version for production code however ,because it will use stack space which is proportional to the length of the list
*/

struct node* sortedMerge(struct node* a,struct node* b)
{
	//Base case
	if(a == NULL)
		return b;
	else if(b == NULL)
		return a;
		
	//Pick either a or b,and recur
	if(a->data <= b->data)
	{
		result = a;
		result->next = sortedMerge(a->next,b);
	}
	else
	{
		result = b;
		result->next = sortedMerge(b->next,a);
	}
	return result;
}

void moveNode(struct node **destRef,struct node **sourceRef)
{
	//the front source node
	struct node *newNode = *sourceRef;
	assert(newNode != NULL);
	//Advance the source pointer
	*sourceRef = newNode->next;
	
	//Link the old dest off the new node
	newNode->next = *destRef;
	
	//Move dest to point to the new node
	*destRef = newNode;
}




/* ----------------------------end---------------------------------*/



//Main driver function
int main()
{
	//Start with empty list
	struct node *res = NULL;
	struct node *a = NULL;
	struct node *b = NULL;
	
	
	push(&a,15);
	push(&a,10);
	push(&a,5);
	
	push(&b,20);
	push(&b,3);
	push(&b,2);
	//Removes duplicates from the linked list
	printList(a);
	printList(b);
	res = sortedMerge(a,b);
 	
 	printf("\nMerge Linked list is:\n");
 	printList(res);
	return 0;
}

