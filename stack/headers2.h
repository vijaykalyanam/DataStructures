#include <stdio.h>
#include <stdlib.h>

#define isEmpty(_top)	isFull(_top)
#define isFull(_top)	(!!!(_top))

struct node {
	int data;
	struct node *next;
};

#ifndef INLINED
#define INLINED
inline void sample2(void)
{
	if (1)
		printf("Extern inline\n");

}
#endif

static inline void samples(void)
{
	if (1)
		printf("static inline header file\n");

}

//extern inline void sample2(void);
int peek(struct node *);
struct node* push(struct node *);
int pop(struct node **);
void list(struct node *);
