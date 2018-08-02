#include "queue_array_headers.h"

struct Queues {
	bool locked;
	unsigned int len;
	struct queue *q;
};

#define MAX_QUEUES	32
static struct Queues Q[32];

unsigned int createQueue(struct queue **q, unsigned int len)
{

	int i;

	for (i = 0; i < MAX_QUEUES; i++) {
		if (!Q[i].locked) {
			Q[i].locked = true;
			Q[i].q = (struct queue *) malloc(len + sizeof(struct queue));
			*q = Q[i].q;
			Q[i].q->front = -1;
			Q[i].q->rear = -1;
			Q[i].q->size = len;
			Q[i].len = len;
			return i;
		}
	}
	return -1;
}

void destroyQueue(unsigned int id)
{
	if (id < 0 || id > MAX_QUEUES-1) {
		printf("Invalid Queue ID\n");
		return;
	}

	free(Q[id].q);
	Q[id].locked = false;
}
