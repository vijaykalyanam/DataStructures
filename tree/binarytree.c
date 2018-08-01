#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *left;
	int data;
	struct node *right;
}*root=NULL;

static struct node *getnode(void) {
	struct node *ptr = (struct node *) calloc(1, sizeof(struct node));
/*
	printf("enter node data:");
	scanf("%d", &ptr->data);
*/
	return ptr;
}

static struct node *__addnode(struct node *r, int data)
{
	struct node *ptr;

	if (r == NULL) {
		ptr = getnode();
		ptr->data = data;
		return ptr;
	}

	if (data < r->data)
		r->left = __addnode(r->left, data);
	else if (data > r->data)
		r->right = __addnode(r->right, data);
	else {
		printf("Duplicate Data !!!\n");
		return r;
	}
}

struct node *addnode(struct node *r)
{
	int data;

	printf("Enter Node Data:\n");
	scanf("%d", &data);

	return __addnode(r,data);
}

void display(struct node *n) {
	if (n == NULL) {
		return;
	}
	printf("%d ", n->data);
	display(n->left);
	display(n->right);
}

int __deletenode(struct node **n)
{
	int curr, next;
	struct node *p = *n;

	curr = p->data;

	if (p->left == NULL) {
		free(p);
		*n = NULL;
		return curr; 
	}

	p->data =  __deletenode(&p->left);
	return curr;
}

struct node *deletenode(struct node *n, int data)
{

	if (n == NULL) {
		printf("Node Not Found\n");
		return n;
	}

	if (n->data == data) {

		if (n->left) {
			n->data = __deletenode(&n->left);
			return n;
		} else if (n->right) {
			n->data = __deletenode(&n->right);
			return n;
		} else {
			free(n);
			return NULL;
		}
	}

	if (data < n->data)
		n->left = deletenode(n->left, data);
	else
		n->right = deletenode(n->right, data);
}

struct node *createbst(struct node *n)
{

	int i;
	int a[] = {9,3,2,4,15,12,18};

	if (n != NULL) {
		printf("Root node is not empty, Must be using someone. Aborting ...\n");
		return n;
	}

	for (i = 0; i < 7; i++) {
		n = __addnode(n, a[i]);
	}

	return n;
}

int sizeoftree(struct node *n)
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

struct node *deletelist(struct node *l)
{
	if (l == NULL)
		return NULL;
	deletelist(l->left);
	deletelist(l->right);
	free(l);
	return NULL;
}

struct node *delete(struct node *n, int data)
{
	struct node *tmp;
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

int main(void) {
	int option = 0xff;
	int n = -1;
	printf("Binary Tree  - Choose your action:\n 1.Create\n"
			"2.display\n3. Insert\n 4.sizeoftree\n");
	printf("5.deleteleftsubtree\n 9.deleterightsubtree\n 6.delete node 66.delete node(pure recursion)\n7.delete list\n8.exit\n");

	while(1) {

		printf("Enter your option:");
		scanf("%d", &option);

		switch (option) {
			case 1: root = createbst(root);
				break;

			case 2: display(root);
				printf("Done\n");
				break;
			case 3: root = addnode(root);
				break;
			case 4: printf("Total Number of Nodes :%d\n", sizeoftree(root));
				break;
			case 6: printf("Enter Node to delete:\n");
				scanf("%d", &n);
				root = deletenode(root, n);
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

			default: ;
		}
	}
	return 0;
}
