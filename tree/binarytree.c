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

int main(void) {
	int option = 0xff;

	printf("Binary Tree  - Choose your action:\n 1.Create\n"
			"2.display\n3.add at beg\n4.add at end\n");
	printf("5.reverse\n6.delete node\n7.delete list\n8.exit\n");

	while(1) {

		printf("Enter your option:");
		scanf("%d", &option);

		switch (option) {
			case 1: root = addnode(root);
				break;

			case 2: display(root);
				printf("Done\n");
				break;
/*
			case 3: addatbegin();
				printf("Done\n");
				break;

			case 4: addatend();
				printf("Done\n");
				break;

			case 5: //reverse();
				root = rreverse(NULL, root);
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
