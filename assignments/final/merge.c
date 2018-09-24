#include <stdlib.h>
#include <stdio.h>
#include "./merge.h"
#define nullptr NULL

void divideList(struct node* first1,struct node** first2)
{
   struct node* middle;
   struct node* current;
   printf("In divideList\n");

   if (first1 == nullptr) {  //list is empty
      *first2 = nullptr;
	  printf("divideList 1\n");
	}
   else if (first1->next == nullptr) {  //list has only one node
      *first2 = nullptr;
  	 printf("divideList 2\n");
	}
   else
   {
      printf("divideList else 3\n");
      middle = first1;
      current = first1->next;
      if (current != nullptr) {	 //list has more than two nodes
      	 printf("divideList else 4\n");
	 current = current->next;
	}
      while (current != nullptr)
      {
      	 printf("divideList else 5\n");
	 middle = middle->next;
	 current = current->next;
	 if (current != nullptr) {
	    current = current->next;
   	 	printf("divideList 6\n");
		}
      } //end while
      printf("divideList else 7\n");
      *first2 = middle->next;  
      middle->next = nullptr; 
   } //end else
   	printf("End divideList\n");
} //end divideList


struct node* mergeList(struct node* first1,struct node* first2)
{
   struct node *lastSmall; //pointer to the last node 
   struct node *newHead;  //pointer to the merged list

   printf("In mergeList\n");

   if (first1 == nullptr) {  //the first sublist is empty
   	printf("mergeList 1\n");
      return first2;
	}
   else if (first2 == nullptr) {  //the second sublist is empty
   	printf("mergeList 2\n");
      return first1;
	}
   else
   {
      if (first1->info < first2->info) //compare the first nodes
      {
   	printf("mergeList 3\n");
	 newHead = first1;
	 first1 = first1->next;
	 lastSmall = newHead;
      }
      else
      {
   	printf("mergeList 4\n");
	 newHead = first2;
	 first2 = first2->next;
	 lastSmall = newHead;
      }
      while (first1 != nullptr && first2 != nullptr)
      {
	 if (first1->info < first2->info)
	 {
   		printf("mergeList 5\n");
	    lastSmall->next = first1;
	    lastSmall = lastSmall->next;
	    first1 = first1->next;
	 }
	 else
	 {
   		printf("mergeList 6\n");
	    lastSmall->next = first2;
	    lastSmall = lastSmall->next;
	    first2 = first2->next;
	 }
      } //end while
      if (first1 == nullptr) { //first sublist is exhausted first
   	printf("mergeList 7\n");
	 lastSmall->next = first2;
	}
      else{	 //second sublist is exhausted first
	 lastSmall->next = first1;
   	printf("End mergeList\n");
	}
      return newHead;
   }
}//end mergeList


void recMergeSort(struct node** head)
{
   struct node* otherHead;

   printf("In recMergeSort\n");

   if (*head != nullptr)  //if the list is not empty
      if ((*head)->next != nullptr)  //if list has more than one
      {
	 divideList(*head, &otherHead);
	 recMergeSort(head);
	 recMergeSort(&otherHead);
	 *head = mergeList(*head, otherHead);
      }
} //end recMergeSort


void mergeSort(struct node **first, struct node **last)
{
   printf("\nIn mergeSort\n");
   recMergeSort(first);

   if (*first == nullptr)
      *last = nullptr;
   else
   {
      *last = *first;
      while ((*last)->next != nullptr)
	 *last = (*last)->next;
   }
} //end mergeSort

/*int length(struct node* head) {
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
}*/
