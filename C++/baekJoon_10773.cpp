#define SIZE 10000

class Stack {
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
};

#include <stdio.h>

int main(void) {

	int num;
	Stack stack;

	scanf("%d", &num);
	getchar();

	for (int i = 0; i < num; i++) {
		
		int input;
		scanf("%d", &input);
		getchar();

		if (input) {
			stack.push(input);
		}
		else {
			stack.pop();
		}
	}

	int buff;
	int total = 0;

	while ((buff = stack.pop()) != -1) total = total + buff;

	printf("%d", total);

	return 0;
}