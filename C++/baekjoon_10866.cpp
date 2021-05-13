#include <iostream>
#include <string>
#include <deque>
#define SIZE 10000

using namespace std;

int main(void) {

	deque<int> deq;

	int input;
	cin >> input;

	string command;
	int data;

	for (int i = 0; i < input; i++) {
		
		//cout << "ют╥б: ";
		cin  >> command;
		//cout << command << endl;

		if (command.compare("push_front") == 0 || command.compare("push_back") == 0) {
			//cout << "data input";
			cin >> data;
			//cout << data << endl;
		}

		if (command.compare("push_front") == 0) {
			deq.push_front(data);
			cout << deq.front() << '\n';
			//cout << deq.front() << endl;

		}
		else if (command.compare("push_back") == 0) {
			deq.push_back(data);

		}
		else if(command.compare("pop_front") == 0) {
			if (deq.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << deq.front() << '\n';
				deq.pop_front();
			}
			


		}
		else if (command.compare("pop_back") == 0) {

			if (deq.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << deq.back() << '\n';
				deq.pop_back();
			}
			

		}
		else if (command.compare("size") == 0) {
			cout << deq.size() << '\n';
		}
		else if (command.compare("empty") == 0) {
			if (deq.empty()) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}

		}
		else if (command.compare("front") == 0) {
			if (deq.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << deq.front() << '\n';
			}
			//cout << 1 << endl;

		}
		else if (command.compare("back") == 0) {
			if (deq.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << deq.back() << '\n';
			}
			

		}


	}

}