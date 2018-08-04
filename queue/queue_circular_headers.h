#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
	int data;
	struct node *link;
};

struct queue {
	struct node *head;
	struct node *tail;
	/* Optional */
	struct node *last;
};
int createQueue(struct queue *q, unsigned int len);
void display(struct queue *q);
