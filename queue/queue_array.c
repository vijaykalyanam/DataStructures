#include <headers.h>
#include <stdio.h>

#define QLEN	64
#define isEmpty() (head == tail)
#define isFull()  ((head == QLEN-1) && ())

int main(void)
{
	static unsigned int head, tail;
	unsigned int op;
	int data;

	do {
		printf("1.list 2.pop 3.push 4.peek 5.isFull 6.isEmpty\n");
		scanf("%d", &op);

		switch(op) {

			case 1: list(astack); break;
			case 2: printf("popped :%d\n",pop()); break;
			case 3: printf("enter data to push:\n");
				scanf("%d", &data);
				push(data); break;
			case 4: peek(astack); break;
			case 5: isFull(); break;
			case 6: isEmpty(); break;
			default: return 0;
		}
	} while(1);
}
