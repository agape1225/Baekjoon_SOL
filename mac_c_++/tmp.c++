#include <cstdio>
#include <string>
#include <iostream> 
#include <vector>
using namespace std;  

void print_arr(int arr[105], int N){
    for(int i = 0; i < N; i++){
        cout << arr[i] << ' ';
    }
}

int main() { 

    int arr[105] = {1, 2, 3};
    int N = 3;

    print_arr(arr, N);
     
    return 0;
} 
