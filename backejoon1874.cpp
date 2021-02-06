#define SIZE 200001

typedef class Stack {
private:

	int stack[SIZE];
	int top;

public:

	Stack() { top = -1; }

	void push(int x) {
		stack[++top] = x;
	}

	int pop() {
		return top == -1 ? -1 : stack[top--];
	}

	int size() {
		return top + 1;
	}

	int empty() {
		return top == -1 ? 1 : 0;
	}

	int getTop() {
		return top == -1 ? -1 : stack[top];
	}
} *stackPtr;

#include <stdio.h>

void reverseStack(Stack &stack);

int main(void) {

	Stack stack;
	Stack answer;
	int arr[100001];
	int num, max;
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		int buff;
		scanf("%d", &buff);
		arr[i] = buff;
	}

	max = 1;

	for (int i = 0; i < num; i++) {

		if (arr[i] >= max) {
			for (int j = max; j <= arr[i]; j++) {
				stack.push(j);
				answer.push('+');
			}
			stack.pop();
			max = arr[i] + 1;
			answer.push('-');
		}
		else {
			if (stack.pop() != arr[i]) {
				printf("No");
				return 0;
			}
			else
				answer.push('-');
		}
	}

	reverseStack(answer);
	
	return 0;
}

void reverseStack(Stack &fStack) {
	char buff;
	if ((buff = fStack.pop()) != -1) {
		reverseStack(fStack);
		printf("%c\n", buff);
	}
}