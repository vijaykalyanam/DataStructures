/*
int isEmpty(struct node *top)
{
	return !!top;
}
*/

#include <headers2.h>


void list(struct node *top)
{

	if (isEmpty(top)) {
		printf("List is Empty\n");
		return;
	}

	do {
		printf("%d ", top->data);
		top = top->next;
	} while(top);

}

int pop(struct node **top)
{

	struct node *tmp, *t;

	if (isEmpty(*top))
		return -1;

	tmp = *top;
	t = *top;
	*top = t->next;
	tmp->next = NULL;

	return tmp->data;
}

struct node* push(struct node *top)
{

	struct node *tmp = (struct node *)calloc(1, sizeof(struct node));
	printf("\nenter node data:");
	scanf("%d", &tmp->data);
	tmp->next = top;
	top = tmp;
	return top;
}

int peek(struct node *top)
{
	if (isEmpty(top))
		return -1;
	return top->data;
}

