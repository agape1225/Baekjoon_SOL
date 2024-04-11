#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    int string_table[30] = {3, 2, 1, 2, 3, 3, 3, 3, 1, 1, 3, 1, 3, 3, 1, 2, 2, 2, 1, 2, 1, 1, 2, 2, 2, 1};
    string S;
    vector<int> arr;

    cin >> S;

    for(auto it : S){
        arr.push_back(string_table[it - 'A']);
    }

    while(true){

        if(arr.size() == 1){
            if(arr[0] % 2 == 1){
                cout << "I'm a winner!";
            }else{
                cout << "You're the winner?";
            }
            return 0;
        }

        vector<int> tmp;
        for(int i = 0; i < arr.size(); i+=2){
            if(i == arr.size() - 1){
                tmp.push_back(arr[i]);
            }else{
                tmp.push_back((arr[i] + arr[i + 1]) % 10);
            }
        }
        arr = tmp;
    }
    return 0;
}