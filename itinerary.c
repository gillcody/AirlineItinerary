#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "itinerary.h"

/*Dynamically allocates a new node with the airport code data and returns a pointer to that new node.*/
Destination *create( char *code )
{
	Destination *d = (Destination*)malloc(sizeof(Destination));

	strcpy(d->code, code);
	d->next = NULL;

	return d;
}

/*This function enters a new node, created by the create() function, into the linked list. 
Normally, the function will add the new node after the node that has an airport code that matches key. 
However, there are two exceptions to this rule: 
1) if the key is equal to the special code ZZZ, add the new node to the front
2) if the key was not found in the list, add the new node to the end of the linked list. 
It should also handle insertion should the linked list be empty. It returns the head of the linked list.*/
Destination *insertAfter( Destination *head, Destination *node, char *key )
{
	Destination *ptr;
	Destination *previous = NULL;
	Destination *n = (Destination *)malloc(sizeof(Destination));

	if (strcmp("ZZZ", key) == 0) 
	{
		strcpy(key, ptr->code);
		n->next = head;
	}

	for (ptr = head; ptr != NULL; ptr = ptr->next)
	{
		if(strcmp(ptr->code, node->code) > 0)
		{
			node->next = ptr;

			if(previous != NULL)
			{
				previous->next = node;
				return head;
			}
			else
			{
				return node;
			}
		}
		previous = ptr;
	}
	previous->next = node;
	return head;

}

/*This function traverses the linked list to find a node that has an airport code that matches key and returns it. 
If it did not find this airport code, it returns NULL.*/
Destination *find( Destination *head, char *key )
{
	Destination *ptr;

	if (head == NULL)
	{
		return NULL;
	}
	
	for (ptr = head; ptr != NULL; ptr = ptr->next)
	{
		if(strcmp(ptr->code, key) == 0)
		{
			return ptr;
		}
	}
}

/*This function traverses the linked list to find a node that has an airport that matches key and removes it from the linked list. 
If it is not found, nothing happens to the linked list. It returns the head of the linked list.*/
Destination *removeNode( Destination *head, char *key )
{
	Destination *ptr;
	Destination *prev;
	Destination *temp;

	if (head == NULL)
	{
		return NULL;
	}

	for (ptr = head; ptr != NULL; ptr = ptr->next)
	{
		if(strcmp(ptr->code, key) == 0)
		{
			temp = ptr;
			
			if (strcmp(ptr->code, head->code) == 0)
			{
				head = head->next;
			}
			else
			{
				prev->next =  ptr->next;
			}

			free(temp);
			return head;
		}

		prev = ptr;
	}

	return head;
}

/*Prints out each destination (airport code) in the itinerary on a separate line. */
void print( Destination *head )
{
	Destination *d;
	
	if (head == NULL)
	{
		printf("No destinations.\n");
	}
	else
	{
		for (d = head; d != NULL; d = d->next)
		{
			printf("%s\n", d->code);
		}
	}
}

/*Prints out the itinerary showing each segment pair between airports on a different line.*/
void printItinerary( Destination *head )
{
	Destination *ptr;

	for (ptr = head; ptr->next != NULL; ptr = ptr->next)
	{
		printf("%s - %s\n", ptr->code, ptr->next->code);
	}
}

/*Destructor for the linked list. It goes through the entire linked list and free() up each nodes and returns NULL at the end.*/
Destination *destruct( Destination *r)
{
	if (r == NULL)
	{
		return NULL;
	}

	destruct(r->next);
	
	free(r);
	return NULL;
}
