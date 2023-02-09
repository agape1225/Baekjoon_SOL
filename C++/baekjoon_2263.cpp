#include <iostream>

using namespace std;

int		pre[100001]		= { 0 };		//전위
int		in[100001]		= { 0 };		//중위
int		post[100001]	= { 0 };		//후위
int		n;

void print_pre(int post_start, int post_end, int in_start, int in_end) {
	

	if (post_start <= post_end) {

		int root = post[post_end];
		cout << root << ' ';

		int	middle = in_start;

		while (in[middle] != root)
			middle++;

		int left_count = middle - in_start;
		int right_count = in_end - middle;

		//left tree
		print_pre(post_start, post_start + left_count - 1, in_start, in_start + left_count - 1);
		//right tree
		print_pre(post_start + left_count, post_start + left_count + right_count - 1, middle + 1, middle + right_count);
	}
}

int main(void) {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> in[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> post[i];
	}
	print_pre(0, n - 1, 0, n - 1);

	return 0;
}