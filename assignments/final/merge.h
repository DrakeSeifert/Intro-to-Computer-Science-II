#ifndef MERGE_H
#define MERGE_H

struct node {
	int info;
	struct node *next;
};
void divideList(struct node *, struct node **);
struct node * mergeList(struct node *,struct node *);
void recMergeSort(struct node **);
void mergeSort(struct node **, struct node **);
//int length(struct node *);
//struct node * push(struct node **, int);
//void print(struct node *, int);

#endif
