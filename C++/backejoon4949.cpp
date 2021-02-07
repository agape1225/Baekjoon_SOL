#define SIZE 100

class Stack {
private:

	char stack[SIZE];
	int top;

public:

	Stack() { top = -1; }

	void push(int x) {
		stack[++top] = x;
	}

	int pop() {
		return top == -1 ? -1 : stack[top--];
	}

	int empty() {
		return top == -1 ? 1 : 0;
	}

	void reset() {
		top = -1;
	}
};

#include <cstdio>

int main(void) {

	Stack stack;
	char msg[SIZE];

	while (1) {

		int state = 1;
		stack.reset();

		scanf("%[^\n]s", msg);
		getchar();

		if (msg[0] == '.')
			break;

		for (int i = 0; i < 100 && msg[i] != '.'; i++) {

			if (msg[i] == '{' || msg[i] == '(' || msg[i] == '[')
				stack.push(msg[i]);

			switch (msg[i]) {

			case '}':
				if (stack.pop() != '{')
					state = 0;
				break;
			case ')':
				if (stack.pop() != '(')
					state = 0;
				break;

			case ']':
				if (stack.pop() != '[')
					state = 0;
				break;
			default:
				continue;

			}
			if (state == 0)
				break;
		}

		if (state && stack.empty())
			printf("yes\n");
		else
			printf("no\n");
	}

	return 0;
}