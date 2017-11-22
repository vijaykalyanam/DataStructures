#include <headers.h>
#include <stdio.h>

int isEmpty(void) {
	return top == -1;
}

int isFull(void) {
	return top == TOP-1;
}

int peek(int stack[]) {
	if(isEmpty()) {
		printf("Stack is Empty\n");
		return -1;
	}

	return stack[top];
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

void list(int astack[]) {

	int t = -1;

	if(isEmpty()) {
		printf("Stack is Empty\n");
		return;
	}
	do {
		t++;
		printf("%d ", astack[t]);
	} while(t != top);
}
