#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct tnode {
	struct tnode *left;
	int data;
	struct tnode *right;
};

struct qnode {
	struct tnode *t;
	struct qnode *link;
};

struct queue {
	struct qnode *head;
	struct qnode *tail;
};

#define IsQueueEmpty(__q)	((__q)->head == (__q)->tail)
#define IsQueueFull(__q)	((__q)->head->link == (__q)->tail)


int createQueue(struct queue *q, unsigned int len);
void Enqueue(struct tnode *n, struct queue *q);
struct tnode *Dequeue(struct queue *q);
