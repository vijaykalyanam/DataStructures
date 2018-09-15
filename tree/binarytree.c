#include <stdio.h>
#include <stdlib.h>
#include "queue_circular_headers.h"

static struct tnode *root;

static struct tnode *gettnode(void) {
	struct tnode *ptr = (struct tnode *) calloc(1, sizeof(struct tnode));
/*
	printf("enter tnode data:");
	scanf("%d", &ptr->data);
*/
	return ptr;
}

static struct tnode *__addtnode(struct tnode *r, int data)
{
	struct tnode *ptr;

	if (r == NULL) {
		ptr = gettnode();
		ptr->data = data;
		return ptr;
	}

	if (data < r->data)
		r->left = __addtnode(r->left, data);
	else if (data > r->data)
		r->right = __addtnode(r->right, data);
	else {
		printf("Duplicate Data !!!\n");
		return r;
	}
}

struct tnode *addtnode(struct tnode *r)
{
	int data;

	printf("Enter Node Data:\n");
	scanf("%d", &data);

	return __addtnode(r,data);
}

void display(struct tnode *n) {
	if (n == NULL) {
		return;
	}
	printf("%d ", n->data);
	display(n->left);
	display(n->right);
}

int __deletetnode(struct tnode **n)
{
	int curr, next;
	struct tnode *p = *n;

	curr = p->data;

	if (p->left == NULL) {
		free(p);
		*n = NULL;
		return curr; 
	}

	p->data =  __deletetnode(&p->left);
	return curr;
}

struct tnode *deletetnode(struct tnode *n, int data)
{

	if (n == NULL) {
		printf("Node Not Found\n");
		return n;
	}

	if (n->data == data) {

		if (n->left) {
			n->data = __deletetnode(&n->left);
			return n;
		} else if (n->right) {
			n->data = __deletetnode(&n->right);
			return n;
		} else {
			free(n);
			return NULL;
		}
	}

	if (data < n->data)
		n->left = deletetnode(n->left, data);
	else
		n->right = deletetnode(n->right, data);
}

struct tnode *createbst(struct tnode *n)
{

	int i;
	int a[] = {9,3,2,4,15,12,18};

	if (n != NULL) {
		printf("Root tnode is not empty, Must be using someone. Aborting ...\n");
		return n;
	}

	for (i = 0; i < 7; i++) {
		n = __addtnode(n, a[i]);
	}

	return n;
}

int sizeoftree(struct tnode *n)
{
	int left, right;

	if (n == NULL)
		return 0;

	left = sizeoftree(n->left);
	right = sizeoftree(n->right);

	/* Leaf Node */
	if (left == 0 && right == 0)
		return 1;

	return 1 + left + right;
}

struct tnode *deletelist(struct tnode *l)
{
	if (l == NULL)
		return NULL;
	deletelist(l->left);
	deletelist(l->right);
	free(l);
	return NULL;
}

struct tnode *delete(struct tnode *n, int data)
{
	struct tnode *tmp;
	if (n == NULL) {
		printf("Node %d not found in the tree\n", data);
		return NULL;
	}
	printf("n->data :%d data :%d\n",n->data, data);

	if (data < n->data)
		n->left = delete(n->left, data);
	else if (data > n->data)
		n->right = delete(n->right, data);
	else {
		if (n->left && n->right) {
			tmp = n->right;
			while(tmp->left != NULL)
				tmp = tmp->left;
			n->data = tmp->data;
			n->right = delete(n->right, tmp->data);
		} else if (n->left == NULL) {
			tmp = n->right;
			free(n);
			return tmp;
		} else if (n->right == NULL) {
			tmp = n->left;
			free(n);
			return tmp;
		}
	}
	return n;
}

static int height(struct tnode *n)
{

	int left;
	int right;

	if (n == NULL)
		return 0;

	left = height(n->left);
	right = height(n->right);

	if (left == 0 && right == 0)
		return 1;

	if (left <= right)
		return 1+left;
	else
		return 1+right;
}
static int swap(struct tnode *n)
{
	int left;
	int right;

	if (n == NULL) {
		return 0;
	}

	left = swap(n->left);
	right = swap(n->right);
	if (left && right) {
		n->left->data = right;
		n->right->data = left;
	}
	return n->data;
}

static void mirror(struct tnode *n)
{
	struct tnode *left;
	struct tnode *right;

	if (n == NULL)
		return;

	left = n->left;
	right = n->right;

	n->right = left;
	n->left = right;
	mirror(n->left);
	mirror(n->right);
}
static void printLevelOrder(struct tnode *n)
{

	struct queue q = {0};
	struct tnode *tmp;

	createQueue(&q, 15);

	Enqueue(n,&q);

	while(!IsQueueEmpty(&q)) {
		tmp = Dequeue(&q);
		printf("%d ", tmp->data);
		if (tmp->left)
			Enqueue(tmp->left, &q);

		if (tmp->right)
			Enqueue(tmp->right, &q);
	}

}

static int printMax(struct tnode *n)
{

	int left;
	int right;

	if (n == NULL)
		return 0;

	left = printMax(n->left);
	right = printMax(n->right);

	if (left == 0 && right == 0)
		return n->data;

	if (left > right)
		return left;
	else if (left < right)
		return right;
}

int main(void) {
	int option = 0xff;
	int n = -1;
	printf("Binary Tree  - Choose your action:\n 1.Create\n"
			"2.display\n3. Insert\n 4.sizeoftree\n");
	printf("5.deleteleftsubtree\n 9.deleterightsubtree\n 6.delete tnode\n"
			"66.delete tnode(pure recursion)\n7.delete list\n8.exit\n 11.swap child\n 12.Mirrors\n 13.LevelOrder");

	struct queue q = {0};
	while(1) {

		printf("Enter your option:");
		scanf("%d", &option);

		switch (option) {
			case 1: root = createbst(root);
				break;

			case 2: display(root);
				printf("Done\n");
				break;
			case 3: root = addtnode(root);
				break;
			case 4: printf("Total Number of Nodes :%d\n", sizeoftree(root));
				break;
			case 6: printf("Enter Node to delete:\n");
				scanf("%d", &n);
				root = deletetnode(root, n);
				printf("Done\n");
				break;
			case 66: printf("Enter Node to delete:\n");
				scanf("%d", &n);
				root = delete(root, n);
				printf("Done\n");
				break;


			case 7: root = deletelist(root);
				printf("Done\n");
				break;
			case 5: root->left = deletelist(root->left);
				printf("Done\n");
				break;
			case 9: root->right = deletelist(root->right);
				printf("Done\n");
				break;
			case 8: exit(0);
				break;

			case 11:	swap(root);
					break;
			case 12:	mirror(root);
					break;
			case 13: printLevelOrder(root);
				 printf("Maximum :%d\n", printMax(root));
				 printf("Height :%d\n", height(root));
				 break;

			default: ;
		}
	}
	return 0;
}
