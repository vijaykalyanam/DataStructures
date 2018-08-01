#include <headers.h>
#include <stdio.h>

/* Advantage of linkedlist stack over array : No need to have
 * extra variable 'top'. when list is empty, its end of stack.
 */

#define TOP 8
static int top = -1;
static int astack[TOP];

int isEmpty(void)
{
	return top == -1;
}

int isFull(void)
{
	return top == TOP-1;
}

int peek(void) {
	if(isEmpty()) {
		printf("Stack is Empty\n");
		return -1;
	}

	return astack[top];
}

int push(int data) {
	if (isFull()) {
		printf("Stack is Full\n");
		return -1;
	}
	astack[++top] = data;
}

int pop(void) {
	if(isEmpty()) {
		printf("Stack is Empty\n");
		return -1;
	}
	return astack[top--];
}

void list(void) {

	int t = top;

	if(isEmpty()) {
		printf("Stack is Empty\n");
		return;
	}

	do {
		printf("%d\n", astack[t--]);
	} while(t >= 0);
}

int main(void)
{
    
        unsigned int op;
        int data;

        do {     
                printf("\nlist 2.pop 3.push 4.peek 5.isFull 6.isEmpty\n");
                scanf("%d", &op);
 
                switch(op) {

                        case 1: list(); break;
			case 2: printf("popped :%d\n", pop()); break;
			case 3: printf("Enter data to push:");
				scanf("%d",&data);
				push(data);
				break;
                        case 4: printf("%d is at top\n", peek()); break;
                                break;
                        case 5: if (isFull())
                                        printf("Stack is Full\n");
                                else
                                        printf("stack is not Full\n");
                                break;
                        case 6: if (isEmpty())
                                        printf("Stack is Empty\n");
                                else
                                        printf("stack is not empty\n");
                                break;
                        default: return 0;
                }
        } while(1);
}               
