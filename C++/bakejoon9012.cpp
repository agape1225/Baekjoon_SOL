#define SIZE 50

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

	int size() {
		return top + 1;
	}

	int empty() {
		return top == -1 ? 1 : 0;
	}

	void reset() {
		top = -1;
	}
};

#include <cstdio>
#include <cstring>
#include <cstdlib>

int main(void) {

	Stack stack;
	char *pMessage = (char*)malloc(sizeof(char) * 50);
	int num;
	scanf("%d", &num);
	getchar();
	
	for (int i = 0; i < num; i++) {
		int ans = 1;
		scanf("%s", pMessage);
		getchar();

		while (*pMessage) {
			
			if (*pMessage == ')') {
				if (stack.pop() != '(') {
					ans = 0;
					break;
				}
				else
					pMessage++;
			}
			else
				stack.push(*pMessage++);
		}

		if (ans && stack.empty())
			printf("YES\n");
		else
			printf("NO\n");

		stack.reset();
	}
	return 0;
}