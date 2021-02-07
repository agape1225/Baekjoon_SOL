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

#include <cstdio>
#include <cstring>
#include <cstdlib>

int main(void) {

	int num, trash;
	char *input = (char*)malloc(sizeof(char) * 10);
	Stack arr = Stack();
	scanf("%d", &num, &trash);
	//getchar();

	for (int i = 0; i < num; i++) {
		scanf("%s", input);
		
		if (!strcmp(input, "push")) {
			int buff;
			//scanf("%d\n", &buff,&trash);
			scanf("%d", &buff);
			getchar();
			arr.push(buff);
		}
		else if (!strcmp(input, "top"))
			printf("%d\n", arr.getTop());
		else if (!strcmp(input, "empty"))
			printf("%d\n", arr.empty());
		else if (!strcmp(input, "size"))
			printf("%d\n", arr.size());
		else if(!strcmp(input, "pop"))
			printf("%d\n", arr.pop());
	}
	return 0;
}