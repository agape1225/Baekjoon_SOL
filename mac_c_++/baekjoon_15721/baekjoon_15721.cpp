#include <iostream>
#include <vector>

using namespace std;

int main(void){
    int A, T, B;
    vector<int> game;
    int n = 2;
    int index = 0;

    cin >> A >> T >> B;

    int count_b = 0;
    int count_d = 0;

    int line = 2;

    while(true){
        vector<int> sentence = {0, 1, 0, 1};

        for(int i = 0; i < line; i++){
            sentence.push_back(0);
        }

        for(int i = 0; i < line; i++){
            sentence.push_back(1);
        }

        for(auto it : sentence){
            if(it == 0){
                count_b++;
            }else{
                count_d++;
            }

            if(B == 0){
                if(T == count_b){
                    cout << index;
                    return 0;
            }
            }else{
                if(T == count_d){
                    cout << index;
                    return 0;
                }
            }
            index = (index + 1) % A;
        }
    }

    
}