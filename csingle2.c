#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct node {
	int data;
	struct node *link;
}**last=NULL;

static struct node *getnode() {
	struct node *ptr = calloc(1, sizeof(struct node));
	printf("enter node data:");
	scanf("%d", &ptr->data);
	return ptr;
} 

void createlist(void) {
	struct node *p;
	int n,i;

	printf("enter no of nodes to create:");
	scanf("%d", &n);

	for(i=0; i<n; i++) {
		if (last == NULL) {
			p = getnode();
			last = &p;
			p->link = *last;
		} else {
			p = getnode();
			/* Error will be thrown if there is no bracket for last */
			p->link = (*last)->link;
			(*last)->link = p;
			last = &p;
		}
	}

	return;
}
/*
 * If there is no '\n', then you dont see debug logs.
 * Printf flush all the data to STDOUT when it read '\n'
 *
 */
void display(void) {
printf("1\n");
sleep(2);
	struct node *p = *last;
printf("12\n");
	if (last == NULL) {
		printf("Empty List\n");
		return;
	}
printf("123\n");
/* This is causing Seg Fault */
	p = (*last)->link;
printf("1234\n");
	do {
		printf("%d ", p->data);
		p = p->link;
	} while(p != *last);
	printf("\n");

	return;
}

#ifdef DISABLED
void addatbegin(void) {
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

void addatend(void) {
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

void reverse(void) {
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

void deletenode(void) {

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
			/* If we are deleting the only node */
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

void deletelist(void) {

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

#endif

int main(void) {
	int option = 0xff;

	printf("Single Linked List - Choose your action:\n 1.Create\n"
			"2.display\n3.add at beg\n4.add at end\n");
	printf("5.reverse\n6.delete node\n7.delete list\n8.exit\n");

	while(1) {

		printf("Enter your option:");
		scanf("%d", &option);

		switch (option) {
			case 1: createlist();
				printf("List created.\n");
				break;

			case 2:
				printf("Start\n");
				display();
				printf("Done\n");
				break;
/*
			case 3: addatbegin();
				printf("Done\n");
				break;

			case 4: addatend();
				printf("Done\n");
				break;

			case 5: reverse();
				printf("Done\n");
				break;

			case 6: deletenode();
				printf("Done\n");
				break;

			case 7: deletelist();
				printf("Done\n");
				break;
*/
			case 8: exit(0);
				break;

			default: ;
		}
	}
	return 0;
}
