/*
 * main.c
 *
 *  Created on: 10-Mar-2020
 *      Author: abhikhapre
 */

#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_list.h"

int main(void)
{
	function_t choice;

	list *head = NULL;
	int dummyListSize = 0;

	do
	{
		printf("\n\nEnter your choice: \n");
		printf("0. CREATE_DUMMY_LIST\n");
		printf("1. INSERT_IN_BEGINNING\n");
		printf("2. INSERT_IN_END\n");
		printf("3. REMOVE_BY_VALUE\n");
		printf("4. REMOVE_BY_INDEX\n");
		printf("5. REVERSE_LIST\n");
		printf("6. BUBBLE_SORT_LIST\n");
		printf("7. SWAP_NODES_BY_DATA\n");
		printf("8. CYCLIC_TEST\n");
		printf("9. EXIT\n");

		scanf("%d",&choice);

		switch(choice)
		{
			case  CREATE_DUMMY_LIST:
				/* Used to create dummy list with random numbers from 0 to 7
				 * Maximum size of dummy list should not be greater than 10 */

				printf("Enter the size of Dummy list : \n");
				scanf("%d",&dummyListSize);
				createDummyList(dummyListSize,&head);
				printList(head);
				break;

			case INSERT_IN_BEGINNING:
				/* Used to insert an element in the beginning of list */

				insertInBeginning(&head);
				printList(head);
				break;

			case INSERT_IN_END:
				/* Used to insert an element in the end of the list */

				insertInEnd(&head);
				printList(head);
				break;

			case REMOVE_BY_VALUE:
				/* Used to remove node data by value */

				removeByValue(&head);
				printList(head);
				break;

			case REMOVE_BY_INDEX:
				/* Used to remove node data by index */

				removeByIndex(&head);
				printList(head);
				break;

			case REVERSE_LIST:
				/* Used to reverse the linked list */

				reverseList(&head);
				printList(head);
				break;

			case BUBBLE_SORT_LIST:
				/* Used to bubble sort list in ascending order */

				bubbleSortList(head);
				printList(head);
				break;

			case SWAP_NODES_BY_DATA:
				/* Used to swap data amongst 2 nodes */

				swapNodesByData(head);
				printList(head);
				break;

			case CYCLIC_TEST:
				/* Used to check if the given list is cyclic or not */

				cyclicListCheck(head);
				printList(head);
				break;

			case EXIT:
				/* Press 10 to exit */
				break;

			default:
				break;
		}
	} while(choice < EXIT);

	return 0;
}


