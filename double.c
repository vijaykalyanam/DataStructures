#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
	struct node *prev;
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
			p->next->prev = p;
			p = p->next;
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
		tmp->next->prev = tmp;
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
		tmp->prev = p;
	}

	return;
}

void reverse(void) {
	struct node *p,*q;
	if (head) {
		p = head;
		q = p->next;
	} else {
		printf("List empty!!!\n");
		return;
	}

	if (q == NULL)
		return;

	p->next = NULL;
	p->prev = q;

	while (q) {
		q->prev = q->next;
		q->next = p;
		p = q;
		q = p->prev;
	}

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
			if (head)
				head->prev = NULL;
			free(p);
			p = head;
		} else {
			while (p->next && p->data != n)
				p = p->next;
			if (p->data == n) {
				tmp = p;
				if (p->next != NULL)
					p->next->prev = p->prev;
				p->prev->next = p->next;
				free(tmp);
			}
			p = p->next;
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
