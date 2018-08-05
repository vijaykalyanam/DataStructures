#include "queue_circular_headers.h"

int createQueue(struct queue *q, unsigned int len)
{
	struct qnode *last = NULL;
	struct qnode *tmp;
	int i;

	if (q == NULL)
		return -1;
	for(i=0; i<len; i++) {
		tmp = calloc(1, sizeof(struct qnode));
		if(last == NULL) {
			last = tmp; 
			last->link = last;
		} else {
			tmp->link = last->link;
			last->link = tmp;
		}
	}
	q->head = q->tail = last;
	return 0;
}

void Enqueue(struct tnode *n, struct queue *q)
{

	if (IsQueueFull(q)) { 
		printf("Queue is Full. Please Increase Size\n");
		return;
	}

	q->head->t = n;
	q->head = q->head->link;
}

struct tnode *Dequeue(struct queue *q)
{
	struct tnode *tmp;

	if (!IsQueueEmpty(q)) {
		tmp = q->tail->t;
		q->tail = q->tail->link;
		return tmp;
	}
}

