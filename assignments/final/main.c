#include <stdlib.h>
#include <stdio.h>
#include "./merge.c"

int length(struct node*);
struct node * push(struct node **, int);
void print(struct node *, int);

int length(struct node* head) {
	struct node* current = head;
	int count = 0;

	while (current != NULL) {
		count++;
		current = current->next;
	}
	return count;
}

struct node * push(struct node **headRef, int info) {
	struct node* newNode = malloc(sizeof(struct node));

	newNode->info = info;
	newNode->next = *headRef;

	return newNode;
}

void print(struct node* head, int length) {
	struct node *current = head;
	int i;

	for (i = 0; i < length; i++) {
		printf("%d ", current->info);
		current = current->next;
	}
}

int main() {
	char ans;
	int num;
	struct node *head = NULL;
	struct node *foo = NULL;

	do {
		printf("Enter a number: ");
		scanf("%d", &num);

		head = push(&head, num);

		printf("Do you want another num? (y or n): ");
		scanf("%1s", &ans);
	} while (ans == 'y');

	printf("\nContents before mergeSort: ");
	print(head, length(head));
	printf("\n");

	mergeSort(&head, &foo);

	printf("\nContents after mergeSort:  ");
	print(head, length(head));
	printf("\n\n");

	return 0;
}
