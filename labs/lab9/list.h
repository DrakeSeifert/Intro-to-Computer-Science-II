struct node {
	int val;
	struct node *next;
};

int length(struct node *);
void push(struct node **, int);
void append(struct node **, int);
void print(struct node *, int);
