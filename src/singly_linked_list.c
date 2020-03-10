/*
 * singly_linked_list.c
 *
 *  Created on: 10-Mar-2020
 *      Author: abhikhapre
 */

#include "singly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

void createDummyList(int size, list **head)
{
	int i;

	for(i=0; i<DUMMY_LIST_SIZE_MAX && i<size; i++)
	{
		list *newNode = (list*)malloc(sizeof(list));
		newNode->data = rand()%100;
		if(head == NULL)
		{
			newNode->next = NULL;
		}
		else
		{
			newNode->next = *head;
		}
		*head = newNode;
	}

}

void printList(list *head)
{
	list *current = head;
	while(current != NULL)
	{
		printf("|%d|->",current->data);
		current = current->next;
	}
	printf("EOL");
}

void insertInBeginning(list **head)
{
	int data;
	printf("Enter the element : \n");
	scanf("%d",&data);
	list *newNode = (list*)malloc(sizeof(list));
	newNode->data = data;

	if(head == NULL)
	{
		newNode->next = NULL;
	}
	else
	{
		newNode->next = *head;
	}
	*head = newNode;
}

void insertInEnd(list **head)
{
	int data;
	list *current = *head;
	printf("Enter the element : \n");
	scanf("%d",&data);
	list *newNode = (list*)malloc(sizeof(list));
	newNode->data = data;
	if(*head == NULL)
	{
		newNode->next = NULL;
		*head = newNode;
	}
	else
	{
		while(current->next != NULL)
		{
			current = current->next;
		}
		current->next = newNode;
		newNode->next = NULL;
	}
}

void removeByValue(list **head)
{
	list *temp,*current;
	int data;
	printf("Enter the data value of node to be removed : \n");
	scanf("%d",&data);
	current = *head;
	temp = *head;

	if(*head == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		while(temp->data != data)
		{
			current = temp;
			temp = temp->next;
		}
	current->next = temp->next;
	free(temp);
	}
}

void removeByIndex(list ** head)
{
	int i=0, index;
	list *current, *temp;
	printf("Enter the index of node to be removed : \n");
	scanf("%d",&index);
	current = *head;
	temp = NULL;

	if(*head == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		while(i != index-1)
		{
			i++;
			current = current->next;
		}
		temp = current->next;
		current->next = temp->next;
		free(temp);
	}
}

void reverseList(list **head)
{
	list *current, *prev, *temp;
	current = *head;

	if(*head == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		while(current != NULL)
		{
			temp = current->next;
			current->next = prev;
			prev = current;
			current = temp;
		}
		*head = prev;
	}
}

void bubbleSortList(list *head)
{
	int listSize = 0;
	//int swapped = 0;
	list *current = NULL;
	//list *temp = NULL;

	if(head == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		current = head;
		while(current != NULL)
		{
			current = current->next;
			listSize++;
		}
		printf("List size = %d\n",listSize);
		printf("Bubble Sorted list --> \n");

		/* Brute force Algorithm */

		for(int i = 0; i<listSize-1; i++)
		{
			current = head;
			for(int j = 0; j<listSize-i-1; j++)
			{
				if(current->data > current->next->data)
				{
					swapNodeData(current, current->next);
				}
				current = current->next;
			}
		}

		/*************************/

		/* Little bit optimized solution (GeeksforGeeks) */

		/*do{

			current = head;
			swapped = 0;
			while(current->next != temp)
			{
				if(current->data > current->next->data)
				{
					swapNodeData(current, current->next);
					swapped =1;
				}
				current = current->next;
			}
		    temp = current;
		}while(swapped);*/

		/**************************************************/

	}

}

void swapNodesByData(list *head)
{
	int node1, node2;
	list *first = head;
	list *second = head;

	printf("Enter first node data: ");
	scanf("%d",&node1);
	printf("Enter second node data: ");
	scanf("%d",&node2);

	while(first != NULL && first->data != node1)
	{
		first = first->next;
	}

	while(second != NULL && second->data != node2)
	{
		second = second->next;
	}

	if(first == NULL || second == NULL)
	{
		if(first == NULL)
		{
			printf("%d is not present in list\n",node1);
		}

		if(second == NULL)
		{
			printf("%d is not present in list\n",node2);
		}
	}
	else
	{
		swapNodeData(first, second);
	}
}

void swapNodeData(list *A, list *B)
{
	A->data = A->data + B->data;
	B->data = A->data - B->data;
	A->data = A->data - B->data;
}

void cyclicListCheck(list *head)
{
	list *slow = head;
	list *fast = head;

	while(slow != NULL && fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next;
		fast = fast->next;
		if(fast == slow)
		{
			printf("List is cyclic\n");
			break;
		}
	}
	if(slow == NULL || fast == NULL)
	{
		printf("List is not cyclic\n");
	}
}


