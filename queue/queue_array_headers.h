#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct queue {
	int front;
	int rear;
	int size;
	int data[0];
};

unsigned int createQueue(struct queue **q, unsigned int len);
void destroyQueue(unsigned int id);
