#define IsQueueFull(__q)	__q.head->link == __q.tail
#define IsQueueEmpty(__q)	__q.head == __q.tail


struct node {
	int data;
	struct node *link;
};

struct queue {
	struct node *head;
	struct node *tail;
	/* Optional */
	struct node *last;
};


int main(void)
{
	struct queue p = {0};
	struct queue *q;
	if (IsQueueFull(p)); // No Error
	if (IsQueueEmpty(p));
	return 0;
}
