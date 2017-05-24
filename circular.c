#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *link;
} *head;

static struct node *getnode() {
	struct node *ptr = calloc(1, sizeof(struct node));
	printf("enter node data:");
	scanf("%d", &ptr->data);
	return ptr;
} 

void deletelist(void) {

	struct node *tmp, *p;

	if (head == NULL) 
		return;
	else
		p = head;

	do {
		tmp = p;
		p = p->link;
		free(tmp);
	} while (p != head);

	head = NULL;

	return;
}

void createlist(void) {
	struct node *p;
	int n,i;

	if (head != NULL)
		deletelist();

	printf("enter no of nodes to create:");
	scanf("%d", &n);

	for(i=0; i<n; i++) {
		if(head == NULL) {
			head = (struct node *) calloc(1, sizeof(struct node));
			p = head;
			printf("Enter HEAD node data:");
			scanf("%d", &p->data);
			p->link = head;
		} else {
			p->link = (struct node *) calloc(1, sizeof(struct node));
			printf("Enter node data:");
			scanf("%d", &p->link->data);
			p->link->link = head;
			p = p->link;
		}
	}

	return;
}

void display(void) {
	struct node *p = head;

	if (head == NULL) {
		printf("List Empty\n");
		return;
	}

	p = head;
	do {
		printf("%d ", p->data);
		p = p->link;
	} while(p->link != head);
	printf("\n");
	return;
}

void addatbegin(void) {
	struct node *tmp = getnode();

	if (head == NULL) {
		head = tmp;
		tmp->link = head;
	} else {
		tmp->link = head;
		head = tmp;
	}
	tmp = NULL;
	return;
}

void addatend(void) {
	struct node *tmp, *p;

	tmp = getnode();

	if (head == NULL) {
		head = tmp;
		tmp->link = head;
	} else {
		p = head;
		do {
		p = p->link;
		} while (p->link != head);
		p->link = tmp;
		tmp->link = head;
	}

	return;
}

void reverse(void) {
	struct node *p,*q,*r;

	if(head) {
		p = head;
		q = p->link;
	} else {
		return;
	}

	if (q == head) {
		printf("ONlY one node\n");
		return;
	}

	p->link = head;
	do {
		r = q->link;
		q->link = p;
		p = q;
		q = r; 
	} while (q->link != head);

	head = q;
	return;
}

void deletenode(void) {

	struct node *tmp, *p;
	int n;

	printf("enter node to delete:");
	scanf("%d",&n);

	p = head;

	while(p) {
		if (n == head->data) {
			p = head;
			head = head->link;
			free(p);
			p = head;
		} else {
			while(p->link && p->link->data != n)
				p = p->link;
			if (p->link != NULL) {
				tmp = p->link;
				p->link = p->link->link;
				free(tmp); 
			} else {
				p = p->link;
			}
		}
	}

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
