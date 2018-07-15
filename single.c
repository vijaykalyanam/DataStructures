#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *link;
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
			p->link = getnode();
			p = p->link;
		}
	}

	return;
}

void display(void) {
	struct node *p = head;

	while(p) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf("\n");
	return;
}

void addatbegin(void) {
	struct node *tmp = getnode();

	if (head == NULL) {
		head = tmp;
	} else {
		tmp->link = head;
		//tmp->link = head->link; If HEAD NODE USED.
		head = tmp;
	}

	return;
}

void addatend(void) {
	struct node *tmp, *p;

	tmp = getnode();

	if (head == NULL) {
		head = tmp;
	} else {
		p = head;
		while (p->link != NULL)
			p = p->link;
		p->link = tmp;
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

	if (q == NULL)
		return;
	p->link = NULL;

	while (q) {
		r = q->link;
		q->link = p;
		p = q;
		q = r; 
	}
	head = p;
	return;
}

/*
 *
 * N1->N2->N3->N4->N5
 *
 * 1. STOP case : Last Node.
 * 2. To rearrange, we need previous node and current node link while returning.
 * 3. We need to return HEAD.
 * 4. 
 *
 *
 */
struct node *rreverse(struct node *prev, struct node *curr)
{
	struct node *last;
	if (curr == NULL)
		return prev;	
	last = rreverse(curr, curr->link);
	curr->link = prev;
        return last;
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

struct node *rdeletenode(struct node *curr, int data)
{
	struct node *tmp;

	if (curr == NULL)
		return NULL;

	if (curr->data == data) {
		tmp = curr->link;
		free(curr);
		curr = rdeletenode(tmp, data);
	} else {
		curr->link = rdeletenode(curr->link, data);
	}
	return curr;
}

void deletelist(void) {

	struct node *tmp, *p;

	p = head;

	while (p) {
		tmp = p;
		p = p->link;
		free(tmp);
	}

	head = NULL;

	return;
}

static struct node *palindrome(struct node *p, struct node *q)
{
	if (q->link == NULL)
		return q;
	q = _palindrome(p->link, q->link->link);

}
int palindrome(struct node *head)
{
      return _palindrome(head, head);
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

			case 5: //reverse();
				head = rreverse(NULL, head);
				printf("Done\n");
				break;

			case 6: deletenode();
				head = rdeletenode(head, 7);
				printf("Done\n");
				break;

			case 7: deletelist();
				printf("Done\n");
				break;

			case 8: if (palindrome(head))
					printf("Not Palindrome\n");
				else
					printf("Paalindrome\n");
				break;
			case 9: exit(0);
				break;

			default: ;
		}
	}
	return 0;
}
