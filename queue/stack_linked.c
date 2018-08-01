#include <headers2.h>
#include <stdio.h>

int main(void)
{

	unsigned int op;
	int data;

	struct node *top = NULL;

	do {
		printf("\nlist 2.pop 3.push 4.peek 5.isFull 6.isEmpty\n");
		scanf("%d", &op);

		switch(op) {

			case 1: list(top); break;
			case 2: printf("popped :%d\n", pop(&top)); break;
			case 3: top = push(top); break;
			case 4: printf("%d is at top\n", peek(top)); break;
			case 5:	printf("Stack is dynamic\n");
				break;
			case 6: if (isEmpty(top))
					printf("Stack is Empty\n");
				else
					printf("stack is not empty\n");
				break;
			default: return 0;
		}
	} while(1);
}
