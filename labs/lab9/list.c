#include <stdio.h>
#include <stdlib.h>
#include "./list.h"

int length(struct node* head) {
	struct node* current = head;
	int count = 0;

	while (current != NULL) {
		count++;
		current = current->next;
	}

	return count;
}

void push(struct node **headRef, int val) {
	struct node* newNode = malloc(sizeof(struct node));

	newNode->val = val;
	newNode->next = *headRef;

	*headRef = newNode;
}

void append(struct node ** headRef, int val) {
	struct node* current = *headRef;
	struct node* newNode;

	newNode = malloc(sizeof(struct node));
	newNode->val = val;
	newNode->next = NULL;

	if (current == NULL) {
		*headRef = newNode;
	}
	else {
		while (current->next != NULL) {
			current = current->next;
		}
	current->next = newNode;
	}
}

void print(struct node* head, int length) {
	struct node* current = head;
	int i;

	for (i = 0; i < length; i++) {
		printf("%d ", current->val);
		current = current->next;
	}
}

int main() {
	char ans;
	int num;
	struct node *head = NULL;

	do {
		printf("Enter a number: ");
		scanf("%d", &num);

		push(&head, num); //changes push to append
		//append(&head, num); //changes push to append

		printf("Do you want another num (y or n): ");
		scanf("%1s", &ans);
	} while (ans == 'y');
	
	printf("Length: %d\n", length(head));

	printf("Contents: ");
	print(head, length(head));
	
	return 0;
}
