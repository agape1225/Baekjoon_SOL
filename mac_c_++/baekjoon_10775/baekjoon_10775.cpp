#include <iostream>
#include <algorithm>

using namespace std;

int gate_set[100005] = {0};
int plain_number[100005] = {0};

int get_root(int x) {
    if(gate_set[x] == x) {
        return x;
    }
    return gate_set[x] = get_root(gate_set[x]);
}

int union_nodes(int x, int y) {
    int root1 = get_root(x);
    int root2 = get_root(y);

    if(root1 < root2) {
        gate_set[root2] = root1;
    }else {
        gate_set[root1] = root2;
    }
}


int main(void) {

    int G, P;
    int ans = 0;
    cin >> G >> P;

    for(int i = 0; i <= G; i++) {
        gate_set[i] = i;
    }
    for(int i = 0; i < P; i++) {
        cin >> plain_number[i];
    }

    for(int i = 0; i < P; i++) {
        // cin >> plain_number[i];

        int tmp = plain_number[i];
        // cin >> tmp;

        int root = get_root(tmp);

        if(root == 0) {
            break;
        }

        union_nodes(root, root -1);
        
        // if(get_root(tmp) == 0) {
        //     break;
        // }

        ans++;


    }

    // for(int i = 0; i < P; i++) {
    //     count_gates[
    //         plain_number[i]
    //     ] = i + 1;

    //     if(count_gates[plain_number[i]] < i + 1) {
    //         break;
    //     }

    //     ans++;
    // }

    cout << ans;

    return 0;

}