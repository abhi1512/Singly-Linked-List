/*
 * singly_linked_list.h
 *
 *  Created on: 10-Mar-2020
 *      Author: abhikhapre
 */

#ifndef SINGLY_LINKED_LIST_H_
#define SINGLY_LINKED_LIST_H_

#define DUMMY_LIST_SIZE_MAX 10

typedef enum{
	CREATE_DUMMY_LIST,
	INSERT_IN_BEGINNING,
	INSERT_IN_END,
	REMOVE_BY_VALUE,
	REMOVE_BY_INDEX,
	REVERSE_LIST,
	BUBBLE_SORT_LIST,
	SWAP_NODES_BY_DATA,
	CYCLIC_TEST,
	EXIT
}function_t;

struct _list{
	int data;
	struct _list *next;
};

typedef struct _list list;

void createDummyList(int size, list **head);
void insertInBeginning(list **head);
void insertInEnd(list **head);
void removeByValue(list **head);
void removeByIndex(list ** head);
void reverseList(list **head);
void bubbleSortList(list *head);
void swapNodesByData(list *head);
void cyclicListCheck(list *head);
void swapNodeData(list *A, list *B);
void printList(list *head);

#endif /* SINGLY_LINKED_LIST_H_ */
