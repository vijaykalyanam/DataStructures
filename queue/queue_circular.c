#include "queue_circular_headers.h"

static struct node *getnode() {
	struct node *ptr = calloc(1, sizeof(struct node));
	printf("enter node data:");
	scanf("%d", &ptr->data);
	return ptr;
} 
/*
int createQueue(struct queue **q, unsigned int len)
{
	struct node *last = NULL;
	struct node *p;
	int i;

	if (q == NULL || *q == NULL)
		return -1;
	for(i=0; i<len; i++) {
		if(last == NULL) {
			(*q)->last = getnode();
			last = (*q)->last;
			last->link = last;
		} else {
			p = getnode();
			p->link = last->link;
			last->link = p;			
			last = last->link;
		}
	}
	// The below approach is not correct. The one should be done as seen beneath of it
	// Remember ETH_HDR() MACRO.
	// *q->head = *q->tail = *q->last = last;
	(*q)->head = (*q)->tail = (*q)->last = last;
	return 0;
}
*/
int createQueue(struct queue *q, unsigned int len)
{
	struct node *last = NULL;
	struct node *p;
	int i;

	if (q == NULL)
		return -1;
	for(i=0; i<len; i++) {
		if(last == NULL) {
			q->last = getnode();
			last = q->last;
			last->link = last;
		} else {
			p = getnode();
			p->link = last->link;
			last->link = p;			
			last = last->link;
		}
	}
	// The below approach is not correct. The one should be done as seen beneath of it
	//*q->head = *q->tail = *q->last = last;
	q->head = q->tail = q->last = last;
	return 0;
}
void display(struct queue *q) {
	struct node *last = q->last;
	struct node *p = last;
	if (last == NULL) {
		printf("Empty List\n");
		return;
	}

	p = last->link;
	do {
		printf("%d ", p->data);
		p = p->link;
	} while(p != last->link);
	printf("\n");
}
/*
static void addatbegin(struct queue *q) {
	struct node *last = q->last;
	struct node *tmp = getnode();

	if (last == NULL) {
		last = tmp;
		last->link = last;
	} else {
		tmp->link = last->link;
		//tmp->link = last->link; If HEAD NODE USED.
		last->link = tmp;
	}
	tmp = NULL;

	return;
}

static void addatend(void) {
	struct node *tmp, *p;

	tmp = getnode();

	if (last == NULL) {
		last = tmp;
		last->link = last;
	} else {
		tmp->link = last->link;
		last->link = tmp;
		last = last->link;
	}
	tmp = NULL;

	return;
}

static void reverse(void) {
	struct node *p,*q,*r;
	if(last) {
		p = last->link;
		q = p->link;
	} else {
		return;
	}

	if (q == NULL)
		return;
	p->link = last;
	last = p;
	//while (q != last) {
	do {
		r = q->link;
		q->link = p;
		p = q;
		q = r; 
	} while(q != last);

	return;
}

static void deletenode(void) {

	struct node *tmp, *p;
	int n;

	if (last == NULL) {
		printf("List is empty\n");
		return;
	}

	printf("enter node to delete:");
	scanf("%d",&n);

	tmp = NULL;
	p = last->link;

	do {
		if (last->link->data == n) {
			tmp = last->link;
			last->link = last->link->link;
			p = last->link;
		} else	if (p->link->data == n) {
			tmp = p->link;
			if (p->link == last)
				last = p;
			p->link = p->link->link;
		} else {
			p = p->link;
		}

		if (tmp) {
//			If we are deleting the only node
			if (tmp == last && tmp == last->link) {
				last = NULL;
				return;
			}
			free(tmp);
			tmp = NULL;
		}

	} while (p != last);

	return;
}

static void deletelist(void) {

	struct node *tmp, *p;

	p = last->link;
	last->link = NULL;

	while (p) {
		tmp = p;
		p = p->link;
		free(tmp);
	}

	last = NULL;

	return;
}

*/
