#include <stdio.h>
#include <stdlib.h>

#if defined(__DOUBLE_LINKED_LIST__)
#elif defined(__SINGLE_LINKED_LIST__)
#elif defined(__DOUBLE_LINKED_LIST__) && defined(__SINGLE_LINKED_LIST__)
#error "Cannot Define both flags At once. UNDEFINING __SINGLE_LINKED_LIST__"
#else
#error "Neither Single Nor Double Linked List Selected."
#error "Usage: cc -D__DOUBLE_LINKED_LIST__/-D__SINGLE_LINKED_LIST__"
#endif

struct node {
	int data;
	struct node *next;
#ifdef __DOUBLE_LINKED_LIST__
	struct node *prev;
#endif
}*head=NULL;

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
		if(head == NULL) {
			p = head = getnode();
		} else {
			p->next = getnode();
#ifdef __DOUBLE_LINKED_LIST__
			p->next->prev = p;
			p = p->next;
#endif
		}
	}

	return;
}

void display(void) {
	struct node *p = head;

	while(p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	return;
}

void addatbegin(void) {

	struct node *tmp;
	tmp = getnode();

	if (head == NULL) {
		head = tmp;
	} else {
		tmp->next = head;
#ifdef __DOUBLE_LINKED_LIST__
		tmp->next->prev = tmp;
#endif
		head = tmp;
	}

	return;
}

void addatend(void) {

	struct node *tmp, *p;

	tmp = getnode();

	p = head;

	if (head == NULL) {
		head = tmp;
	} else {
		while (p->next != NULL)
			p = p->next;
		p->next = tmp;
#ifdef __DOUBLE_LINKED_LIST__
		tmp->prev = p;
#endif
	}

	return;
}

void reverse(void) {

	struct node *p,*q;
#ifdef __SIGNLE_LINKED_LIST__
	struct node *r;
#endif
	if (head) {
		p = head;
		q = p->next;
	} else {
		printf("List empty!!!\n");
		return;
	}

	if (q == NULL) {
		printf("List has Only one Node!!!\n");
		return;
	}

	p->next = NULL;

#ifdef __DOUBLE_LINKED_LIST__

	p->prev = q;
	while (q) {
		q->prev = q->next;
		q->next = p;
		p = q;
		q = p->prev;
	}

#elif __SIGNLE_LINKED_LIST__

	while (q) {
		r = q->next;
		q->next = p;
		p = q;
		q = r; 
	}
#endif
	head = p;
	return;
}

void deletenode(void) {

	int n;
	struct node *p, *tmp;

	printf("enter node to delete with data:");
	scanf("%d", &n);

	p = head;

	while (p) {

		if (head->data == n) {
			head = head->next;
#ifdef __DOUBLE_LINKED_LIST__
			if (head)
				head->prev = NULL;
#endif
			free(p);
			p = head;
		} else {
			while (p->next && p->data != n)
				p = p->next;
#ifdef __DOUBLE_LINKED_LIST__
			if (p->data == n) {
				tmp = p;
				if (p->next != NULL)
					p->next->prev = p->prev;
				p->prev->next = p->next;
				free(tmp);
			}
			p = p->next;
#elif __SIGNLE_LINKED_LIST__
			if (p->next != NULL) {
				tmp = p->next;
				p->next = p->next->next;
				free(tmp); 
			} else {
				p = p->link;
			}
#endif
		}
	}
	return;
}

void deletelist(void) {

	struct node *tmp, *p;

	p = head;

	while (p) {
		tmp = p;
		p = p->next;
		free(tmp);
	}
	head = NULL;
	return;
}

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

			case 2: display();
				printf("Done\n");
				break;

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

			case 8: exit(0);
				break;

			default: ;
		}
	}
	return 0;
}
