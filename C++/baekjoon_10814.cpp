#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
#define SIZE 100000

using namespace std;

int		age[SIZE];
int		buff[SIZE];
string	name[SIZE];

int main(void) {

	int N;

	scanf_s("%d", &N);

	int tmp;
	for (int i = 0; i < N; i++) {
		//scanf_s("%d", &age[i]);
		scanf_s("%d", &tmp);
		age[i] = buff[i] = tmp;
		cin >> name[i];
	}

	sort(buff, buff + N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (age[j] == buff[i]) {
				printf("%d ", age[j]);
				cout << name[j];
				printf("\n");
				age[j] = -1;
				break;
			}
		}
	}

	return 0;

}