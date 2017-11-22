#include <stdio.h>
#include <stdlib.h>

#define isEmpty(_top)	isFull(_top)
#define isFull(_top)	(!!!(_top))

struct node {
	int data;
	struct node *next;
};

int peek(struct node *);
struct node* push(struct node *);
int pop(struct node **);
void list(struct node *);
