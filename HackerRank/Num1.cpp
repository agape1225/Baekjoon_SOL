#include <iostream>

using namespace std;

int get_cardinality(int x) {

    int count = 1;

    while (x > 1) {

        

        if (x % 2 == 1) {
            count++;
        }
        x /= x;

        cout << x << endl;
    }

    return count;

}

int main(void) {

    cout << get_cardinality(10269);

    return 0;

}