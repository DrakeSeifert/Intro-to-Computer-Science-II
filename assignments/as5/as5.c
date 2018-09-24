/************************************************************************************
 * Program: as5.c
 * Author: Drake Seifert
 * Date: 6/5/15
 * Description: Linked list sorting in C
 * Input: int values for the linked lists
 * Output: your list in ascending or descending order
 * **********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "./as5.h"

/************************************************************************************
 * Function: length
 * Description: finds length of linked list
 * Parameters: struct node*
 * Pre-Conditions: linked list entered
 * Post-Conditions: returns length as an int
 * **********************************************************************************/

int length(struct node* head) {
	struct node* current = head;
	int count = 0;

	while (current != NULL) {
		count++;
		current = current->next;
	}
	return count;
}

/************************************************************************************
 * Function: push
 * Description: pushes value to front of linked list
 * Parameters: struct node**, int
 * Pre-Conditions: value entered for linked list
 * Post-Conditions: pushes value to front of linked list
 * **********************************************************************************/

struct node * push(struct node **headRef, int val) {
	struct node* newNode = malloc(sizeof(struct node));

	newNode->val = val;
	newNode->next = *headRef;

	return newNode;
}

/************************************************************************************
 * Function: append
 * Description: puts value at end of linked list, points tail to last node
 * Parameters: struct node **, struct node **, int
 * Pre-Conditions: value entered for linked list
 * Post-Conditions: puts value at end of linke list, points tail to last node
 * **********************************************************************************/

struct node * append(struct node **headRef, struct node **tail_ptr, int val) {
	struct node* current = *headRef;
	struct node* tail = *tail_ptr;
	struct node* newNode;

	newNode = malloc(sizeof(struct node));
	newNode->val = val;
	newNode->next = NULL;
	tail = newNode;

	if (current == NULL) {
		*headRef = newNode;
	}
	else {
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = tail;
	}
	return *headRef;
}

/************************************************************************************
 * Function: print
 * Description: prints linked list
 * Parameters: struct node*, int
 * Pre-Conditions: linked list created
 * Post-Conditions: prints linked list values in order with a space inbetween
 * **********************************************************************************/

void print(struct node *head, int length) {
	struct node *current = head;
	int i;
	for (i = 0; i < length; i++) {
		printf("%d ", current->val);
		current = current->next;
	}
}

/************************************************************************************
 * Function: clear
 * Description: clears linked list
 * Parameters: struct node*
 * Pre-Conditions: user has finished using initial linked list
 * Post-Conditions: sets all linked list values to NULL
 * **********************************************************************************/

struct node * clear(struct node *head) {
	struct node *current = head;
	struct node *temp = head;

	while ((current = head) != NULL) {
		head = head->next;
		free(current);
	}
}

/************************************************************************************
 * Function: remove_node
 * Description: removes node from list
 * Parameters: struct node*, int
 * Pre-Conditions: user chose to remove node
 * Post-Conditions: removes node of value entered
 * **********************************************************************************/

struct node * remove_node(struct node *head, int a) {
	struct node *current = head;
	struct node *temp1 = NULL;
	struct node *temp2 = NULL;

	while (current->next != NULL) {
		if (current->next->val != a)
			current = current->next;
		else {
			temp1 = current->next->next;
			temp2 = current;
			current = current->next;
			current = NULL;
			temp2->next = temp1;
			return;
		}
	}

	printf("\nError! Invalid entry :(\n");
}

/************************************************************************************
 * Function: sort_ascending
 * Description: sorts linked list in ascending order
 * Parameters: struct node*
 * Pre-Conditions: user chose ascending order
 * Post-Conditions: sorts linked list in ascending order
 * **********************************************************************************/

struct node * sort_ascending(struct node *head) {
	int x, i, temp;
	struct node *current = head;
	struct node *temp2 = NULL;
	
	if (current == NULL)
		return;

	do {
		x = 0;
		current = head;
		while (current->next != temp2) {
			if (current->val > current->next->val) {
				temp = current->val;
				current->val = current->next->val;
				current->next->val = temp;
				x = 1;
			}
			current = current->next;
		}
		temp2 = current;
	} while (x);
}

/************************************************************************************
 * Function: sort_descending
 * Description: sorts linked list in descending order
 * Parameters: struct node*
 * Pre-Conditions: user chose descending order
 * Post-Conditions: sorts linked list in descending order
 * **********************************************************************************/

struct node * sort_descending(struct node *head) {
	int x, i, temp;
	struct node *current = head;
	struct node *check = NULL;
	
	if (current == NULL)
		return;

	do {
		x = 0;
		current = head;
		while (current->next != check) {
			if (current->val < current->next->val) {
				temp = current->val;
				current->val = current->next->val;
				current->next->val = temp;
				x = 1;
			}
			current = current->next;
		}
		check = current;
	} while (x);
}

/************************************************************************************
 * Function: insert_middle
 * Description: inserts value into middle of linked list
 * Parameters: struct node*, int, int
 * Pre-Conditions: user chose to enter node into the middle
 * Post-Conditions: inserts value into middle of linked list
 * **********************************************************************************/

struct node * insert_middle(struct node *head, int a, int b) {
	struct node *current = head;
	struct node* newNode = malloc(sizeof(struct node));

	while (current != NULL) {
		if (current->val != a)
			current = current->next;
		else {
			newNode->val = b;
			newNode->next = current->next;
			current->next = newNode;
			return;
		}
	}
	printf("\nError! Node value entered does not exist :(\n");
}

int main() {
	char ans[2];
	int num, choice;
	struct node *head = NULL;
	struct node *tail = NULL;

	do {
		do {
			printf("\nEnter a number: ");
			scanf("%d", &num);
			//head = push(&head, num);         //push function
			head = append(&head, &tail, num);  //append function

			printf("Do you want another num (y or n): ");
			scanf("%1s", ans);
		} while (ans[0] == 'y');
		
		//sorting functions:

		printf("\nSort ascending or descending (a or d)?: ");
		scanf("%1s", ans);
		if (ans[0] == 'a')
			sort_ascending(head);
		else if (ans[0] == 'd')
			sort_descending(head);

		printf("\nYour linked list is: ");
		print(head, length(head));

		//insert_middle function:

		printf("\n\nWould you like to insert a node into the middle (y or n)?: ");
		scanf("%1s", ans);
		if (ans[0] == 'y') {
			printf("\nWhat is your new value?: ");
			scanf("%d", &num);
			printf("\nWhat value would you like to place it after? ");
			scanf("%d", &choice);

			insert_middle(head, choice, num);

			printf("\nYour new linked list is: ");
			print(head, length(head));
			printf("\n");
		}
		
		//remove_node function:

		printf("\nWould you like to remove a node from the middle (y or n)?: ");
		scanf("%1s", ans);
		if (ans[0] == 'y') {
			printf("\nWhat node would you like to remove?: ");
			scanf("%d", &num);

			remove_node(head, num);

			printf("\nYour new linked list is: ");
			print(head, length(head));
			printf("\n");
		}
		
		//clear function:
	
		printf("\nDo you want to do this again (y or n)? ");
		scanf("%1s", ans);
		
		head = clear(head);

	} while (ans[0] == 'y');

	printf("\nGoodbye!\n\n");
	
	return 0;
}
