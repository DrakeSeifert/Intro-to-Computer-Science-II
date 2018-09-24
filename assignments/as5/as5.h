/************************************************************************************
 * Program: as5.c
 * Author: Drake Seifert
 * Date: 6/5/15
 * Description: Linked list sorting in C
 * Input: int values for the linked lists
 * Output: your list in ascending or descending order
 * **********************************************************************************/

struct node {
	int val;
	struct node *next;	
};

int length(struct node *);
void print(struct node *, int);

struct node * push(struct node **, int);
struct node * append(struct node **, struct node **, int);

struct node * clear(struct node *);
struct node * remove_node(struct node *, int);
struct node * sort_ascending(struct node *);
struct node * sort_descending(struct node *);
struct node * insert_middle(struct node *, int, int);
